#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define vpi vector<pair<int, int>>
#define mii map<int, int>
#define pb push_back
#define __mayuk                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int32_t main()
{
    __mayuk;
    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}

class disjointsetUnion
{
public:
    vector<int> rank, parent, size;

public:
    disjointsetUnion(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findparent(int node)
    {
        if (node == parent[node])
            return node;
        else
        {
            return parent[node] = findparent(parent[node]);
        }
    }

    // which node have larger rank become parent of the node having smaller rank , if both have equal rank then we can make any of them parent of any but whom we make parent its rank increases by 1 .....
    void unionbyRank(int u, int v)
    {
        int upar = findparent(u);
        int vpar = findparent(v);
        if (upar == vpar)
            return;

        if (rank[upar] < rank[vpar])
            parent[upar] = vpar;

        else if (rank[upar] > rank[vpar])
            parent[vpar] = upar;

        else if (rank[upar] == rank[vpar])
        {
            parent[upar] = vpar;
            rank[vpar]++;
        }
    }

    // larger size node become parent of smaller size node and and also its size is increased by the size of smaller size node, here if both has equal size then also we can take any one of them and do the same .....

    void unionbySize(int u, int v)
    {
        int upar = findparent(u);
        int vpar = findparent(v);
        if (upar == vpar)
            return;

        if (size[upar] > size[vpar])
        {
            parent[vpar] = upar;
            size[upar] += size[vpar];
        }
        else
        {
            parent[upar] = vpar;
            size[vpar] += size[upar];
        }
    }
};

// no of proviences using dsu......

int findCircleNum(vector<vector<int>> &isConnected)
{
    int v = isConnected.size();
    disjointsetUnion ds(v);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (isConnected[i][j] == 1)
                ds.unionbySize(i, j);
        }
    }

    int componentcnt = 0;
    for (int i = 0; i < v; i++)
    {
        if (ds.findparent(i) == i)
            componentcnt++;
    }

    return componentcnt;
}

//  Number of Operations to Make Network Connected...........

// in one operation we can remove an extra edge and use this 2 join 2 connected components now we have to return the minimum no of operations so that there is no connected component remain in the graph if it is not possible then return -1 ......

// if 2 components have same parent it means they are connected becuase they already have an edge and still if we can found any edge it means it is extra edge so we have to count it....

int makeConnected(int n, vector<vector<int>> &connections)
{
    disjointsetUnion ds(n);
    int extraedge = 0;
    for (auto it : connections)
    {
        int u = it[0], v = it[1];
        if (ds.findparent(u) == ds.findparent(v))
            extraedge++;
        else
            ds.unionbySize(u, v);
    }

    int componentcnt = 0;

    // because for each connected component its parent node is equal to the node.....
    for (int i = 0; i < n; i++)
    {
        if (ds.findparent(i) == i)
            componentcnt++;
    }

    int ans = componentcnt - 1;
    if (extraedge >= ans)
    {
        return ans;
    }
    else
    {
        return -1;
    }
}

// account merge leetcode......

/*
Input: accounts =   [["John","johnsmith@mail.com","john_newyork@mail.com"],
                    ["John","johnsmith@mail.com","john00@mail.com"],
                    ["Mary","mary@mail.com"],
                    ["John","johnnybravo@mail.com"] ]

Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
         ["Mary","mary@mail.com"],
         ["John","johnnybravo@mail.com"]]


*/

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    int n = accounts.size();
    unordered_map<string, int> mapmailnode;

    disjointsetUnion ds(n);

    // step 1 --> maping all the emails with the proper index and union same email indexes.....
    for (int i = 0; i < n; i++)
    {
        int m = accounts[i].size();
        // this loop runs from j=1 because at j=0 there is name stored.....
        for (int j = 1; j < m; j++)
        {
            string email = accounts[i][j];
            if (mapmailnode.find(email) == mapmailnode.end())
            {
                mapmailnode[email] = i;
            }
            else if (mapmailnode.find(email) != mapmailnode.end())
            {
                // it means this email is already present in the map....
                ds.unionbyRank(i, mapmailnode[email]);
            }
        }
    }

    // store the email into an vector<string> based on the indexes....
    vector<string> mergeemail[n];
    for (auto it : mapmailnode)
    {
        string email = it.first;
        int node = it.second;
        int parentnode = ds.findparent(node);
        mergeemail[parentnode].push_back(email);
    }

    // now from this to convert it into main answer based on sorted order of email....

    vector<vector<string>> ans;
    for (int i = 0; i < n; i++)
    {
        if (mergeemail[i].size() == 0)
            continue;
        else
        {
            sort(mergeemail[i].begin(), mergeemail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergeemail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
    }

    return ans;
}

// no of island 2 --> online query based questions....

/*
HINT and STEPS to IMPLEMENT -->
whenever we make any cell value ( 0 to 1 ) cnt ++
then iterate on its neighbouring element for each neighbouring element if we found it is land(1) and they are not belong to the same commponent union them and reduce cnt by 1 i.e. cnt -- ...
keep the track current cnt in a array for each operation ...
*/

bool isvailed(int row, int col, int n, int m, vector<vector<int>> &vis)
{
    if (row >= 0 and row < n and col >= 0 and col < m and vis[row][col] == 1)
        return true;
    else
        return false;
}

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
{
    disjointsetUnion ds(n * m);
    vector<vector<int>> vis(n, vector<int>(m, 0));

    vector<int> r = {0, -1, 0, 1};
    vector<int> c = {-1, 0, 1, 0};

    int cnt = 0;
    vector<int> ans;
    for (auto it : operators)
    {
        int row = it[0], col = it[1];
        if (vis[row][col] == 1)
        {
            ans.push_back(cnt);
            continue;
        }
        else
        {
            vis[row][col] = 1;
            cnt++;

            for (int i = 0; i < 4; i++)
            {
                int adjrow = row + r[i], adjcol = col + c[i];
                if (isvailed(adjrow, adjcol, n, m, vis) == true)
                {
                    // this is how we convert a cells id(row, col) into a single number to take union because dsu only works for single no not pairs.....
                    int nodeno = row * m + col;
                    int adjnodeno = adjrow * m + adjcol;

                    if (ds.findparent(nodeno) != ds.findparent(adjnodeno))
                    {
                        cnt--;
                        ds.unionbyRank(nodeno, adjnodeno);
                    }
                    else
                    {
                        // if they are already belongs to the same component....
                        // do nothing....
                    }
                }
            }
            ans.push_back(cnt);
        }
    }
    return ans;
}

// making a large insland......
// the size of grid is ( n*n  ).....

bool isvailed(int row, int col, int n, vector<vector<int>> &grid)
{
    if (row >= 0 and row < n and col >= 0 and col < n and grid[row][col] == 1)
        return true;
    else
        return false;
}

// in this question since we are concern about the area so we have to do unionbysize if we do uniounbyrank then we cant able to acess correct size because it is still remain 1 so we have to do unioubysize .....
int largestIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    disjointsetUnion ds(n * n);

    vector<int> r = {0, -1, 0, 1};
    vector<int> c = {-1, 0, 1, 0};

    // 1. traversing on each cell of the grid and connecting each 1 cell and calculate their sizes.....

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 0)
                continue;
            else
            {
                // traversing the neighbouring nodes.....
                for (int i = 0; i < 4; i++)
                {
                    int adjrow = row + r[i], adjcol = col + c[i];
                    if (isvailed(adjrow, adjcol, n, grid) == true)
                    {
                        int nodeno = row * n + col, adjnodeno = adjrow * n + adjcol;
                        ds.unionbySize(nodeno, adjnodeno);
                    }
                }
            }
        }
    }

    // 2. take every 0 cell and try to convert it to 1 and then find the maximum area.....

    int maxsize = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 1)
                continue;
            else
            {
                set<int> component;
                // traversing the neighbouring nodes.....
                for (int i = 0; i < 4; i++)
                {
                    int adjrow = row + r[i], adjcol = col + c[i];
                    if (isvailed(adjrow, adjcol, n, grid) == true)
                    {
                        int adjnodeno = adjrow * n + adjcol;
                        int parentadjcomponent = ds.findparent(adjnodeno);
                        component.insert(parentadjcomponent);
                    }
                }

                int size = 0;
                for (auto it : component)
                {
                    size += ds.size[it];
                }
                // 1 for this cells itself area....
                size += 1;
                maxsize = max(maxsize, size);
            }
        }
    }

    // incase if all the grid is entire 1 then the second loop part of the function will not run and the maxsize value is remain 0 so to resolve this issue we have to check once .....
    for (int cellno = 0; cellno < n * n; cellno++)
    {
        int sizecomponent = ds.size[ds.findparent(cellno)];
        maxsize = max(maxsize, sizecomponent);
    }

    return maxsize;
}

// most stone removed from the same row and column......

// in this question they are not given the size of the grid they just provid an array which contains the coordinates of the stones, so we take the last stone coordinate since they are  in sorted order and make a grid of that size ex if last coordinate is (2,3) then our grid size is (2*3)....

int removeStones(vector<vector<int>> &stones)
{
    // this is the total no of stones....
    int n = stones.size();

    int mxrow = 0, mxcol = 0;
    for (auto it : stones)
    {
        mxrow = max(mxrow, it[0]);
        mxcol = max(mxcol, it[1]);
    }

    // what should be the size of dsu it is mxrow+mxcol +1 ---> +1 is for safer side if it is 1 based indexing.....
    disjointsetUnion ds(mxrow + mxcol + 1);

    unordered_map<int, int> stonenodes;

    for (auto it : stones)
    {
        int rownode = it[0];
        int colnode = it[1] + mxrow + 1;
        ds.unionbySize(rownode, colnode);

        // we also have to keep track of that which are the nodes i.e.  which rows and columns has stones because we have to discard all remaining nodes of the dsu , since it has total (mxrow+mxcol+ 1) node and all are not containing stones we have to count only those component which contains stones.....
        stonenodes[rownode] = 1;
        stonenodes[colnode] = 1;
    }

    // now all those nodes (i.e rows and cols which contains stones are marked as 1 in the map now we have to find the no of components from these ).....

    int componentcnt = 0;
    for (auto it : stonenodes)
    {
        int node = it.first;
        int parentnode = ds.findparent(it.first);

        // this is the standard way to find total no of components which we also use in no of proviences question.....
        if (parentnode == node)
            componentcnt++;
    }
    int ans = n - componentcnt;
    return ans;
}

// find if path exist in graph......

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    int n = edges.size();
    disjointsetUnion ds(n + 1);
    for (auto it : edges)
    {
        int u = it[0], v = it[1];
        if (ds.findparent(u) != ds.findparent(v))
            ds.unionbyRank(u, v);
        // else if already belong to the same component then no need to take the union again....
    }

    if (ds.findparent(source) == ds.findparent(destination))
        return true;
    else
        return false;
}
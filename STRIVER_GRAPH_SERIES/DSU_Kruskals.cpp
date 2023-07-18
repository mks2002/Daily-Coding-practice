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

// this is for 1 based indexing which is also work for 0 based indexing if we run upto n not n+1....
class disjointsetUnion
{
    vector<int> rank, parent, size;

public:
    disjointsetUnion(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
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

// we can use union by rank and union by size interchangely....
int32_t main()
{
    __mayuk;
    disjointsetUnion ds(7);
    ds.unionbyRank(1, 2);
    ds.unionbyRank(2, 3);
    ds.unionbyRank(4, 5);
    ds.unionbyRank(6, 7);
    ds.unionbyRank(5, 6);

    if (ds.findparent(3) == ds.findparent(7))
        cout << "belongs to same " << endl;
    else
        cout << "not belong to same " << endl;

    ds.unionbyRank(3, 7);

    if (ds.findparent(3) == ds.findparent(7))
        cout << "belongs to same " << endl;
    else
        cout << "not belong to same " << endl;
    return 0;
}

// kruskals algorithm......
/*
1. it is used to find MST minimum spanning tree of a given graph..
ALgo -->
1. first sort all the edgest according to their weights..
2. initially consider all nodes as individual nodes then traverse the sorted edges and and merge 2 nodes to same component if they belong to the different component and if they belong to the same component then do nothing. ...

4. once we traverse the entire edges vector we got our MST....

Time complexity --> O(e*log(e))
*/

// it is 0 based indexing...
// in this function we have to return the sum of MST edges....

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<pair<int, pair<int, int>>> edgelist;

    // here we store the edges....
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int adjnode = it[0];
            int wt = it[1];
            int node = i;
            edgelist.push_back({wt, {node, adjnode}});
        }
    }

    sort(edgelist.begin(), edgelist.end());

    disjointsetUnion ds(V);
    int mstwtsum = 0;
    for (auto it : edgelist)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if (ds.findparent(u) != ds.findparent(v))
        {
            mstwtsum += wt;

            // we can use any of them .....
            ds.unionbyRank(u, v);
            ds.unionbySize(u, v);
        }
        else
        {
            // if both has same parent , it means they are already connected so, do nothing....
        }
    }

    return mstwtsum;
}

// leetcode 1584 --> minimum cost to connect all the points ....

int minCostConnectPoints(vector<vector<int>> &points)
{
    int n = points.size();
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            v.push_back({dist, {i, j}});
        }
    }

    sort(v.begin(), v.end());
    int cost = 0;
    disjointsetUnion ds(n);

    for (auto it : v)
    {
        int u = it.second.first, v = it.second.second, dist = it.first;
        if (ds.findparent(u) != ds.findparent(v))
        {
            cost += dist;
            // it is undirected graph , so we need to do it for both the sides .....
            ds.unionbyRank(u, v);
            ds.unionbyRank(v, u);
        }
        else
        {
            // if they are already connected then do nothing ....
        }
    }
}
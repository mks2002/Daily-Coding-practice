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

// print the shortest path ......

// this is 1 based indexing graph.....
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[n + 1];
    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    vector<int> dist(n + 1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // in this parent array we try to store the shortest path in terms of parent of each node whose is part of the shortest path....
    vector<int> parent(n + 1);
    for (int i = 0; i < n + 1; i++)
        parent[i] = i;

    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int currdist = pq.top().first, currnode = pq.top().second;
        pq.pop();
        for (auto it : adj[currnode])
        {
            int nextnode = it.first, nextdist = it.second;

            if (dist[nextnode] > currdist + nextdist)
            {
                dist[nextnode] = currdist + nextdist;
                pq.push({dist[nextnode], nextnode});

                // parent of the next node is updated to the currnode .....
                parent[nextnode] = currnode;
            }
        }
    }

    // if we cant able to reach destination then we have to return -1 ....
    if (dist[n] == 1e9)
        return {-1};

    vector<int> path;
    int node = n;
    while (parent[node] != node)
    {
        path.push_back(node);
        node = parent[node];
    }
    // because when node =1 then the loop terminates so we have to insert it seperately....
    path.push_back(1);
    reverse(path.begin(), path.end());
    return path;

    /*
        // we can do the same thing with this method.....
        // here we initially put the last node into the path and then started from its parent node so when the loops end then we dont have to seperately put the last node into the path vector...

        int node = n;
        path.push_back(n);
        while (parent[node] != node)
        {
            path.push_back(parent[node]);
            node = parent[node];
        }
        reverse(path.begin(), path.end());
        return path;

    */
}

// path with minimum efforts...........

int minimumEffortPath(vector<vector<int>> &heights)
{
    int n = heights.size(), m = heights[0].size();

    vector<int> r = {0, -1, 0, 1};
    vector<int> c = {-1, 0, 1, 0};

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    dist[0][0] = 0;

    // initially the distance of the startion point is 0 because the effort is (max difference between 2 cells value.)....
    pq.push({0, {0, 0}});

    while (!pq.empty())
    {
        int currenteffort = pq.top().first;
        int currrow = pq.top().second.first;
        int currcol = pq.top().second.second;
        pq.pop();

        // it means we reached our destination....
        if (currrow == n - 1 and currcol == m - 1)
            return currenteffort;

        for (int i = 0; i < 4; i++)
        {
            int newrow = currrow + r[i], newcol = currcol + c[i];
            if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m)
            {
                int neweffort = max(abs(heights[currrow][currcol] - heights[newrow][newcol]), currenteffort);

                if (neweffort < dist[newrow][newcol])
                {
                    dist[newrow][newcol] = neweffort;
                    pq.push({neweffort, {newrow, newcol}});
                }
            }
        }
    }
    // if the queue is empty and still we are not reach the destination it means we cant reach there so the answer in this case is 0.....
    return 0;
}

// shortest path leetcode..........

/*
statement----------->
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

sol --->

these question is solved only using bfs not dfs because here we required the shortest path for that we have to travel at all neighbor simultaneously not in a depth manner so bfs is required....

we use queue data structure
queue<pair<pair<row, col>, length of path>> q;

whenvever there is something shortest path is mentioned we have to use bfs we cant use dfs in such scenario.....

*/
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    if (grid[0][0] == 1 or grid[n - 1][n - 1] == 1)
    {
        return -1;
    }
    vector<vector<int>> vis(n, vector<int>(n, 0));
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    vis[0][0] = 1;

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int currdis = q.front().second;
        q.pop();
        if (row == n - 1 and col == n - 1)
        {
            return currdis;
        }
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int newrow = row + i;
                int newcol = col + j;
                if (newrow >= 0 and newrow <= n - 1 and newcol >= 0 and newcol <= n - 1 and vis[newrow][newcol] == 0 and grid[newrow][newcol] == 0)
                {
                    q.push({{newrow, newcol}, currdis + 1});
                    vis[newrow][newcol] = 1;
                }
            }
        }
    }
    // if after complete the entire traversl still we dont return any dist it means we never able to reach the destination and hence return -1.....
    return -1;
}

// gfg version of the question here we can move only on 1 not 0 ..........
// also in gfg we can move only in 4 direction not diagonal movment....

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
{
    int n = grid.size();
    int m = grid[0].size();
    if (grid[source.first][source.second] == 0 or grid[destination.first][destination.second] == 0)
        return -1;

    // if we dont use this condition still it is properly working because in the while loop this condtion get handled....
    if (source.first == destination.first and source.second == destination.second)
        return 0;

    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, pair<int, int>>> q;

    vector<int> r = {0, -1, 0, 1};
    vector<int> c = {-1, 0, 1, 0};

    q.push({0, {source.first, source.second}});
    vis[source.first][source.second] = 1;
    while (!q.empty())
    {
        int currdist = q.front().first;
        int currrow = q.front().second.first;
        int currcol = q.front().second.second;
        q.pop();

        if (currrow == destination.first and currcol == destination.second)
            return currdist;

        for (int i = 0; i < 4; i++)
        {
            int newrow = currrow + r[i];
            int newcol = currcol + c[i];
            if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and grid[newrow][newcol] == 1 and vis[newrow][newcol] == 0)
            {
                q.push({currdist + 1, {newrow, newcol}});
                vis[newrow][newcol] = 1;
            }
        }
    }
    // if after the entire queue traversal still we not reach the destination it means we cant reach there so return -1....
    return -1;
}

// instead of using the visited array we can solve both the question using a distance array and djkhastra method.....

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    if (grid[0][0] == 1 or grid[n - 1][n - 1] == 1)
        return -1;

    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    queue<pair<pair<int, int>, int>> q;

    // since we consider it into our path so it will contribute a distance of 1 unit also.....
    dist[0][0] = 1;
    q.push({{0, 0}, dist[0][0]});

    while (!q.empty())
    {
        int currrow = q.front().first.first;
        int currcol = q.front().first.second;
        int currdist = q.front().second;
        q.pop();

        if (currrow == n - 1 and currcol == n - 1)
        {
            // we can use any of these 2 ....

            return currdist;
            return dist[currrow][currcol];
        }

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int newrow = currrow + i;
                int newcol = currcol + j;

                if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < n and grid[newrow][newcol] == 0 and (1 + currdist) < dist[newrow][newcol])
                {
                    dist[newrow][newcol] = 1 + currdist;
                    q.push({{newrow, newcol}, dist[newrow][newcol]});
                }
            }
        }
    }
    // if after the queue is traverse still we not reach the destination it means we cant able to reach there....
    return -1;
}

/*
IMPORTANT point --->
if we initially take dist[0][0]=0 instead of takin =1 then during returning we have to add + 1 in the main answer ......
*/

// gfg version of the problem.....

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
{
}

// cheapest flight with k stops.....

// this is 0 based indexing....
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];

    // it is directed graph so only u-> v we have to create edge ....
    for (auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }
    // this vector will contains the price for each node ...
    vector<int> dist(n, 1e9);
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    dist[src] = 0;
    while (!q.empty())
    {
        int currstops = q.front().first;
        int currnode = q.front().second.first;
        int currprice = q.front().second.second;
        q.pop();
        // if current stopage already exceeds the value of k then we dont have to continue on that path....
        if (currstops > k)
            continue;

        for (auto it : adj[currnode])
        {
            int nextnode = it.first;
            int nextnodeprice = it.second;
            int totalprice = nextnodeprice + currprice;
            // here we use <=k condition because if the currstops is equals to k still we can take one more step to reach at the destination....
            if (totalprice < dist[nextnode] and currstops <= k)
            {
                dist[nextnode] = totalprice;
                q.push({currstops + 1, {nextnode, dist[nextnode]}});
            }
        }
    }

    if (dist[dst] == 1e9)
        return -1;
    else
        return dist[dst];
}

// number of ways to reach at the destination ........

int countPaths(int n, vector<vector<int>> &roads)
{
    vector<pair<int, int>> adj[n];
    for (auto it : roads)
    {
        int u = it[0], v = it[1], wt = it[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    int mod = 1e9 + 7;

    vector<int> dist(n, INT_MAX), ways(n, 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[0] = 0, ways[0] = 1;
    pq.push({dist[0], 0});
    while (!pq.empty())
    {
        int currnode = pq.top().second, currdist = pq.top().first;
        pq.pop();
        for (auto it : adj[currnode])
        {
            int nextnode = it.first, nextdist = it.second;
            if ((currdist + nextdist) < dist[nextnode])
            {
                dist[nextnode] = (currdist + nextdist) % mod;
                pq.push({dist[nextnode], nextnode});
                ways[nextnode] = ways[currnode] % mod;
            }
            else if ((currdist + nextdist) == dist[nextnode])
            {
                // it means we have already reach at this node with the minimum path so add it into our number of ways ...

                ways[nextnode] = (ways[nextnode] + ways[currnode]) % mod;
            }
        }
    }

    int ans = ways[n - 1] % mod;
    return ans;
}
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

// this is the way to find shortest path in directed acyclic graph ......

/*
 here we use this method instead of using any standard algorithm like djkhastra  because in this method our time complexity is O(e+v) but if we use standard algorithm like djkhastra then the t. c. is O(elogv) so by doing this method we can reduce the time complexity.....

algo -->
try to find toposort using bfs or dfs  , dfs is more suitable and after finishing the dfs we have to pick each node from the stack one by one and relax them based on their weights this method is similar to djkhastra...

just we add extra toposort method so that the no of iterations get reduced....

*/
void dfs(int vertex, int total, vector<int> &vis, vector<pair<int, int>> adj[], stack<int> &st)
{
    vis[vertex] = 1;
    for (auto it : adj[vertex])
    {
        int v = it.first;
        if (vis[v] == 0)
        {
            dfs(v, total, vis, adj, st);
        }
    }
    st.push(vertex);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    vector<int> vis(N, 0);
    stack<int> st;
    for (int i = 0; i < N; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, N, vis, adj, st);
        }
    }

    vector<int> dist(N, 1e9);
    dist[0] = 0;

    while (!st.empty())
    {
        int currnode = st.top();
        st.pop();
        for (auto it : adj[currnode])
        {
            int nextnode = it.first;
            int nextwt = it.second;

            if (dist[currnode] + nextwt < dist[nextnode])
            {
                dist[nextnode] = dist[currnode] + nextwt;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == 1e9)
            dist[i] = -1;
    }

    return dist;
}
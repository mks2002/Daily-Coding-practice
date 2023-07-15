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
#define __ms                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int32_t main()
{
    __ms;

    return 0;
}

void bfsgraph(int node, vector<int> adj[], vector<int> &vis, vector<int> &bfs)
{
    queue<int> q;
    vis[node] = 1;
    q.push(node);
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        bfs.push_back(current);
        for (auto it : adj[current])
        {
            if (vis[it] == 0)
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
}

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> bfs;
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            bfsgraph(i, adj, vis, bfs);
        }
    }
    return bfs;
}

void dfsgraph(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfs)
{
    vis[node] = 1;
    dfs.push_back(node);
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            dfsgraph(it, adj, vis, dfs);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> dfs;
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            dfsgraph(i, adj, vis, dfs);
        }
    }
    return dfs;
}

int numProvinces(vector<vector<int>> adj, int V)
{
    vector<int> adjlist[V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i != j and adj[i][j] == 1)
            {
                adjlist[i].push_back(j);
                adjlist[j].push_back(i);
            }
        }
    }
    vector<int> vis(V, 0);

    vector<int> bfs;
    vector<int> dfs;
    int cnt = 0;
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            cnt++;
            // we can use any of them....
            // bfsgraph(i, adjlist, vis, bfs);
            dfsgraph(i, adjlist, vis, dfs);
        }
    }
    return cnt;
}
// this is the last few topics of graph algorithms.....

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

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
            dfs(it, adj, vis, st);
    }
    st.push(node);
}

void dfs2(int node, vector<vector<int>> &adjT, vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adjT[node])
    {
        if (vis[it] == 0)
            dfs2(it, adjT, vis);
    }
}

// this is the entire kosaraju algorithms...........
int kosaraju(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
            dfs(i, adj, vis, st);
    }

    vector<vector<int>> adjT(V);
    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }

    int scnt = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (vis[node] == 0)
        {
            scnt++;
            dfs2(node, adjT, vis);
        }
    }

    return scnt;
}


// Bridges in the graph .......


// this  is the leetcode question critical connection to solve this we need the .....
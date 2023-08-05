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

vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
{
    int n = quiet.size();
    vector<int> adj[n];
    vector<int> ans(n, 0), indegree(n, 0);
    queue<int> q;

    // which nodes are less richer increase their indegree, so that the most richest node has indegree 0 ...
    for (auto it : richer)
    {
        adj[it[0]].push_back(it[1]);
        indegree[it[1]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);

            if (quiet[it] < quiet[node])
                ans[node] = it;
        }
    }
    return ans;
}
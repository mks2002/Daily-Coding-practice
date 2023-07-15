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
#define __ms                         \
   ios_base::sync_with_stdio(false); \
   cin.tie(NULL);

vi bfstrav(int v, vi adj[])
{
   vi bfs;
   vi vis(v + 1, 0);
   queue<int> q;
   rep(i, 1, v + 1)
   {
      if (vis[i] == 0)
      {
         q.push(i);
         vis[i] = 1;
         while (!q.empty())
         {
            int node = q.front();
            q.pop();
            bfs.pb(node);
            for (auto child : adj[node])
            {
               if (vis[child] == 0)
               {
                  q.push(child);
                  vis[child] = 1;
               }
            }
         }
      }
   }
   return bfs;
}

int32_t main()
{
   __ms;

   int m, n;
   cin >> m >> n;

   vi adj[n + 1];
   rep(i, 0, m)
   {
      int u, v;
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
   }

   vi ans = bfstrav(n, adj);

   for (auto it : ans)
   {
      cout << it << " ";
   }
   cout << endl;

   return 0;
}


// using dfs.........
void dfs(vector<int> adj[], vector<int> vis, int size, int idx)
{
   vis[idx] = 1;
   for (auto it : adj[idx])
   {
      if (vis[it] == 0)
      {
         dfs(adj, vis, size, it);
      }
   }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
   int v = isConnected.size();
   vector<int> adj[v + 1];
   for (int i = 0; i < v; i++)
   {
      for (int j = 0; j < v; j++)
      {
         if (isConnected[i][j] == 1 and i != j)
         {
            adj[i + 1].push_back(j + 1);
            adj[j + 1].push_back(i + 1);
         }
      }
   }

   int cnt = 0;
   vector<int> vis(v + 1, 0);
   for (int i = 1; i <= v; i++)
   {
      if (vis[i] == 0)
      {
         cnt++;
         dfs(adj, vis, v + 1, i);
      }
   }
   return cnt;
}

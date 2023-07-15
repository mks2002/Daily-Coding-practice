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

int32_t main()
{
   __ms;

   int m, n;
   cin >> m >> n;

   int adj[n + 1][n + 1] = {0};
   rep(i, 0, n + 1)
   {
      rep(j, 0, n + 1)
      {
         adj[i][j] = 0;
      }
   }

   rep(i, 0, m)
   {
      int u, v;
      cin >> u >> v;
      adj[u][v] = 1;
      adj[v][u] = 1;
   }

   rep(i, 1, n + 1)
   {
      rep(j, 1, n + 1)
      {
         cout << adj[i][j] << " ";
      }
      cout << endl;
   }

   // using adjacency list.....

   vi adj1[n + 1];
   rep(i, 0, m)
   {
      int u, v;
      cin >> u >> v;
      adj1[u].pb(v);
      adj1[v].pb(u);
   }

   rep(i, 0, n + 1)
   {
      cout << i << " -> ";
      for (auto j : adj1[i])
      {
         cout << j << " ";
      }
      cout << endl;
   }

   return 0;
}
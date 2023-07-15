#include <bits/stdc++.h>
using namespace std;
// #define int long long int
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define vpi vector<pair<int, int>>
#define mii map<int, int>
#define pb push_back
#define __mayuk                      \
   ios_base::sync_with_stdio(false); \
   cin.tie(NULL);

void mindist_djkhastra(vector<pair<int, int>> adj[], int n, int src)
{
   vector<int> dist(n + 1, 1e8);
   dist[src] = 0;

   // this is a min heap.....
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   pq.push({0, src});

   while (!pq.empty())
   {
      int currnode = pq.top().second;
      int currdist = pq.top().first;
      pq.pop();
      for (auto it : adj[currnode])
      {
         int nextnode = it.first;
         int nextdist = it.second;
         if (dist[nextnode] > currdist + nextdist)
         {
            dist[nextnode] = currdist + nextdist;
            pq.push({dist[nextnode], nextnode});
         }
      }
   }

   for (int i = 0; i <= n; i++)
   {
      cout << i << " - " << dist[i] << endl;
   }
}

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{

   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

   vector<int> distTo(V, INT_MAX);

   distTo[S] = 0;
   pq.push({0, S});

   while (!pq.empty())
   {
      int node = pq.top().second;
      int dis = pq.top().first;
      pq.pop();
      for (auto it : adj[node])
      {
         int v = it[0];
         int w = it[1];
         if (dis + w < distTo[v])
         {
            distTo[v] = dis + w;

            pq.push({dis + w, v});
         }
      }
   }

   return distTo;
}

int main()
{
   __mayuk;
   int n, m;
   cin >> n >> m;
   vector<pair<int, int>> adj[n + 1];

   for (int i = 0; i < m; i++)
   {
      int u, v, wt;
      cin >> u >> v >> wt;
      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
   }

   // this convertion is we do for the second function to work properly which takes vector<vector<int>> as input...
   vector<vector<int>> adj1[n + 1];
   for (int i = 0; i <= n; i++)
   {
      for (int j = 0; j < adj[i].size(); j++)
      {
         adj1[i][j] = {adj[i][j].first, adj[i][j].second};
      }
   }

   // mindist_djkhastra(adj, n, 1);

   vi ans = dijkstra(n, adj1, 1);
   for (auto it : ans)
   {
      cout << it << " ";
   }
   return 0;
}
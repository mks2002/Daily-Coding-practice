// this code is for 1 based indexing....

#include <bits/stdc++.h>
using namespace std;

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

// if i just have to compute the sum of mst using the prims and the graph is stored in adjcancey list then we can use directly this function and it is for 0 based indexing...

// int primspanningsum(vector<int> adj[], int v)
// {
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    vector<int>vis(v,0);
//    pq.push({0,0});
//    int sum=0;
//    while (!pq.empty())
//    {
//      auto it =pq.top();
//      int currentnode=it.second;
//      int dist=it.first;
//      if(vis[currentnode]==1)continue;
//      vis[currentnode]=1;
//      sum+=dist;
//      for(auto it: adj[currentnode]){
//        int nextnode=
//      }
//    }
   

// }

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
   int parent[n + 1], mstset[n + 1], dist[n + 1];
   for (int i = 0; i <= n; i++)
   {
      parent[i] = -1;
      mstset[i] = 0;
      dist[i] = INT_MAX;
   }

   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   dist[1] = 0;
   parent[1] = -1;
   pq.push({0, 1});
   int cost = 0;

   // since in mst there is n-1 edges so we run this loop for n-1 times....
   for (int i = 0; i < n - 1; i++)
   {
      int currentnode = pq.top().second;
      pq.pop();
      mstset[currentnode] = 1;
      for (auto it : adj[currentnode])
      {
         int nextdist = it.second;
         int nextnode = it.first;
         if (mstset[nextnode] == 0 and dist[nextnode] > nextdist)
         {
            dist[nextnode] = nextdist;
            parent[nextnode] = currentnode;
            pq.push({dist[nextnode], nextnode});
         }
      }
   }

   for (int i = 1; i <= n; i++)
   {
      cout << parent[i] << " - " << i << endl;
      cost += dist[i];
   }
   cout << endl;
   cout << cost << endl;

   return 0;
}
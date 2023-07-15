#include <bits/stdc++.h>
using namespace std;

/*  Function to implement Bellman Ford
 *   edges: vector of vectors which represents the graph
 *   S: source vertex to start traversing graph with
 *   V: number of vertices
 */


vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
   vector<int> dist(V, 1e8);
   dist[S] = 0;
   for (int i = 0; i < V - 1; i++)
   {
      for (auto it : edges)
      {
         int u = it[0];
         int v = it[1];
         int wt = it[2];
         if (dist[u] != 1e8 && dist[u] + wt < dist[v])
         {
            dist[v] = dist[u] + wt;
         }
      }
   }

   // Nth relaxation to check negative cycle
   for (auto it : edges)
   {
      int u = it[0];
      int v = it[1];
      int wt = it[2];
      if (dist[u] != 1e8 && dist[u] + wt < dist[v])
      {
         return {-1};
      }
   }

   return dist;
}

int main()
{  
   //static data..... 
   // int n = 6;
   // vector<vector<int>> edges(7, vector<int>(3));
   // edges[0] = {3, 2, 6};
   // edges[1] = {5, 3, 1};
   // edges[2] = {0, 1, 5};
   // edges[3] = {1, 5, -3};
   // edges[4] = {1, 2, -2};
   // edges[5] = {3, 4, -2};
   // edges[6] = {2, 4, 3};

   int n, m;
   cin >> n >> m;
   vector<vector<int>> edges(n + 1, vector<int>(3));
   for (int i = 0; i < m; i++)
   {
      int u, v, wt;
      cin >> u >> v >> wt;
      vector<int> temp={u,v,wt};
      edges.push_back(temp);
   }

   int S = 0;

   // 6 7
   // 3 2 6
   // 5 3 1
   // 0 1 5
   // 1 5 -3
   // 1 2 -2
   // 3 4 -2
   // 2 4 3

   // we can also convert this in vector<pair<int,int>> but for that we have to modify the function also....

   // int n, m;
   // cin >> n >> m;
   // vector<pair<int, int>> adj[n + 1];
   // for (int i = 0; i < m; i++)
   // {
   //    int u, v, wt;
   //    cin >> u >> v >> wt;
   //    adj[u].push_back({v, wt});
   //    adj[v].push_back({u, wt});
   // }

   vector<int> dist = bellman_ford(n, edges, S);

   for (auto d : dist)
   {
      cout << d << " ";
   }
   cout << endl;

   return 0;
}
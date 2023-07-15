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
#define __mayuk                      \
   ios_base::sync_with_stdio(false); \
   cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;

// bfs traversal of graph...................
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
   int vis[V] = {0};
   vis[0] = 1;
   queue<int> q;
   q.push(0);
   vector<int> bfs;
   while (!q.empty())
   {
      int node = q.front();
      q.pop();
      bfs.push_back(node);
      for (auto it : adj[node])
      {
         if (!vis[it])
         {
            vis[it] = 1;
            q.push(it);
         }
      }
   }
   return bfs;
}


// dfs traversal of graph.......
void dfs(int node, vector<int> adjLs[], int vis[])
{
   vis[node] = 1;
   for (auto it : adjLs[node])
   {
      if (!vis[it])
      {
         dfs(it, adjLs, vis);
      }
   }
}



int numProvinces(vector<vector<int>> adj, int V)
{
   vector<int> adjLs[V];
   for (int i = 0; i < V; i++)
   {
      for (int j = 0; j < V; j++)
      {
         if (adj[i][j] == 1 && i != j)
         {
            adjLs[i].push_back(j);
            adjLs[j].push_back(i);
         }
      }
   }
   int vis[V] = {0};
   int cnt = 0;
   for (int i = 0; i < V; i++)
   {

      if (!vis[i])
      {

         cnt++;
         dfs(i, adjLs, vis);
      }
   }
   return cnt;
}

int32_t main()
{
   __mayuk;

   return 0;
}
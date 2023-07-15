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

// in this bipertite detection algorithm if at any point of graph we find that it is not bipertite then we declare the entire graph is not bipertite but if it is bipertite from all the points then it is bipertite graph.....

// this is the helper function which use bfs to check bipertite...
bool helperbfs(int vertex, int col, int total, vector<int> adj[], vector<int> &color)
{

   color[vertex] = col;
   queue<int> q;
   q.push(vertex);
   while (!q.empty())
   {
      int node = q.front();
      q.pop();
      for (auto it : adj[node])
      {
         if (color[it] == -1)
         {
            color[it] = 1 - color[node];
            q.push(it);
         }
         else if (color[it] != -1 and color[it] == color[node])
         {
            return false;
         }
      }
   }

   return true;
}

// this is the helper function which use dfs to check bipertite....
bool helperdfs(int vertex, int col, int total, vector<int> adj[], vector<int> &color)
{
   color[vertex] = col;
   for (auto it : adj[vertex])
   {
      if (color[it] == -1)
      {
         if (helperdfs(it, 1 - col, total, adj, color) == false)
         {
            return false;
         }
      }
      else if (color[it] != -1 and color[it] == color[vertex])
      {
         return false;
      }
   }
   return true;
}

// graph[i] is a vector<int> which denotes the attached nodes of i....
bool isBipartite(vector<vector<int>> &graph)
{
   int n = graph.size();

   // this is the way of making adjacency list from edges vector....
   vector<int> adj[n];
   for (int i = 0; i < n; i++)
   {
      vector<int> temp = graph[i];
      int size = temp.size();
      for (int j = 0; j < size; j++)
      {
         adj[i].push_back(temp[j]);
      }
   }

   vector<int> color(n, -1);
   for (int i = 0; i < n; i++)
   {
      if (color[i] == -1)
      {
         // we pass the initial color as 1...........

         // either bfs....
         if (helperbfs(i, 1, n, adj, color) == false)
         {
            return false;
         }
         
         // or dfs....
         if (helperdfs(i, 1, n, adj, color) == false)
         {
            return false;
         }
      }
   }
   return true;
}

int32_t main()
{
   __mayuk;

   return 0;
}


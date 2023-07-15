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

// in cycle detection if we found at any point of graph there is a cycle then the entire graph is cyclic.....

// using bfs...................

// here we learn how to detect cycle in undirected graph using bfs and dfs......
// v is the total no of vertex....
// this is for 1 based indexing.....

// here in this function the vertex is the initial source vertex....

bool helper(int vertex, int total, vector<int> &vis, vector<int> adj[])
{
   vis[vertex] = 1;
   queue<pair<int, int>> q;
   q.push({vertex, -1});
   while (!q.empty())
   {
      int current_child = q.front().first;
      int parent = q.front().second;

      q.pop();
      for (auto it : adj[current_child])
      {
         if (vis[it] == 0)
         {
            vis[it] = 1;
            q.push({it, current_child});
         }
         else if (vis[it] != 0 and it != parent)
         {
            return true;
         }
      }
   }
   return false;
}

bool isCycle(int V, vector<int> adj[])
{

   vector<int> vis(V + 1, 0);
   for (int i = 1; i <= V; i++)
   {
      if (vis[i] == 0)
      {
         if (helper(i, V, vis, adj) == true)
         {
            return true;
         }
      }
   }
   return false;
}

// using dfs.............

bool helper(int vertex, int parent, int total, vector<int> &vis, vector<int> adj[])
{
   vis[vertex] = 1;
   for (auto it : adj[vertex])
   {
      if (vis[it] == 0)
      {
         if (helper(it, vertex, total, vis, adj) == true)
         {
            return true;
         }
      }
      else if (vis[it] != 0 and it != parent)
      {
         return true;
      }
   }
   return false;
}

bool isCycle(int v, vector<int> adj[])
{
   vector<int> vis(v + 1, 0);
   for (int i = 1; i <= v; i++)
   {
      if (vis[i] == 0)
      {
         if (helper(i, v, -1, vis, adj) == true)
         {
            return true;
         }
      }
   }
   return false;
}


int32_t main()
{
   __mayuk;

   return 0;
}
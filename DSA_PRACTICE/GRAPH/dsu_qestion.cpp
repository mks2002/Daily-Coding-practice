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
class mayuk_disjoint_set
{
public:
   vector<int> rank, size, parent;

   mayuk_disjoint_set(int n)
   {
      rank.resize(n + 1, 0);
      parent.resize(n + 1);
      size.resize(n + 1);
      for (int i = 0; i <= n; i++)
      {
         parent[i] = i;
         size[i] = 1;
      }
   }

   //  if we dont store this value in the parent[node] then also the answer is same it is for more accuracy ...
   int findparent(int node)
   {
      if (node == parent[node])
         return node;
      return parent[node] = findparent(parent[node]);
   }

   void unionsize(int u, int v)
   {
      int uparent = findparent(u);
      int vparent = findparent(v);
      if (uparent == vparent)
         return;
      if (size[uparent] < size[vparent])
      {
         parent[uparent] = vparent;
         size[vparent] += size[uparent];
      }
      else
      {
         parent[vparent] = uparent;
         size[vparent] += size[uparent];
      }
   }

   void unionrank(int u, int v)
   {
      int uparent = findparent(u);
      int vparent = findparent(v);
      if (uparent == vparent)
         return;
      if (rank[uparent] < rank[vparent])
      {
         parent[uparent] = vparent;
      }
      else if (rank[vparent] < rank[uparent])
      {
         parent[vparent] = uparent;
      }
      else
      {
         parent[uparent] = vparent;
         rank[vparent]++;
      }
   }
};

// no of provinces....

class Solution
{
public:
   // adjacency matrix is given ...
   int numProvinces(vector<vector<int>> adj, int V)
   {
      mayuk_disjoint_set ds(V);
      for (int i = 0; i < V; i++)
      {
         for (int j = 0; j < V; j++)
         {
            if (adj[i][j] == 1)
            {
               ds.unionsize(i, j);
            }
         }
      }

      int cnt = 0;
      for (int i = 0; i < V; i++)
      {
         if (ds.findparent(i) == i)
            cnt++;
      }
      return cnt;
   }
};

int32_t main()
{
   __mayuk;

   return 0;
}
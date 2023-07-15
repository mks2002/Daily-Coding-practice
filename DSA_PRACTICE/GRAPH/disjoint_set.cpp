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

// no of extra edges require to make one join graph....
// it is a zero based indexing graph according to the question ...
class Solution
{
public:
   int Solve(int n, vector<vector<int>> &edge)
   {
      mayuk_disjoint_set ds(n);
      int extraedge = 0;
      for (auto it : edge)
      {
         int u = it[0];
         int v = it[1];
         if (ds.findparent(u) == ds.findparent(v))
         {
            extraedge++;
         }
         else
         {
            ds.unionsize(u, v);
         }
      }
      int componentcount = 0;

      for (int i = 0; i < n; i++)
      {
         if (ds.parent[i] == i)
            componentcount++;
      }
      int ans = componentcount - 1;
      if (extraedge >= ans)
      {
         return ans;
      }
      else
      {
         return -1;
      }
   }
};

// account merge dsu .....
class Solution
{
public:
   vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
   {
      int n = accounts.size();
      mayuk_disjoint_set ds(n);
      unordered_map<string, int> mapemailnode;
      for (int i = 0; i < n; i++)
      {
         int m = accounts[i].size();
         for (int j = 1; j < m; j++)
         {
            string email = accounts[i][j];
            if (mapemailnode.find(email) == mapemailnode.end())
            {
               mapemailnode[email] = i;
            }
            else
            {
               ds.unionsize(i, mapemailnode[email]);
            }
         }
      }
      vector<string> detail[n];
      for (auto it : mapemailnode)
      {
         string email = it.first;
         int node = ds.findparent(it.second);
         detail[node].push_back(email);
      }
      vector<vector<string>> ans;

      for (int i = 0; i < n; i++)
      {
         if (detail[i].size() == 0)
            continue;
         sort(detail[i].begin(), detail[i].end());
         vector<string> temp;
         temp.push_back(accounts[i][0]);
         for (auto it : detail[i])
         {
            temp.push_back(it);
         }
         ans.push_back(temp);
      }

      return ans;
   }
};

int32_t main()
{
   __mayuk;

   return 0;
}
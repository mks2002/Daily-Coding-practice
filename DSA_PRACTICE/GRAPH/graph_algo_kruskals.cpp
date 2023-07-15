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

struct node
{
   int u;
   int v;
   int wt;
   node(int first, int second, int third)
   {
      u = first;
      v = second;
      wt = third;
   }
};

bool cmp(node a, node b)
{
   return a.wt < b.wt;
}

int findparent(int u, vector<int> &parent)
{
   if (u == parent[u])
      return u;
   return findparent(parent[u], parent);
}

void findunion(int u, int v, vector<int> &parent, vector<int> &rank)
{
   u = findparent(u, parent);
   v = findparent(v, parent);
   if (rank[u] < rank[v])
   {
      parent[u] = v;
   }
   else if (rank[v] < rank[u])
   {
      parent[v] = u;
   }
   else
   {
      parent[u] = v;
      rank[u]++;
   }
}

int main()
{
   __mayuk;

   int n, m;
   cin >> n >> m;
   vector<node> edges;
   for (int i = 0; i < m; i++)
   {
      int u, v, wt;
      cin >> u >> v >> wt;
      edges.pb(node(u, v, wt));
   }

   vector<int> parent(n + 1);
   for (int i = 0; i <= n; i++)
   {
      parent[i] = i;
   }
   vector<int> rank(n + 1, 0);
   int cost = 0;
   vector<pair<int, int>> mst;

   sort(edges.begin(), edges.end(), cmp);
   for (auto it : edges)
   {
      if (findparent(it.u, parent) != findparent(it.v, parent))
      {
         cost += it.wt;
         mst.push_back({it.u, it.v});
         findunion(it.u, it.v, parent, rank);
      }
   }
   cout << "this is the mst " << endl;
   for (auto it : mst)
   {
      cout << it.first << " - " << it.second << endl;
   }
   cout << endl;

   cout << "the cost of mst is : " << cost << endl;
   return 0;
}

// this are input for this graph...
// 6 9
// 5 4 9
// 5 1 4
// 4 1 1
// 4 3 5
// 4 2 3
// 1 2 2
// 3 2 3
// 3 6 8
// 2 6 7
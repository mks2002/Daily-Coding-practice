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

// cycle detection in directed graph using dfs....

bool helper(int vertex, int total, int vis[], int pathvis[], vector<int> adj[])
{
   vis[vertex] = 1;
   pathvis[vertex] = 1;

   for (auto it : adj[vertex])
   {
      if (vis[it] == 0)
      {
         if (helper(it, total, vis, pathvis, adj) == true)
            return true;
      }
      else if (vis[it] == 1 and pathvis[it] == 1)
      {
         return true;
      }
   }

   pathvis[vertex] = 0;
   return false;
}

// suppose this is 0 based indexing if it is 1 based indexing then we just increase the size of visited array and runs the loop from the 1 to <=v ....
bool isCyclic(int V, vector<int> adj[])
{
   int vis[V] = {0};
   int pathvis[V] = {0};
   for (int i = 0; i < V; i++)
   {
      if (vis[i] == 0)
      {
         // if at any point we fond cycle then it means entire grapy is cyclick so need to further check....
         if (helper(i, V, vis, pathvis, adj) == true)
         {
            return true;
         }
      }
   }
   return false;
}

// topological sort is only vailed for directed acyclick graph....

// Topological sort using dfs....................

// whenever we return from the bfs we have to store the vertex in the stack and then remove one by one from the stack and store it to answer....

// time complexity O(v+e)....

void dfs(int vertex, int total, int vis[], stack<int> &st, vector<int> adj[])
{
   vis[vertex] = 1;
   for (auto it : adj[vertex])
   {
      if (vis[it] == 0)
      {
         dfs(it, total, vis, st, adj);
      }
   }
   st.push(vertex);
}

vector<int> topoSort(int V, vector<int> adj[])
{
   int vis[V] = {0};
   stack<int> st;
   for (int i = 0; i < V; i++)
   {
      if (vis[i] == 0)
      {
         dfs(i, V, vis, st, adj);
      }
   }
   vector<int> ans;
   while (!st.empty())
   {
      ans.push_back(st.top());
      st.pop();
   }
   return ans;
}

// topological sort using bfs  Kahn's algorithm..................
/*
1.. first count the indegree of each node..
2.. if the indegree of any node initially is 0 ( there is atleast 1 such node is exist) put it into the queue...
3.. now iterate on the queue pop each element from the queue store it into the answer and for each item which get out from the
    queue reduce the indegree of its neighboring node by one  during this if the indegree of any node become 0 then push it into the queue...
*/

// time complexity O(v+e)....
vector<int> topoSort(int V, vector<int> adj[])
{
   int indegree[V] = {0};
   for (int i = 0; i < V; i++)
   {
      for (auto it : adj[i])
      {
         indegree[it]++;
      }
   }

   queue<int> q;
   for (int i = 0; i < V; i++)
   {
      if (indegree[i] == 0)
      {
         q.push(i);
      }
   }

   vector<int> ans;
   while (!q.empty())
   {
      int node = q.front();
      q.pop();
      ans.push_back(node);

      for (auto it : adj[node])
      {
         indegree[it]--;
         if (indegree[it] == 0)
         {
            q.push(it);
         }
      }
   }
   return ans;
}

// cycle detection in directed graph using bfs............

// in this method if we dont able to create a topo sort which has exactly n elements then it means there exist a cycle otherwise a topo sort is surely exist , so if toposort exist then no cycle  otherwise cycle is there.....

#define rep(i, a, b) for (int i = a; i < b; i++)

bool isCyclic(int V, vector<int> adj[])
{
   int indegree[V] = {0};
   rep(i, 0, V)
   {
      for (auto it : adj[i])
      {
         indegree[it]++;
      }
   }
   queue<int> q;
   rep(i, 0, V)
   {
      if (indegree[i] == 0)
      {
         q.push(i);
      }
   }
   vector<int> topoSort;
   while (!q.empty())
   {
      int node = q.front();
      q.pop();
      topoSort.push_back(node);
      for (auto it : adj[node])
      {
         indegree[it]--;
         if (indegree[it] == 0)
         {
            q.push(it);
         }
      }
   }

   //   if the size of toposort is equal to total no of nodes then it means there is no cycle exist...
   if (topoSort.size() == V)
   {
      return false;
   }
   else
   {
      return true;
   }
}

// similar question gfg prerequisite tasks........

bool isPossible(int N, vector<pair<int, int>> &prerequisites)
{
   vector<int> adj[N];
   for (auto it : prerequisites)
   {
      adj[it.first].push_back(it.second);
   }

   int indegree[N] = {0};
   for (int i = 0; i < N; i++)
   {
      for (auto it : adj[i])
      {
         indegree[it]++;
      }
   }
   queue<int> q;
   for (int i = 0; i < N; i++)
   {
      if (indegree[i] == 0)
      {
         q.push(i);
      }
   }
   vector<int> topoSort;
   while (!q.empty())
   {
      int node = q.front();
      q.pop();
      topoSort.push_back(node);
      for (auto it : adj[node])
      {
         indegree[it]--;
         if (indegree[it] == 0)
         {
            q.push(it);
         }
      }
   }
   if (topoSort.size() == N)
   {
      return true;
   }
   return false;
}

vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites)
{
   vector<int> adj[n];
   for (auto it : prerequisites)
   {
      adj[it[0]].push_back(it[1]);
   }

   int indegree[n];
   for (int i = 0; i < n; i++)
   {
      for (auto it : adj[i])
      {
         indegree[it]++;
      }
   }
   queue<int> q;
   for (int i = 0; i < n; i++)
   {
      if (indegree[i] == 0)
      {
         q.push(i);
      }
   }
   vector<int> ans;
   while (!q.empty())
   {
      int node = q.front();
      q.pop();
      ans.push_back(node);
      for (auto it : adj[node])
      {
         indegree[it]--;
         if (indegree[it] == 0)
         {
            q.push(it);
         }
      }
   }

   if (ans.size() == n)
   {
      return ans;
   }
   else
   {
      //  returning an empty array....
      return {};
   }
}

int32_t main()
{
   __mayuk;

   return 0;
}

// Course scheduling leetcode...........
bool helper(int vertex, int total, vector<int> &vis, vector<int> &pathvis, vector<int> adj[])
{
   vis[vertex] = 1;
   pathvis[vertex] = 1;

   for (auto it : adj[vertex])
   {
      if (vis[it] == 0)
      {
         if (helper(it, total, vis, pathvis, adj) == true)
            return true;
      }
      else if (vis[it] == 1 and pathvis[it] == 1)
      {
         return true;
      }
   }
   pathvis[vertex] = 0;
   return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
   int n = numCourses;
   vector<int> adj[n];
   for (auto it : prerequisites)
   {
      adj[it[1]].push_back(it[0]);
   }

   vector<int> vis(n, 0);
   vector<int> pathvis(n, 0);

   for (int i = 0; i < n; i++)
   {
      if (vis[i] == 0)
      {
         if (helper(i, n, vis, pathvis, adj) == true)
         {
            return false;
         }
      }
   }
   return true;
}

// same question using bfs.....

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
   vector<int> adj[numCourses];
   for (auto it : prerequisites)
   {
      adj[it[1]].push_back(it[0]);
   }
   // here we create our adjacency list....

   vector<int> indegree(numCourses, 0);
   for (int i = 0; i < numCourses; i++)
   {
      cout << indegree[i] << " ";
   }
   rep(i, 0, numCourses)
   {
      for (auto it : adj[i])
      {
         indegree[it]++;
      }
   }
   queue<int> q;
   rep(i, 0, numCourses)
   {
      if (indegree[i] == 0)
      {
         q.push(i);
      }
   }
   vector<int> topoSort;
   while (!q.empty())
   {
      int node = q.front();
      q.pop();
      topoSort.push_back(node);
      for (auto it : adj[node])
      {
         indegree[it]--;
         if (indegree[it] == 0)
         {
            q.push(it);
         }
      }
   }
   // it means it is DAG so there is no cyclick dependenecy so we can assign courses....
   if (topoSort.size() == numCourses)
   {
      return true;
   }
   else
   {
      return false;
   }
}

// course schedule 2 leetcode....

// this is using bfs....
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
   int n = numCourses;

   vector<int> adj[n];
   for (auto it : prerequisites)
   {
      adj[it[0]].push_back(it[1]);
   }

   vector<int> indegree(n, 0);
   for (int i = 0; i < n; i++)
   {
      for (auto it : adj[i])
      {
         indegree[it]++;
      }
   }

   queue<int> q;
   for (int i = 0; i < n; i++)
   {
      if (indegree[i] == 0)
      {
         q.push(i);
      }
   }
   //   this ans vector contains the topoSort....
   vector<int> ans;
   while (!q.empty())
   {
      int node = q.front();
      q.pop();
      ans.push_back(node);
      for (auto it : adj[node])
      {
         indegree[it]--;
         if (indegree[it] == 0)
         {
            q.push(it);
         }
      }
   }

   if (ans.size() == n)
   {
      return ans;
   }
   else
   {
      //  returning an empty array....
      return {};
   }
}

// if we have to solve this using dfs then we have to use the cycle detection method to check if at any point we found cycle during dfs we instantly return true without continuing the dfs....

bool helperDfs(int vertex, int total, vector<int> &vis, vector<int> &pathvis, stack<int> &st, vector<int> adj[])
{
   vis[vertex] = 1;
   pathvis[vertex] = 1;
   for (auto it : adj[vertex])
   {
      if (vis[it] == 0)
      {
         if (helperDfs(it, total, vis, pathvis, st, adj) == true)
         {
            return true;
         }
      }
      else if (vis[it] == 1 and pathvis[it] == 1)
      {
         return true;
      }
   }
   pathvis[vertex] = 0;
   st.push(vertex);
   return false;
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
   int n = numCourses;
   vector<int> adj[n];
   for (auto it : prerequisites)
   {
      adj[it[0]].push_back(it[1]);
   }
   vector<int> vis(n, 0);
   vector<int> pathvis(n, 0);
   stack<int> st;

   for (int i = 0; i < n; i++)
   {
      if (vis[i] == 0)
      {
         if (helperDfs(i, n, vis, pathvis, st, adj) == true)
         {
            return {};
         }
      }
   }

   // this ans vector contains the topoSort....
   vector<int> ans;

   while (!st.empty())
   {
      ans.push_back(st.top());
      st.pop();
   }

   if (ans.size() == n)
   {
      return ans;
   }
   else
   {
      //  returning an empty array....
      return {};
   }
}

/*

this simple solution gives wrong answer for the input --------->

numCourses = 2
prerequisites = [[0,1],[1,0]]

Output = [0,1]
Expected []

because here if we found the cycle still we continue the dfs to find the topoSort for different nodes, but it is wrong once we found that there exist a cycle then it means we cant able to take all the courses so at any point when we found cycle we have to stop the furhere dfs call return an empty array....

void dfs(int vertex, int total, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
   vis[vertex] = 1;
   for (auto it : adj[vertex])
   {
      if (vis[it] == 0)
      {
         dfs(it, total, vis, st, adj);
      }
   }
   st.push(vertex);
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
   int n = numCourses;
   vector<int> adj[n];
   for (auto it : prerequisites)
   {
      adj[it[1]].push_back(it[0]);
   }
   vector<int> vis(n, 0);
   vector<int> pathvis(n, 0);
   stack<int> st;

   for (int i = 0; i < n; i++)
   {
      if (vis[i] == 0)
      {
         dfs(i, n, vis, st, adj);
      }
   }

   // this ans vector contains the topoSort....
   vector<int> ans;

   while (!st.empty())
   {
      ans.push_back(st.top());
      st.pop();
   }

   if (ans.size() == n)
   {
      return ans;
   }
   else
   {
      //  returning an empty array....
      return {};
   }
}
*/

// find evantual safe states....

// this is the gfg version...
bool helperDfs(int vertex, int total, vector<int> &vis, vector<int> &pathvis, vector<int> &checksafe, vector<int> adj[])
{
   vis[vertex] = 1;
   pathvis[vertex] = 1;
   for (auto it : adj[vertex])
   {
      if (vis[it] == 0)
      {
         if (helperDfs(it, total, vis, pathvis, checksafe, adj) == true)
         {
            return true;
         }
      }
      else if (vis[it] == 1 and pathvis[it] == 1)
      {
         return true;
      }
   }

   // when we return from the loop it means that this node is not part of cylce so we make pathvis = false and mark that node as safe node...
   pathvis[vertex] = 0;
   checksafe[vertex] = 1;
   return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
   vector<int> vis(V, 0);
   vector<int> pathvis(V, 0);
   vector<int> checksafe(V, 0);

   for (int i = 0; i < V; i++)
   {
      if (vis[i] == 0)
      {
         // whethere cycle is found or not we have to check for each and every node ....
         helperDfs(i, V, vis, pathvis, checksafe, adj);
      }
   }

   vector<int> safenodes;
   for (int i = 0; i < V; i++)
   {
      if (checksafe[i] == 1)
      {
         safenodes.push_back(i);
      }
   }
   return safenodes;
}

// find evantual safe state leetcode....

bool helperDfs(int vertex, int total, vector<int> &vis, vector<int> &pathvis, vector<int> &checksafe, vector<int> adj[])
{
   vis[vertex] = 1;
   pathvis[vertex] = 1;
   for (auto it : adj[vertex])
   {
      if (vis[it] == 0)
      {
         if (helperDfs(it, total, vis, pathvis, checksafe, adj) == true)
         {
            return true;
         }
      }
      else if (vis[it] == 1 and pathvis[it] == 1)
      {
         return true;
      }
   }

   // when we return from the loop it means that this node is not part of cylce so we make pathvis = false and mark that node as safe node...
   pathvis[vertex] = 0;
   checksafe[vertex] = 1;
   return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
   int n = graph.size();

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

   vector<int> vis(n, 0);
   vector<int> pathvis(n, 0);
   vector<int> checksafe(n, 0);

   for (int i = 0; i < n; i++)
   {
      if (vis[i] == 0)
      {
         // whethere cycle is found or not we have to check for each and every node ....
         helperDfs(i, n, vis, pathvis, checksafe, adj);
      }
   }

   vector<int> safenodes;
   for (int i = 0; i < n; i++)
   {
      if (checksafe[i] == 1)
      {
         safenodes.push_back(i);
      }
   }
   return safenodes;
}
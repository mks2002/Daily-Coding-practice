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

// q..1 --> print the djkhastra shortest path......................

// Create an adjacency list of pairs of the form node1 -> {node2, edge weight}
// where the edge weight is the weight of the edge from node1 to node2.
// Create a priority queue for storing the nodes along with distances
// in the form of a pair { dist, node }.

// Create a dist array for storing the updated distances and a parent array
// for storing the nodes from where the current nodes represented by indices of
// the parent array came from.
// Push the source node to the queue.
// Topmost element of the priority queue is with minimum distance value.
// Iterate through the adjacent nodes of the current popped node.

// Check if the previously stored distance value is
// greater than the current computed value or not,
// if yes then update the distance value.

// Update the parent of the adjNode to the recent
// node where it came from.
// If distance to a node could not be found, return an array containing -1.
// Store the final path in the ‘path’ array.
// Iterate backwards from destination to source through the parent array.
// Since the path stored is in a reverse order, we reverse the array
// to get the final answer and then return the array.

// this is a 1 based indexing problem here source is 1 and the destination is n ....

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{

   vector<pair<int, int>> adj[n + 1];

   // this is the way to change the edges vector into adjacency list.....
   for (auto it : edges)
   {
      adj[it[0]].push_back({it[1], it[2]});
      adj[it[1]].push_back({it[0], it[2]});
   }

   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

   vector<int> dist(n + 1, 1e9), parent(n + 1);
   for (int i = 1; i <= n; i++)
      parent[i] = i;

   dist[1] = 0;

   pq.push({0, 1});
   while (!pq.empty())
   {

      auto it = pq.top();
      pq.pop();
      int node = it.second;
      int dis = it.first;

      for (auto it : adj[node])
      {
         int adjNode = it.first;
         int edW = it.second;

         if (dis + edW < dist[adjNode])
         {
            dist[adjNode] = dis + edW;
            pq.push({dis + edW, adjNode});

            parent[adjNode] = node;
         }
      }
   }

   if (dist[n] == 1e9)
      return {-1};

   vector<int> path;
   int node = n;

   while (parent[node] != node)
   {
      path.push_back(node);
      node = parent[node];
   }
   path.push_back(1);

   reverse(path.begin(), path.end());
   return path;
}

// q ..2 ----->
// Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1.....
// we can move only in 4 directions......

// If the path is not possible between source cell and destination cell, then return -1.

// Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right.

//_________________________________________________________________________________________

// Create a queue for storing cells with their distances from source
// in the form {dist,{cell coordinates pair}}.
// Create a distance matrix with initially all the cells marked as
// unvisited and the source cell as 0.

// The following delta rows and delts columns array are created such that
// each index represents each adjacent node that a cell may have
// in a direction.

// Iterate through the maze by popping the elements out of the queue
// and pushing whenever a shorter distance to a cell is found.

// Through this loop, we check the 4 direction adjacent nodes
// for a shorter path to destination.

// Checking the validity of the cell and updating if dist is shorter.

// Return the distance until the point when
// we encounter the destination cell.

// If no path is found from source to destination....

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
{

   if (source.first == destination.first && source.second == destination.second)
      return 0;
   // {dist,{cell coordinates pair}}.
   // here we dont need to use priority_queue because the distance between nodes is 1 so a simple queue will also work.....
   queue<pair<int, pair<int, int>>> q;
   int n = grid.size();
   int m = grid[0].size();

   vector<vector<int>> dist(n, vector<int>(m, 1e9));
   dist[source.first][source.second] = 0;
   q.push({0, {source.first, source.second}});

   int dr[] = {-1, 0, 1, 0};
   int dc[] = {0, 1, 0, -1};

   while (!q.empty())
   {
      auto it = q.front();
      q.pop();
      int dis = it.first;
      int r = it.second.first;
      int c = it.second.second;

      for (int i = 0; i < 4; i++)
      {
         int newr = r + dr[i];
         int newc = c + dc[i];

         if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc])
         {
            dist[newr][newc] = 1 + dis;

            if (newr == destination.first && newc == destination.second)
               return dis + 1;
            q.push({1 + dis, {newr, newc}});
         }
      }
   }
   return -1;
}

//________________________________________________________________________________________

// path with minimum efforts .....

// Create a priority queue containing pairs of cells
// and their respective distance from the source cell in the
// form {diff, {row of cell, col of cell}}.

// Create a distance matrix with initially all the cells marked as
// unvisited and the dist for source cell (0,0) as 0.

// The following delta rows and delts columns array are created such that
// each index represents each adjacent node that a cell may have
// in a direction.

// Iterate through the matrix by popping the elements out of the queue
// and pushing whenever a shorter distance to a cell is found.

// Check if we have reached the destination cell,
// return the current value of difference (which will be min).
// row - 1, col
// row, col + 1
// row - 1, col
// row, col - 1

// Checking validity of the cell.

// Effort can be calculated as the max value of differences
// between the heights of the node and its adjacent nodes.

// If the calculated effort is less than the prev value
// we update as we need the min effort.

int MinimumEffort(vector<vector<int>> &heights)
{
   // {diff, {row of cell, col of cell}}.

   priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

   int n = heights.size();
   int m = heights[0].size();

   vector<vector<int>> dist(n, vector<int>(m, 1e9));
   dist[0][0] = 0;
   pq.push({0, {0, 0}});

   int dr[] = {-1, 0, 1, 0};
   int dc[] = {0, 1, 0, -1};
   while (!pq.empty())
   {
      auto it = pq.top();
      pq.pop(); 
      int diff = it.first;
      int row = it.second.first;
      int col = it.second.second;

      if (row == n - 1 && col == m - 1)
      {
         return diff;
      }

      for (int i = 0; i < 4; i++)
      {

         int newr = row + dr[i];
         int newc = col + dc[i];

         if (newr >= 0 && newc >= 0 && newr < n && newc < m)
         {
            // we just have to check the path difference ....
            int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);

            if (newEffort < dist[newr][newc])
            {
               dist[newr][newc] = newEffort;
               pq.push({newEffort, {newr, newc}});
            }
         }
      }
   }
   return 0;
   // if unreachable
}

//_____________________________________________________________________________________________________________

// Create the adjacency list to depict airports and flights in
// the form of a graph.

// Create a queue which stores the node and their distances from the
// source in the form of {stops, {node, dist}} with ‘stops’ indicating
// the no. of nodes between src and current node.
// Distance array to store the updated distances from the source.

// Iterate through the graph using a queue like in Dijkstra with
// popping out the element with min stops first.

// We stop the process as soon as the limit for the stops reaches.

// We only update the queue if the new calculated dist is
// less than the prev and the stops are also within limits.

// If the destination node is unreachable return ‘-1’
// else return the calculated dist from src to dst.

int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
   vector<pair<int, int>> adj[n];
   for (auto it : flights)
   {
      adj[it[0]].push_back({it[1], it[2]});
   }
   // {stops, {node, dist}}
   queue<pair<int, pair<int, int>>> q;

   q.push({0, {src, 0}});

   vector<int> dist(n, 1e9);
   dist[src] = 0;

   while (!q.empty())
   {
      auto it = q.front();
      q.pop();
      int stops = it.first;
      int node = it.second.first;
      int cost = it.second.second;

      if (stops > K)
         continue;
      for (auto iter : adj[node])
      {
         int adjNode = iter.first;
         int edW = iter.second;

         if (cost + edW < dist[adjNode] && stops <= K)
         {
            dist[adjNode] = cost + edW;
            q.push({stops + 1, {adjNode, cost + edW}});
         }
      }
   }
   if (dist[dst] == 1e9)
      return -1;
   return dist[dst];
}

//________________________________________________________________________________________________________

// Create a queue for storing the numbers as a result of multiplication
// of the numbers in the array and the start number.

// Create a dist array to store the no. of multiplications to reach
// a particular number from the start number.
// Multiply the start no. with each of numbers in the arr
// until we get the end no.

// If the no. of multiplications are less than before
// in order to reach a number, we update the dist array.
// Whenever we reach the end number
// return the calculated steps

int minimumMultiplications(vector<int> &arr, int start, int end)
{
   queue<pair<int, int>> q;
   q.push({start, 0});

   vector<int> dist(100000, 1e9);
   dist[start] = 0;
   int mod = 100000;

   while (!q.empty())
   {
      int node = q.front().first;
      int steps = q.front().second;
      q.pop();

      for (auto it : arr)
      {
         int num = (it * node) % mod;

         if (steps + 1 < dist[num])
         {
            dist[num] = steps + 1;

            if (num == end)
               return steps + 1;
            q.push({num, steps + 1});
         }
      }
   }
   // If the end no. is unattainable.
   return -1;
}

//___________________________________________________________________________
// no of ways to arrive at destination......
// source is 0 and intersection is n-1 ......
// road[i]={ui, vi, time }....

// Creating an adjacency list for the given graph.

// Defining a priority queue (min heap).

// Initializing the dist array and the ways array
// along with their first indices.

// Iterate through the graph with the help of priority queue
// just as we do in Dijkstra's Algorithm.

// This ‘if’ condition signifies that this is the first
// time we’re coming with this short distance, so we push
// in PQ and keep the no. of ways the same.

// If we again encounter a node with the same short distance
// as before, we simply increment the no. of ways.

// Finally, we return the no. of ways to reach
// (n-1)th node modulo 10^9+7.

int countPaths(int n, vector<vector<int>> &roads)
{

   vector<pair<int, int>> adj[n];
   for (auto it : roads)
   {
      adj[it[0]].push_back({it[1], it[2]});
      adj[it[1]].push_back({it[0], it[2]});
   }

   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

   vector<int> dist(n, 1e9), ways(n, 0);
   dist[0] = 0;
   ways[0] = 1;
   pq.push({0, 0});

   // Define modulo value
   int mod = (int)(1e9 + 7);

   while (!pq.empty())
   {
      int dis = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      for (auto it : adj[node])
      {
         int adjNode = it.first;
         int edW = it.second;

         if (dis + edW < dist[adjNode])
         {
            dist[adjNode] = dis + edW;
            pq.push({dis + edW, adjNode});
            ways[adjNode] = ways[node];
         }

         else if (dis + edW == dist[adjNode])
         {
            ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
         }
      }
   }
   return ways[n - 1] % mod;
}

int32_t main()
{
   __mayuk;

   return 0;
}
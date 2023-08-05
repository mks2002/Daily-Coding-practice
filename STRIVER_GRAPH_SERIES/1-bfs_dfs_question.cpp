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

// the bfs and dfs traversel code.....

// suppose this is 0 based indexing graph....
void bfsgraph(int node, vector<int> adj[], vector<int> &vis, vector<int> &bfs)
{
   queue<int> q;
   vis[node] = 1;
   q.push(node);

   while (!q.empty())
   {
      int current = q.front();
      q.pop();
      bfs.push_back(current);
      for (auto it : adj[current])
      {
         if (vis[it] == 0)
         {
            vis[it] = 1;
            q.push(it);
         }
      }
   }
}

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
   vector<int> vis(V, 0);
   vector<int> bfs;
   for (int i = 0; i < V; i++)
   {
      if (vis[i] == 0)
      {
         bfsgraph(i, adj, vis, bfs);
      }
   }
   return bfs;
}

void dfsgraph(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfs)
{
   vis[node] = 1;
   dfs.push_back(node);
   for (auto it : adj[node])
   {
      if (vis[it] == 0)
      {
         dfsgraph(it, adj, vis, dfs);
      }
   }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
   vector<int> vis(V, 0);
   vector<int> dfs;
   for (int i = 0; i < V; i++)
   {
      if (vis[i] == 0)
      {
         dfsgraph(i, adj, vis, dfs);
      }
   }
   return dfs;
}

int32_t main()
{
   __mayuk;

   return 0;
}

// no of proviences.............. leetcode
// this is 1 based indexing...

// [[1,1,0],[1,1,0],[0,0,1]]  --> input
// 2 ---> output...

// helper function which using bfs....
void bfsgraph(int node, vector<int> adj[], vector<int> &vis, vector<int> &bfs)
{
   queue<int> q;
   vis[node] = 1;
   q.push(node);
   while (!q.empty())
   {
      int current = q.front();
      q.pop();
      bfs.push_back(current);
      for (auto it : adj[current])
      {
         if (vis[it] == 0)
         {
            vis[it] = 1;
            q.push(it);
         }
      }
   }
}

// helper function which using dfs....
void dfsgraph(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfs)
{
   vis[node] = 1;
   dfs.push_back(node);
   for (auto it : adj[node])
   {
      if (vis[it] == 0)
      {
         dfsgraph(it, adj, vis, dfs);
      }
   }
}

// this is 1 based indexing......
// here we just need the count so if we dont pass the vector to store the traversal then also it works properly...
int findCircleNum(vector<vector<int>> &isConnected)
{
   int v = isConnected.size();

   // change the adjacency matrix into an adjacency list...
   vector<int> adj[v + 1];

   for (int i = 0; i < v; i++)
   {
      for (int j = 0; j < v; j++)
      {
         if (isConnected[i][j] == 1 and i != j)
         {
            adj[i + 1].push_back(j + 1);
            adj[j + 1].push_back(i + 1);
         }
      }
   }

   int cnt = 0;
   vector<int> vis(v + 1, 0);

   // this vector is for storing the bfs or dfs traversal ....
   vector<int> temp;
   for (int i = 1; i <= v; i++)
   {
      if (vis[i] == 0)
      {
         cnt++;
         // bfsgraph(i, adj, vis, temp);
         dfsgraph(i, adj, vis, temp);
      }
   }
   return cnt;
}

// whether the given graph is 1 based or 0 based indexing if our main algorithm is correct it is give correct answer irrespective of whether we use 1 based indexing or 0 based indexing to solve this question....

// this is 0 based indexing......
int findCircleNum(vector<vector<int>> &isConnected)
{
   int v = isConnected.size();

   // change the adjacency matrix into an adjacency list...
   vector<int> adj[v];
   for (int i = 0; i < v; i++)
   {
      for (int j = 0; j < v; j++)
      {
         if (isConnected[i][j] == 1 and i != j)
         {
            adj[i].push_back(j);
            adj[j].push_back(i);
         }
      }
   }

   int cnt = 0;
   vector<int> vis(v, 0);

   // this vector is for storing the bfs or dfs traversal ....
   vector<int> temp;
   for (int i = 0; i < v; i++)
   {
      if (vis[i] == 0)
      {
         cnt++;
         // bfsgraph(i, adj, vis, temp);
         dfsgraph(i, adj, vis, temp);
      }
   }
   return cnt;
}

// Q.2  ----> no. of islands..........
// here we have to traverse only on the lands which are denoted by '1'...

// in leet code only horizontal and vertical movment is allowed no diagonal movment....
void bfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int row, int col)
{
   int n = grid.size();
   int m = grid[0].size();

   vector<int> r = {0, -1, 0, 1};
   vector<int> c = {-1, 0, 1, 0};

   queue<pair<int, int>> q;
   vis[row][col] = 1;

   q.push({row, col});
   while (!q.empty())
   {
      int currrow = q.front().first;
      int currcol = q.front().second;
      q.pop();

      for (int j = 0; j < 4; j++)
      {
         int neworw = currrow + r[j];
         int newcol = currcol + c[j];
         if (neworw >= 0 and neworw < n and newcol >= 0 and newcol < m and grid[neworw][newcol] == '1' and vis[neworw][newcol] == 0)
         {
            vis[neworw][newcol] = 1;
            q.push({neworw, newcol});
         }
      }
   }
}

// same above leetcode question using dfs.......
void dfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int row, int col)
{
   int n = grid.size();
   int m = grid[0].size();

   vis[row][col] = 1;

   vector<int> r = {0, -1, 0, 1};
   vector<int> c = {-1, 0, 1, 0};

   for (int j = 0; j < 4; j++)
   {
      int neworw = row + r[j];
      int newcol = col + c[j];
      if (neworw >= 0 and neworw < n and newcol >= 0 and newcol < m and grid[neworw][newcol] == '1' and vis[neworw][newcol] == 0)
      {
         dfs(grid, vis, neworw, newcol);
      }
   }
}

int numIslands(vector<vector<char>> &grid)
{
   int n = grid.size();
   int m = grid[0].size();
   vector<vector<int>> vis(n, vector<int>(m, 0));
   int cnt = 0;
   for (int row = 0; row < n; row++)
   {
      for (int col = 0; col < m; col++)
      {
         if (vis[row][col] == 0 and grid[row][col] == '1')
         {
            cnt++;
            // we can use any of them....
            bfs(grid, vis, row, col);
            dfs(grid, vis, row, col);
         }
      }
   }
   return cnt;
}

// in gfg diagonal movment is allowed ......
void bfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int row, int col)
{
   int n = grid.size();
   int m = grid[0].size();

   queue<pair<int, int>> q;
   vis[row][col] = 1;
   q.push({row, col});
   while (!q.empty())
   {
      int currrow = q.front().first;
      int currcol = q.front().second;
      q.pop();

      for (int i = -1; i <= 1; i++)
      {
         for (int j = -1; j <= 1; j++)
         {
            int neworw = currrow + i;
            int newcol = currcol + j;
            if (neworw >= 0 and neworw < n and newcol >= 0 and newcol < m and grid[neworw][newcol] == '1' and vis[neworw][newcol] == 0)
            {
               vis[neworw][newcol] = 1;
               q.push({neworw, newcol});
            }
         }
      }
   }
}

// same using dfs....
void dfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int row, int col)
{
   int n = grid.size();
   int m = grid[0].size();
   vis[row][col] = 1;
   for (int i = -1; i <= 1; i++)
   {
      for (int j = -1; j <= 1; j++)
      {
         int newrow = row + i;
         int newcol = col + j;
         if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and vis[newrow][newcol] == 0 and grid[newrow][newcol] == '1')
         {
            dfs(grid, vis, newrow, newcol);
         }
      }
   }
}

int numIslands(vector<vector<char>> &grid)
{
   int n = grid.size();
   int m = grid[0].size();
   vector<vector<int>> vis(n, vector<int>(m, 0));
   int cnt = 0;
   for (int row = 0; row < n; row++)
   {
      for (int col = 0; col < m; col++)
      {
         if (vis[row][col] == 0 and grid[row][col] == '1')
         {
            cnt++;

            // we can use any of them.....
            bfs(grid, vis, row, col);
            dfs(grid, vis, row, col);
         }
      }
   }
   return cnt;
}

// flood fill algorithm ........
/*
input ----> [ [ 1, 1, 1 ],
              [ 2, 2, 0 ],
              [ 2, 2, 2 ]  ]

initial row=2 , initial col=0, newval=3


output ----> [ [ 1, 1, 1 ],
               [ 3, 3, 0 ],
               [ 3, 3, 3 ]  ]
*/

// instead of using the visited array for validity we use the initial color to match whether it is vailed node or not.....

// using dfs...
void dfs(int sr, int sc, vector<vector<int>> &image, vector<vector<int>> &ans, int newcolor, int inicolor, vector<int> &r, vector<int> &c)
{
   ans[sr][sc] = newcolor;
   int n = image.size();
   int m = image[0].size();

   for (int i = 0; i < 4; i++)
   {
      int newrow = sr + r[i];
      int newcol = sc + c[i];
      if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and image[newrow][newcol] == inicolor and ans[newrow][newcol] != newcolor)
      {
         dfs(newrow, newcol, image, ans, newcolor, inicolor, r, c);
      }
   }
}

// same question using bfs......

void bfs(int sr, int sc, vector<vector<int>> &image, vector<vector<int>> &ans, int newcolor, int inicolor, vector<int> &r, vector<int> &c)
{
   int n = image.size();
   int m = image[0].size();

   ans[sr][sc] = newcolor;
   queue<pair<int, int>> q;
   q.push({sr, sc});

   while (!q.empty())
   {
      int currrow = q.front().first;
      int currcol = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++)
      {
         int newrow = currrow + r[i];
         int newcol = currcol + c[i];
         if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and image[newrow][newcol] == inicolor and ans[newrow][newcol] != newcolor)
         {
            ans[newrow][newcol] = newcolor;
            q.push({newrow, newcol});
         }
      }
   }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
   int inicolor = image[sr][sc];
   vector<vector<int>> ans = image;
   vector<int> r = {0, -1, 0, 1};
   vector<int> c = {-1, 0, 1, 0};

   // we can use any of them...
   dfs(sr, sc, image, ans, color, inicolor, r, c);
   bfs(sr, sc, image, ans, color, inicolor, r, c);

   return ans;
}

// shortest path leetcode..........

/*
statement----------->
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

sol --->

these question is solved only using bfs not dfs because here we required the shortest path for that we have to travel at all neighbor simultaneously not in a depth manner so bfs is required....

we use queue data structure
queue<pair<pair<row, col>, length of path>> q;

whenvever there is something shortest path is mentioned we have to use bfs we cant use dfs in such scenario.....

*/

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
   int n = grid.size();
   if (grid[0][0] == 1 and grid[n - 1][n - 1] == 1)
   {
      return -1;
   }

   vector<vector<int>> vis(n, vector<int>(n, 0));
   queue<pair<pair<int, int>, int>> q;
   q.push({{0, 0}, 1});

   // we make the grid 1 so that during traversal we cant able to come back at the same path again and again...
   grid[0][0] = 1;
   vis[0][0] = 1;

   while (!q.empty())
   {
      int row = q.front().first.first;
      int col = q.front().first.second;
      int currdis = q.front().second;
      q.pop();

      if (row == n - 1 and col == n - 1)
      {
         return currdis;
      }

      for (int i = -1; i <= 1; i++)
      {
         for (int j = -1; j <= 1; j++)
         {
            int newrow = row + i;
            int newcol = col + j;
            if (newrow >= 0 and newrow <= n - 1 and newcol >= 0 and newcol <= n - 1 and vis[newrow][newcol] == 0 and grid[newrow][newcol] == 0)
            {
               q.push({{newrow, newcol}, currdis + 1});
               grid[newrow][newcol] = 1;
               vis[newrow][newcol] = 1;
            }
         }
      }
   }
   // if after complete the entire traversl still we dont return any dist it means we never able to reach the destination and hence return -1.....
   return -1;
}

// if we want we can solve this without changint the original grid just we need to change the visited array....
// in Djkhastra_questions.cpp file the solution is mentioned.....

// now these are some problems which are only solved using bfs.....

// rotting oranges.....

// 0 --> empty cell , 1 --> fresh orange, 2 --> rotten orange .....
// queue<pair<pair<row, col>, mxtime>> q;

int orangesRotting(vector<vector<int>> &grid)
{
   int n = grid.size();
   int m = grid[0].size();

   queue<pair<pair<int, int>, int>> q;

   vector<vector<int>> vis(n, vector<int>(m, 0));

   rep(i, 0, n)
   {
      rep(j, 0, m)
      {
         if (grid[i][j] == 2)
         {
            q.push({{i, j}, 0});
            vis[i][j] = 2;
         }
      }
   }

   vector<int> r = {0, -1, 0, 1};
   vector<int> c = {-1, 0, 1, 0};

   int mxtime = 0;

   while (!q.empty())
   {
      int currrow = q.front().first.first;
      int currcol = q.front().first.second;
      int currtime = q.front().second;

      q.pop();
      mxtime = max(mxtime, currtime);

      for (int i = 0; i < 4; i++)
      {
         int newrow = currrow + r[i];
         int newcol = currcol + c[i];
         if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and grid[newrow][newcol] == 1 and vis[newrow][newcol] != 2)
         {
            q.push({{newrow, newcol}, currtime + 1});
            vis[newrow][newcol] = 2;
         }
      }
   }
   // if still there are some cells remain in the grid which are not reachable then we have to return -1 .....
   rep(i, 0, n)
   {
      rep(j, 0, m)
      {
         if (grid[i][j] == 1 and vis[i][j] != 2)
         {
            return -1;
         }
      }
   }
   return mxtime;
}

// the zero one matrix problem can only be solved using bfs....

/*
for each cell we have to found the distance of nearest cell which is 0...

whenever something nearest shortest come we have to use bfs...


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

*/

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
   int n = mat.size();
   int m = mat[0].size();
   vector<vector<int>> vis(n, vector<int>(m, 0));
   vector<vector<int>> distmat(n, vector<int>(m, 0));
   queue<pair<pair<int, int>, int>> q;

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (mat[i][j] == 0)
         {
            vis[i][j] = 1;
            q.push({{i, j}, 0});
         }
         else
         {
            vis[i][j] = 0;
         }
      }
   }

   int r[] = {-1, 0, 1, 0};
   int c[] = {0, 1, 0, -1};

   while (!q.empty())
   {
      int currrow = q.front().first.first;
      int currcol = q.front().first.second;
      int dist = q.front().second;
      q.pop();

      // each time when we pop from the queue we have to update the dist of that particular cell in the answer matrix with the current distance....
      distmat[currrow][currcol] = dist;

      for (int i = 0; i < 4; i++)
      {
         int newrow = currrow + r[i];
         int newcol = currcol + c[i];

         // for all cells whose values are 0 we initillay deal with them now we have to check for all cells whose value are 1....
         if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and vis[newrow][newcol] == 0 and mat[newrow][newcol] == 1)
         {
            vis[newrow][newcol] = 1;
            q.push({{newrow, newcol}, dist + 1});
         }
      }
   }
   return distmat;
}

// gfg ---> replace 0 with x
// leetcode --> surrounded regions..

// this one is of gfg....
// which I solved using dfs...
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, vector<int> &r, vector<int> &c)
{
   int n = mat.size();
   int m = mat[0].size();
   vis[row][col] = 1;

   for (int i = 0; i < 4; i++)
   {
      int newrow = row + r[i];
      int newcol = col + c[i];

      if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and vis[newrow][newcol] == 0 and mat[newrow][newcol] == 'O')
      {
         dfs(newrow, newcol, vis, mat, r, c);
      }
   }
}

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board, vector<int> &r, vector<int> &c)
{
   int n = board.size();
   int m = board[0].size();
   queue<pair<int, int>> q;

   vis[row][col] = 1;
   q.push({row, col});
   while (!q.empty())
   {
      int currrow = q.front().first;
      int currcol = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++)
      {
         int newrow = currrow + r[i];
         int newcol = currcol + c[i];

         if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and vis[newrow][newcol] == 0 and board[newrow][newcol] == 'O')
         {
            vis[newrow][newcol] = 1;
            q.push({newrow, newcol});
         }
      }
   }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
   vector<vector<int>> vis(n, vector<int>(m, 0));

   vector<int> r = {0, -1, 0, 1};
   vector<int> c = {-1, 0, 1, 0};

   for (int j = 0; j < m; j++)
   {
      // dfs for first row...
      if (vis[0][j] == 0 and mat[0][j] == 'O')
      {
         dfs(0, j, vis, mat, r, c);
      }
      //  dfs for last row...
      if (vis[n - 1][j] == 0 and mat[n - 1][j] == 'O')
      {
         dfs(n - 1, j, vis, mat, r, c);
      }
   }

   for (int i = 0; i < n; i++)
   {
      // dfs for first column...
      if (vis[i][0] == 0 and mat[i][0] == 'O')
      {
         dfs(i, 0, vis, mat, r, c);
      }
      //  dfs for last column...
      if (vis[i][m - 1] == 0 and mat[i][m - 1] == 'O')
      {
         dfs(i, m - 1, vis, mat, r, c);
      }
   }

   //  after doing the dfs from all 4 boundaries....
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (vis[i][j] == 0 and mat[i][j] == 'O')
         {
            // because all boundary cells or cells which attach with boundary whose values are '0' we already make their visited as 1 ....
            mat[i][j] = 'X';
         }
      }
   }

   return mat;
}

// this one is of leetcode......
// surrounding regions .......

// helper function which using bfs....
void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board, vector<int> &r, vector<int> &c)
{
   int n = board.size();
   int m = board[0].size();
   queue<pair<int, int>> q;

   vis[row][col] = 1;
   q.push({row, col});
   while (!q.empty())
   {
      int currrow = q.front().first;
      int currcol = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++)
      {
         int newrow = currrow + r[i];
         int newcol = currcol + c[i];

         if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and vis[newrow][newcol] == 0 and board[newrow][newcol] == 'O')
         {
            vis[newrow][newcol] = 1;
            q.push({newrow, newcol});
         }
      }
   }
}

// helper function which using dfs....
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board, vector<int> &r, vector<int> &c)
{
   int n = board.size();
   int m = board[0].size();
   vis[row][col] = 1;

   for (int i = 0; i < 4; i++)
   {
      int newrow = row + r[i];
      int newcol = col + c[i];
      if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and vis[newrow][newcol] == 0 and board[newrow][newcol] == 'O')
      {
         dfs(newrow, newcol, vis, board, r, c);
      }
   }
}

void solve(vector<vector<char>> &board)
{
   int n = board.size();
   int m = board[0].size();

   vector<vector<int>> vis(n, vector<int>(m, 0));
   vector<int> r = {0, -1, 0, 1};
   vector<int> c = {-1, 0, 1, 0};

   // we traverse only in boundaries.....
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (i == 0 or i == n - 1 or j == 0 or j == m - 1)
         {
            if (board[i][j] == 'O')
            {
               // we can use any of them to solve this....

               bfs(i, j, vis, board, r, c);
               // dfs(i, j, vis, board, r, c);
            }
         }
      }
   }

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (vis[i][j] == 0 and board[i][j] == 'O')
         {
            board[i][j] = 'X';
         }
      }
   }
}

// no of enclaves.... same name in gfg and leetcode...

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<int> &r, vector<int> &c)
{
   int n = grid.size();
   int m = grid[0].size();
   queue<pair<int, int>> q;

   vis[row][col] = 1;
   q.push({row, col});

   while (!q.empty())
   {
      int currrow = q.front().first;
      int currcol = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++)
      {
         int newrow = currrow + r[i];
         int newcol = currcol + c[i];
         if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and vis[newrow][newcol] == 0 and grid[newrow][newcol] == 1)
         {
            vis[newrow][newcol] = 1;
            q.push({newrow, newcol});
         }
      }
   }
}

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<int> &r, vector<int> &c)
{
   int n = grid.size();
   int m = grid[0].size();
   vis[row][col] = 1;

   for (int i = 0; i < 4; i++)
   {
      int newrow = row + r[i];
      int newcol = col + c[i];
      if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and vis[newrow][newcol] == 0 and grid[newrow][newcol] == 1)
      {
         dfs(newrow, newcol, vis, grid, r, c);
      }
   }
}

int numEnclaves(vector<vector<int>> &grid)
{
   int n = grid.size();
   int m = grid[0].size();

   vector<vector<int>> vis(n, vector<int>(m, 0));
   vector<int> r = {0, -1, 0, 1};
   vector<int> c = {-1, 0, 1, 0};

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (i == 0 or i == n - 1 or j == 0 or j == m - 1)
         {
            if (grid[i][j] == 1)
            {
               // we can use any of the 2 methods.....
               bfs(i, j, vis, grid, r, c);
               dfs(i, j, vis, grid, r, c);
            }
         }
      }
   }

   int cnt = 0;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (vis[i][j] == 0 and grid[i][j] == 1)
         {
            cnt++;
         }
      }
   }
   return cnt;
}

// no of closed islands.......

void bfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<int> &r, vector<int> &c)
{
   int n = grid.size(), m = grid[0].size();
   queue<pair<int, int>> q;

   vis[row][col] = 1;
   q.push({row, col});
   while (!q.empty())
   {
      int currrow = q.front().first;
      int currcol = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++)
      {
         int newrow = currrow + r[i];
         int newcol = currcol + c[i];

         if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and grid[newrow][newcol] == 0 and vis[newrow][newcol] == 0)
         {
            vis[newrow][newcol] = 1;
            q.push({newrow, newcol});
         }
      }
   }
}

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<int> &r, vector<int> &c)
{
   int n = grid.size(), m = grid[0].size();
   vis[row][col] = 1;
   for (int i = 0; i < 4; i++)
   {
      int newrow = row + r[i];
      int newcol = col + c[i];
      if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and grid[newrow][newcol] == 0 and vis[newrow][newcol] == 0)
      {
         dfs(newrow, newcol, grid, vis, r, c);
      }
   }
}

int closedIsland(vector<vector<int>> &grid)
{
   int n = grid.size(), m = grid[0].size();

   vector<vector<int>> vis(n, vector<int>(m, 0));
   // for all cells whose values are 1 for that we have to make our visited array also 1 .....
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (grid[i][j] == 1)
            vis[i][j] = 1;
      }
   }

   vector<int> r = {0, -1, 0, 1};
   vector<int> c = {-1, 0, 1, 0};

   for (int i = 0; i < n; i++)
   {
      if (grid[i][0] == 0 and vis[i][0] == 0)
      {
         dfs(i, 0, grid, vis, r, c);
      }
      if (grid[i][m - 1] == 0 and vis[i][m - 1] == 0)
      {
         dfs(i, m - 1, grid, vis, r, c);
      }
   }

   for (int j = 0; j < m; j++)
   {
      if (grid[0][j] == 0 and vis[0][j] == 0)
      {
         dfs(0, j, grid, vis, r, c);
      }

      if (grid[n - 1][j] == 0 and vis[n - 1][j] == 0)
      {
         dfs(n - 1, j, grid, vis, r, c);
      }
   }

   int compcnt = 0;

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {

         if (grid[i][j] == 0 and vis[i][j] == 0)
         {
            compcnt++;
            dfs(i, j, grid, vis, r, c);
         }
      }
   }

   return compcnt;
}

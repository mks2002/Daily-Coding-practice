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
#define __mayuk                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int32_t main()
{
    __mayuk;
    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}

// surrounding regions leetcode .....

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
                    dfs(i, j, vis, board, r, c);
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

// max area of a island.....

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<int> &r, vector<int> &c, int &area)
{
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;
    area++;
    for (int i = 0; i < 4; i++)
    {
        int newrow = row + r[i];
        int newcol = col + c[i];
        if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and vis[newrow][newcol] == 0 and grid[newrow][newcol] == 1)
        {
            dfs(newrow, newcol, grid, vis, r, c, area);
        }
    }
}
// in bfs we have 2 options either we can do the area++ 2 times during pushing the values into the queue or we can do it 1 time during poping the values from the queue......

void bfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<int> &r, vector<int> &c, int &area)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;

    vis[row][col] = 1;
    q.push({row, col});
    area++;

    while (!q.empty())
    {
        int currrow = q.front().first;
        int currcol = q.front().second;
        q.pop();
        // area++;
        for (int i = 0; i < 4; i++)
        {
            int newrow = currrow + r[i];
            int newcol = currcol + c[i];
            if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and vis[newrow][newcol] == 0 and grid[newrow][newcol] == 1)
            {
                vis[newrow][newcol] = 1;
                q.push({newrow, newcol});
                area++;
            }
        }
    }
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<int> r = {0, -1, 0, 1};
    vector<int> c = {-1, 0, 1, 0};
    int area = 0;
    int mxarea = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 and grid[i][j] == 1)
            {
                // we can solve it using both the methods.....
                dfs(i, j, grid, vis, r, c, area);
                bfs(i, j, grid, vis, r, c, area);
            }
            mxarea = max(area, mxarea);
            area = 0;
        }
    }
    return mxarea;
}





// no of distinct islands....

// required data structures --> vector<pair<int,int>> v, set<vector<pair<int,int>>> st .......

#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>

void dfs(int row, int col, vvi &grid, vvi &vis, vpi &shape, int baserow, int basecol, vi &r, vi &c)
{
   int n = grid.size();
   int m = grid[0].size();
   vis[row][col] = 1;

   shape.push_back({row - baserow, col - basecol});

   for (int i = 0; i < 4; i++)
   {
      int newrow = row + r[i];
      int newcol = col + c[i];
      if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and vis[newrow][newcol] == 0 and grid[newrow][newcol] == 1)
      {
         // for a same component the value of baserow and basecol remains same which is similar to starting value which is passed from parent function...
         dfs(newrow, newcol, grid, vis, shape, baserow, basecol, r, c);
      }
   }
}

// in bfs if we do any task during pushing element into the queue then we have to do it 2 times because pushing element is happens 2 times but if we want to do all this extra tasks only 1 time then we can do them after poping the element from the queue , the function works exactly same as before....

void bfs(int row, int col, vvi &grid, vvi &vis, vpi &shape, int baserow, int basecol, vi &r, vi &c)
{
   int n = grid.size();
   int m = grid[0].size();
   vis[row][col] = 1;
   shape.push_back({row - baserow, col - basecol});

   queue<pair<int, int>> q;
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
            shape.push_back({newrow - baserow, newcol - basecol});
            q.push({newrow, newcol});
         }
      }
   }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
   int n = grid.size();
   int m = grid[0].size();
   vector<vector<int>> vis(n, vector<int>(m, 0));
   vector<int> r = {0, -1, 0, 1};
   vector<int> c = {-1, 0, 1, 0};

   set<vector<pair<int, int>>> st;

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (vis[i][j] == 0 and grid[i][j] == 1)
         {
            vector<pair<int, int>> shape;

            // we can use either bfs or dfs ....
            dfs(i, j, grid, vis, shape, i, j, r, c);
            bfs(i, j, grid, vis, shape, i, j, r, c);
            st.insert(shape);
         }
      }
   }
   return st.size();
}

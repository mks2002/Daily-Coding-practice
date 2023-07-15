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

int32_t main()
{
   __mayuk;

   return 0;
}

// gfg........
vector<vector<int>> nearest(vector<vector<int>> grid)
{
   int n = grid.size();
   int m = grid[0].size();

   vector<vector<int>> vis(n, vector<int>(m, 0));
   vector<vector<int>> distmat(n, vector<int>(m, 0));

   queue<pair<pair<int, int>, int>> q;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (grid[i][j] == 1)
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
   vector<int> r = {0, -1, 0, 1};
   vector<int> c = {-1, 0, 1, 0};

   while (!q.empty())
   {
      int currrow = q.front().first.first;
      int currcol = q.front().first.second;
      int dist = q.front().second;
      q.pop();
      distmat[currrow][currcol] = dist;

      for (int i = 0; i < 4; i++)
      {
         int newrow = currrow + r[i];
         int newcol = currcol + c[i];
         if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and vis[newrow][newcol] == 0)
         {
            vis[newrow][newcol] = 1;
            q.push({{newrow, newcol}, dist + 1});
         }
      }
   }
   return distmat;
}

// in leetcode we have to find the dist of nearest 0 for each cell instead of 1 ......

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
   int n = mat.size();
   int m = mat[0].size();
   vector<vector<int>> vis(n, vector<int>(m, 0));
   vector<vector<int>> distmat(n, vector<int>(m, 0));
   queue<pair<pair<int, int>, int>> q;

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
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
   vector<int> r = {0, -1, 0, 1};
   vector<int> c = {-1, 0, 1, 0};

   while (!q.empty())
   {
      int currrow = q.front().first.first;
      int currcol = q.front().first.second;
      int dist = q.front().second;
      q.pop();
      distmat[currrow][currcol] = dist;

      for (int i = 0; i < 4; i++)
      {
         int newrow = currrow + r[i];
         int newcol = currcol + c[i];
         if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and vis[newrow][newcol] == 0)
         {
            vis[newrow][newcol] = 1;
            q.push({{newrow, newcol}, dist + 1});
         }
      }
   }
   return distmat;
}
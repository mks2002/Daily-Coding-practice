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

int findNonMinOrMax(vector<int> &nums)
{
   int n = nums.size();
   int mx = INT_MIN;
   int mn = INT_MAX;
   for (int i = 0; i < n; i++)
   {
      if (nums[i] > mx)
      {
         mx = nums[i];
      }
      if (nums[i] < mn)
      {
         mn = nums[i];
      }
   }
   int ans = -1;
   for (int i = 0; i < n; i++)
   {
      if (nums[i] != mx and nums[i] != mn)
      {
         ans = nums[i];
         break;
      }
   }
   return ans;
}

string smallestString(string s)
{
   int n = s.length();
   string temp = "";

   if (n == 1)
   {
      if (s[0] == 'a')
      {
         temp += "z";
      }
      else
      {
         temp += s[0] - 1;
      }
      return temp;
   }
   else
   {
      int arr[26] = {0};
      for (int i = 0; i < n; i++)
      {
         arr[s[i] - 'a']++;
      }
      // for checking whether there exist any other character except 'a' in the string or not.....
      int cntflag = false;
      for (int i = 1; i < 26; i++)
      {
         if (arr[i] != 0)
         {
            cntflag = true;
         }
      }

      int i = 0;
      bool flag = true;
      while (i < n and s[i] == 'a')
      {
         if (cntflag == true)
         {
            temp += "a";
            i++;
         }
         else
         {
            if (i == 0 and flag == true)
            {
               temp += "a";
               i++;
            }
            else if (flag == true and i != 0 and i == n - 1)
            {
               temp += "z";
               flag = false;
               i++;
            }
            else if (flag == true and i != 0)
            {
               temp += "a";
               i++;
            }
         }
      }

      if (i < n)
      {
         temp += s[i] - 1;
         int j = i;
         while (j < n - 1)
         {
            if (s[j + 1] != 'a')
            {
               char x = s[j + 1] - 1;
               temp += x;
               j++;
            }
            else
            {
               temp += s[j + 1];
               j++;
               break;
            }
         }
         while (j < n - 1)
         {
            temp += s[j + 1];
            j++;
         }
      }
      return temp;
   }
}


// https://www.codingninjas.com/codestudio/contests/codekaze-round-2-mock-test/8382475/problems/17231?leftPanelTab=0
























/*
for (int j = 0; j < m; j++)
   {
      // for first row...
      if (vis[0][j] == 0 and board[0][j] == 'O')
      {
         bfs(0, j, vis, board, r, c);
      }
      // for last row..
      if (vis[n - 1][j] == 0 and board[n - 1][j] == 'O')
      {
         bfs(n - 1, j, vis, board, r, c);
      }
   }

   for (int i = 0; i < n; i++)
   {
      // for first column...
      if (vis[i][0] == 0 and board[i][0] == 'O')
      {
         bfs(i, 0, vis, board, r, c);
      }

      // for last column ...
      if (vis[i][m - 1] == 0 and board[i][m - 1] == 'O')
      {
         bfs(i, m - 1, vis, board, r, c);
      }
   }
*/

/*

  for (int j = 0; j < m; j++)
   {
      if (vis[0][j] == 0 and grid[0][j] == 1)
      {
         dfs(0, j, vis, grid, r, c);
      }

      if (vis[n - 1][j] == 0 and grid[n - 1][j] == 1)
      {
         dfs(n - 1, j, vis, grid, r, c);
      }
   }

   //   dfs for first and last column...
   for (int i = 0; i < n; i++)
   {
      if (vis[i][0] == 0 and grid[i][0] == 1)
      {
         dfs(i, 0, vis, grid, r, c);
      }
      if (vis[i][m - 1] == 0 and grid[i][m - 1] == 0)
      {
         dfs(i, m - 1, vis, grid, r, c);
      }
   }
*/


// in no of enclaves the 2 individual loops approach give wrong answer but the nested loop approach works in both the questions ....
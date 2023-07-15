
// frog jump with k steps......

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

// simple recursion........
int fkjump(int idx, int n, int steps, vi &heights)
{
   if (idx == 0)
      return 0;

   int minjump = INT_MAX;
   for (int j = 1; j <= steps; j++)
   {
      if (idx - j >= 0)
      {
         int currjump = fkjump(idx - j, n, steps, heights) + abs(heights[idx] - heights[idx - j]);
         minjump = min(minjump, currjump);
      }
   }
   return minjump;
}

int frog_Kjump(int n, int k, vi &heights)
{
   return fkjump(n - 1, n, k, heights);
}

// memoization......

int fkjump(int idx, int n, int steps, vi &heights, vector<int> &dp)
{
   if (idx == 0)
      return 0;

   if (dp[idx] != -1)
      return dp[idx];

   int minjump = INT_MAX;

   for (int j = 1; j <= steps; j++)
   {
      if (idx - j >= 0)
      {
         int currjump = fkjump(idx - j, n, steps, heights, dp) + abs(heights[idx] - heights[idx - j]);
         minjump = min(minjump, currjump);
      }
   }
   return dp[idx] = minjump;
}

int frog_Kjumpmemo(int n, int k, vi &heights)
{
   vector<int> dp(n, -1);
   return fkjump(n - 1, n, k, heights, dp);
}

int frog_k_tabulation(int n, int k, vi &heights)
{
   vector<int> dp(n, -1);
   dp[0] = 0;

   // loop for tabulation which is exact reverse in range and direction of recursion , in recursion the value of idx --> (n-1 to 1 ) here it is from (1 to n-1)...........
   for (int i = 1; i < n; i++)
   {
      int minjump = INT_MAX;
      for (int j = 1; j <= k; j++)
      {
         if (i - j >= 0)
         {
            int currentjump = dp[i - j] + abs(dp[i] - dp[i - j]);
            minjump = min(minjump, currentjump);
         }
      }
      dp[i] = minjump;
   }
   return dp[n - 1];
}

int32_t main()
{
   __mayuk;
   int n, k;
   vector<int> heights;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      heights.push_back(x);
   }

   cout << frog_Kjump(n, k, heights) << endl;
   cout << frog_Kjumpmemo(n, k, heights) << endl;
   cout << frog_k_tabulation(n, k, heights) << endl;
   return 0;
}
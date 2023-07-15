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

// here left and right denotes the respective left and right calls ....

// simple recursion....
int f(int idx, int n, vi &heights)
{
   if (idx == 0)
      return 0;

   int left = f(idx - 1, n, heights) + abs(heights[idx] - heights[idx - 1]);
   int right = INT_MAX;
   if (idx > 1)
   {
      right = f(idx - 2, n, heights) + abs(heights[idx] - heights[idx - 2]);
   }

   int ans = min(left, right);
   return ans;
}

int frogjump(int n, vi &heights)
{
   return f(n - 1, n, heights);
}

// memoization....
int f(int idx, int n, vi &heights, vi &dp)
{
   if (idx == 0)
      return 0;

   if (dp[idx] != -1)
      return dp[idx];

   int left = f(idx - 1, n, heights, dp) + abs(heights[idx] - heights[idx - 1]);

   int right = INT_MAX;
   if (idx > 1)
   {
      right = f(idx - 2, n, heights, dp) + abs(heights[idx] - heights[idx - 2]);
   }

   return dp[idx] = min(left, right);
}

int frogjumpmemo(int n, vi &heights)
{
   vi dp(n + 1, -1);
   return f(n - 1, n, heights, dp);
}

// tabulation......
// in tabulation we have to replace the function calls by dp array...
int frogjumptabu(int n, vi &heights)
{
   vi dp(n + 1, -1);

   // base case .....
   dp[0] = 0;

   for (int i = 1; i < n; i++)
   {
      int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
      int right = INT_MAX;
      if (i > 1)
      {
         right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
      }
      dp[i] = min(left, right);
   }
   return dp[n - 1];
}

// space optimization ....
/*
 in space optimization we replace
 dp[i-1]=prev
 dp[i-2]=prev2
 dp[i]=curr
*/

int frogjumpspaceopt(int n, vi &heights)
{
   int prev = 0;
   int prev2 = 0;
   for (int i = 1; i < n; i++)
   {
      int left = prev + abs(heights[i] - heights[i - 1]);
      int right = INT_MAX;
      if (i > 1)
      {
         right = prev2 + abs(heights[i] - heights[i - 2]);
      }
      int curr = min(left, right);
      prev2 = prev;
      prev = curr;
   }
   return prev;
}

int32_t main()
{
   __mayuk;
   int n = 4;
   vi a = {10, 20, 30, 10};
   cout << frogjump(n, a) << endl;
   cout << frogjumpmemo(n, a) << endl;
   cout << frogjumptabu(n, a) << endl;
   cout << frogjumpspaceopt(n, a) << endl;
   return 0;
}

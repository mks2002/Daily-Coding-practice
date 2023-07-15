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

int fib(int n)
{
   if (n <= 1)
   {
      return n;
   }

   return fib(n - 1) + fib(n - 2);
}

int fibmemo(int n, vi dp)
{
   if (n <= 1)
      return n;
   if (dp[n] != -1)
      return dp[n];
   return dp[n] = fib(n - 1) + fib(n - 2);
}

int fibtabulation(int n)
{
   vector<int> dp(n + 1, -1);

   dp[0] = 0;
   dp[1] = 1;

   for (int i = 2; i <= n; i++)
   {
      dp[i] = dp[i - 1] + dp[i - 2];
   }
   return dp[n];
}

int fibspaceopt(int n)
{
   int prev2 = 0;
   int prev = 1;

   for (int i = 2; i <= n; i++)
   {
      int cur_i = prev2 + prev;
      prev2 = prev;
      prev = cur_i;
   }
   return prev;
}

int32_t main()
{
   __mayuk;
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      vi v(n + 1, -1);

      // cout << fib(n) << endl;
      cout << fibmemo(n, v) << endl;
      cout << fibtabulation(n) << endl;
      cout << fibspaceopt(n) << endl;
   }
   return 0;
}

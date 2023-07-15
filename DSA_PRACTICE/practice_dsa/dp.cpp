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

// int findWaysUtil(int ind, int target, vector<int> &arr,
//                  vector<vector<int>> &dp)
// {
//    if (target == 0)
//       return 1;

//    if (ind == 0)
//       return arr[0] == target;

//    if (dp[ind][target] != -1)
//       return dp[ind][target];

//    int notTaken = findWaysUtil(ind - 1, target, arr, dp);

//    int taken = 0;
//    if (arr[ind] <= target)
//       taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);

//    return dp[ind][target] = notTaken + taken;
// }

// int findWays(vector<int> &num, int tar)
// {
//    int n = num.size();
//    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
//    return findWaysUtil(n - 1, tar, num, dp);
// }

int findWaysUtil(int ind, int target, vector<int> &arr,
                 vector<vector<int>> &dp)
{
   int n = arr.size();
   if (target == 0)
      return 1;

   if (ind == (n - 1))
      return arr[n - 1] == target;

   if (dp[ind][target] != -1)
      return dp[ind][target];

   int notTaken = findWaysUtil(ind + 1, target, arr, dp);

   int taken = 0;
   if (arr[ind] <= target)
      taken = findWaysUtil(ind + 1, target - arr[ind], arr, dp);

   return dp[ind][target] = notTaken + taken;
}

int findWays(vector<int> &num, int tar)
{
   int n = num.size();
   vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
   return findWaysUtil(0, tar, num, dp);
}

int32_t main()
{
   __mayuk;

   return 0;
}
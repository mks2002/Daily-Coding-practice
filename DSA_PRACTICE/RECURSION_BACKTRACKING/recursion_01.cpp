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

void print(int n)
{
   // if (n == 0)
   //    return;
   if (n == 1)
   {
      cout << n << endl;
      return;
   }
   print(n - 1);
   cout << n << endl;
}

void reverseprint(int n)
{
   if (n == 0)
      return;
   cout << n << endl;
   reverseprint(n - 1);
}


// printing using 2 parameters.....
void print2(int n, int i)
{
   if (i > n)
      return;
   cout << i << endl;
   print2(n, i + 1);
}

void reverseprint2(int n, int i)
{
   if (i < 1)
      return;
   cout << i << endl;
   reverseprint2(n, i - 1);
}

// print 1 to n without using i+1 use i-1......
void printdecreae(int n, int i)
{
   if (i < 1)
      return;
   printdecreae(n, i - 1);
   cout << i << endl;
}

// same print n to 1 without using i-1 using i+1......
void printreverseincrease(int n, int i)
{
   if (i < 1)
      return;
}

int helper(int idx, int size, vector<int> &nums, int target, int sum, vector<vector<int>> &dp)
{
   if (idx == size)
   {
      if (sum == target)
         return 1;
      else
         return 0;
   }
   if (dp[idx][sum] != -1)
      return dp[idx][sum];
   int left = helper(idx + 1, size, nums, target, sum + nums[idx], dp);
   int right = helper(idx + 1, size, nums, target, sum - nums[idx], dp);
   int ans = left + right;
   return dp[idx][sum] = ans;
}

int findTargetSumWays(vector<int> &nums, int target)
{
   int n = nums.size();
   int sum = 0;
   vector<vector<int>> dp(n, vector<int>(target + 1, -1));
   int ans = helper(0, n, nums, target, sum, dp);
   return ans;
}

int32_t main()
{
   __mayuk;
   // print2(5,1);
   // reverseprint2(5, 5);
   printdecreae(5, 5);
   return 0;
}
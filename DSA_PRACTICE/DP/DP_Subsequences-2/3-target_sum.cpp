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

/*
// we are given an array and we can use either '+'  or '-'  negative sign on each element once and we have to determine by doing this in how many ways we can make target.....

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

*/

// simple recursion ....

int helper(int idx, int currsum, vector<int> &nums, int target)
{
    if (idx < 0)
    {
        if (currsum == target)
            return 1;
        else
            return 0;
    }

    int plus = helper(idx - 1, currsum + nums[idx], nums, target);
    int minus = helper(idx - 1, currsum - nums[idx], nums, target);

    int ans = plus + minus;
    return ans;
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int currsum = 0;
    int ans = helper(n - 1, currsum, nums, target);
    return ans;
}

// memoization........

int helper(int idx, int currsum, vector<int> &nums, int target, vector<vector<int>> &dp)
{
    if (idx < 0)
    {
        if (currsum == target)
            return 1;
        else
            return 0;
    }

    if (dp[idx][currsum] != -1)
        return dp[idx][currsum];

    int plus = helper(idx - 1, currsum + nums[idx], nums, target, dp); 
    int minus = helper(idx - 1, currsum - nums[idx], nums, target, dp);
    int ans = plus + minus;
    return dp[idx][currsum] = ans;
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int currsum = 0;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    int ans = helper(n - 1, currsum, nums, target, dp);
    return ans;
}

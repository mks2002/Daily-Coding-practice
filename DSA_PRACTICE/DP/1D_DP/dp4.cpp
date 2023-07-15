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

// maximum sum of non adjacent elements...

int solve(vector<int> &nums, int idx)
{
    if (idx == 0)
        return nums[idx];
        
    if (idx < 0)
        return 0;

    int pick = nums[idx] + solve(nums, idx - 2);
    int notpick = 0 + solve(nums, idx - 1);

    return max(pick, notpick);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    int ans = solve(nums, n - 1);
    return ans;
}

// memoization.....

int solve(vector<int> &nums, int idx, vector<int> &dp)
{
    if (idx == 0)
        return nums[idx];
    if (idx < 0)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];
    int pick = nums[idx] + solve(nums, idx - 2, dp);
    int notpick = 0 + solve(nums, idx - 1, dp);

    return dp[idx] = max(pick, notpick);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    int ans = solve(nums, n - 1, dp);
    return ans;
}

// tabulation....

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);

    // base case ..
    dp[0] = nums[0];
    int neg = 0; // this is for keep track of negative idx..

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
        {
            pick = nums[i] + dp[i - 2];
        }
        int notpick = 0 + dp[i - 1];

        dp[i] = max(pick, notpick);
    }
    return dp[n - 1];
}

// space optimization....

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();

    // this is the base case..
    int prev2 = 0, prev = nums[0];

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
        {
            pick = nums[i] + prev2;
        }
        int notpick = 0 + prev;

        int curr = max(pick, notpick);

        prev2 = prev;
        prev = curr;
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
    }
    return 0;
}

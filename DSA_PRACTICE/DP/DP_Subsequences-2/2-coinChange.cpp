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
// 322. Coin Change..........

// minimum number of coins to make the target.....

int helper(int idx, int target, vector<int> &coins)
{
    if (idx == 0)
    {
        if ((target % coins[0]) == 0)
            return target / coins[0];
        else
            return 1e9;
    }

    int nontake = 0 + helper(idx - 1, target, coins);
    int take = INT_MAX;
    if (target >= coins[idx])
        take = 1 + helper(idx - 1, target - coins[idx], coins);
    int ans = min(take, nontake);
    return ans;
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    int ans = helper(n - 1, amount, coins);
    if (ans >= 1e9)
        return -1;
    else
        return ans;
}

// memoization..........

int helper(int idx, int target, vector<int> &coins, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if ((target % coins[0]) == 0)
            return target / coins[0];
        else
            return 1e9;
    }

    if (dp[idx][target] != -1)
        return dp[idx][target];

    int nontake = 0 + helper(idx - 1, target, coins, dp);
    int take = INT_MAX;
    if (target >= coins[idx])
        take = 1 + helper(idx, target - coins[idx], coins, dp);
    int ans = min(take, nontake);
    return dp[idx][target] = ans;
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = helper(n - 1, amount, coins, dp);
    if (ans >= 1e9)
        return -1;
    else
        return ans;
}

// tabulation......

/*

if (coins[0] <= amount)
{
    for (int i = coins[0]; i <= amount; i++)
    {
        if ((i % coins[0]) == 0)
            dp[0][i] = i / coins[0];
        else
            dp[0][i] = 1e9;
    }
}

this base case is giving wrong answer for the input
coins = [1]
amount = 0
Output --> -1
Expected  0

// because here we dont make all the indices which are less then coins[0] as 1e9 , so they remains -1 and it will gives wrong answer in may condtions like this.....

*/

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    // base case......
    for (int target = 0; target <= amount; target++)
    {
        if ((target % coins[0]) == 0)
            dp[0][target] = target / coins[0];
        else
            dp[0][target] = 1e9;
    }

    for (int idx = 1; idx < n; idx++)
    {
        for (int target = 0; target <= amount; target++)
        {
            int nontake = 0 + dp[idx - 1][target];
            int take = INT_MAX;
            if (target >= coins[idx])
                take = 1 + dp[idx][target - coins[idx]];
            int ans = min(take, nontake);
            dp[idx][target] = ans;
        }
    }

    if (dp[n - 1][amount] >= 1e9)
        return -1;
    else
        return dp[n - 1][amount];
}

// space optimization........

/*
in this method we actuallly required 2 different 1d vectors for 2 different states of the dp array one is dp[idx] and another is dp[idx-1] .......

dp[idx] --> curr , dp[idx-1]  --> prev .....

*/

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> prev(amount + 1, -1), prev2(amount + 1, -1);

    for (int target = 0; target <= amount; target++)
    {
        if ((target % coins[0]) == 0)
            prev[target] = target / coins[0];
        else
            prev[target] = 1e9;
    }

    for (int idx = 1; idx < n; idx++)
    {
        vector<int> curr(amount + 1, 0);
        for (int target = 0; target <= amount; target++)
        {
            int nontake = 0 + prev[target];
            int take = INT_MAX;
            if (target >= coins[idx])
                take = 1 + curr[target - coins[idx]];

            int ans = min(take, nontake);
            curr[target] = ans;
        }
        prev2 = prev;
        prev = curr;
    }

    if (prev[amount] >= 1e9)
        return -1;
    else
        return prev[amount];
}
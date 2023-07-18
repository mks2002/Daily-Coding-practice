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

// this problem is similar to stocks 2 problem just the only difference is here we also need to pay a transaction fee after each successful transaction ( 1 buy + 1 sell ) and we have to reduce that fee from the each time we do one sell or one buy from any 1 of these....

// we can do infinite number of transactions .......

// simple recursive solution ....

int helper(int idx, int currstate, vector<int> &prices, int fee)
{
    if (idx >= prices.size())
        return 0;

    int profit = 0;
    if (currstate == 1) // buying state ...
    {
        int nontake = 0 + helper(idx + 1, 1, prices, fee);
        int take = -prices[idx] + helper(idx + 1, 0, prices, fee);
        profit = max(take, nontake);
    }
    else if (currstate == 0) // selling state ...
    {
        int nontake = 0 + helper(idx + 1, 0, prices, fee);
        // each time after one complete transaction we have to reduce the fee from our current money ....
        int take = prices[idx] + helper(idx + 1, 1, prices, fee) - fee;
        profit = max(take, nontake);
    }

    return profit;
}

int maxProfit(vector<int> &prices, int fee)
{
    int idx = 0, buy = 1, sell = 0;
    int ans = helper(idx, buy, prices, fee);
    return ans;
}

// memoization ........

int helper(int idx, int currstate, vector<int> &prices, int fee, vector<vector<int>> &dp)
{
    if (idx >= prices.size())
        return 0;
    if (dp[idx][currstate] != -1)
        return dp[idx][currstate];

    int profit = 0;
    if (currstate == 1) // buying state ...
    {
        int nontake = 0 + helper(idx + 1, 1, prices, fee, dp);
        int take = -prices[idx] + helper(idx + 1, 0, prices, fee, dp);
        profit = max(take, nontake);
    }
    else if (currstate == 0) // selling state ..
    {
        int nontake = 0 + helper(idx + 1, 0, prices, fee, dp);
        // each time after one complete transaction we have to reduce the fee from our current money ....
        int take = prices[idx] + helper(idx + 1, 1, prices, fee, dp) - fee;
        profit = max(take, nontake);
    }

    return dp[idx][currstate] = profit;
}

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    int idx = 0, buy = 1, sell = 0;
    vector<vector<int>> dp(n, vector<int>(2, -1));
    int ans = helper(idx, buy, prices, fee, dp);
    return ans;
}

// tabulation ......

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    // base cases --> if idx >= n return 0 ....
    dp[n][0] = dp[n][1] = 0;

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int currstate = 1; currstate >= 0; currstate--)
        {
            int profit = 0;
            if (currstate == 1) // buying state .;.
            {
                int nontake = 0 + dp[idx + 1][1];
                int take = -prices[idx] + dp[idx + 1][0];
                profit = max(take, nontake);
            }
            else if (currstate == 0) // selling state ...
            {
                int nontake = 0 + dp[idx + 1][0];
                // each time after one complete transaction we have to reduce the fee from our current money ....
                int take = prices[idx] + dp[idx + 1][1] - fee;
                profit = max(take, nontake);
            }

            dp[idx][currstate] = profit;
        }
    }

    return dp[0][1];
}

// space optimization ......

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<int> prev(2, -1), prev2(2, -1);

    // base cases ....
    prev[0] = prev[1] = 0;

    for (int idx = n - 1; idx >= 0; idx--)
    {
        vector<int> curr(2, 0);
        for (int currstate = 1; currstate >= 0; currstate--)
        {
            int profit = 0;
            if (currstate == 1) // buying state ...
            {
                int nontake = 0 + prev[1];
                int take = -prices[idx] + prev[0];
                profit = max(take, nontake);
            }
            else if (currstate == 0) // selling state ...
            {
                int nontake = 0 + prev[0];
                // each time after one complete transaction we have to reduce the fee from our current money ....
                int take = prices[idx] + prev[1] - fee;
                profit = max(take, nontake);
            }

            curr[currstate] = profit;
        }
        prev2 = prev;
        prev = curr;
    }
    return prev[1];
}
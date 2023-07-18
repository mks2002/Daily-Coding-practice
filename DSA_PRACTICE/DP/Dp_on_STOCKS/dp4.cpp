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

// buy and sell stocks 4......

/*
currstate = 1 --> buying state
currstate = 0 --> selling state.

*/

// similar to the previous problem there we are allowed to do atmost 2 transactions here we are allowed to do at most k transactions......

// simple recursion....

int helper(int idx, int currstate, int cap, vector<int> &prices)
{
    if (cap == 0)
        return 0;
    if (idx == prices.size())
        return 0;

    int profit = 0;

    if (currstate == 1)
    {
        int take = -prices[idx] + helper(idx + 1, 0, cap, prices);
        int nontake = 0 + helper(idx + 1, 1, cap, prices);
        profit = max(take, nontake);
    }
    else if (currstate == 0)
    {
        int nontake = 0 + helper(idx + 1, 0, cap, prices);
        int take = prices[idx] + helper(idx + 1, 1, cap - 1, prices);
        profit = max(take, nontake);
    }
    return profit;
}

int maxProfit(int k, vector<int> &prices)
{
    int idx = 0, buy = 1, sell = 0, cap = k;
    int ans = helper(idx, buy, cap, prices);
    return ans;
}

// memoiazation.....

int helper(int idx, int currstate, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    // base cases...
    if (cap == 0)
        return 0;
    if (idx == prices.size())
        return 0;
    if (dp[idx][currstate][cap] != -1)
        return dp[idx][currstate][cap];

    int profit = 0;

    if (currstate == 1)
    {
        int take = -prices[idx] + helper(idx + 1, 0, cap, prices, dp);
        int nontake = 0 + helper(idx + 1, 1, cap, prices, dp);
        profit = max(take, nontake);
    }
    else if (currstate == 0)
    {
        int nontake = 0 + helper(idx + 1, 0, cap, prices, dp);
        int take = prices[idx] + helper(idx + 1, 1, cap - 1, prices, dp);
        profit = max(take, nontake);
    }
    return dp[idx][currstate][cap] = profit;
}

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    int idx = 0, buy = 1, sell = 0, cap = k;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(cap + 1, -1)));
    int ans = helper(idx, buy, cap, prices, dp);
    return ans;
}

// tabulation.....

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));

    // if cap == 0 return 0 .....
    for (int idx = 0; idx <= n; idx++)
    {
        for (int currstate = 0; currstate <= 1; currstate++)
            dp[idx][currstate][0] = 0;
    }

    // if idx == n return 0 ......
    for (int currstate = 0; currstate <= 1; currstate++)
    {
        for (int cap = 0; cap <= k; cap++)
            dp[n][currstate][cap] = 0;
    }

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int currstate = 1; currstate >= 0; currstate--)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                int profit = 0;
                if (currstate == 1) // buying state ....
                {
                    int nontake = 0 + dp[idx + 1][1][cap];
                    int take = -prices[idx] + dp[idx + 1][0][cap];
                    profit = max(take, nontake);
                }
                else if (currstate == 0) // selling state ....
                {
                    int nontake = 0 + dp[idx + 1][0][cap];
                    int take = prices[idx] + dp[idx + 1][1][cap - 1];
                    profit = max(take, nontake);
                }

                dp[idx][currstate][cap] = profit;
            }
        }
    }

    return dp[0][1][k];
}

// space optimization ....

// dp[idx+1] --> prev , dp[idx] --> curr .....

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> prev(2, vector<int>(k + 1, -1)), prev2(2, vector<int>(k + 1, -1));

    // if cap == 0 return 0 .....
    for (int currstate = 0; currstate <= 1; currstate++)
        prev[currstate][0] = 0;

    // if idx == n return 0 ......
    for (int currstate = 0; currstate <= 1; currstate++)
    {
        for (int cap = 0; cap <= k; cap++)
            prev[currstate][cap] = 0;
    }

    for (int idx = n - 1; idx >= 0; idx--)
    {
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        for (int currstate = 1; currstate >= 0; currstate--)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                int profit = 0;
                if (currstate == 1)
                {
                    int nontake = 0 + prev[1][cap];
                    int take = -prices[idx] + prev[0][cap];
                    profit = max(take, nontake);
                }
                else if (currstate == 0)
                {
                    int nontake = 0 + prev[0][cap];
                    int take = prices[idx] + prev[1][cap - 1];
                    profit = max(take, nontake);
                }

                curr[currstate][cap] = profit;
            }
        }

        prev2 = prev;
        prev = curr;
    }

    return prev[1][k];
}
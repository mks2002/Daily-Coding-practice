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
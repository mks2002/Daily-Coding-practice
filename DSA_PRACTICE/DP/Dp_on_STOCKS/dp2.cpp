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

// buy and sell stock 2....

// in the previous question we can buy once and sell once but here we can do the task mutiple times buy each time we have to buy before sell ...
// so here we need to try out all possible combination and then from there we have to take the maximum...

// simple recursive solution......

/*
currstate = 1 --> buying state
currstate = 0 --> selling state.

*/

// in this kind of problems we have to do transactions and if we try to do transactions in reverse order then it is very complicated so in this type of questions we have to solve the recursion from (0 to n-1) instead of (n-1 to 0) and since the recursion is (0 to n-1) so the tabulation will be from (n-1 to 0) , and the currstate variable loop is also not reverse in the tabulation because whether it is tabulation or recusion first always we have to buy then only we can able to sell.....

int helper(int idx, int currstate, vector<int> &prices)
{
    if (idx == prices.size())
        return 0;

    int profit = 0;

    // buying state.....
    if (currstate == 1)
    {
        int take = -prices[idx] + helper(idx, 0, prices);
        int nontake = 0 + helper(idx + 1, 1, prices);
        profit = max(take, nontake);
    }
    // selling state.....
    else if (currstate == 0)
    {
        int take = prices[idx] + helper(idx + 1, 1, prices);
        int nontake = 0 + helper(idx + 1, 0, prices);
        profit = max(take, nontake);
    }

    return profit;
}

int maxProfit(vector<int> &prices)
{
    int idx = 0, buy = 1, sell = 0;
    int ans = helper(idx, buy, prices);
    return ans;
}

// memoiazation.....

int helper(int idx, int currstate, vector<int> &prices, vector<vector<int>> &dp)
{
    // base case...
    if (idx == prices.size())
        return 0;

    if (dp[idx][currstate] != -1)
        return dp[idx][currstate];

    int profit = 0;
    if (currstate == 1)
    {
        int take = -prices[idx] + helper(idx, 0, prices, dp);
        int nontake = 0 + helper(idx + 1, 1, prices, dp);
        profit = max(take, nontake);
    }
    else if (currstate == 0)
    {
        int take = prices[idx] + helper(idx + 1, 1, prices, dp);
        int nontake = 0 + helper(idx + 1, 0, prices, dp);
        profit = max(take, nontake);
    }
    return dp[idx][currstate] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int idx = 0, buy = 1, sell = 0;
    vector<vector<int>> dp(n, vector<int>(2, -1));
    int ans = helper(idx, buy, prices, dp);
    return ans;
}

// tabulation.....
/*
1. since tabulation is exact opposite to the memoiazation so there we start from 0 to n, so here we start from reverse i.e.from
   idx = n to 0..

2.  here the dp vector size is (n+1)*2 because we have to go upto idx =n for base case...

3.  one thing which is common in both memoiazation and tabulation is that what we return in memoiazation and tabulation both have same parameter i.e.  for memoiazation the parameter of parent function call is become the return index value of the dp array of tabulation code..

*/

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    // base case...
    dp[n][0] = dp[n][1] = 0;

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int currstate = 0; currstate <= 1; currstate++)
        {
            int profit = 0;
            if (currstate == 1)
            {
                int take = -prices[idx] + dp[idx + 1][0];
                int nontake = 0 + dp[idx + 1][1];
                profit = max(take, nontake);
            }
            else if (currstate == 0)
            {
                int take = prices[idx] + dp[idx + 1][1];
                int nontake = 0 + dp[idx + 1][0];
                profit = max(take, nontake);
            }

            dp[idx][currstate] = profit;
        }
    }

    return dp[0][1];
}

// space optimiazation....

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> prev(2, -1), prev2(2, -1);

    // base case...
    prev[0] = prev[1] = 0;

    for (int idx = n - 1; idx >= 0; idx--)
    {
        vector<int> curr(2, 0);
        for (int currstate = 0; currstate <= 1; currstate++)
        {
            int profit = 0;
            if (currstate == 1)
            {
                int take = -prices[idx] + prev[0];
                int nontake = 0 + prev[1];
                profit = max(take, nontake);
            }
            else if (currstate == 0)
            {
                int take = prices[idx] + prev[1];
                int nontake = 0 + prev[0];
                profit = max(take, nontake);
            }
            curr[currstate] = profit;
        }

        prev2 = prev;
        prev = curr;
    }

    return prev[1];
}

// the prev2 variable is not useful in any of the dp question where we dont have to deal with idx-2 or idx+2 kind of thing we use this so that the flow is not break otherwise if we dont use this then also it gives correct answer so in that case we have to use only one prev , prev2 is not required and in main outer loop prev=curr, thats the thing which we have to do....

// instead of using 2 vectors curr, prev of 2 size we can directly use 4 integer variable also to solve this question....

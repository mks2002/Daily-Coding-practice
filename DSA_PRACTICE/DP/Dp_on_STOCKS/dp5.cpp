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

// Best Time to Buy and Sell Stock with Cooldown....

/*
here also we allowed to do unlimited tranactions...
1. it means we can not buy just after sell....
2. it has similar solution like the second stock problem just when we sell then we move to idx+2 instead of idx+1....
*/

// memoiazation...........

int helper(int idx, int currstate, vector<int> &prices, vector<vector<int>> &dp)
{
    // base case...
    if (idx >= prices.size())
        return 0;

    if (dp[idx][currstate] != -1)
        return dp[idx][currstate];

    int profit = 0;
    if (currstate == 1)
    {
        int take = -prices[idx] + helper(idx + 1, 0, prices, dp);
        int nontake = 0 + helper(idx + 1, 1, prices, dp);
        profit = max(take, nontake);
    }
    else if (currstate == 0)
    {
        // after selling we move to next of next index...
        int take = prices[idx] + helper(idx + 2, 1, prices, dp);
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

// tabulation........

// for tabulating this code we have to declare a 2d array of size (n+2)*2 because we are dealing with idx+2  .....

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(n + 2, vector<int>(2, -1));

    // base case --> if idx == n return 0 ...
    dp[n][0] = dp[n][1] = dp[n + 1][0] = dp[n + 1][1] = 0;

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int currstate = 1; currstate >= 0; currstate--)
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
                // after selling we move to next of next index...
                int take = prices[idx] + dp[idx + 2][1];
                int nontake = 0 + dp[idx + 1][0];
                profit = max(take, nontake);
            }

            dp[idx][currstate] = profit;
        }
    }

    return dp[0][1];
}

// space optimization.......

/*
now here actually we have to use the prev2 similar to frog jump question

dp[idx] --> curr , dp[idx+1] --> prev , dp[idx+2] --> prev2.....

in the outer loop  --->  prev2 = prev; prev = curr;

// in this question we have to maintain 2 different states so required both prev2 , prev in the space optimization ....
*/

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> prev(2, -1), prev2(2, -1);

    // base case....
    prev[0] = prev[1] = prev2[0] = prev2[1] = 0;

    for (int idx = n - 1; idx >= 0; idx--)
    {
        vector<int> curr(2, 0);
        for (int currstate = 1; currstate >= 0; currstate--)
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
                // after selling we move to next of next index...
                int take = prices[idx] + prev2[1];
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

/*
in case of tabulation and space optimization both, the currstate loop we can run it from (0 to 1) or ( 1 to 0 ) both works properly but it is recommended that whatever is our buying state in memoization we have to start our loop from that because first we have to buy then only we can sell..
 ex --> 
 if buy = 1 the currstate loop -> ( 1 to 0 )
 if buy = 0 the currstate loop -> ( 0 to 1 )

and since in our memoization code the buy = 1 so in our tabulation and space optimizatio we run the currstate loop from (1 to 0) .......

*/
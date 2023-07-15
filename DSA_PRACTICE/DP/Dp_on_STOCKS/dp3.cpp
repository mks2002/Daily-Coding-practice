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

// buy and sell stocks 3.....

/*
it is similar to the previous question but here we are restricted to do only maximum 2 transactions not unlimited transactions...

to solve this question everything remain same as previous just here we have to add one more parameter in the function call which is cap whose value varying from 0 1 2 it denotes the no of transaction we have done till now..

once one complete trasaction (1 buy + 1 sell ) will be done we reduce the value of cap by 1...

from parent function the value of cap is 2 and in base case one more condition is added ( if cap ==0 return 0 )..

*/

int helper(int idx, int currentstate, int cap, vector<int> &prices)
{
    // base cases......
    if (cap == 0) // this is the extra base case which will keep track of no of transactions....
        return 0;
    if (idx == prices.size())
        return 0;

    int profit = 0;

    if (currentstate == 1)
    {
        int nontake = 0 + helper(idx + 1, 1, cap, prices);
        int take = -prices[idx] + helper(idx + 1, 0, cap, prices);
        profit = max(take, nontake);
    }
    else if (currentstate == 0)
    {
        int nontake = 0 + helper(idx + 1, 0, cap, prices);
        //  once the buy and sell both done we reduce cap by 1...
        int take = prices[idx] + helper(idx + 1, 1, cap - 1, prices);
        profit = max(take, nontake);
    }

    return profit;
}

int maxProfit(vector<int> &prices)
{
    int idx = 0, buy = 1, sell = 0, cap = 2;
    int ans = helper(idx, buy, cap, prices);
    return ans;
}

// memoiazation....

int helper(int idx, int currentstate, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    // this are the 3 base cases....
    if (cap == 0)
        return 0;

    if (idx == prices.size())
        return 0;

    if (dp[idx][currentstate][cap] != -1)
        return dp[idx][currentstate][cap];

    int profit = 0;

    if (currentstate == 1)
    {
        int nontake = 0 + helper(idx + 1, 1, cap, prices, dp);
        int take = -prices[idx] + helper(idx + 1, 0, cap, prices, dp);
        profit = max(take, nontake);
    }
    else if (currentstate == 0)
    {
        int nontake = 0 + helper(idx + 1, 0, cap, prices, dp);
        //  once the buy and sell both done we reduce cap by 1...
        int take = prices[idx] + helper(idx + 1, 1, cap - 1, prices, dp);
        profit = max(take, nontake);
    }

    return dp[idx][currentstate][cap] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int idx = 0, buy = 1, sell = 0, cap = 2;

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    int ans = helper(idx, buy, cap, prices, dp);
    return ans;
}

// tabulation.....

/*
if cap==0 return 0
it means if the cap is 0 irrespective of what is the value of idx and currstate dp[idx][currstate][0]=0 for all values of currstate and idx....

if idx == n return 0
so if idx is n then whatever the value of cap and currstate dp[n][currstate][cap]=0;


we have to run the cap loop from 1 to 2 not from 0 to 2 because the cap==0 is already mention in the base case and if we run from 0 to 2 and we try to access the value cap-1 in cap=0 then it gives run time error for trying to access the negative index...

*/

// in the tabulation as I mention in the previous question of stock all the loops (idx, cap) are reversed in but the currstate loop will remain same i.e (1, 2) because whether it is tabulation or memoiazation we have to first buy and then only we can able to sell.....

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));

    // base cases...

    // if cap == 0 return 0..
    for (int idx = 0; idx <= n; idx++)
    {
        for (int currstate = 0; currstate <= 1; currstate++)
            dp[idx][currstate][0] = 0;
    }

    // if idx == n return 0..
    for (int currstate = 0; currstate <= 1; currstate++)
    {
        for (int cap = 0; cap <= 2; cap++)
            dp[n][currstate][cap] = 0;
    }

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int currstate = 0; currstate <= 1; currstate++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                int profit = 0;
                if (currstate == 1)
                {
                    int nontake = 0 + dp[idx + 1][1][cap];
                    int take = -prices[idx] + dp[idx + 1][0][cap];
                    profit = max(take, nontake);
                }
                else if (currstate == 0)
                {
                    int nontake = 0 + dp[idx + 1][0][cap];
                    int take = prices[idx] + dp[idx + 1][1][cap - 1];
                    profit = max(take, nontake);
                }

                dp[idx][currstate][cap] = profit;
            }
        }
    }

    return dp[0][1][2];
}

// space optimiazation.....

// in case of 3d dp --> reduce it to 2 2d dp vector<vector<int>> instead of using the 3d dp ..

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> prev(2, vector<int>(3, -1));
    vector<vector<int>> prev2(2, vector<int>(3, -1));

    // base cases....
    for (int currstate = 0; currstate <= 1; currstate++)
        prev[currstate][0] = 0;

    for (int currstate = 0; currstate <= 1; currstate++)
    {
        for (int cap = 0; cap <= 2; cap++)
            prev[currstate][cap] = 0;
    }

    for (int idx = n - 1; idx >= 0; idx--)
    {
        vector<vector<int>> curr(2, vector<int>(3, 0));
        for (int currstate = 0; currstate <= 1; currstate++)
        {
            for (int cap = 1; cap <= 2; cap++)
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
    return prev[1][2];
}
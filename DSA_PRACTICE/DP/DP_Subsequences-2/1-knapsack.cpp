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
 in this question our main target is to maximize the value which we can generate so that the bag is capable of fit that much amount in the bag....
 the maxweight denotes the maximum weight that our bag can carry....
*/

// simple recursive solution.....
int helper(int idx, vector<int> &weight, vector<int> &value, int maxWeight)
{
    if (idx == 0)
    {
        if (maxWeight >= weight[0])
            return value[0];
        else
            return 0;
    }

    int nontake = 0 + helper(idx - 1, weight, value, maxWeight);
    int take = INT_MIN;
    if (weight[idx] <= maxWeight)
    {
        take = value[idx] + helper(idx - 1, weight, value, maxWeight - weight[idx]);
    }
    int ans = max(take, nontake);
    return ans;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    int ans = helper(n - 1, weight, value, maxWeight);
    return ans;
}

// memoization....

int helper(int idx, vector<int> &weight, vector<int> &value, int mxweight, vector<vector<int>> &dp)
{
    // base cases.....
    if (idx == 0)
    {
        if (mxweight >= weight[0])
            return value[0];
        else
            return 0;
    }
    if (dp[idx][mxweight] != -1)
        return dp[idx][mxweight];

    int nontake = 0 + helper(idx - 1, weight, value, mxweight, dp);
    int take = INT_MIN;
    if (weight[idx] <= mxweight)
        take = value[idx] + helper(idx - 1, weight, value, mxweight - weight[idx], dp);

    int ans = max(take, nontake);
    return dp[idx][mxweight] = ans;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    int ans = helper(n - 1, weight, value, maxWeight, dp);
    return ans;
}

// tabulation......
/*
in tabulation first we have to handle the base case then we have to reverse the variables range value in the loops ......
in memoiazation idx : (n-1, 0) , mxweight : (mxweight, 0)
in tabulation idx : (0, n-1) , mxweight : (0, mxweight)
*/

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));

    // base cases......
    for (int i = weight[0]; i <= maxWeight; i++)
        dp[0][i] = value[0];

    for (int idx = 1; idx < n; idx++)
    {
        for (int wt = 0; wt <= maxWeight; wt++)
        {
            int nontake = 0 + dp[idx - 1][wt];
            int take = INT_MIN;
            if (weight[idx] <= wt)
                take = value[idx] + dp[idx - 1][wt - weight[idx]];
            int ans = max(take, nontake);
            dp[idx][wt] = ans;
        }
    }
    return dp[n - 1][maxWeight];
}
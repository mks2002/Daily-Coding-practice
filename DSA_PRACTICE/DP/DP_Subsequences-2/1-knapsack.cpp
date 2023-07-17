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
 the maxweight denotes the maximum weight that our bag can carry i.e. it is the capacity of our bag......
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

// whenever for computing the main answer we have to take the sum then in tabulation we initialize our dp array with 0 instead of initialize it with (-1) , because in many cases it will give wrong answer if we initialize it with -1 ......

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

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

// space optimizing using normal approach ........

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0), prev2(maxWeight + 1, -1);

    for (int i = weight[0]; i <= maxWeight; i++)
        prev[i] = value[0];

    for (int idx = 1; idx < n; idx++)
    {
        vector<int> curr(maxWeight + 1, 0);
        for (int wt = 0; wt <= maxWeight; wt++)
        {
            int nontake = 0 + prev[wt];
            int take = INT_MIN;
            if (weight[idx] <= wt)
                take = value[idx] + prev[wt - weight[idx]];

            int ans = max(take, nontake);
            curr[wt] = ans;
        }

        prev2 = prev;
        prev = curr;
    }

    return prev[maxWeight];
}

// space optimization using single array.........

// for doing this we only use the prev array no curr array or not the prev2 array , and for doing this when we fill the curr array in the nested loop instead of filling that curr array we start changing the prev array and for this to work properly we have to run the nested loop from the right to left direction instead of left to right , because if we run the nested loop ( 0 to mxweight ) i.e. left to right than we already override the prev value before using it for calculating the current value so it will give wrong answer , so for this to work properly we have to run the nested loop from right to left..................

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);
    for (int i = weight[0]; i <= maxWeight; i++)
        prev[i] = value[0];

    for (int idx = 1; idx < n; idx++)
    {
        for (int wt = maxWeight; wt >= 0; wt--)
        {
            int nontake = 0 + prev[wt];
            int take = INT_MIN;
            if (weight[idx] <= wt)
                take = value[idx] + prev[wt - weight[idx]];
            int ans = max(take, nontake);
            prev[wt] = ans;
        }
    }

    return prev[maxWeight];
}
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

// subset sum equal to k if present return true else return false.....

// simple recursive approach...

bool helper(int idx, int target, vector<int> &arr)
{
    if (target == 0)
        return true;
    if (idx == 0)
        return (arr[idx] == target);

    bool nontake = helper(idx - 1, target, arr);
    bool take = false;
    if (arr[idx] <= target)
        take = helper(idx - 1, target - arr[idx], arr);

    bool ans = take or nontake;
    return ans;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    bool ans = helper(n - 1, k, arr);
    return ans;
}

// memoiazation.....

bool helper(int idx, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (idx == 0)
        return (arr[0] == target);

    if (dp[idx][target] != -1)
        return dp[idx][target];

    bool nontake = helper(idx - 1, target, arr, dp);
    bool take = false;
    if (arr[idx] <= target)
        take = helper(idx - 1, target - arr[idx], arr, dp);

    bool ans = take or nontake;
    return dp[idx][target] = ans;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    bool ans = helper(n - 1, k, arr, dp);
    return ans;
}

// tabulation....

/*
the second parameter of the dp array is denoting the target value so according to second base case 
if (idx == 0)
return (arr[0] == target);

so if we have to convert it to into tabulation then for that we can do is when the target is equal to arr[0] then at particular that cell of the dp we have to make it true 

hence dp[0][arr[0]]= true 
and this index is only available if the arr[0]<=target because we declare the size of dp array (n* target+1)..

*/
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // base case.....
    for (int i = 0; i < n; i++)    // if the target is 0 , then whatever be the value of idx it is true......
        dp[i][0] = true;

    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int idx = 1; idx < n; idx++)
    {
        for (int target = 1; target <= k; target++)
        {

            bool notTaken = dp[idx - 1][target];

            bool taken = false;
            if (arr[idx] <= target)
                taken = dp[idx - 1][target - arr[idx]];
            bool ans = notTaken or taken;
            dp[idx][target] = ans;
        }
    }

    return dp[n - 1][k];
}

// space optimiazation......

// in case of space optimization one thing that we have to take care of is that all the vectors which we use like prev, prev2 and curr there first value must be equal to true and rest others are false because in our base case of tabulation as we see that for all indices where the target is 0 that is true so we have to mark all the vectors first index here as true....

// whenever we declare prev and curr we have to make there first element as true....

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, false);
    vector<bool> prev2(k + 1, false);

    // base cases....
    prev[0] = true;

    if (arr[0] <= k)
        prev[arr[0]] = true;

    for (int idx = 1; idx < n; idx++)
    {
        vector<bool> curr(k + 1, false);
        curr[0] = true;

        for (int target = 1; target <= k; target++)
        {
            bool nontake = prev[target];
            bool take = false;
            if (arr[idx] <= target)
                take = prev[target - arr[idx]];
            bool ans = take or nontake;
            curr[target] = ans;
        }
        prev2 = prev;
        prev = curr;
    }

    return prev[k];
}
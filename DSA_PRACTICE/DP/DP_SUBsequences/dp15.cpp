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

// minimmum absolute difference between subsets.....

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int k = sum;

    // calling the tabulation method....
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // base case.....
    for (int i = 0; i < n; i++)
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

    int minans = 1e9;
    for (int i = 0; i <= sum; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int s1 = i;
            int s2 = sum - i;
            minans = min(minans, abs(s1 - s2));
        }
    }

    return minans;
}

// we can also use space optimization in this.....

vector<bool> subsetSumToK(int n, int k, vector<int> &arr)
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

    return prev;
}

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    vector<bool> ans = subsetSumToK(n, sum, arr);

    int minans = 1e8;

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == true)
        {
            int s1 = i;
            int s2 = sum - i;
            minans = min(minans, abs(s1 - s2));
        }
    }

    return minans;
}
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

// count partitions of an array into 2 subsets such that their difference is equal to a given value --> s1 - s2 = d and s1 >= s2 ....

/*
intution...

s1 and s2 are 2 parts of the array so s1+ s2 = total sum .

let totalsum of array = st
hence s1+ s2 =st   --> s1= st -s2

we have to find s1 - s2 =d --> st - s2 - s2  = d --> st - 2*s2 =d --> s2 =(st- d)/2

hence s2 = (totalsum - d)/2

so the question comes down to we have to calculate the total no of subsequence having sum s2= (total - d)/2..

*/

// code of dp 16...

int helper(int idx, vector<int> &arr, int target, vector<vector<int>> &dp)
{

    if (idx == 0)
    {
        if (target == 0 and arr[0] == 0)
            return 2;
        if (target == 0 or target == arr[0])
            return 1;
        else
            return 0;
    }

    if (dp[idx][target] != -1)
        return dp[idx][target];

    int mod = 1e9 + 7;

    int nontake = helper(idx - 1, arr, target, dp) % mod;
    int take = 0;
    if (arr[idx] <= target)
        take = helper(idx - 1, arr, target - arr[idx], dp) % mod;
    int ans = (take + nontake) % mod;

    return dp[idx][target] = ans % mod;
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int mod = 1e9 + 7;

    if (sum - d < 0 or (sum - d) % 2 != 0)
        return 0;

    int requiresum = (sum - d) / 2;

    vector<vector<int>> dp(n, vector<int>(requiresum + 1, -1));
    int ans = helper(n - 1, arr, requiresum, dp) % mod;

    return ans;
}
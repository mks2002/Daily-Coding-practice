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

// count subsets with sum k .....

// simple recursive solution.....

int helper(int idx, vector<int> &arr, int target)
{
    if (target == 0)
        return 1;

    if (idx == 0)
        return arr[0] == target;

    int nontake = helper(idx - 1, arr, target);
    int take = 0;
    if (arr[idx] <= target)
        take = helper(idx - 1, arr, target - arr[idx]);

    int ans = take + nontake;
    return ans;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    int ans = helper(n - 1, num, tar);
    return ans;
}

// memoization......

int helper(int idx, vector<int> &arr, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;
    if (idx == 0)
        return arr[0] == target;

    if (dp[idx][target] != -1)
        return dp[idx][target];

    int nontake = helper(idx - 1, arr, target, dp);
    int take = 0;
    if (arr[idx] <= target)
        take = helper(idx - 1, arr, target - arr[idx], dp);

    int ans = take + nontake;

    return dp[idx][target] = ans;
}

int findWays(vector<int> &num, int tar)
{

    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    int ans = helper(n - 1, num, tar, dp);
    return ans;
}

// tabulation.......

/*
1. the target loop will always run from 1 to target not from 0 to target....
2. in this question we have to initialize the dp array with 0 not -1 , if we initialize it with -1 then it will wrong answer because here we have to add the older values with the new values....
*/

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    // base cases...
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (num[0] <= tar)
        dp[0][num[0]] = 1;
        

    for (int idx = 1; idx < n; idx++)
    {
        for (int target = 1; target <= tar; target++)
        {
            int nontake = dp[idx - 1][target];
            int take = 0;
            if (num[idx] <= target)
                take = dp[idx - 1][target - num[idx]];

            int ans = take + nontake;
            dp[idx][target] = ans;
        }
    }

    return dp[n - 1][tar];
}

// space optimization.......

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    int mod = 1e9 + 7;
    vector<int> prev(tar + 1, 0);
    vector<int> prev2(tar + 1, -1);

    // base cases...
    prev[0] = 1;
    if (num[0] <= tar)
        prev[num[0]] = 1;

    for (int idx = 1; idx < n; idx++)
    {
        vector<int> curr(tar + 1, 0);
        curr[0] = 1;
        for (int target = 1; target <= tar; target++)
        {
            int nontake = prev[target];
            int take = 0;
            if (num[idx] <= target)
                take = prev[target - num[idx]];
            int ans = (take + nontake) % mod;

            curr[target] = ans;
        }

        prev2 = prev;
        prev = curr;
    }
    return prev[tar] % mod;
}

/*
the all above codes are working properly if there is no 0 in the array but if the array contains 0 then the function gives wrong answer because whethere we consider the 0 into the target or not it gives the same answer again and again ex -->
input [0 ,0 ,0 ,1]  target=1
output --> 1 ( of previous code )
but here the actual outpu is 4 { [0,1] , [ 0, 0, 1] [0,0,0,1] and [1]}..

for achiving that functionality we have to remove the first base case that if target==0 return 1 because after target become 0 still we have to go deeper in the array to check whether there exist 0 or not ..

*/

// updated code....

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

    int nontake = helper(idx - 1, arr, target, dp);
    int take = 0;
    if (arr[idx] <= target)
        take = helper(idx - 1, arr, target - arr[idx], dp);
    int ans = take + nontake;

    return dp[idx][target] = ans;
}

int findWays(vector<int> &num, int tar)
{

    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    int ans = helper(n - 1, num, tar, dp);
    return ans;
}

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

// simple recursive solution .....
// it has exponential time complexity....

int helper(int i, int j, vector<int> &arr)
{
    if (i == j)
        return 0;

    int minstep = 1e9;
    for (int k = i; k <= j - 1; k++)
    {
        int currsteps = (arr[i - 1] * arr[k] * arr[j]) + helper(i, k, arr) + helper(k + 1, j, arr);

        minstep = min(minstep, currsteps);
    }

    return minstep;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    int ans = helper(1, N - 1, arr);
    return ans;
}

// memoiazation.......

// time complexity of this solution is O(n^3)....

int helper(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int minsteps = 1e9;
    for (int k = i; k < j; k++)
    {
        int currsteps = (arr[i - 1] * arr[k] * arr[j]) + helper(i, k, arr, dp) + helper(k + 1, j, arr, dp);
        minsteps = min(minsteps, currsteps);
    }

    return dp[i][j] = minsteps;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    int ans = helper(1, N - 1, arr, dp);
    return ans;
}

// tabulation.......

// in recursion the the ( i ) is going from 1 to N-1 (at max) and ( j ) is moving from (N-1) to i , j cant be less then because at any moment when it is equal to (i) it hits base case and return......

// we know that the tabulation is just opposite to the recursion and hence we have to reverse the loops of i , j in the tabulation code ....

// time complexity --> O(n^3) but no extra stack space for recursion....

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    // base case....
    for (int i = 0; i < N; i++)
        dp[i][i] = 0;

    for (int i = N - 1; i >= 1; i--)
    {
        // if we want we can start the j from i but that is the base case which we already handle so we have to start j from i+1 .....
        for (int j = i + 1; j < N; j++)
        {
            int minsteps = 1e9;
            for (int k = i; k < j; k++)
            {
                int currsteps = (arr[i - 1] * arr[k] * arr[j]) + dp[i][k] + dp[k + 1][j];
                minsteps = min(minsteps, currsteps);
            }

            dp[i][j] = minsteps;
        }
    }

    return dp[1][N - 1];
}

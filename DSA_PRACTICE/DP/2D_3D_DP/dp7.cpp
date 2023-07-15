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

// dp on grids.....

// we have to go from grid[0][0] to grid[m-1][n-1] and count all unique paths...
// only right and bottom moves are allowed...

// simple recursive solution ....

int solve(int i, int j)
{
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 or j < 0)
        return 0;

    int up = solve(i - 1, j);
    int left = solve(i, j - 1);
    int ans = up + left;
    return ans;
}

int uniquePaths(int m, int n)
{
    int ans = solve(m - 1, n - 1);
    return ans;
}



// memoiazation.....
int solve(int i, int j, vvi &dp)
{
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 or j < 0)
        return 0;

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = solve(i - 1, j, dp);
    int left = solve(i, j - 1, dp);
    int ans = up + left;
    return dp[i][j] = ans;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ans = solve(m - 1, n - 1, dp);
    return ans;
}

// tabulation.....

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j == 0)
                dp[i][j] = 0;
            else
            {
                int up = 0;
                int left = 0;

                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];

                int ans = up + left;
                dp[i][j] = ans;
            }
        }
    }
    return dp[m - 1][n - 1];
}

// space optimization.....

// we have to use 2 vectors ...
/*
dp[i]-->curr dp[i-1]=prev dp[i-2]=prev2;
after each iteration in the main outer loop ---> prev2=prev prev=curr;
*/

int uniquePaths(int m, int n)
{
    vector<int> prev(n, 0);
    vector<int> prev2(n, -1);

    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j == 0)
                curr[j] = 1;
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];
                int ans = left + up;
                curr[j] = ans;
            }
        }
        prev2 = prev;
        prev = curr;
    }
    return prev[n - 1];
}

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

// in recursive code or memoization we alwaays have to take boundary condition before returing base case....


// minimum path sum in grid.....
// from (0,0) --> (n-1,m-1)   --> only bottom and right movment is allowed..

// simple recursion....
int solve(int i, int j, vvi &grid)
{
    if (i < 0 or j < 0)
        return 1e9;
    if (i == 0 and j == 0)
        return grid[i][j];

    long up = grid[i][j] + solve(i - 1, j, grid);
    long left = grid[i][j] + solve(i, j - 1, grid);

    int ans = min(up, left);
    return ans;
}
int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = solve(n - 1, m - 1, grid);
    return ans;
}

// memoiazation....

int solve(int i, int j, vvi &grid, vvi &dp)
{
    if (i < 0 or j < 0)
        return 1e9;
    if (i == 0 and j == 0)
        return grid[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = grid[i][j] + solve(i - 1, j, grid, dp);
    int left = grid[i][j] + solve(i, j - 1, grid, dp);
    int ans = min(up, left);
    return dp[i][j] = ans;
}

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = solve(n - 1, m - 1, grid, dp);
    return ans;
}

// tabulation..........

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 and j == 0)
                dp[i][j] = grid[i][j];
            else
            {
                int left = 1e9;
                int up = 1e9;
                if (i > 0)
                    up = grid[i][j] + dp[i - 1][j];
                if (j > 0)
                    left = grid[i][j] + dp[i][j - 1];

                int ans = min(left, up);
                dp[i][j] = ans;
            }
        }
    }
    return dp[n - 1][m - 1];
}

// space optimization....
int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m, 0);
    vector<int> prev2(m, -1);

    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 and j == 0)
                curr[j] = grid[i][j];
            else
            {
                int left = 1e9;
                int up = 1e9;
                if (i > 0)
                    up = grid[i][j] + prev[j];
                if (j > 0)
                    left = grid[i][j] + curr[j - 1];
                int ans = min(up, left);
                curr[j] = ans;
            }
        }
        prev2 = prev;
        prev = curr;
    }
    return prev[m - 1];
}
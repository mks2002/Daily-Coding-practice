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

// unique paths 2 leetcode..
/*
1.. similar to the previous question but here there are cells with value 1 on which we cant travel...

2.. if any how we found any obstacle block in our path then we instantly return 0 because it cant be count in the no of possible paths...

3.. so for that we have to add only 1 extra base case in the previous code and the rest of the code remains same...
    if (i >= 0 and j >= 0 and grid[i][j] == 1)
        return 0;
*/

int solve(int i, int j, vvi &grid)
{
    if (i >= 0 and j >= 0 and grid[i][j] == 1)
        return 0;

    if (i == 0 and j == 0)
        return 1;
    if (i < 0 or j < 0)
        return 0;

    int up = solve(i - 1, j, grid);
    int left = solve(i, j - 1, grid);
    int ans = up + left;
    return ans;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    int ans = solve(n - 1, m - 1, obstacleGrid);
    return ans;
}

// memoiazation...

int solve(int i, int j, vvi &grid, vvi &dp)
{
    if (i >= 0 and j >= 0 and grid[i][j] == 1)
        return 0;
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 or j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = solve(i - 1, j, grid, dp);
    int left = solve(i, j - 1, grid, dp);
    int ans = up + left;
    return dp[i][j] = ans;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = solve(n - 1, m - 1, obstacleGrid, dp);
    return ans;
}

// tabulation....

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i >= 0 and j >= 0 and obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else if (i == 0 and j == 0)
                dp[i][j] = 1;
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
    return dp[n - 1][m - 1];
}

// space optimization...

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<int> prev(m, 0);
    vector<int> prev2(m, -1);

    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i >= 0 and j >= 0 and obstacleGrid[i][j] == 1)
                curr[j] = 0;
            else if (i == 0 and j == 0)
                curr[j] = 1;
            else
            {
                int left = 0;
                int up = 0;
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
    return prev[m - 1];
}
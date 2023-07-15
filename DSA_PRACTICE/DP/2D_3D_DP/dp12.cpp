#include <bits/stdc++.h>
using namespace std;
// #define int long long int
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

// there are total 9 recursive calls for 1 movment of first robot there is 3 corresponding movment of second robot so in total 9 recursive calls will be there....

// simple recursion.....

int helper(int i, int j1, int j2, vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if (j1 < 0 or j2 < 0 or j1 >= m or j2 >= m)
        return -1e8;

    if (i == n - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    int maxans = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1] + helper(i + 1, j1 + dj1, j2 + dj2, grid);
            else
                value = grid[i][j1] + grid[i][j2] + helper(i + 1, j1 + dj1, j2 + dj2, grid);

            maxans = max(maxans, value);
        }
    }
    return maxans;
}

int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = helper(0, 0, m - 1, grid);
    return ans;
}

// memoiazation.....
#define vvi vector<vector<vector<int>>>

int helper(int i, int j1, int j2, vector<vector<int>> &grid, vvi &dp)
{
    int n = grid.size();
    int m = grid[0].size();
    if (j1 < 0 or j2 < 0 or j1 >= m or j2 >= m)
        return -1e8;

    if (i == n - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxans = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1] + helper(i + 1, j1 + dj1, j2 + dj2, grid, dp);
            else
                value = grid[i][j1] + grid[i][j2] + helper(i + 1, j1 + dj1, j2 + dj2, grid, dp);

            maxans = max(maxans, value);
        }
    }
    return dp[i][j1][j2] = maxans;
}

int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    int ans = helper(0, 0, m - 1, grid, dp);
    return ans;
}

// tabulation.....

// since this is a 3d dp there are 3 nested loops will run for 3 variable i, j1, j2....

int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    // base case...
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxans = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value = 0;

                        // since we have to include the out of bound cases so here we need to check for it before returing...
                        if (j1 == j2)
                        {
                            if (j1 + dj1 >= 0 and j1 + dj1 < m and j2 + dj2 >= 0 and j2 + dj2 < m)
                                value = grid[i][j1] + dp[i + 1][j1 + dj1][j2 + dj2];
                            else
                                value = -1e8;
                        }
                        else
                        {
                            if (j1 + dj1 >= 0 and j1 + dj1 < m and j2 + dj2 >= 0 and j2 + dj2 < m)
                                value = grid[i][j1] + grid[i][j2] + dp[i + 1][j1 + dj1][j2 + dj2];
                            else
                                value = -1e8;
                        }

                        maxans = max(maxans, value);
                    }
                }
                dp[i][j1][j2] = maxans;
            }
        }
    }
    return dp[0][0][m - 1];
}

// space optimiazation.....
/*
in case of 1d dp --> reduce it to 2 integers variable
in case of 2d dp --> reduce it to 2 vector<int>
in case of 3d dp --> reduce it to 2 2d dp vector<vector<int>> instead of using the 3d dp ..
*/

int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> prev(m, vector<int>(m, -1));
    vector<vector<int>> prev2(m, vector<int>(m, -1));

    // base cases.....
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                prev[j1][j2] = grid[n - 1][j1];
            else
                prev[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        vector<vector<int>> curr(m, vector<int>(m, 0));
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxans = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                        {
                            if (j1 + dj1 >= 0 and j1 + dj1 < m and j2 + dj2 >= 0 and j2 + dj2 < m)
                                value = grid[i][j1] + prev[j1 + dj1][j2 + dj2];
                            else
                                value = -1e8;
                        }
                        else
                        {
                            if (j1 + dj1 >= 0 and j1 + dj1 < m and j2 + dj2 >= 0 and j2 + dj2 < m)
                                value = grid[i][j1] + grid[i][j2] + prev[j1 + dj1][j2 + dj2];
                            else
                                value = -1e8;
                        }
                        maxans = max(maxans, value);
                    }
                }
                curr[j1][j2] = maxans;
            }
        }
        prev2 = prev;
        prev = curr;
    }
    return prev[0][m - 1];
}
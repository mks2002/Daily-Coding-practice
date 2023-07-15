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

// minimum falling path sum .... leetcode.
// variable starting point and variable ending point...

int helper(int row, int col, vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    if (col < 0 or col >= m)
        return 1e5;

    if (row == 0)
        return matrix[row][col];

    int up = matrix[row][col] + helper(row - 1, col, matrix);
    int left = matrix[row][col] + helper(row - 1, col - 1, matrix);
    int right = matrix[row][col] + helper(row - 1, col + 1, matrix);
    int ans = min(up, min(left, right));
    return ans;
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int minans = INT_MAX;
    for (int j = 0; j < m; j++)
    {
        int ans = helper(n - 1, j, matrix);
        minans = min(ans, minans);
    }
    return minans;
}

// memoiazation...

int helper(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    int n = matrix.size();
    int m = matrix[0].size();
    if (col < 0 or col >= m)
        return 1e5;

    if (row == 0)
        return matrix[row][col];

    if (dp[row][col] != -1)
        return dp[row][col];

    int up = matrix[row][col] + helper(row - 1, col, matrix, dp);
    int left = matrix[row][col] + helper(row - 1, col - 1, matrix, dp);
    int right = matrix[row][col] + helper(row - 1, col + 1, matrix, dp);
    int ans = min(up, min(left, right));
    return dp[row][col] = ans;
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int minans = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int j = 0; j < m; j++)
    {
        int ans = helper(n - 1, j, matrix, dp);
        minans = min(ans, minans);
    }
    return minans;
}

// tabulation........

/*

// this tabulation code will give wrong answer because here we use 3 nested loops but in the recursive function the for loop is not part of the recursive function itself it is used in its parent function , so similarly we have to use the third loop after computing all the values of the dp table as we have done in correct tabulation code give below...


int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int minans = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(m, -1));

    // base case...
    for (int j = 0; j < m; j++)
        dp[0][j] = matrix[0][j];

    for (int k = 0; k < m; k++)
    {
        for (int row = 1; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {

                int up = matrix[row][col] + dp[row - 1][col];
                int left = INT_MAX, right = INT_MAX;

                if (col > 0)
                    left = matrix[row][col] + dp[row - 1][col - 1];
                if (col < m - 1)
                    right = matrix[row][col] + dp[row - 1][col + 1];

                int ans = min(up, min(left, right));
                minans = min(ans, minans);
                dp[row][col] = minans;
            }
        }
    }
    return dp[n - 1][m - 1];
}

*/

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int minans = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(m, -1));

    // base case...
    for (int j = 0; j < m; j++)
        dp[0][j] = matrix[0][j];

    for (int row = 1; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            int up = matrix[row][col] + dp[row - 1][col];
            int left = INT_MAX, right = INT_MAX;

            if (col > 0)
                left = matrix[row][col] + dp[row - 1][col - 1];
            if (col < m - 1)
                right = matrix[row][col] + dp[row - 1][col + 1];

            int ans = min(up, min(left, right));
            dp[row][col] = ans;
        }
    }

    for (int k = 0; k < m; k++)
    {
        minans = min(minans, dp[n - 1][k]);
    }

    return minans;
}

// space optimiazation.....

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int minans = INT_MAX;

    vector<int> prev(m, 0);
    vector<int> prev2(m, -1);

    // base case...

    for (int j = 0; j < m; j++)
        prev[j] = matrix[0][j];

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + prev[j];
            int left = INT_MAX, right = INT_MAX;
            if (j > 0)
                left = matrix[i][j] + prev[j - 1];
            if (j < m - 1)
                right = matrix[i][j] + prev[j + 1];

            int ans = min(up, min(left, right));
            curr[j] = ans;
        }

        prev2 = prev;
        prev = curr;
    }

    for (int k = 0; k < m; k++)
    {
        minans = min(minans, prev[k]);
    }
    return minans;
}
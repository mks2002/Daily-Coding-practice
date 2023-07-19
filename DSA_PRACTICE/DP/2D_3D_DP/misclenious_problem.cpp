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

// Paths in Matrix Whose Sum Is Divisible by K........

// in question it is given we have to go from (0,0) --> (n-1,m-1)  but we do in reverse manner.....

// simple recursive code.....

int helper(int i, int j, int pathsum, int k, vector<vector<int>> &grid, int mod)
{
    if (i < 0 or j < 0)
        return 0;
    if (i == 0 and j == 0)
    {
        pathsum += grid[i][j];
        if (pathsum % k == 0)
            return 1;
        else
            return 0;
    }

    int up = helper(i - 1, j, pathsum + grid[i][j], k, grid, mod) % mod;
    int left = helper(i, j - 1, pathsum + grid[i][j], k, grid, mod) % mod;

    int ans = (up + left) % mod;
    return ans;
}

int numberOfPaths(vector<vector<int>> &grid, int k)
{
    int n = grid.size(), m = grid[0].size();
    int pathsum = 0;
    int mod = 1e9 + 7;
    int ans = helper(n - 1, m - 1, pathsum, k, grid, mod) % mod;
    return ans % mod;
}

// memoiazation ....

// here we can see there is 3 changing variables i, j , pathsum so we have to use a 3d dp to memoize this solution but the value of pathsum can be any thing (it might be very large) so we cant declare a such a dp array of infinit size so what we do is we know the range of k which is upto 50 each time so our dp size is (n*m*51) and each time when the pathsum value is exceeds the k during storing it we take the modulo of it with k......

// this memoization code is perfectly working.....

int helper(int i, int j, int pathsum, int k, vector<vector<int>> &grid, int mod, vector<vector<vector<int>>> &dp)
{
    if (i < 0 or j < 0)
        return 0;
    if (i == 0 and j == 0)
    {
        pathsum += grid[i][j];
        if (pathsum % k == 0)
            return 1;
        else
            return 0;
    }
    if (dp[i][j][pathsum % k] != -1)
        return dp[i][j][pathsum % k];

    int up = helper(i - 1, j, pathsum + grid[i][j], k, grid, mod, dp) % mod;
    int left = helper(i, j - 1, pathsum + grid[i][j], k, grid, mod, dp) % mod;

    int ans = (up + left) % mod;
    return dp[i][j][pathsum % k] = ans % mod;
}

int numberOfPaths(vector<vector<int>> &grid, int k)
{
    int n = grid.size(), m = grid[0].size();
    int pathsum = 0;
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(51, -1)));
    int ans = helper(n - 1, m - 1, pathsum, k, grid, mod, dp) % mod;
    return ans % mod;
}

// here we take the third parameter of dp array as 51 because the range of k is from 0 to 50 .....



/*

// another way to write the same recursive code just changing the initial values.....
// this is wrong approach becuase here we without knowing the current value of (i-1) or (j-1) we directly try to access grid[i-1][j-1] so it will give error....

int helper(int i, int j, int pathsum, int k, vector<vector<int>> &grid)
{
    if (i < 0 or j < 0)
        return 0;
    if (i == 0 and j == 0)
    {
        if (pathsum % k == 0)
            return 1;
        else
            return 0;
    }

    int up = helper(i - 1, j, pathsum + grid[i-1][j], k, grid);
    int left = helper(i, j - 1, pathsum + grid[i][j-1], k, grid);

    int ans = up + left;
    return ans;
}

int numberOfPaths(vector<vector<int>> &grid, int k)
{
    int n = grid.size(), m = grid[0].size();
    int pathsum = grid[n-1][m-1];
    int ans = helper(n - 1, m - 1, pathsum, k, grid);
    return ans;
}

*/




// this tabulation code gives wrong answer for 1 sample test case.....
int numberOfPaths(vector<vector<int>> &grid, int k)
{
    int n = grid.size(), m = grid[0].size();
    int pathsum = 0, mod = 1e9 + 7;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(51, -1)));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int pathsum = k; pathsum >= 0; pathsum--)
            {
                if (i == 0 or j == 0)
                {
                    if ((pathsum + grid[i][j]) % k == 0)
                        dp[i][j][pathsum % k] = 1;
                    else
                        dp[i][j][pathsum % k] = 0;
                }
                else
                {
                    int up = 0, left = 0;
                    if (i > 0)
                        up = dp[i - 1][j][(pathsum + grid[i][j]) % k];
                    if (j > 0)
                        left = dp[i][j - 1][(pathsum + grid[i][j]) % k];

                    int ans = (left % mod + up % mod) % mod;
                    dp[i][j][pathsum % k] = ans;
                }
            }
        }
    }
    return dp[n - 1][m - 1][0];
}

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

// we have to return the total no of strictly increasing path from any cell to any other cell from one cell to that particular cell is also considered as a path of length 1...

#define vvi vector<vector<int>>

int mod = 1e9 + 7;
vector<int> r = {0, -1, 0, 1};
vector<int> c = {-1, 0, 1, 0};

bool isvailed(int x, int y, vvi &grid)
{
    if (x < 0 or x >= grid.size() or y < 0 or y >= grid[0].size())
    {
        return false;
    }

    return true;
}

int dfs(int row, int col, vvi &grid, vvi &dp)
{
    if (dp[row][col] != -1)
        return dp[row][col];

    // the answer is initialized with 1 not 0 because if we take only that particular cell grid[row][col] then for that also it is considered as a path of length 1 ....
    int ans = 1;
    for (int i = 0; i < 4; i++)
    {
        int newrow = row + r[i];
        int newcol = col + c[i];
        if (isvailed(newrow, newcol, grid) == true and grid[newrow][newcol] > grid[row][col])
        {
            ans = (ans % mod + dfs(newrow, newcol, grid, dp) % mod) % mod;
        }
    }

    return dp[row][col] = ans % mod;
}

int countPaths(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            count = (count % mod + dfs(i, j, grid, dp) % mod) % mod;
        }
    }
    return count % mod;
}



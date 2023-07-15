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

// traingel leetcode.....

// fixed starting point but varaible ending point...

// in all the previous questions of grid we start from the back and try to go to the first but here we start from the start because if we try to start from the end there are multiple starting points in the last row which is not prefarable...

// simple recursion.....

int helper(int row, int col, int n, vector<vector<int>> &triangele)
{
    if (row == n - 1)
        return triangele[row][col];

    int down = triangele[row][col] + helper(row + 1, col, n, triangele);
    int diagonal = triangele[row][col] + helper(row + 1, col + 1, n, triangele);

    int ans = min(down, diagonal);
    return ans;
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    int ans = helper(0, 0, n, triangle);
    return ans;
}

// memoiazation...

int helper(int row, int col, int n, vector<vector<int>> &triangele, vector<vector<int>> &dp)
{
    if (row == n - 1)
        return triangele[row][col];

    if (dp[row][col] != -1)
        return dp[row][col];

    int down = triangele[row][col] + helper(row + 1, col, n, triangele, dp);
    int diagonal = triangele[row][col] + helper(row + 1, col + 1, n, triangele, dp);

    int ans = min(down, diagonal);
    return dp[row][col] = ans;
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = helper(0, 0, n, triangle, dp);
    return ans;
}


// tabulation......

// since we know that the tabulation is the opposite of the memoiazation thats why when we write the memoiazation from the ending side the tabulation we write from the starting side , but here we write the memoiazation from the starting side so the tabulation will be from ending side , i.e. we have to write the tabulation for the last row and then we have to run a loop from n-2 to 0 , the loops will run in the reverse direction so that the tabulation is exactly the opposite of the memoiazation...

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    // base case..
    for (int j = 0; j < n; j++)
        dp[n - 1][j] = triangle[n - 1][j];

    // both the loops will run in opposite manner...
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            int ans = min(down, diagonal);
            dp[i][j] = ans;
        }
    }

    //    here the answer is stored in the first row , first col of the dp...
    return dp[0][0];
}

// space optimiazation.....

/*
in this kind of reverse tabulation if we want to convert it into the space optimiazation we have to convert
 --->   dp[i+1][j]= prev[j]

*/

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> prev(n, 0);
    vector<int> prev2(n, -1);

    for (int j = 0; j < n; j++)
        prev[j] = triangle[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> curr(n, 0);
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + prev[j];
            int diagonal = triangle[i][j] + prev[j + 1];
            int ans = min(down, diagonal);
            curr[j] = ans;
        }

        prev2 = prev;
        prev = curr;
    }
    return prev[0];
}
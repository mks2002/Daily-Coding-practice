// NINJA's training...

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

// simple recursion....

int solve(int day, int last, vector<vector<int>> &points)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(points[0][i], maxi);
            }
        }
        return maxi;
    }

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        int current = 0;
        if (i != last)
        {
            current = points[day][i] + solve(day - 1, i, points);
        }
        maxi = max(maxi, current);
    }
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    int ans = solve(n - 1, 3, points);
    return ans;
}

// using memoiazation......

int solve(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(points[0][i], maxi);
            }
        }
        return maxi;
    }

    if (dp[day][last] != -1)
        return dp[day][last];

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        int current = 0;
        if (i != last)
        {
            current = points[day][i] + solve(day - 1, i, points, dp);
        }
        maxi = max(maxi, current);
    }

    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    int ans = solve(n - 1, 3, points, dp);
    return ans;
}

// tabulation.....

// in 2d dp tabulation we have to use 2 nested loops for 2 variables......
// in tabulation we have to replace the function calls by dp array...

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int days = 1; days < n; days++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[days][last] = 0;

            // this entire thing we just copy from the memoization....
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                int current = 0;
                if (task != last)
                {
                    current = points[days][task] + dp[days - 1][task];
                }
                maxi = max(maxi, current);
            }

            dp[days][last] = maxi;
        }
    }
    return dp[n - 1][3];
}

// space optimization....

/*
in case of 1d dp space optimization we use 2 variables instead of using an entire array similarly in case of 2d dp space optimization we use 2 1d array instead of using the entire 2d array...

dp[days]   --> curr
dp[days-1] --> prev
dp[days-2] --> prev2
*/

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);
    vector<int> prev2(4, 0);

    // base case...
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int days = 1; days < n; days++)
    {
        // declaring the current variable...
        vector<int> current(4, 0);

        for (int last = 0; last < 4; last++)
        {

            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                int temp = 0;
                if (task != last)
                {
                    temp = points[days][task] + prev[task];
                }
                maxi = max(maxi, temp);
            }

            current[last] = maxi;
        }

        //  common steps of space optimization.....
        prev2 = prev;
        prev = current;
    }

    return prev[3];
}

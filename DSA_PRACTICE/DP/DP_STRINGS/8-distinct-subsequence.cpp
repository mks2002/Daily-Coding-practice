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

// simple recursive solution ....

int helper(int idx1, int idx2, string &s1, string &s2)
{
    // base cases....
    if (idx2 < 0)
        return 1;
    if (idx1 < 0)
        return 0;

    int ans = 0;
    if (s1[idx1] == s2[idx2])
        ans = helper(idx1 - 1, idx2 - 1, s1, s2) + helper(idx1 - 1, idx2, s1, s2);
    else if (s1[idx1] != s2[idx2])
        ans = helper(idx1 - 1, idx2, s1, s2);

    return ans;
}

int numDistinct(string s, string t)
{
    int n = s.length(), m = t.length();
    int ans = helper(n - 1, m - 1, s, t);
    return ans;
}

// memoiazation .....

int helper(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
{
    // base cases .....
    if (idx2 < 0)
        return 1;
    if (idx1 < 0)
        return 0;
    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    int ans = 0;
    if (s1[idx1] == s2[idx2])
        ans = helper(idx1 - 1, idx2 - 1, s1, s2, dp) + helper(idx1 - 1, idx2, s1, s2, dp);
    else if (s1[idx1] != s2[idx2])
        ans = helper(idx1 - 1, idx2, s1, s2, dp);

    return dp[idx1][idx2] = ans;
}

int numDistinct(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = helper(n - 1, m - 1, s, t, dp);
    return ans;
}

// the previous 1 is 0 based indexing , we have to convert it to 1 based indexing so that we can apply tabulation and space optimization , because in 0 based indexing we require the negative index value in base case which is not possible in this both cases ....

int helper(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
{
    // base cases .....
    if (idx2 == 0)
        return 1;
    if (idx1 == 0)
        return 0;
    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    int ans = 0;
    if (s1[idx1 - 1] == s2[idx2 - 1])
        ans = helper(idx1 - 1, idx2 - 1, s1, s2, dp) + helper(idx1 - 1, idx2, s1, s2, dp);
    else if (s1[idx1 - 1] != s2[idx2 - 1])
        ans = helper(idx1 - 1, idx2, s1, s2, dp);

    return dp[idx1][idx2] = ans;
}

int numDistinct(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int ans = helper(n, m, s, t, dp);
    return ans;
}

// tabulation .....

// in the second base case of the tabulation we have to start our idx2 value from 1 to m not from (0 to m ) , because in the first base case we already set the value of idx2=0 , that is equal to 1 , so if we again make it 0 then for the dp[0][0] it become equals to 0 from 1 , which gives wrong answer ....

// in the tabulation we have to store the data into double , because for int and long long it gives wrong answer ....

int numDistinct(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, -1));

    // base case .....
    for (int idx1 = 0; idx1 <= n; idx1++)
        dp[idx1][0] = 1;
    for (int idx2 = 1; idx2 <= m; idx2++)
        dp[0][idx2] = 0;

    for (int idx1 = 1; idx1 <= n; idx1++)
    {
        for (int idx2 = 1; idx2 <= m; idx2++)
        {
            double ans = 0;
            if (s[idx1 - 1] == t[idx2 - 1])
                ans = dp[idx1 - 1][idx2 - 1] + dp[idx1 - 1][idx2];
            else if (s[idx1 - 1] != t[idx2 - 1])
                ans = dp[idx1 - 1][idx2];

            dp[idx1][idx2] = ans;
        }
    }

    return dp[n][m];
}

// space optimization ........

// because of the first base case of the tabulation we have to always make first element of the prev and curr as 1 ...

int numDistinct(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<double> prev(m + 1, -1), prev2(m + 1, -1);

    // base cases......
    prev[0] = 1;
    for (int idx2 = 1; idx2 <= m; idx2++)
        prev[idx2] = 0;

    for (int idx1 = 1; idx1 <= n; idx1++)
    {
        vector<double> curr(m + 1, 0);
        curr[0] = 1;
        for (int idx2 = 1; idx2 <= m; idx2++)
        {
            double ans = 0;
            if (s[idx1 - 1] == t[idx2 - 1])
                ans = prev[idx2 - 1] + prev[idx2];
            else if (s[idx1 - 1] != t[idx2 - 1])
                ans = prev[idx2];

            curr[idx2] = ans;
        }
        prev2 = prev;
        prev = curr;
    }

    return prev[m];
}

// now here if we want we can remove the prev2 , then it will take only 2 vectors , because here we have to manage only 1 previous states .....

// 1 vector space optimization ......

int numDistinct(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<double> prev(m + 1, -1);

    // base case ...
    prev[0] = 1;
    for (int idx2 = 1; idx2 <= m; idx2++)
        prev[idx2] = 0;

    for (int idx1 = 1; idx1 <= n; idx1++)
    {
        for (int idx2 = 1; idx2 <= m; idx2++)
        {
            double ans = 0;

            if (s[idx1 - 1] == t[idx2 - 1])
                ans = prev[idx2 - 1] + prev[idx2];
            else if (s[idx1 - 1] != t[idx2 - 1])
                ans = prev[idx2];
            
                
        }
    }
}
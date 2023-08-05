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

int helper(int idx1, int idx2, string &s1, string &s2)
{
    if (idx1 < 0)
        return idx2 + 1;
    if (idx2 < 0)
        return idx1 + 1;

    int ans = 0;
    if (s1[idx1] == s2[idx2])
        ans = 0 + helper(idx1 - 1, idx2 - 1, s1, s2);
    else if (s1[idx1] != s2[idx2])
    {
        int insert = 1 + helper(idx1, idx2 - 1, s1, s2);
        int delet = 1 + helper(idx1 - 1, idx2, s1, s2);
        int replace = 1 + helper(idx1 - 1, idx2 - 1, s1, s2);

        ans = min(insert, min(delet, replace));
    }

    return ans;
}

int minDistance(string word1, string word2)
{
    int n = word1.length(), m = word2.length();
    int ans = helper(n - 1, m - 1, word1, word2);
    return ans;
}

// memoization .....

int helper(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (idx1 < 0)
        return idx2 + 1;
    if (idx2 < 0)
        return idx1 + 1;
    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    int ans = 0;
    if (s1[idx1] == s2[idx2])
        ans = 0 + helper(idx1 - 1, idx2 - 1, s1, s2, dp);
    else if (s1[idx1] != s2[idx2])
    {
        int insert = 1 + helper(idx1, idx2 - 1, s1, s2, dp);
        int delet = 1 + helper(idx1 - 1, idx2, s1, s2, dp);
        int replace = 1 + helper(idx1 - 1, idx2 - 1, s1, s2, dp);

        ans = min(insert, min(delet, replace));
    }

    return dp[idx1][idx2] = ans;
}

int minDistance(string word1, string word2)
{
    int n = word1.length(), m = word2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = helper(n - 1, m - 1, word1, word2, dp);
    return ans;
}

// memoization for 1 based index.......

int helper(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (idx1 == 0)
        return idx2;
    if (idx2 == 0)
        return idx1;
    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    int ans = 0;
    if (s1[idx1 - 1] == s2[idx2 - 1])
        ans = 0 + helper(idx1 - 1, idx2 - 1, s1, s2, dp);
    else if (s1[idx1 - 1] != s2[idx2 - 1])
    {
        int insert = 1 + helper(idx1, idx2 - 1, s1, s2, dp);
        int delet = 1 + helper(idx1 - 1, idx2, s1, s2, dp);
        int replace = 1 + helper(idx1 - 1, idx2 - 1, s1, s2, dp);

        ans = min(insert, min(delet, replace));
    }

    return dp[idx1][idx2] = ans;
}

int minDistance(string word1, string word2)
{
    int n = word1.length(), m = word2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int ans = helper(n, m, word1, word2, dp);
    return ans;
}

// tabulation .....

int minDistance(string word1, string word2)
{
    int n = word1.length(), m = word2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // base cases .....
    for (int idx2 = 0; idx2 <= m; idx2++)
        dp[0][idx2] = idx2;
    for (int idx1 = 0; idx1 <= n; idx1++)
        dp[idx1][0] = idx1;

    for (int idx1 = 1; idx1 <= n; idx1++)
    {
        for (int idx2 = 1; idx2 <= m; idx2++)
        {
            int ans = 0;
            if (word1[idx1 - 1] == word2[idx2 - 1])
                ans = 0 + dp[idx1 - 1][idx2 - 1];
            else if (word1[idx1 - 1] != word2[idx2 - 1])
            {
                int insert = 1 + dp[idx1][idx2 - 1];
                int delet = 1 + dp[idx1 - 1][idx2];
                int replace = 1 + dp[idx1 - 1][idx2 - 1];

                ans = min(insert, min(delet, replace));
            }

            dp[idx1][idx2] = ans;
        }
    }
    return dp[n][m];
}

// space optimization ........

int minDistance(string word1, string word2)
{
    int n = word1.length(), m = word2.length();
    vector<int> prev(m + 1, -1), prev2(m + 1, -1);

    // base case ....
    for (int idx2 = 0; idx2 <= m; idx2++)
        prev[idx2] = idx2;
    prev[0] = 0;

    for (int idx1 = 1; idx1 <= n; idx1++)
    {
        vector<int> curr(m + 1, 0);
        if (idx1 <= m)
            curr[idx1] = idx1;
        for (int idx2 = 1; idx2 <= m; idx2++)
        {
            int ans = 0;
            if (word1[idx1 - 1] == word2[idx2 - 1])
                ans = 0 + prev[idx2 - 1];
            else if (word1[idx1 - 1] != word2[idx2 - 1])
            {
                int insert = 1 + curr[idx2 - 1];
                int delet = 1 + prev[idx2];
                int replace = 1 + prev[idx2 - 1];

                ans = min(insert, min(delet, replace));
            }

            curr[idx2] = ans;
        }
        prev2 = prev;
        prev = curr;
    }
    return prev[m];
}

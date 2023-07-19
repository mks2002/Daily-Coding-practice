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

// printing the longest common subsequence ....

vector<vector<int>> longestCS(string &s1, string &s2)
{
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // base cases --> if (i==0 or j==0 )return 0 ....
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int idx1 = 1; idx1 <= n; idx1++)
    {
        for (int idx2 = 1; idx2 <= m; idx2++)
        {
            int ans = 0;
            if (s1[idx1 - 1] == s2[idx2 - 1])
                ans = 1 + dp[idx1 - 1][idx2 - 1];
            else if (s1[idx1 - 1] != s2[idx2 - 1])
                ans = 0 + max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);

            dp[idx1][idx2] = ans;
        }
    }

    return dp;
}

string findLCS(int n, int m, string &s1, string &s2)
{
    vector<vector<int>> dp = longestCS(s1, s2);
    int idx1 = n, idx2 = m;
    string ans;

    while (idx1 > 0 and idx2 > 0)
    {
        if (s1[idx1 - 1] == s2[idx2 - 1])
        {
            ans.push_back(s1[idx1 - 1]);
            idx1--;
            idx2--;
        }
        else
        {
            //  if (s1[idx1 - 1] != s2[idx2 - 1])....
            if (dp[idx1 - 1][idx2] > dp[idx1][idx2 - 1])
                idx1--;
            else // if (dp[idx1 - 1][idx2] < dp[idx1][idx2 - 1])
                idx2--;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// time complexity O(n* m) .....

// we cant use space optimized solution here because we need the entire 2d dp array to iterate through it ....
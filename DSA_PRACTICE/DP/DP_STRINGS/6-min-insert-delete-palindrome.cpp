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

// leetcode 583 .........

// delete operation to make s1 == s2 , in 1 operation we can delete 1 character from any 1 string .....

int lcs(string s1, string s2)
{
    int n = s1.length(), m = s2.length();

    vector<int> prev(m + 1, -1), prev2(m + 1, -1);
    for (int i = 0; i <= m; i++)
        prev[i] = 0;

    for (int idx1 = 1; idx1 <= n; idx1++)
    {
        vector<int> curr(m + 1, 0);
        for (int idx2 = 1; idx2 <= m; idx2++)
        {
            int ans = 0;
            if (s1[idx1 - 1] == s2[idx2 - 1])
                ans = 1 + prev[idx2 - 1];
            else if (s1[idx1 - 1] != s2[idx2 - 1])
                ans = 0 + max(prev[idx2], curr[idx2 - 1]);

            curr[idx2] = ans;
        }
        prev2 = prev;
        prev = curr;
    }
    return prev[m];
}

int minDistance(string word1, string word2)
{
    int lcsLength = lcs(word1, word2);
    int n = word1.length(), m = word2.length();
    int ans = (n + m) - (2 * lcsLength);
    return ans;
}

// 712. Minimum ASCII Delete Sum for Two Strings .....

int minimumDeleteSum(string s1, string s2)
{
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));

    for (int i = 1; i <= s1.size(); i++)
        dp[i][0] = dp[i - 1][0] + s1[i - 1];

    for (int j = 1; j <= s2.size(); j++)
        dp[0][j] = dp[0][j - 1] + s2[j - 1];

    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
            }
        }
    }

    return dp[s1.size()][s2.size()];
}
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

// longest palindromic subsequence .....

// in this question we are given only a singel stirng and we have to determine from all of the subsequence of that string which is one is palindrome of largest length and we have to return that length .....

/*

APPROACH -->
we have to take the main given string and we have to find the lcs of that string with its reverse string and that length of lcs is the longest palindromic subsequence for these given string .....

*/

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.length(), m = text2.length();
    vector<int> prev(m + 1, -1), prev2(m + 1, -1);

    // base case ....
    for (int j = 0; j <= m; j++)
        prev[j] = 0;

    for (int idx1 = 1; idx1 <= n; idx1++)
    {
        vector<int> curr(m + 1, 0);
        for (int idx2 = 1; idx2 <= m; idx2++)
        {
            int ans = 0;
            if (text1[idx1 - 1] == text2[idx2 - 1])
                ans = 1 + prev[idx2 - 1];
            else if (text1[idx1 - 1] != text2[idx2 - 1])
                ans = 0 + max(prev[idx2], curr[idx2 - 1]);

            curr[idx2] = ans;
        }

        prev2 = prev;
        prev = curr;
    }

    return prev[m];
}

// if we want we can use memoization and tabulation here in this question also ........
int longestPalindromeSubseq(string s)
{
    string main = s;
    reverse(s.begin(), s.end());
    int ans = longestCommonSubsequence(main, s);
    return ans;
}






// if we have to print the longest palindromic longestCommonSubsequence .....

// this is the tabulated code of the lcs ....
// for printing purpose we have to use only the tabulation.....
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

string longestPalindromePrint(string s)
{
    int n = s.length();
    string main = s;
    reverse(s.begin(), s.end());
    vector<vector<int>> dp = longestCS(main, s);
    int idx1 = n, idx2 = n;
    string ans;
    while (idx1 > 0 and idx2 > 0)
    {
        if (main[idx1 - 1] == s[idx2 - 1])
        {
            ans.push_back(main[idx1 - 1]);
            idx1--;
            idx2--;
        }
        else
        {
            // if (main[idx1 - 1] != s[idx2 - 1]).....

            if (dp[idx1 - 1][idx2] > dp[idx1][idx2 - 1])
                idx1--;
            else // if (dp[idx1 - 1][idx2] < dp[idx1][idx2 - 1])
                idx2--;
        }
    }

    reverse(ans.begin(),ans.end());
    return ans;
}
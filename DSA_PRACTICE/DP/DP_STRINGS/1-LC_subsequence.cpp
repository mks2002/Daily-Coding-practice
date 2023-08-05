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

/*

Approach -->
if the 2 indexs at both strings have same character then add +1 to our length and reduce both the indexes for the next single recusive call ..

if (s1[idx1] == s2[idx2])
   ans = 1 + f(idx1 - 1, idx2 - 1, s1, s2);

but if the characters does not match we have to call 2 further recursive calls f(idx1-1, idx2) and f(idx1, idx2-1) and then we have to take maximum from these 2 calls ..

if(s1[idx1] != s2[idx2])
   ans = 0 + max(f(idx1 - 1, idx2, s1, s2), f(idx1, idx2 - 1, s1, s2))

BASE CASE -->

once our any of the indexes become less than 0 we return 0 ..
if (idx1 < 0 or idx2 < 0)
      return 0;

// if we not include this base case still it is working properly ,and also this condition may not always encounters because it is not necessary that both indexes become 0 at the same time ..........

// if we want we can remove this base case because it will automatically take care by the recursion and when it go to idx<0 then we return 0 already....

if (idx1 == 0 and idx2 == 0)
{
    if (s1[0] == s2[0])
       return 1;
    else
       return 0;
}

// so this base case is not required , but still if we include it in our code then also there is nothing wrong with this may be it reduce the number of recursive calls slightly but there is no significany impact of this , so we not include this in our code .....

*/

// simple recursion .......

int helper(int idx1, int idx2, string &s1, string &s2)
{
    // base case ....
    if (idx1 < 0 or idx2 < 0)
        return 0;

    int ans = 0;

    if (s1[idx1] == s2[idx2])
        ans = 1 + helper(idx1 - 1, idx2 - 1, s1, s2);
    else if (s1[idx1] != s2[idx2])
        ans = 0 + max(helper(idx1 - 1, idx2, s1, s2), helper(idx1, idx2 - 1, s1, s2));

    return ans;
}

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.length(), m = text2.length();
    int ans = helper(n - 1, m - 1, text1, text2);
    return ans;
}

// memoization .....

// in memoizatin if in helper function we not pass the strings by reference then in some cases it gives tle on leetcode , so we have to pass both the string by reference in the helper function ....

// for 0 based indexing .....
int helper(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
{
    // base cases ....
    if (idx1 < 0 or idx2 < 0)
        return 0;
    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    int ans = 0;

    if (s1[idx1] == s2[idx2])
        ans = 1 + helper(idx1 - 1, idx2 - 1, s1, s2, dp);
    else if (s1[idx1] != s2[idx2])
        ans = 0 + max(helper(idx1 - 1, idx2, s1, s2, dp), helper(idx1, idx2 - 1, s1, s2, dp));

    return dp[idx1][idx2] = ans;
}

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.length(), m = text2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = helper(n - 1, m - 1, text1, text2, dp);
    return ans;
}

// this memoization is using 0 based indexing here in base case we have to include the negative values of indexes but we can not convert this to tabulation because in tabulation array we cant access the negative indexes for filling the dp table , so for that we have to convert this memoization code to 1 based indexing , so that we can convert it to tabulation easily .....

// in this conversion the states of dp and the function calls remains same , just the base case indexes changes and the indexes of the string changes .......

// memoization for 1 based indexing .....
int helper(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
{
    // base case .....
    if (idx1 == 0 or idx2 == 0)
        return 0;
    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    int ans = 0;

    if (s1[idx1 - 1] == s2[idx2 - 1])
        ans = 1 + helper(idx1 - 1, idx2 - 1, s1, s2, dp);
    else if (s1[idx1 - 1] != s2[idx2 - 1])
        ans = 0 + max(helper(idx1, idx2 - 1, s1, s2, dp), helper(idx1 - 1, idx2, s1, s2, dp));

    return dp[idx1][idx2] = ans;
}

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.length(), m = text2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int ans = helper(n, m, text1, text2, dp);
    return ans;
}

// tabulation ........

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.length(), m = text2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // base cases ---> if ( i == 0 or j == 0 )return 0 .....
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int idx1 = 1; idx1 <= n; idx1++)
    {
        for (int idx2 = 1; idx2 <= m; idx2++)
        {
            int ans = 0;
            if (text1[idx1 - 1] == text2[idx2 - 1])
                ans = 1 + dp[idx1 - 1][idx2 - 1];
            else if (text1[idx1 - 1] != text2[idx2 - 1])
                ans = 0 + max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);

            dp[idx1][idx2] = ans;
        }
    }
    return dp[n][m];
}

// space optimization .......

// in this approach when we write the base case then the second one base case is not required because here we dont have an array of size (n+1) we have all the arrays of size (m+1) , so only 1 base case is there .....

// dp[idx1 - 1][idx2 - 1] --> prev[idx2-1] , dp[idx1][idx2]= curr[idx2] .....

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
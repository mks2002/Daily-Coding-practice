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

// in this question we have to find the Longest common substring --> which means it is a contigous part from both the strings ....

// if we have to solve this using recursion then we need 3 parameters so , for that reason in this question we directly use tabulation .....

/*
APPROACH -->
in the tabulation this time it is not confirm that we got our answer at dp[n-1][m-1] because the longest common substring may be some where between 2 strings , so we have to keep a max variable initialize with 0 and each time when we found any matching character we have to stroe the max of dp[i][j] into the max variable , and if the both characters not match at point we not go for
max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
we directly put there a 0 , because here if at any point 2 characters are not match then it cant be part of the common substring ...

ex -->

s1 --> wasdijkl  , s2 --> wsdjkl
output --> 3
The longest common substring is “jkl”, of length 3.

s1 --> tyfg  , s2 --> cvbnuty
output --> 2
The longest common substring is “ty”, of length 2.
*/

// tabulation .....
int lcs(string &str1, string &str2)
{
    int n = str1.length(), m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // base cases ---> if ( i == 0 or j == 0 )return 0 .....
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    int maxi = 0;
    for (int idx1 = 1; idx1 <= n; idx1++)
    {
        for (int idx2 = 1; idx2 <= m; idx2++)
        {
            int ans = 0;
            if (str1[idx1 - 1] == str2[idx2 - 1])
                ans = 1 + dp[idx1 - 1][idx2 - 1];
            else
                ans = 0;
            maxi = max(ans, maxi);
            dp[idx1][idx2] = ans;
        }
    }

    return maxi;
}

// space optimization .....

int lcs(string &str1, string &str2)
{
    int n = str1.length(), m = str2.length();
    vector<int> prev(m + 1, -1), prev2(m + 1, -1);

    // base case ....
    for (int j = 0; j <= m; j++)
        prev[j] = 0;

    int maxi = 0;
    for (int idx1 = 1; idx1 <= n; idx1++)
    {
        vector<int> curr(m + 1, 0);
        for (int idx2 = 1; idx2 <= m; idx2++)
        {
            int ans = 0;
            if (str1[idx1 - 1] == str2[idx2 - 1])
                ans = 1 + prev[idx2 - 1];
            else
                ans = 0;
            maxi = max(maxi, ans);
            curr[idx2] = ans;
        }

        prev2 = prev;
        prev = curr;
    }
    return maxi;
}

// in this question also the prev2 is not required we just use it to maintain the flow if we want we can solve it using only prev and curr 2 vectors.....

int lcs(string &str1, string &str2)
{
    int n = str1.length(), m = str2.length();
    vector<int> prev(m + 1, -1);

    // base case ....
    for (int j = 0; j <= m; j++)
        prev[j] = 0;

    int maxi = 0;
    for (int idx1 = 1; idx1 <= n; idx1++)
    {
        vector<int> curr(m + 1, 0);
        for (int idx2 = 1; idx2 <= m; idx2++)
        {
            int ans = 0;
            if (str1[idx1 - 1] == str2[idx2 - 1])
                ans = 1 + prev[idx2 - 1];
            else
                ans = 0;

            maxi = max(maxi, ans);
            curr[idx2] = ans;
        }

        prev = curr;
    }

    return maxi;
}
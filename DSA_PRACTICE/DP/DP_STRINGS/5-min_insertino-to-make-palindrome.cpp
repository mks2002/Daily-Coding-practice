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

in this question we have to found the number of minimum character that we have to insert in a given string such that it becomes palindrom ..

APPROACH -->
in this case the maximum answer is (n) the length of original string because total characters which are in the original string if we insert them in reverse order then it becomes palindrome ..
to solve this question with minimum number of characters  we have to find the longest palindromic subsequence lenght suppose it is ( l) then the answer is (n-l) character because (n-l) are those characters who are not contribute to make a palindrom ..
so we have to insert (n-l) characters to make it palindrome ....

*/

int longestpalindrome(string &s1, string &s2)
{
    int n = s1.length();
    vector<int> prev(n + 1, -1);

    // base case ...
    for (int i = 0; i <= n; i++)
        prev[i] = 0;

    for (int idx1 = 1; idx1 <= n; idx1++)
    {
        vector<int> curr(n + 1, 0);
        for (int idx2 = 1; idx2 <= n; idx2++)
        {
            int ans = 0;
            if (s1[idx1 - 1] == s2[idx2 - 1])
                ans = 1 + prev[idx2 - 1];
            else if (s1[idx1 - 1] != s2[idx2 - 1])
                ans = 0 + max(prev[idx2], curr[idx2 - 1]);

            curr[idx2] = ans;
        }
        prev = curr;
    }
    return prev[n];
}

int palindromeLength(string &s)
{
    string main = s;
    reverse(s.begin(), s.end());
    return longestpalindrome(main, s);
}

int minInsertions(string s)
{
    int n = s.length();
    int currpalindrome = palindromeLength(s);
    int ans = n - currpalindrome;
    return ans;
}

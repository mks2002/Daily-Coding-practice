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

// longest palindromic substring ......
/*

APPROACH -->

1.  in this question first we try to find longest common substring of the given string with its reverse string ...

2. once we found the length we cant traverse on the dp array to find it because it is not in continous form like the subseqence matrix ,and also it is somewhere in the center of the matrix, so we can just calculate length of the longest palindromic substring using these function ...

3. once the lenght is calculated we traverse on each window of the string of that length and if it is palindrom return true , in case there are multiple answers then return the first once ....

*/

// this approach is wrong because of some particular test cases mentioned below .....

// this dp approach will give wrong answer .....

/*

s = "aacabdkacaa"
Stdout --> 4
Output -- > ""
Expected --> "aca"
also the length calculating with this approach is also wrong because the length is 3 but since the first and last strings matches it calculate the length = 4 ..

*/

int lcsubstring(string &s1, string &s2)
{
    int n = s1.length(), m = s2.length();
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
            if (s1[idx1 - 1] == s2[idx2 - 1])
                ans = 1 + prev[idx2 - 1];
            else
                ans = 0;

            maxi = max(ans, maxi);
            curr[idx2] = ans;
        }
        prev = curr;
    }
    return maxi;
}

bool ispalindrome(string &s)
{
    int n = s.length();
    if (n == 1)
        return true;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}

string longestPalindrome(string s)
{
    int n = s.length();
    string main = s;
    reverse(s.begin(), s.end());
    int length = lcsubstring(main, s);

    if (length == n)
        return main;

    string temp = "";
    string ans;
    for (int i = 0; i < length; i++)
        temp.push_back(main[i]);

    if (ispalindrome(temp) == true)
        return temp;

    for (int i = length; i < n; i++)
    {
        temp.push_back(main[i]);
        temp.erase(temp.begin());

        if (ispalindrome(temp) == true)
            ans = temp;
    }

    return ans;
}

// then how to solve this ......

/*
since the given length of the string in range (0 to 1000)..

so we can check for each of the substring whether it is palindrome or not and then from that we store the maximum length .......

*/

bool ispalindrome(string &s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }

    return true;
}

string longestPalindrome(string s)
{
    int n = s.length();
    int maxlength = 0;
    int startidx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (ispalindrome(s, i, j) == true)
            {
                if ((j - i + 1) > maxlength)
                {
                    maxlength = max(maxlength, (j - i + 1));
                    startidx = i;
                }
            }
        }
    }

    string ans = s.substr(startidx, maxlength);
    return ans;
}

// both the dp and this approach takes almost same time O(n^2), but the dp approach gives wrong answer in many cases ....
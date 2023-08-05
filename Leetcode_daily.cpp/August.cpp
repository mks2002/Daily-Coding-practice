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

// plane recursive solution .....

bool helper(int idx, string &s, unordered_set<string> &st)
{
    // if we traverse the entire string and not find any false then it means the segment which we choose is present in the dictonary so return true....
    if (idx == s.size())
        return true;

    string temp = "";
    for (int i = idx; i < s.size(); i++)
    {
        if ((st.find(s.substr(i, i - idx + 1)) != st.end()) and (helper(i + 1, s, st) == true))
            return true;
    }

    // in the loop if we dont find any true condition then we have to return false ....
    return false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> st;
    for (auto it : wordDict)
        st.insert(it);

    bool ans = helper(0, s, st);
    return ans;
}

// this is memoized solution .....

bool helper(int idx, string &s, unordered_set<string> &st, vector<int> &dp)
{
    if (idx == s.size())
        return true;
    if (dp[idx] != -1)
        return dp[idx];
    string temp = "";
    for (int i = idx; i < s.size(); i++)
    {
        if ((st.find(s.substr(idx, i - idx + 1)) != st.end()) and (helper(i + 1, s, st) == true))
            return dp[idx] = true;
    }

    return dp[idx] = false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> st;
    for (auto it : wordDict)
        st.insert(it);
    int n = s.size();
    vector<int> dp(n + 1, -1);
    bool ans = helper(0, s, st, dp);
    return ans;
}

int helper(int n, vector<int> &dp)
{
    if (n <= 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += helper(i - 1, dp) * helper(n - i, dp);

    return dp[n] = ans;
}

int numTrees(int n)
{
    vector<int> dp(n + 1, -1);
    int ans = helper(n, dp);
    return ans;
}
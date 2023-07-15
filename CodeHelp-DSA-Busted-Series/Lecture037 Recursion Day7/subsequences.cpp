
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

    return 0;
}

void solve(vector<string> &ans, string str, string output, int i)
{
    // base case
    if (i >= str.length())
    {
        if (output.length() > 0)
            ans.push_back(output);
        return;
    }

    // exclude
    solve(ans, str, output, i + 1);
    // include
    output.push_back(str[i]);
    solve(ans, str, output, i + 1);
}

vector<string> subsequences(string str)
{

    vector<string> ans;
    string output = "";
    solve(ans, str, output, 0);
    return ans;
}

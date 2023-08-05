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


void solve(int idx, vector<int> &nums, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        solve(idx + 1, nums, ans);
        swap(nums[idx], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> ds;
    vector<vector<int>> ans;
    solve(0, nums, ans);
    return ans;
}

void solve(int idx, string &s, vector<string> &ans)
{
    if (idx == s.size())
    {
        ans.push_back(s);
        return;
    }

    for (int i = idx; i < s.size(); i++)
    {
        swap(s[idx], s[i]);
        solve(idx + 1, s, ans);
        swap(s[idx], s[i]);
    }
}

vector<string> permutation(string S)
{
    vector<string> ans;
    solve(0, S, ans);
    return ans;
}
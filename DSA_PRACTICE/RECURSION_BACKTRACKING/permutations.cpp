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

void solve(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, vector<int> &vis)
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (vis[i] == 0)
        {
            ds.push_back(nums[i]);
            vis[i] = 1;
            solve(nums, ds, ans, vis);
            ds.pop_back();
            vis[i] = 0;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> ds;
    vector<vector<int>> ans;
    vector<int> vis(nums.size(), 0);
    solve(nums, ds, ans, vis);
    return ans;
}

void solve(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, vector<int> &vis)
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (vis[i] == 1)
            continue;
        if (i > 0 and nums[i] == nums[i - 1])
            continue;

        ds.push_back(nums[i]);
        vis[i] = 1;
        solve(nums, ds, ans, vis);
        ds.pop_back();
        vis[i] = 0;
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<int> ds;
    vector<vector<int>> ans;
    vector<int> vis(nums.size(), 0);
    sort(nums.begin(), nums.end());
    solve(nums, ds, ans, vis);
    return ans;
}
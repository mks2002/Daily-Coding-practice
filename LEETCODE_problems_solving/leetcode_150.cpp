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

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    //    for fast input output....
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, vector<string>> m;
    int n = strs.size();
    for (int i = 0; i < n; i++)
    {
        string temp = strs[i];
        sort(strs[i].begin(), strs[i].end());
        m[strs[i]].push_back(temp);
    }

    vector<vector<string>> ans;
    for (auto it : m)
    {
        ans.push_back(it.second);
    }
    return ans;
}

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

int longestConsecutive(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int lastsmaller = INT_MIN;
    int cnt = 0;
    int longest = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if ((nums[i] - 1) == lastsmaller)
        {
            cnt = cnt + 1;
            lastsmaller = nums[i];
        }
        else if ((nums[i] - 1) != lastsmaller and nums[i] == lastsmaller)
        {
            continue;
        }
        else if ((nums[i] - 1) != lastsmaller and nums[i] != lastsmaller)
        {
            cnt = 1;
            lastsmaller = nums[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}

// this is more optimized because for searching in unordered_set it takes O(1) time....
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> st;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        st.insert(nums[i]);
    }
    int longest = 0;
    int cnt = 0;
    for (auto it : st)
    {
        if (st.find(it - 1) != st.end())
        {
            continue;
        }
        else
        {
            cnt = 0;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                cnt++;
                x = x + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}
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

int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    int maxi = INT_MIN;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(nums[i]);
        maxi = max(maxi, nums[i]);
    }
    if (st.find(1) == st.end())
        return 1;
    for (int i = 2; i <= maxi; i++)
    {
        if (st.find(i) == st.end())
            return i;
    }
    // if after the entire traversal we cant find any missing number it means the number is maxi+1 ....
    return maxi + 1;
}

// maximum gap leetcode 164 ........

vector<int> countsort(vector<int> &nums)
{
    int n = nums.size();
    map<int, int> m;
    for (int i = 0; i < n; i++ )
        m[nums[i]]++;

    vector<int> ans;
    for (auto it : m)
    {
        int cnt = it.second;
        while (cnt--)
        {
            ans.push_back(it.first);
        }
    }
    return ans;
}

int maximumGap(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2)
        return 0;
    vector<int> sortednums = countsort(nums);

    int maxgap = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        int currgap = sortednums[i] - sortednums[i - 1];
        maxgap = max(maxgap, currgap);
    }

    return maxgap;
}
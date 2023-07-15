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

// 496. Next Greater Element I ............

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{

    stack<int> st;
    int n = nums2.size();
    vector<int> temp;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size() == 0)
        {
            temp.push_back(-1);
        }
        else if (!st.empty() and nums2[i] < st.top())
        {
            temp.push_back(st.top());
        }
        else if (!st.empty() and nums2[i] >= st.top())
        {
            while (!st.empty() and nums2[i] >= st.top())
            {
                st.pop();
            }
            if (st.empty())
            {
                temp.push_back(-1);
            }
            else
            {
                temp.push_back(st.top());
            }
        }

        st.push(nums2[i]);
    }

    reverse(temp.begin(), temp.end());
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[nums2[i]] = temp[i];
    }
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(m[nums1[i]]);
    }
    return ans;
}
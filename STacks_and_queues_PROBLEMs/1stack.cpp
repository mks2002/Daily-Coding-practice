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

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long> ans;
    stack<long long> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size() == 0)
        {
            ans.push_back(-1);
        }
        else if (!st.empty() and arr[i] < st.top())
        {
            ans.push_back(st.top());
        }
        else
        {
            // if st.top() <= arr[i].....
            while (!st.empty() and st.top() <= arr[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top());
            }
        }

        st.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// immidiate smaller element......

void immediateSmaller(vector<int> &arr, int n)
{
    stack<int> s;
    vector<int> v;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s.size() == 0)
            v.push_back(-1);

        else if (!s.empty() && s.top() < arr[i])
            v.push_back(s.top());

        else
            v.push_back(-1);

        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        arr[i] = v[i];
    }
}
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

// house robber 2 ...

/*
 it is similar to the previous question just the difference is here the last house is adjacent to the first house ...

approach -->

whatever is my answer it cant contain the first and last element both because they are adjacent so my answer will either contain the first element or the last element...

so I have to make 2 function calls one from (0, n-2) and other from (1, n-1) and the maximum of this 2 is my final answer...
*/

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();

    // this is the base case..
    int prev2 = 0, prev = nums[0];

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
        {
            pick = nums[i] + prev2;
        }
        int notpick = 0 + prev;

        int curr = max(pick, notpick);

        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp1, temp2;

    if (n == 1)
        return nums[0];

    // split the array ...
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(nums[i]);
        if (i != n - 1)
            temp2.push_back(nums[i]);
    }
    int ans1 = maximumNonAdjacentSum(temp1);
    int ans2 = maximumNonAdjacentSum(temp2);
    return max(ans1, ans2);
}
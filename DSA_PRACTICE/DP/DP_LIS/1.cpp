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

// Longest increasing subsequence.....

/*
Algorithm --->

1. in this type of question we have to take 2 parameter idx, previdx , where the idx is the current index and the previdx is the index of the previous element which we take...

2. to keep track of the previous index is necessary because we have to form a longest increasing sequence so for that we have to keep track of the previous element because if the previous element is greater then our current element then we cant include it in the answer otherwise it is not a increasin sequence..

*/

/*
[1,3,6,7,9,4,10,5,6]
this base case gives wrong answer for the above input the answer is 6 but this base case returns 7 ..
if (idx == nums.size() - 1)
    {
        if (nums[nums.size() - 1] > nums[nums.size() - 2])
            return 1;
        else
            return 0;
    }

if we use this if condition --->
(nums[nums.size() - 1] > nums[nums.size() - 2] and previdx==(nums.size() - 2))
        return 1;

then the above test case pass but it gives wrong answer for
[2,15,3,7,8,6,18]  expected = 5 but it gives 4 ..


we can not rely upon this kind of base cases where we directly compare the 2 consecutive indexes we need this kind of base case where we compare with the idx and the previdx ..

if (idx == nums.size() - 1)
    {
         if (previdx != -1 and nums[idx] > nums[previdx])
            return 1;
        else
            return 0;
    }

this is almost correct but except 1 case for input -->
[0] or any 1 size array it returns 0 but it must return 1...


if (idx == nums.size() - 1)
    {
        if (nums.size() == 1)
            return 1;
        else if (previdx != -1 and nums[idx] > nums[previdx])
            return 1;
        else
            return 0;
    }

this is the 2nd correct base casee which gives exactly same answer .....


*/

//  if we want we can not use 2nd base case because it is automatically take care by the first base case and if we use this base case then we can remove the first base case because if we already define base case at idx = n-1 then the recursive call never goes to idx = nums.size()....

int helper(int idx, int previdx, vector<int> &nums)
{
    if (idx == nums.size())
        return 0;

    int anslen = 0;
    int nontake = 0 + helper(idx + 1, previdx, nums);
    int take = 0;
    if (previdx == -1 or nums[idx] > nums[previdx])
    {
        // if we take this index then for next call it become the previdx and length increases by 1...
        take = 1 + helper(idx + 1, idx, nums);
    }
    anslen = max(take, nontake);
    return anslen;
}

int lengthOfLIS(vector<int> &nums)
{
    int idx = 0, previdx = -1;
    int ans = helper(idx, previdx, nums);
    return ans;
}

// memoiazation....

// since previdx value is starting from -1 and we dont have negative indexes in array so during memoization we have to replace the previdx by previdx+1 so that it works properly without any error this same kind of thing we have also done in lcs and because in worst case the previdx value can go upto n and we use previdx + 1 so the dp array size is n*(n+1).....

// if I use dp array of size n*n then also it is properly working on leetcode but for more accuracy we have to use size n*(n+1)....

int helper(int idx, int previdx, vector<int> &nums, vector<vector<int>> &dp)
{
    if (idx == nums.size())
        return 0;

    if (dp[idx][previdx + 1] != -1)
        return dp[idx][previdx + 1];

    int anslen = 0;
    int nontake = 0 + helper(idx + 1, previdx, nums, dp);
    int take = 0;
    if (previdx == -1 or nums[idx] > nums[previdx])
        take = 1 + helper(idx + 1, idx, nums, dp);

    anslen = max(take, nontake);
    return dp[idx][previdx + 1] = anslen;
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    int idx = 0, previdx = -1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans = helper(idx, previdx, nums, dp);
    return ans;
}

// method 2 using 2nd base case ........

int helper(int idx, int previdx, vector<int> &nums, vector<vector<int>> &dp)
{
    if (idx == nums.size() - 1)
    {
        if (nums.size() == 1)
            return 1;
        else if (previdx != -1 and nums[idx] > nums[previdx])
            return 1;
        else
            return 0;
    }

    if (dp[idx][previdx + 1] != -1)
        return dp[idx][previdx + 1];

    int anslen = 0;
    int nontake = 0 + helper(idx + 1, previdx, nums, dp);
    int take = 0;
    if (previdx == -1 or nums[idx] > nums[previdx])
    {
        // if we take this index then for next call it become the previdx and length increases by 1..
        take = 1 + helper(idx + 1, idx, nums, dp);
    }
    anslen = max(take, nontake);
    return dp[idx][previdx + 1] = anslen;
}

int lengthOfLIS(vector<int> &nums)
{
    int idx = 0, previdx = -1;
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    int ans = helper(idx, previdx, nums, dp);
    return ans;
}

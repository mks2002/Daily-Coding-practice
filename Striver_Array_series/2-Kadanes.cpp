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

// this is the naive approach O(n^3) ....
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += nums[k];

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

// better ---> O(n^2)...

// if we want we can remove the third loop ......
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            maxi = max(sum, maxi);
        }
    }

    return maxi;
}

// most optimized kadanes --> O(n)...

int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int maxsum = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        maxsum = max(maxsum, sum);

        // if at any time sum is less then 0 then we start it again with 0 ...
        if (sum < 0)
            sum = 0;
    }
    return maxsum;
}

// in the question if the entire array contains all negative numbers and we are allowed to return empty subarray whose sum is 0 then for that we have to add an additional check in the above function .....

int maxSubArray(vector<int> &nums)
{
    int sum = 0, maxsum = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        maxsum = max(maxsum, sum);

        if (sum < 0)
            sum = 0;
    }

    if (maxsum < 0)
        return 0;
    else
        return maxsum;
}

// now if suppose there are multiple subarrays which will give the maximus sum now we have to print any one of them.....

// 1. so to solve this one important observation is that whenever we find that sum =0 it means from here one new subarray is started ..

vector<int> maxSumarray(vector<int> &nums)
{
    int sum = 0, maxsum = INT_MIN, startidx = -1, endidx = -1;
    int currstart = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
            currstart = i;

        sum += nums[i];
        if (sum > maxsum)
        {
            maxsum = sum;
            startidx = currstart;
            endidx = i;
        }

        if (sum < 0)
            sum = 0;
    }
    vector<int> ans;
    for (int i = startidx; i <= endidx; i++)
    {
        ans.push_back(nums[i]);
    }

    return ans;
}
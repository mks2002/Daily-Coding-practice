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

// partition subsets sum into 2 equal parts......

// if we can able to found any subset whose sum is equal to s/2 then for the remaining elements of that array they must give a sum of s/2 where s is the total sum of the array and hence by doing this we can divide the array in 2 subsets having equal sum....

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, false);
    vector<bool> prev2(k + 1, false);

    // base cases....
    prev[0] = true;

    if (arr[0] <= k)
        prev[arr[0]] = true;

    for (int idx = 1; idx < n; idx++)
    {
        vector<bool> curr(k + 1, false);
        curr[0] = true;

        for (int target = 1; target <= k; target++)
        {
            bool nontake = prev[target];
            bool take = false;
            if (arr[idx] <= target)
                take = prev[target - arr[idx]];
            bool ans = take or nontake;
            curr[target] = ans;
        }
        prev2 = prev;
        prev = curr;
    }

    return prev[k];
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
        sum += nums[i];

    if (sum % 2 != 0)
        return false;
        
    bool ans = subsetSumToK(nums.size(), sum / 2, nums);
    return ans;
}
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

// this is the code studio version here we have to return all the triplets also in any order.....
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    set<vector<int>> st;
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                vector<int> temp;
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    for (auto it : st)
    {
        ans.push_back(it);
    }
    return ans;
}

// try to optimize.........

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    set<vector<int>> st;
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            // by doing this we get rid of the third loop......
            int third = -(arr[i] + arr[j]);
            // third element is already present in the array.....
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    for (auto it : st)
    {
        ans.push_back(it);
    }
    return ans;
}

// most optimized approach.....

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 and nums[i] == nums[i - 1])
            continue;
        int left = i + 1, right = n - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum < 0)
            {
                left++;
            }
            else if (sum > 0)
            {
                right--;
            }
            else
            {
                vector<int> temp = {nums[i], nums[left], nums[right]};
                ans.push_back(temp);
                left++, right--;

                // since we have to count only the unique number of pairs so if we get same numbers then we have to move our left and right pointers....
                while (left < right and nums[left] == nums[left - 1])
                    left++;
                while (left < right and nums[right] == nums[right + 1])
                    right--;
            }
        }
    }
    return ans;
}

// gfg version if we find any triplet we return true else return false......

bool findTriplets(int arr[], int n)
{
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (i > 0 and arr[i] == arr[i - 1])
            continue;
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum > 0)
            {
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}
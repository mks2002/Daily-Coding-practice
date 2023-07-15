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
#define __mayuk                      \
   ios_base::sync_with_stdio(false); \
   cin.tie(NULL);

// vector<int> twoSum(vector<int> &nums, int target)
// {
// sort(nums.begin(),nums.end());
// int s=0;
// int e=nums.size();
// while(s<=e){
// if((nums[s]+nums[e])==target){

// }
// }

int32_t main()
{
   __mayuk;

   return 0;
}

// int pivotIndex(vector<int> &nums)
// {
//    int n = nums.size();
//    int ls = 0;
//    int rs = 0;
//    int ps = 0;
//    for (int i = 0; i < n; i++)
//    {
//       ps += nums[i];
//    }
//    rs = ps;
//    for (int i = 0; i < n; i++)
//    {
//       ls + nums[i];
//       if (ls == rs)
//          retrun i;
//       rs -= nums[i];
//    }
//    return -1;
// }

int pivotIndex(vector<int> &nums)
{
   int n = nums.size();
   int sum = 0;
   vector<int> pre;
   vector<int> suf;
   for (int i = 0; i < n; i++)
   {
      sum += nums[i];
      pre.push_back(sum);
   }
   sum = 0;
   for (int i = n - 1; i >= 0; i--)
   {
      sum += nums[i];
      suf.push_back(sum);
   }
   reverse(suf.begin(), suf.end());
   for (int i = 0; i < n; i++)
   {
      if (pre[i] == suf[i])
         return i;
   }

   return -1;
}

vector<int> twoSum(vector<int> &nums, int target)
{
   int n = nums.size();
   int s = 0;
   int e = n - 1;
   while (s <= e)
   {
      int mid = s + (e - s) / 2;
   }
}

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
   int m = nums1.size();
   int n = nums2.size();
   sort(nums1.begin(), nums1.end());
   sort(nums2.begin(), nums2.end());
   vector<int> ans;
   int i = 0;
   int j = 0;

   while (i < m and j < n)
   {
      if (nums1[i] == nums2[j])
      {
         ans.push_back(nums1[i]);
         i++;
         j++;
      }
      else if (nums1[i] < nums2[j])
      {
         i++;
      }
      else
      {
         j++;
      }
   }

   return ans;
}

vector<int> twoSum(vector<int> &nums, int target)
{

   vector<int> ans;
   unordered_map<int, int> m;
   int n = nums.size();
   for (int i = 0; i < n; i++)
   {
      if (m.find(target - nums[i]) != m.end())
      {
         ans.push_back(m[nums[i]]);
         ans.push_back(i);
         return ans;
      }
      m[nums[i]] = i;
   }
   return ans;
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
   int i = m - 1;
   int j = n - 1;
   int k = m + n - 1;
   while (j >= 0 and i >= 0)
   {
      if (nums1[i] > nums2[j])
      {
         nums1[k--] = nums1[i--];
      }
      else
      {
         nums1[k--] = nums2[j--];
      }
   }
   while (i >= 0)
   {
      nums1[k--] = nums1[i--];
   }
   while (j >= 0)
   {
      nums1[k--] = nums2[j--];
   }
}

int maxProfit(vector<int> &prices)
{
   int mini = prices[0];
   int mxprofit = 0;
   int n = prices.size();
   for (int i = 1; i < n; i++)
   {
      int cost = prices[i] - mini;
      mxprofit = max(cost, mxprofit);
      mini = min(mini, prices[i]);
   }
   return mxprofit;
}
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

// given an array of distinct integers and a integer target return a list of all those unique combination whose sum is equal to the target we can choose any element any no of times.....

void helper(int idx, vector<int> &arr, int target, vector<int> &ds, vector<vector<int>> &ans)
{
   if (idx == arr.size())
   {
      if (target == 0)
      {
         ans.push_back(ds);
      }
      return;
   }

   if (arr[idx] <= target)
   {
      ds.push_back(arr[idx]);
      helper(idx, arr, target - arr[idx], ds, ans);
      ds.pop_back();
   }
   helper(idx + 1, arr, target, ds, ans);
}

vector<vector<int>> combinationsum(vector<int> &arr, int target)
{
   vector<int> ds;
   vector<vector<int>> ans;

   helper(0, arr, target, ds, ans);
   return ans;
}

// combinationsum 2..........
// similar like 1 but here the array contains duplicate element but we have to return only the unique vector<vector<int>> in the answer and we can take one element only 1 time...

// m 1.................
void helper2(int idx, vi &arr, int target, vi &ds, set<vector<int>> &temp)
{
   if (idx == arr.size())
   {
      if (target == 0)
      {
         temp.insert(ds);
      }
      return;
   }
   if (arr[idx] <= target)
   {
      ds.push_back(arr[idx]);
      helper2(idx + 1, arr, target - arr[idx], ds, temp);
      ds.pop_back();
   }
   helper2(idx + 1, arr, target, ds, temp);
}

set<vector<int>> combinationsum2(vi &arr, int target)
{
   vi ds;
   set<vector<int>> ans;
   // vvi temp;
   helper2(0, arr, target, ds, ans);
   // for(auto it:temp){
   //    ans.insert(it);
   // }
   return ans;
}

// m2..................

void helper3(int idx, vi &arr, int target, vi &ds, vvi &ans)
{
   if (target == 0)
   {
      sort(ds.begin(), ds.end());
      ans.push_back(ds);
      return;
   }

   for (int i = idx; i < arr.size(); i++)
   {
      if (i > idx and arr[i] == arr[i - 1])
         continue;
      if (arr[i] <= target)
      {
         ds.push_back(arr[i]);
         helper3(i + 1, arr, target - arr[i], ds, ans);
         ds.pop_back();
      }
   }
}

vvi combinationsum3(vi &arr, int target)
{
   vi ds;
   vvi temp;
   helper3(0, arr, target, ds, temp);
   set<vi> ans;
   for (auto it : temp)
   {
      ans.insert(it);
   }
   temp.clear();
   for (auto it : ans)
   {
      temp.push_back(it);
   }
   return temp;
}

int32_t main()
{
   __mayuk;

   vi v = {2, 3, 6, 7};
   vi v2 = {10, 1, 2, 7, 6, 1, 5};
   // vi v2 = {1, 1, 1, 2, 2};
   // vvi ans = combinationsum(v, 7);
   // set<vector<int>> ans = combinationsum2(v2, 8);
   // set<vector<int>> ans = combinationsum2(v2, 4);

   // for method 2............
   vvi ans = combinationsum3(v2, 8);
   //   vvi ans = combinationsum3(v2, 4);
   for (auto it : ans)
   {
      for (auto id : it)
      {
         cout << id << ' ';
      }
      cout << endl;
   }
   return 0;
}

void subsetgenerate(int idx, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
   if (idx == nums.size())
   {
      ans.push_back(ds);
      return;
   }

   ds.push_back(nums[idx]);
   subsetgenerate(idx + 1, nums, ds, ans);
   ds.pop_back();

   subsetgenerate(idx + 1, nums, ds, ans);
}

vector<vector<int>> subsets(vector<int> &nums)
{
   vector<int> ds;
   vector<vector<int>> ans;
   int idx = 0;
   subsetgenerate(idx, nums, ds, ans);
   return ans;
}

// generate unique subsetw where the given array contains duplicate elements....

void helper(int idx, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
   ans.push_back(ds);
   for (int i = idx; i < nums.size(); i++)
   {
      if (i > idx and nums[i] == nums[i - 1])
         continue;
      ds.push_back(nums[i]);
      helper(i + 1, nums, ds, ans);
      ds.pop_back();
   }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
   vector<int> ds;
   vector<vector<int>> ans;
   sort(nums.begin(), nums.end());
   helper(0, nums, ds, ans);
   return ans;
}

void combinationgenerate(int idx, vector<int> &candidates, int target, vector<int> &ds, vector<vector<int>> &ans)
{
   if (idx == candidates.size())
   {
      if (target == 0)
      {
         ans.push_back(ds);
      }
      return;
   }

   if (target >= candidates[idx])
   {
      ds.push_back(candidates[idx]);
      combinationgenerate(idx, candidates, target - candidates[idx], ds, ans);
      ds.pop_back();
   }

   combinationgenerate(idx + 1, candidates, target, ds, ans);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
   vector<int> ds;
   vector<vector<int>> ans;
   int idx = 0;
   combinationgenerate(idx, candidates, target, ds, ans);
   return ans;
}

void helper(vector<string> &ans, int n, int open, int close, string currentstr)
{
   if (currentstr.length() == n * 2)
   {
      ans.push_back(currentstr);
      return;
   }

   if (open < n)
   {
      currentstr.push_back('(');
      helper(ans, n, open + 1, close, currentstr);
      currentstr.pop_back();
   }
   if (close < open)
   {
      currentstr.push_back(')');
      helper(ans, n, open, close + 1, currentstr);
      currentstr.pop_back();
   }
}

vector<string> generateParenthesis(int n)
{
   vector<string> ans;
   string currentstr = "";
   int open = 0, close = 0;
   helper(ans, n, open, close, currentstr);
   return ans;
}

// combination sum 2 leetcode..........
void helper(int idx, vector<int> &arr, int currsum, int target, vector<int> &ds, vector<vector<int>> &ans)
{
   if (currsum == target)
   {
      ans.push_back(ds);
      return;
   }

   for (int i = idx; i < arr.size(); i++)
   {
      if (i > idx and arr[i] == arr[i - 1])
         continue;
      if (arr[i] > target - currsum)
         break;
      ds.push_back(arr[i]);
      currsum += arr[i];
      helper(i + 1, arr, currsum, target, ds, ans);
      ds.pop_back();
      currsum -= arr[i];
   }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
   vi ds;
   vvi ans;
   sort(candidates.begin(), candidates.end());

   helper(0, candidates, 0, target, ds, ans);
   return ans;
}

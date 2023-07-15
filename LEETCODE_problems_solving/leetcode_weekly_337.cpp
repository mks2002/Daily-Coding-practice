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

// this is wrong because counting start from right side in binary format...
// vector<int> evenOddBit(int n)
// {
//    vector<int> v;
//    while (n != 0)
//    {
//       int bit = n & 1;
//       v.push_back(bit);
//       n = n >> 1;
//    }
//    reverse(v.begin(), v.end());
//    int odd = 0;
//    int even = 0;
//    for (int i = 0; i < v.size(); i++)
//    {
//       if (i % 2 == 0 and v[i] == 1)
//          even++;
//       if (i % 2 == 1 and v[i] == 1)
//          odd++;
//    }
//    vector<int> ans;
//    ans.push_back(even);
//    ans.push_back(odd);
//    return ans;
// }

vector<int> evenOddBit(int n)
{
   vector<int> v;
   int i = 0;
   int odd = 0;
   int even = 0;
   while (n != 0)
   {
      int bit = n & 1;
      if (i % 2 == 0 and bit == 1)
         even++;
      if (i % 2 == 1 and bit == 1)
         odd++;
      i += 1;
      n = n >> 1;
   }
   vector<int> ans;
   ans.push_back(even);
   ans.push_back(odd);
}

// for knight move check we have to take sum of absolute difference of x and y coordinate and it is 3...

int32_t main()
{
   __mayuk;

   return 0;
}

bool issemi(string s)
{
   if (s.length() == 1)
      return true;
   int cnt = 0;
   for (int i = 1; i < s.length(); i++)
   {
      if (s[i - 1] == s[i])
         cnt++;
   }
   if (cnt <= 1)
      return true;
   else
      return false;
}

int longestSemiRepetitiveSubstring(string s)
{
   int n = s.length();
   int ans = 0;
   for (int i = 0; i < n; i++)
   {
      for (int j = i; j < n; j++)
      {
         //   by doing this we can check for all substrings...
         string temp = s.substr(i, j - i + 1);
         if (issemi(temp) == true)
         {
            ans = max(ans, (int)temp.length());
         }
      }
   }
   return ans;
}

// temp vector store the final position of the robots not in same order because we consider that after collision they not changed their directions but move in the same direction by this the final position of each robot changes but the net distance sum which we required remains same...
int sumDistance(vector<int> &nums, string s, int d)
{
   int n = nums.size();
   int mod = 1e9 + 7;

   vector<int> temp;
   for (int i = 0; i < n; i++)
   {
      if (s[i] == 'L')
      {
         temp.push_back(nums[i] - d);
      }
      else if (s[i] == 'R')
      {
         temp.push_back(nums[i] + d);
      }
   }

   long long presum = 0;
   long long ans = 0;
   sort(temp.begin(), temp.end());
   for (int i = 0; i < temp.size(); i++)
   {
      ans += i * (long long)temp[i] - presum;
      ans = ans % mod;
      presum += temp[i];
   }

   return ans;
}

// [ -3, -1, 1 ] - 3 - 4 - 3 pre 0 - 3 - 4 tempdist 0 2 6

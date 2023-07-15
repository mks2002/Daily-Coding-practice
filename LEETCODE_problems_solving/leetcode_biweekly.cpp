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

// bi weekly 106..

bool isFascinating(int n)
{
   string temp = "";
   temp += to_string(n);
   int x = 2 * n;
   int y = 3 * n;
   temp += to_string(x);
   temp += to_string(y);
   int arr[9] = {0};
   for (int i = 0; i < temp.length(); i++)
   {
      if (temp[i] != '0')
      {
         arr[temp[i] - '1']++;
      }
   }

   for (int i = 0; i < 9; i++)
   {
      if (arr[i] != 1)
      {
         return false;
      }
   }
   return true;
}

/*
Find the Longest Semi-Repetitive Substring

You are given a 0-indexed string s that consists of digits from 0 to 9.
A string t is called a semi-repetitive if there is at most one consecutive pair of the same digits inside t. For example, 0010, 002020, 0123, 2002, and 54944 are semi-repetitive while 00101022, and 1101234883 are not.

Return the length of the longest semi-repetitive substring inside s.
A substring is a contiguous non-empty sequence of characters within a string.

*/

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

// in substr function the first parameter is starting index and the second parameter is length of the substring....

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

// stack created
// initialized a counter variable with 0
// iterating through the string
// checking if the stack is empty OR element is already present in the stack
// if the element is not present in the stack then we pop the stack element
// Now, check if the stack is empty , if so then increment the counter variable by 1
// lastly return the count of balanced substrings

int balancedStringSplit(string s)
{
   stack<char> st;
   int count = 0;

   for (int i = 0; i < s.length(); i++)
   {
      if (st.empty() || st.top() == s[i])
      {
         st.push(s[i]);
      }
      else
      {
         st.pop();
      }

      if (st.empty())
         count++;
   }

   return count;
}

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

// leetcode biweekly Contest 108 .....

int isWinner(vector<int> &player1, vector<int> &player2)
{
   int sum1 = 0, sum2 = 0;
   for (int i = 0; i < player1.size(); i++)
   {
      if (i == 0)
         sum1 += player1[i];
      else if (i == 1)
      {
         if (player1[i - 1] == 10)
            sum1 += (2 * player1[i]);
         else
            sum1 += player1[i];
      }
      else
      {
         if (player1[i - 1] == 10 or player1[i - 1] == 10)
            sum1 += (2 * player1[i]);
      }
   }

   for (int i = 0; i < player2.size(); i++)
   {
      if (i <= 1)
         sum1 += player2[i];
      else if (i == 1)
      {
         if (player2[i - 1] == 10)
            sum1 += (2 * player2[i]);
         else
            sum1 += player2[i];
      }
      else
      {
         if (player2[i - 1] == 10 or player2[i - 1] == 10)
            sum1 += (2 * player2[i]);
      }
   }

   if (sum1 == sum2)
      return 0;
   else if (sum1 > sum2)
      return 1;
   else
      return 2;
}

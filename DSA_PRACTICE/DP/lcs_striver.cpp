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

// simple recursive solution......

int helper(int idx1, int idx2, string s1, string s2)
{
   if (idx1 < 0 or idx2 < 0)
      return 0;

  
   if (idx1 == 0 and idx2 == 0)
   {
      if (s1[0] == s2[0])
         return 1;
      else
         return 0;
   }

   int ans = 0;
   if (s1[idx1] == s2[idx2])
   {
      ans = 1 + helper(idx1 - 1, idx2 - 1, s1, s2);
   }
   else
   {
      ans = 0 + max(helper(idx1 - 1, idx2, s1, s2), helper(idx1, idx2 - 1, s1, s2));
   }
   return ans;
}

int longestCommonSubsequence(string text1, string text2)
{
   int n = text1.size();
   int m = text2.size();
   int ans = helper(n - 1, m - 1, text1, text2);
   return ans;
}

// 0 based indexing solution.....
int f(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
{
   if (idx1 < 0 or idx2 < 0)
   {
      return 0;
   }

// if we not include this base case still it is working properly ,and also this condition may not always encounters because it is not necessary that both indexes become 0 at the same time ..........
   if (idx1 == 0 and idx2 == 0)
   {
      if (s1[0] == s2[0])
         return 1;
      else
         return 0;
   }

   if (dp[idx1][idx2] != -1)
      return dp[idx1][idx2];

   int ans = 0;

   if (s1[idx1] == s2[idx2])
   {
      ans = 1 + f(idx1 - 1, idx2 - 1, s1, s2, dp);
   }
   else
   {
      ans = 0 + max(f(idx1 - 1, idx2, s1, s2, dp), f(idx1, idx2 - 1, s1, s2, dp));
   }

   return dp[idx1][idx2] = ans;
}

int longestCommonSubsequence(string text1, string text2)
{
   int n = text1.size();
   int m = text2.size();
   vector<vector<int>> dp(n, vector<int>(m, -1));
   return f(n - 1, m - 1, text1, text2, dp);
}

// 1 based indexing memoization........
int f(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
{
   if (idx1 == 0 or idx2 == 0)
   {
      return 0;
   }

   if (dp[idx1][idx2] != -1)
      return dp[idx1][idx2];
   if (s1[idx1 - 1] == s2[idx2 - 1])
   {
      return dp[idx1][idx2] = 1 + f(idx1 - 1, idx2 - 1, s1, s2, dp);
   }
   else
   {
      return dp[idx1][idx2] = 0 + max(f(idx1 - 1, idx2, s1, s2, dp), f(idx1, idx2 - 1, s1, s2, dp));
   }
}

int longestCommonSubsequence(string text1, string text2)
{
   int n = text1.size();
   int m = text2.size();
   vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
   return f(n, m, text1, text2, dp);
}

// based on this 1 based indexing we write our tabulation ..........
// because in 0 based indexing the base case contains -1 index which is not possible in dp[i][j].............

int longestCommonSubsequence(string text1, string text2)
{
   int n = text1.size();
   int m = text2.size();
   vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
   for (int i = 0; i <= n; i++)
   {
      dp[i][0] = 0;
   }

   for (int j = 0; j <= m; j++)
   {
      dp[0][j] = 0;
   }

   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= m; j++)
      {
         if (text1[i - 1] == text2[j - 1])
         {
            dp[i][j] = 1 + dp[i - 1][j - 1];
         }
         else
         {
            dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
         }
      }
   }
   return dp[n][m];
}

// space optimization.......
// in case of 2d dp space optimization we just took column size 2 vectors......

int longestCommonSubsequence(string text1, string text2)
{
   int n = text1.size();
   int m = text2.size();

   vector<int> prev(m + 1, 0), prev2(m + 1, -1);

   for (int i = 0; i <= m; i++)
   {
      prev[i] = 0;
   }

   for (int i = 1; i <= n; i++)
   {
      vector<int> curr(m + 1, 0);
      for (int j = 1; j <= m; j++)
      {
         if (text1[i - 1] == text2[j - 1])
         {
            curr[j] = 1 + prev[j - 1];
         }
         else
         {
            curr[j] = 0 + max(prev[j], curr[j - 1]);
         }
      }
      prev2 = prev;
      prev = curr;
   }

   // we can return any of them.....
   return prev[m];
   // return curr[m];
}

// printing the longest common subsequnce.................

void PrintlongestCommonSubsequence(string text1, string text2)
{
   int n = text1.size();
   int m = text2.size();
   vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
   for (int i = 0; i <= n; i++)
   {
      dp[i][0] = 0;
   }
   for (int j = 0; j <= m; j++)
   {
      dp[0][j] = 0;
   }

   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= m; j++)
      {
         if (text1[i - 1] == text2[j - 1])
         {
            dp[i][j] = 1 + dp[i - 1][j - 1];
         }
         else
         {
            dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
         }
      }
   }

   int lengthsubsequnce = dp[n][m];
   string ans = "";
   for (int i = 0; i < lengthsubsequnce; i++)
   {
      ans += '#';
   }
   int idx = lengthsubsequnce - 1;
   int i = n, j = m;
   while (i > 0 and j > 0)
   {
      if (text1[i - 1] == text2[j - 1])
      {
         ans[idx] = text1[i - 1];
         ans[idx] = text2[j - 1]; // we can do  any one....
         idx--;
         i--;
         j--;
      }
      else
      {
         if (dp[i - 1][j] > dp[i][j - 1])
         {
            i--;
         }
         else
         {
            j--;
         }
      }
   }
   cout << ans << endl;
}

int32_t main()
{
   __mayuk;
   int t;
   cin >> t;
   while (t--)
   {
      string s1, s2;
      cin >> s1 >> s2;
      cout << longestCommonSubsequence(s1, s2) << endl;
      PrintlongestCommonSubsequence(s1, s2);
   }

   return 0;
}

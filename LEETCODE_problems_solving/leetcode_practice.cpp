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
// 1.. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts

// max area of cake after horizontal and vertical cuts.....
// because the length which is pass in function is the last length.....

int maxdiff(vector<int> &v, int length)
{
   sort(v.begin(), v.end());
   int cut_max = v[0];
   for (int i = 0; i < v.size() - 1; i++)
   {
      int cut_max = max(cut_max, v[i + 1] - v[i]);
   }
   cut_max = max(cut_max, length);
   return cut_max;
}

int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
{
   int mod = 1e9 + 7;
   int x = maxdiff(horizontalCuts, h);
   int y = maxdiff(verticalCuts, w);
   return (x * y) % mod;
}

// rearrange array to maximize prefix sum......
// we have to find such a rearrangement of the string so that in prefix array maximum no is positive...

vector<int> shuffle(vector<int> &nums, int n)
{
   vector<int> ans;
   for (int i = 0; i < nums.size() / 2; i++)
   {
      ans.push_back(nums[i]);
      ans.push_back(nums[i + n]);
   }
   return ans;
}

int numIdenticalPairs(vector<int> &nums)
{
   int n = nums.size();
   int cnt = 0;
   for (int i = 0; i < n; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         if (nums[i] == nums[j])
            cnt++;
      }
   }
   return cnt;
}

vector<int> leftRigthDifference(vector<int> &nums)
{
   int n = nums.size();
   vector<int> left(n), right(n);
   left[0] = 0;
   right[n - 1] = 0;
   for (int i = 0; i < n - 1; i++)
   {
      left[i + 1] = left[i] + nums[i];
   }

   for (int i = n - 1; i > 0; i--)
   {
      right[i - 1] = right[i] + nums[i];
   }
   vector<int> ans;
   for (int i = 0; i < n; i++)
   {
      ans.push_back(abs(left[i] - right[i]));
   }
   return ans;
}

vector<int> decode(vector<int> &encoded, int first)
{
   int n = encoded.size();
   vector<int> ans;
   ans.push_back(first);
   for (int i = 0; i < n; i++)
   {
      int temp = encoded[i] ^ ans[i];
      ans.push_back(temp);
   }
   return ans;
}

bool canMakeArithmeticProgression(vector<int> &arr)
{
   sort(arr.begin(), arr.end());
   int diff = arr[1] - arr[0];
   for (int i = 0; i < arr.size() - 1; i++)
   {
      if ((arr[i + 1] - arr[i]) != diff)
      {
         return false;
      }
   }
   return true;
}

vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
   int n = nums.size();
   vector<int> temp;
   for (int i = 0; i < n; i++)
   {
      int cnt = 0;
      int curr = nums[i];
      for (int j = 0; j < n; j++)
      {
         if (j != i and nums[j] < nums[i])
            cnt++;
      }
      temp.push_back(cnt);
   }
   return temp;
}

int sumOfMultiples(int n)
{
   int sum = 0;
   for (int i = 1; i <= n; i++)
   {
      if (i % 3 == 0 or i % 5 == 0 or i % 7 == 0)
      {
         sum += i;
      }
   }
   return sum;
}

int maximumWealth(vector<vector<int>> &accounts)
{
   int n = accounts.size();
   int m = accounts[0].size();
   vector<int> temp;
   for (int i = 0; i < n; i++)
   {
      int sum = 0;
      for (int j = 0; j < m; j++)
      {
         sum += accounts[i][j];
      }
      temp.push_back(sum);
   }
   sort(temp.begin(), temp.end());
   return temp[temp.size() - 1];
}

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
   int max = candies[0];
   for (int i = 0; i < candies.size(); i++)
   {
      if (candies[i] > max)
      {
         max = candies[i];
      }
   }
   vector<bool> ans;
   for (int i = 0; i < candies.size(); i++)
   {
      if (extraCandies + candies[i] >= max)
      {
         ans.push_back(true);
      }
      else
      {
         ans.push_back(false);
      }
   }
   return ans;
}

int mostWordsFound(vector<string> &sentences)
{
   int n = sentences.size();
   vector<int> ans;
   for (int i = 0; i < n; i++)
   {
      string temp = sentences[i];
      int length = temp.size();
      int cnt = 0;
      for (int i = 0; i < length - 1; i++)
      {
         if (temp[i] == ' ' and temp[i + 1] != ' ')
         {
            cnt++;
         }
      }
      cnt += 1;
      ans.push_back(cnt);
   }
   sort(ans.begin(), ans.end());
   int maxans = ans[ans.size() - 1];
   return maxans;
}

vector<string> sortPeople(vector<string> &names, vector<int> &heights)
{
   map<int, string> m;
   int n = names.size();
   for (int i = 0; i < n; i++)
   {
      m[heights[i]] = names[i];
   }
   sort(heights.begin(), heights.end());
   reverse(heights.begin(), heights.end());
   vector<string> ans;
   for (int i = 0; i < n; i++)
   {
      ans.push_back(m[heights[i]]);
   }
   return ans;
}

int maxProductDifference(vector<int> &nums)
{
   int n = nums.size();
   sort(nums.begin(), nums.end());
   int max = nums[nums.size() - 1] * nums[nums.size() - 2];
   int min = nums[0] * nums[1];
   int ans = max - min;
   return ans;
}

int diagonalSum(vector<vector<int>> &mat)
{
   int n = mat.size();
   int m = mat[0].size();
   int sum = 0;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (i == j)
         {
            sum += mat[i][j];
         }
         else
         {
            if (j == n - 1 - i)
            {
               sum += mat[i][j];
            }
         }
      }
   }
   return sum;
}

int countKDifference(vector<int> &nums, int k)
{
   int cnt = 0;
   int n = nums.size();
   for (int i = 0; i < n; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         if (abs(nums[i] - nums[j]) == k)
            cnt++;
      }
   }
   return cnt;
}

int numJewelsInStones(string jewels, string stones)
{
   int cnt = 0;
   for (int i = 0; i < stones.length(); i++)
   {
      char temp = stones[i];
      for (int j = 0; j < jewels.length(); j++)
      {
         if (temp == jewels[j])
         {
            cnt++;
         }
      }
   }
   return cnt;
}

// incomplete.....
string decodeMessage(string key, string message)
{
}

int removeDuplicates(vector<int> &nums)
{
   map<int, int> m;
   for (auto it : nums)
   {
      m[it]++;
   }
   nums.clear();
   vector<int> ans;
   for (auto it : m)
   {
      if (it.second > 0)
      {
         ans.push_back(it.first);
         nums.push_back(it.first);
      }
   }
   return ans.size();
}

// first occurrence of needle in haystack, or -1..........
int strStr(string haystack, string needle)
{
   int n = needle.length();
   int m = haystack.length();

   if (n > m)
      return -1;

   string temp = "";
   for (int i = 0; i < n - 1; i++)
   {
      temp += haystack[i];
   }
   int ans = -1;
   for (int i = n - 1; i < m; i++)
   {
      temp += haystack[i];
      if (temp == needle)
      {
         ans = i - temp.size() + 1;
         break;
      }
      temp.erase(temp.begin());
   }

   return ans;
}

int lengthOfLastWord(string s)
{
   int cnt = 0;
   int tempcnt = 0;
   for (int i = s.length() - 1; i >= 0; i--)
   {
      if (s[i] == ' ')
         tempcnt++;
      else
      {
         break;
      }
   }
   for (int i = s.length() - 1 - tempcnt; i >= 0; i--)
   {
      if (s[i] == ' ')
      {
         break;
      }
      else
      {
         cnt++;
      }
   }
   return cnt;
}

// sort array in increasing frequency.....
vector<int> frequencySort(vector<int> &nums)
{
   map<int, int> m;
   for (auto it : nums)
   {
      m[it]++;
   }
   vector<int> v;
   for (auto it : m)
   {
      v.push_back(it.second);
   }
   sort(v.begin(), v.end());
   for (auto it : v)
   {
      int elem = it;
   }
}
int32_t main()
{
   __mayuk;

   return 0;
}

// Sort characters by frequency.....

// this solution is giving runtime_error .....
string frequencySort(string s)
{
   vector<int> fre(62, 0);
   for (int i = 0; i < s.length(); i++)
   {
      if (s[i] >= 'A' and s[i] <= 'Z')
      {
         fre[s[i] - 'A']++;
      }
      else if (s[i] >= 'a' and s[i] <= 'z')
      {
         fre[s[i] - 'a' + 26]++;
      }
      else if (s[i] >= '0' and s[i] <= '9')
      {
         fre[s[i] - '0' + 52]++;
      }
   }
   map<int, vector<char>> m;
   for (int i = 0; i < 26; i++)
   {
      if (fre[i] != 0)
      {
         m[fre[i]].push_back('A' + i);
      }
   }
   for (int i = 26; i < 52; i++)
   {
      if (fre[i] != 0)
      {
         m[fre[i]].push_back('a' + i);
      }
   }
   for (int i = 52; i, 62; i++)
   {
      if (fre[i] != 0)
      {
         m[fre[i]].push_back('0' + i);
      }
   }
   sort(fre.begin(), fre.end());

   string ans = "";
   for (int i = 0; i < 62; i++)
   {
      if (fre[i] != 0)
      {
         vector<char> temp = m[fre[i]];
         int curr = fre[i];
         for (auto it : temp)
         {
            while (curr--)
            {
               ans += it;
            }
         }
      }
   }
   return ans;
}

int mySqrt(int x)
{
   int s = 1;
   int end = x;
   int ans = 0;
   while (s <= end)
   {
      long long mid = s + (end - s) / 2;
      if (mid * mid == x)
      {
         return mid;
      }
      else if (mid * mid < x)
      {
         ans = mid;
         s = mid + 1;
      }
      else
      {
         end = mid - 1;
      }
      mid = s + (end - s) / 2;
   }
   return ans;
}

// k most frequent element.....

vector<int> topKFrequent(vector<int> &nums, int k)
{
   map<int, int> m;
   for (auto it : nums)
   {
      m[it]++;
   }
   vector<int> temp;
   map<int, int> m2;
   for (auto it : m)
   {
      m2[it.second] = it.first;
   }
   for (auto it : m)
   {
      temp.push_back(it.second);
   }
   sort(temp.begin(), temp.end());
   reverse(temp.begin(), temp.end());
   vector<int> ans;
   for (int i = 0; i < k; i++)
   {
      ans.push_back(m2[temp[i]]);
   }
   return ans;
}

vector<int> targetIndices(vector<int> &nums, int target)
{
   int n = nums.size();
   sort(nums.begin(), nums.end());
   vector<int> ans;
   for (int i = 0; i < n; i++)
   {
      if (nums[i] == target)
      {
         ans.push_back(i);
      }
   }
   return ans;
}

// this is for 1d array.....
vector<int> arrayRankTransform(vector<int> &arr)
{
   vector<int> temp = arr;
   sort(temp.begin(), temp.end());
   int rank = 1;
   map<int, int> m;
   vector<int> ranktemp;
   ranktemp.push_back(1);
   for (int i = 1; i < temp.size(); i++)
   {
      if (temp[i] > temp[i - 1])
      {
         ranktemp.push_back(++rank);
      }
      else
      {
         ranktemp.push_back(rank);
      }
   }
   for (int i = 0; i < temp.size(); i++)
   {
      m[temp[i]] = ranktemp[i];
   }
   vector<int> ans;
   for (auto it : arr)
   {
      ans.push_back(m[it]);
   }
   return ans;
}

// similar to previous question but it is for 2d array............
vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix)
{
}
// incomplete...

// wrong answer...
int findContentChildren(vector<int> &g, vector<int> &s)
{
   sort(g.begin(), g.end());
   sort(s.begin(), s.end());
   int i = 0, j = 0;
   int cnt = 0;
   while (i < g.size() and j < s.size())
   {
      if (s[j] >= g[i])
         cnt++;
      i++;
      j++;
   }
   return cnt;
}

// product of array except itself..............
vector<int> productExceptSelf(vector<int> &nums)
{
   int n = nums.size();
   int left[n];
   int right[n];
   for (int i = 0; i < n; i++)
   {
      left[i] = 1;
      right[i] = 1;
   }

   left[0] = nums[0];
   right[n - 1] = nums[n - 1];
   for (int i = 1; i < n; i++)
   {
      left[i] = left[i - 1] * nums[i];
   }
   for (int i = n - 2; i >= 0; i--)
   {
      right[i] = right[i + 1] * nums[i];
   }

   vector<int> ans;
   ans.push_back(right[1]);
   for (int i = 1; i < n - 1; i++)
   {
      ans.push_back(left[i - 1] * right[i + 1]);
   }
   ans.push_back(left[n - 2]);
   return ans;
}

// Binary search based solutions..............

// Search Insert Position ...................
int searchInsert(vector<int> &nums, int target)
{
   int s = 0;
   int end = nums.size() - 1;
   int ans = nums.size();
   while (s <= end)
   {
      int mid = s + (end - s) / 2;
      if (nums[mid] == target)
      {
         return mid;
      }
      else if (nums[mid] > target)
      {
         ans = mid;
         end = mid - 1;
      }
      else
      {

         s = mid + 1;
      }

      mid = s + (end - s) / 2;
   }
   return ans;
}

// since we initially declart the answer as arr.size() i.e. the last position of the array so if the target > arr[mid] then we dont need to update the value of ans , the value of answer is only changed when the arr[mid]> target in that case we have to shift our ans towards left....
bool isBadVersion(int x)
{
}

int firstBadVersion(int n)
{
   int s = 1;
   int end = n;
   int ans = n;
   while (s <= end)
   {
      int mid = s + (end - s) / 2;
      if (isBadVersion(mid))
      {
         ans = mid;
         end = mid - 1;
      }
      else
      {
         s = mid + 1;
      }
      mid = s + (end - s) / 2;
   }
   return ans;
}

int firstoccur(vector<int> &nums, int target)
{
   int s = 0;
   int end = nums.size() - 1;
   int ans = nums.size() - 1;
   while (s <= end)
   {
      int mid = s + (end - s) / 2;
      if (nums[mid] == target)
      {
         ans = mid;
         end = mid - 1;
      }
      else if (nums[mid] < target)
      {
         s = mid + 1;
      }
      else
      {
         end = mid - 1;
      }
      mid = s + (end - s) / 2;
   }
   return ans;
}

int lastoccur(vector<int> &nums, int target)
{
   int s = 0;
   int end = nums.size() - 1;
   int ans = 0;
   while (s <= end)
   {
      int mid = s + (end - s) / 2;
      if (nums[mid] == target)
      {
         ans = mid;
         s = mid + 1;
      }
      else if (nums[mid] < target)
      {
         s = mid + 1;
      }
      else
      {
         end = mid - 1;
      }
      mid = s + (end - s) / 2;
   }
   return ans;
}

// no of occurence of a number in sorted array....

vector<int> searchRange(vector<int> &nums, int target)
{
   int x = firstoccur(nums, target);
   int y = lastoccur(nums, target);
   vector<int> ans;
   ans.push_back(x);
   ans.push_back(y);
   return ans;
}

int singleNonDuplicate(vector<int> &nums)
{
   int n = nums.size();
   if (nums.size() == 1)
      return nums[0];
   if (nums[0] != nums[1])
      return nums[0];
   if (nums[n - 1] != nums[n - 2])
      return nums[n - 1];

   int s = 1;
   int end = n - 2;
   while (s <= end)
   {
      int mid = s + (end - s) / 2;
      if (nums[mid] != nums[mid + 1] and nums[mid] != nums[mid - 1])
      {
         return nums[mid];
      }
      else if ((mid % 2 == 0 and nums[mid] == nums[mid + 1]) or (mid % 2 == 1 and nums[mid] == nums[mid - 1]))
      {
         s = mid + 1;
      }
      else if ((mid % 2 == 0 and nums[mid] == nums[mid - 1]) or (mid % 2 == 1 and nums[mid] == nums[mid + 1]))
      {
         end = mid - 1;
      }
      mid = s + (end - s) / 2;
   }
   return -1;
}

// strings problems..........

string kthDistinct(vector<string> &arr, int k)
{
   map<string, int> m;
   for (auto it : arr)
   {
      m[it]++;
   }
   vector<string> temp;
   for (auto it : m)
   {
      if (it.second == 1)
      {
         temp.push_back(it.first);
      }
   }
   string ans = "";
}

// reverse string in place.......
void reverseString(vector<char> &s)
{
   int n = s.size();
   for (int i = 0; i < n / 2; i++)
   {
      swap(s[i], s[n - i - 1]);
   }
}

// reverse only vowels of a string....
string reverseVowels(string s)
{
   vector<char> temp;
   for (auto it : s)
   {
      if (it == 'a' or it == 'e' or it == 'i' or it == 'o' or it == 'u' or it == 'A' or it == 'E' or it == 'I' or it == 'O' or it == 'U')
      {
         temp.push_back(it);
      }
   }
   int n = temp.size();
   for (int i = 0; i < n / 2; i++)
   {
      swap(temp[i], temp[n - i - 1]);
   }
   int idx = 0;
   string ans = "";
   for (int i = 0; i < s.length(); i++)
   {
      if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U')
      {
         ans += temp[idx++];
      }
      else
      {
         ans += s[i];
      }
   }
   return ans;
}

vector<string> summaryRanges(vector<int> &nums)
{
   int n = nums.size();
   vector<string> ans;
   string temp = "";
   for (int i = 0; i < n; i++)
   {
      int j = i;
      while (j < n - 1 and nums[j + 1] == nums[j] + 1)
      {
         j++;
      }

      if (j > i)
      {
         temp += to_string(nums[i]);
         temp += '->';
         temp += to_string(nums[j]);
      }
      else
      {
         temp += to_string(nums[i]);
      }
      ans.push_back(temp);
      temp = "";
      i = j;
   }
   return ans;
}

bool isPalindrome(string s)
{
   int n = s.length();
   for (int i = 0; i < n; i++)
   {
      if (s[i] >= 'A' and s[i] <= 'Z')
      {
         s[i] += 32;
      }
   }
   string temp;
   for (auto it : s)
   {
      if ((it >= 'a' and it <= 'z') or (it >= '0' and it <= '9'))
      {
         temp += it;
      }
   }
   n = temp.length();
   for (int i = 0; i < n / 2; i++)
   {
      if (temp[i] != temp[n - i - 1])
      {
         return false;
      }
   }
   return true;
}
// reverse words in string.....

// this is O(n^2) solution.........
string reverseWords(string s)
{
   int n = s.length();
   stack<string> st;
   for (int i = 0; i < n; i++)
   {
      string temp = "";
      while (s[i] != ' ' and i < n)
      {
         temp += s[i];
      }
      st.push(temp);
   }
   string ans = "";
   while (!st.empty())
   {
      ans += st.top();
      ans += " ";
      st.pop();
   }
   return ans;
}

string reverseWords(string s)
{
   string ans = "";
   string temp = "";
   for (int i = s.length() - 1; i >= 0; i--)
   {
      if (s[i] == ' ')
      {
         reverse(temp.begin(), temp.end());
         if (temp.size() > 0 and ans.size() == 0)
         {
            ans += temp;
         }
         else if (temp.size() > 0 and ans.size() > 0)
         {
            ans += " ";
            ans += temp;
         }
         temp = "";
      }
      else
      {
         temp += s[i];
      }
   }

   // the last word is still remaining....
   reverse(temp.begin(), temp.end());
   if (temp.size() > 0 and ans.size() == 0)
   {
      ans += temp;
   }
   else if (temp.size() > 0 and ans.size() > 0)
   {
      ans += " ";
      ans += temp;
   }
   return ans;
}

string mergeAlternately(string word1, string word2)
{
   int i = 0;
   int j = 0;
   string ans = "";
   while (i < word1.length() and j < word2.length())
   {
      ans += word1[i];
      ans += word2[i];
      i++;
      j++;
   }
   while (i < word1.length())
   {
      ans += word1[i++];
   }
   while (j < word2.length())
   {
      ans += word2[j++];
   }
   return ans;
}

// power of 2.........
bool isPowerOfTwo(int n)
{
   int x = abs(n);
   int temp = __builtin_popcount(x);
   if (temp == 1)
   {
      return true;
   }
   return false;
}

// tree ......

struct TreeNode
{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode *p, TreeNode *q)
{
   if (p == NULL and q == NULL)
   {
      return true;
   }
   if (p != NULL and q == NULL)
      return false;
   if (p == NULL and q != NULL)
      return false;

   int current = (p->val == q->val);
   int left = isSameTree(p->left, q->left);
   int right = isSameTree(p->right, q->right);

   if (current and left and right)
   {
      return true;
   }
   else
   {
      return false;
   }
}

// maths and numbers....
// add digits of a number untill final answer has only 1 digit.....
int add(int x)
{
   int sum = 0;
   while (x > 0)
   {
      int d = x % 10;
      sum += d;
      x = x / 10;
   }
   return sum;
}

int addDigits(int num)
{
   int sum = add(num);
   if (sum <= 9)
   {
      return sum;
   }
   else
   {
      int ans = addDigits(sum);
      return ans;
   }
}

// sliding window..........

// maximum average subarray with k size........
double findMaxAverage(vector<int> &nums, int k)
{
   int n = nums.size();
   int sum = 0;
   double avg = 0;
   for (int i = 0; i < k; i++)
   {
      sum += nums[i];
   }
   avg = (sum * 1.0) / k;
   double ans = avg;
   for (int i = k; i < n; i++)
   {
      sum += nums[i];
      sum -= nums[i - k];
      avg = (sum * 1.0) / k;
      ans = max(ans, avg);
   }
   return ans;
}

int maxVowels(string s, int k)
{
   int n = s.length();
}

/*
this will give wrong answer for the test case --> 0 0 1 0 1 n=1..

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
   int size = flowerbed.size();
   for (int i = 1; i < size - 1; i++)
   {
      if (flowerbed[i] == 0 and flowerbed[i - 1] == 0 and flowerbed[i + 1] == 0)
      {
         flowerbed[i] = 1;
         n = n - 1;
      }
   }
   if (n == 0)
   {
      return true;
   }
   else
   {
      return false;
   }
}
*/
bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
   int size = flowerbed.size();
   for (int i = 0; i < size; i++)
   {
      if (flowerbed[i] == 0)
      {
         int prev = (i == 0) ? 0 : flowerbed[i - 1];
         int next = (i == size - 1) ? 0 : flowerbed[i + 1];

         if (prev == 0 and next == 0)
         {
            flowerbed[i] = 1;
            n = n - 1;
         }
      }
   }
   if (n == 0)
   {
      return true;
   }
   else
   {
      return false;
   }
}

int kthFactor(int n, int k)
{
   vector<int> temp;
   for (int i = 1; i <= n / 2; i++)
   {
      if (n % i == 0)
      {
         temp.push_back(i);
      }
   }
   temp.push_back(n);
   if (temp.size() >= k)
   {
      return temp[k - 1];
   }
   else
   {
      return -1;
   }
}

// optimal string partiion.....
/*
this solution is wrong because in this test case
 --->  hdklqkcssgxlvehvq
 ---> (hdklq kcs sgxlveh vq ) there are 4 strings but in our solution we got only 2 strings as answer...
int partitionString(string s)
{
   int fre[26] = {0};
   int n = s.length();
   int mx = 0;
   for (int i = 0; i < n; i++)
   {
      fre[s[i] - 'a']++;
   }
   for (int i = 0; i < 26; i++)
   {
      if (fre[i] > mx)
      {
         mx = fre[i];
      }
   }
   return mx;
}

*/

// we have to keep track of our current stored characters whenever we found any repeating character we have to start with another because we cant change the order of the elements ...
int partitionString(string s)
{
   int ans = 1;
   set<char> st;
   for (auto c : s)
   {
      // we found the element in the set
      if (st.find(c) != st.end())
      {
         ans++;
         st.clear();
      }
      st.insert(c);
   }
   return ans;
}

// length of longest substring wihtout repeating characters....
// s contains each type of character....
// there are total 256 characters....

int lengthOfLongestSubstring(string s)
{
   int start = 0;
   int end = 0;
   int fre[256] = {0};
   int ans = 0;
   while (end < s.length())
   {
      fre[s[end]]++;

      while (fre[s[end]] > 1)
      {
         fre[s[start]]--;
         start++;
      }

      ans = max(ans, end - start + 1);
      end++;
   }
   return ans;
}

int maxVowels(string s, int k)
{
   int n = s.length();
   int vcnt = 0;
   string temp = "";
   for (int i = 0; i < k; i++)
   {
      temp += s[i];
      if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
      {
         vcnt++;
      }
   }

   int i = k;
   int ans = 0;
   while (i < n)
   {
      char current = s[i];
      temp += current;
      if (current == 'a' or current == 'e' or current == 'i' or current == 'o' or current == 'u')
      {
         vcnt++;
      }
      char remchar = temp[i - k];
      temp.erase(temp.begin(), temp.begin() + 1);
      if (remchar == 'a' or remchar == 'e' or remchar == 'i' or remchar == 'o' or remchar == 'u')
      {
         vcnt--;
      }
      ans = max(ans, vcnt);
      i++;
   }
   return ans;
}

// linked list based question .........
struct ListNode
{
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// delete the middle node of a linked list.....
ListNode *deleteMiddle(ListNode *head)
{
   int len = 1;
   ListNode *temp = head;
   while (temp != NULL)
   {
      len++;
      temp = temp->next;
   }
   if (len == 1)
   {
      return NULL;
   }
   else
   {
      int cnt = 0;
      temp = head;
      while (cnt < len / 2)
      {
         temp = temp->next;
      }
      temp->next = temp->next->next;
   }
   return head;
}

// delete the nth node from the last of linked list......

ListNode *removeNthFromEnd(ListNode *head, int n)
{
   int len = 0;
   ListNode *temp = head;
   while (temp != NULL)
   {
      temp = temp->next;
      len++;
   }
   if (n == len)
   {
      head = head->next;
   }
   else
   {
      int cnt = 1;
      temp = head;
      while (cnt < len - n)
      {
         temp = temp->next;
         cnt++;
      }
      temp->next = temp->next->next;
   }
   return head;
}

// middle of linked list....
ListNode *middleNode(ListNode *head)
{
   int len = 0;
   ListNode *temp = head;
   while (temp != NULL)
   {
      temp = temp->next;
      len++;
   }
   int cnt = 1;
   temp = head;
   while (cnt != len / 2 + 1)
   {
      temp = temp->next;
      cnt++;
   }
   return temp;
}

// minimum bit flips to make a or b ==c ....

int minFlips(int a, int b, int c)
{
   int ans = 0;
   while (a != 0 or b != 0 or c != 0)
   {
      int ai = a % 2;
      int bi = b % 2;
      int ci = c % 2;
      if (ci == 1)
      {
         if (ai == 0 and bi == 0)
         {
            ans += 1;
         }
      }
      else
      {
         if (ai == 1 and bi == 1)
         {
            ans += 2;
         }
         else if (ai == 1 or bi == 1)
         {
            ans += 1;
         }
      }
      a = a / 2;
      b = b / 2;
      c = c / 2;
   }
   return ans;
}

int length(ListNode *head)
{
   int len = 0;
   while (head != NULL)
   {
      len++;
      head = head->next;
   }
   return len;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
   ListNode *p = head;
   ListNode *q = NULL;
   ListNode *r;
   int len = length(head);
   if (len < k)
   {
      return head;
   }
   int cnt = 0;
   while (p != NULL and cnt < k)
   {
      r = p->next;
      p->next = q;
      q = p;
      p = r;
      cnt++;
   }
   if (r != NULL)
   {
      head->next = reverseKGroup(r, k);
   }
   return q;
}

int countNegatives(vector<vector<int>> &grid)
{
   int n = grid.size();
   int m = grid[0].size();
   int cnt = 0;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (grid[i][j] < 0)
            cnt++;
      }
   }
   return cnt;
}

// spiral matrix leetcode.......

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
   int n = matrix.size();
   int m = matrix[0].size();

   int cnt = 0;
   int srow = 0;
   int scol = 0;
   int erow = n - 1;
   int ecol = m - 1;
   vector<int> ans;

   while (cnt < n * m)
   {
      // left to right...
      for (int i = scol; i <= ecol and cnt < n * m; i++)
      {
         ans.push_back(matrix[srow][i]);
         cnt++;
      }
      srow++;
      // up to down....
      for (int i = srow; i <= erow and cnt < n * m; i++)
      {
         ans.push_back(matrix[i][ecol]);
         cnt++;
      }
      ecol--;

      // right to left..
      for (int i = ecol; i >= scol and cnt < n * m; i--)
      {
         ans.push_back(matrix[erow][i]);
         cnt++;
      }
      erow--;
      // down to up ...
      for (int i = erow; i >= srow and cnt < n * m; i--)
      {
         ans.push_back(matrix[i][scol]);
         cnt++;
      }
      scol++;
   }
   return ans;
}

// spiral matrix 2 ......
vector<vector<int>> generateMatrix(int n)
{
   vector<vector<int>> ans(n, vector<int>(n, 0));

   int cnt = 1;
   int srow = 0;
   int scol = 0;
   int erow = n - 1;
   int ecol = n - 1;

   while (cnt <= n * n)
   {
      // left to right...
      for (int i = scol; i <= ecol and cnt <= n * n; i++)
      {
         ans[srow][i] = cnt;
         cnt++;
      }
      srow++;

      // up to down....
      for (int i = srow; i <= erow and cnt <= n * n; i++)
      {
         ans[i][ecol] = cnt;
         cnt++;
      }
      ecol--;

      // right to left..
      for (int i = ecol; i >= scol and cnt <= n * n; i--)
      {
         ans[erow][i] = cnt;
         cnt++;
      }
      erow--;

      // down to up ...
      for (int i = erow; i >= srow and cnt <= n * n; i--)
      {
         ans[i][scol] = cnt;
         cnt++;
      }
      scol++;
   }
   return ans;
}

// merge 2 sorted lists..........

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
   ListNode *temp1 = list1;
   ListNode *temp2 = list2;

   ListNode *dummy = new ListNode(-1);
   ListNode *temp3 = dummy;
   // we have to use and because if any of them become NULL then the while loop terminate.....
   while (temp1 != NULL and temp2 != NULL)
   {
      if (temp1->val > temp2->val)
      {
         temp3->next = temp2;
         temp2 = temp2->next;
      }
      else if (temp1->val <= temp2->val)
      {
         temp3->next = temp1;
         temp1 = temp1->next;
      }
      temp3 = temp3->next;
   }

   while (temp1 != NULL)
   {
      temp3->next = temp1;
      temp1 = temp1->next;
      temp3 = temp3->next;
   }
   while (temp2 != NULL)
   {
      temp3->next = temp2;
      temp2 = temp2->next;
      temp3 = temp3->next;
   }

   return dummy->next;
}

/*

// this is not correct method to do this problem......

int compress(vector<char> &chars)
{
   map<char, int> m;
   for (auto it : chars)
   {
      m[it]++;
   }
   vector<char> temp;
   for (auto it : m)
   {
      if (it.second == 1)
      {
         temp.push_back(it.first);
      }
      else if (it.second > 1)
      {
         temp.push_back(it.first);
         string temp2 = to_string(it.second);
         for (auto it : temp2)
         {
            temp.push_back(it);
         }
      }
   }
   chars = temp;
   int ans = chars.size();
   return ans;
}

for this input      --> ["a","a","a","b","b","a","a"]
output must be      --> ["a","3","b","2","a","2"]
but our code gives  --> ["a","5","b","2"]

it directly add all the occurence of a character but we have to count it in groups....
*/

int compress(vector<char> &chars)
{
   int cnt = 1;
   vector<char> temp;
   temp.push_back(chars[0]);

   for (int i = 1; i < chars.size(); i++)
   {
      if (chars[i] == chars[i - 1])
      {
         cnt++;
      }
      else
      {
         if (cnt > 1)
         {
            string temp2 = to_string(cnt);
            for (auto it : temp2)
            {
               temp.push_back(it);
            }
            cnt = 1;
         }

         // push the current character....
         temp.push_back(chars[i]);
      }
   }
   // for the frequency of last character....
   if (cnt > 1)
   {
      string temp2 = to_string(cnt);
      for (auto it : temp2)
      {
         temp.push_back(it);
      }
   }
   chars = temp;
   return temp.size();
}

vector<vector<int>> levelOrderBottom(TreeNode *root)
{
   vector<vector<int>> ans;
   queue<TreeNode *> q;
   if (root == NULL)
   {
      return ans;
   }
   q.push(root);
   while (!q.empty())
   {
      int qsize = q.size();
      vector<int> temp;

      while (qsize--)
      {
         TreeNode *node = q.front();
         q.pop();

         if (node->left != NULL)
         {
            q.push(node->left);
         }

         if (node->right != NULL)
         {
            q.push(node->right);
         }

         temp.push_back(node->val);
      }
      // temp is again redeclare by empty vector.....
      ans.push_back(temp);
   }
   reverse(ans.begin(), ans.end());
   return ans;
}

int maxLevelSum(TreeNode *root)
{
   queue<TreeNode *> q;
   q.push(root);
   int sum = 0;
   int maxsum = INT_MIN;
   int maxlevel = 1;
   int level = 1;
   while (!q.empty())
   {
      int x = q.size();
      while (x--)
      {
         TreeNode *current = q.front();
         q.pop();
         sum += current->val;
         if (current->left != NULL)
         {
            q.push(current->left);
         }
         if (current->right != NULL)
         {
            q.push(current->right);
         }
      }
      if (sum > maxsum)
      {
         maxsum = sum;
         maxlevel = level;
      }
      sum = 0;
      level++;
   }
   return maxlevel;
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
}

// minimum difference in a binary search tree....
void inorder(TreeNode *root, vector<int> &in)
{
   if (root == NULL)
      return;
   inorder(root->left, in);
   in.push_back(root->val);
   inorder(root->right, in);
}

int getMinimumDifference(TreeNode *root)
{
   vector<int> in;
   inorder(root, in);
   int inidiff = in[1] - in[0];
   int mindiff = inidiff;
   for (int i = 1; i < in.size(); i++)
   {
      int currdif = in[i + 1] - in[i];
      mindiff = min(currdif, mindiff);
   }
   return mindiff;
}

// increasing triplet subsequnce....
bool increasingTriplet(vector<int> &nums)
{
   if (nums.size() < 3)
      return false;

   int x = INT_MIN, y = INT_MIN;
   x = nums[0];

   for (int i = 1; i < nums.size(); i++)
   {
      if (nums[i] < x)
      {
         x = nums[i];
      }
      else if (nums[i] >= x and nums[i] < y)
      {
         y = nums[i];
      }
      else
      {
         return true;
      }
   }
   return false;
}

// max consecutive 1 size subarray....

int longestOnes(vector<int> &nums, int k)
{
   int i = 0, j = 0, zerocnt = 0, size = 0, ans = 0;
   int n = nums.size();
   while (i < n and j < n)
   {
      if (nums[j] == 1)
      {
         // do nothing...
      }
      else if (nums[j] == 0)
      {
         zerocnt++;

         if (zerocnt > k)
         {
            while (zerocnt > k)
            {
               if (nums[i] == 1)
               {
                  // do nothing...
               }
               else if (nums[i] == 0)
               {
                  zerocnt--;
               }

               i++;
            }
         }
      }

      size = j - i + 1;
      ans = max(size, ans);

      j++;
   }
   return ans;
}

// longest subarray of 1 after deleting 1 element....
int longestSubarray(vector<int> &nums)
{
   int i = 0, j = 0, zerocnt = 0, size = 0, ans = 0;
   int k = 1;
   int n = nums.size();
   while (i < n and j < n)
   {
      if (nums[j] == 1)
      {
         // do nothing...
      }
      else if (nums[j] == 0)
      {
         zerocnt++;

         if (zerocnt > k)
         {
            while (zerocnt > k)
            {
               if (nums[i] == 1)
               {
                  // do nothing...
               }
               else if (nums[i] == 0)
               {
                  zerocnt--;
               }

               i++;
            }
         }
      }

      size = j - i + 1;
      ans = max(size, ans);

      j++;
   }
   if (ans > 0)
   {
      // because here we have to delete that 0 element so the length reduced by 1......
      ans = ans - 1;
   }
   return ans;
}

int singleNumber(vector<int> &nums)
{
}

int orangesRotting(vector<vector<int>> &grid)
{
   int n = grid.size();
   int m = grid[0].size();
   queue<pair<pair<int, int>, int>> q;
   vector<vector<int>> vis(n, vector<int>(m, 0));

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (grid[i][j] == 2)
         {
            vis[i][j] = 2;
            q.push({{i, j}, 0});
         }
      }
   }

   int maxtime = 0;
   vector<int> r = {-1, 0, 1, 0};
   vector<int> c = {0, 1, 0, -1};
   while (!q.empty())
   {
      int currrow = q.front().first.first;
      int currcol = q.front().first.second;
      int currtime = q.front().second;
      maxtime = max(maxtime, currtime);
      q.pop();
      for (int i = 0; i < 4; i++)
      {
         int nextrow = currrow + r[i];
         int nextcol = currcol + c[i];
         if (nextrow >= 0 and nextrow < n and nextcol >= 0 and nextcol < m and vis[nextrow][nextcol] != 2 and grid[nextrow][nextcol] == 1)
         {
            vis[nextrow][nextcol] = 2;
            q.push({{nextrow, nextcol}, currtime + 1});
         }
      }
   }

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (grid[i][j] == 1 and vis[i][j] != 2)
         {
            return -1;
         }
      }
   }
   return maxtime;
}

int maxArea(vector<int> &height)
{
   int start = 0;
   int end = height.size() - 1;
   int maxarea = 0;
   while (start < end)
   {
      int area = min(height[start], height[end]) * (end - start);
      maxarea = max(area, maxarea);
      if (min(height[start], height[end]) == height[start])
      {
         start++;
      }
      else if (min(height[start], height[end]) == height[end])
      {
         end--;
      }
   }
   return maxarea;
}

// The isdigit() function, declared in the <cctype> header file in C++, is used to determine whether the provided character represents a decimal digit. It returns 1(non-zero) if the provided character is a digit, 0 otherwise...
int myAtoi(string s)
{
   if (s.length() == 0)
      return 0;
   int i = 0;
   while (s[i] == ' ')
   {
      i++;
   }
   // removing all the leading spaces....
   s = s.substr(i);
   int sign = +1;
   long ans = 0;
   if (s[0] == '-')
   {
      sign = -1;
   }
   int Max = INT_MAX, Min = INT_MIN;
   i = (s[0] == '+' or s[0] == '-') ? 1 : 0;

   while (i < s.length())
   {
      if (s[i] == ' ' or isdigit(s[i]) == 0)
         break;
      ans = ans * 10 + (s[i] - '0');
      if (sign == -1 and -1 * ans < Min)
         return Min;
      if (sign == 1 and ans > Max)
         return Max;
      i++;
   }
   return sign * ans;
}
/*
Constraints:

-100.0 < x < 100.0
-2^31 <= n <= 2^31-1
n is an integer.
Either x is not zero or n > 0.
-10^4 <= xn <= 10^4
*/
double myPow(double x, int n)
{
   double ans = 1.0;
   int nn = n;
   if (nn < 0)
      nn = -1 * nn;
   while (nn != 0)
   {
      if (nn % 2 == 0)
      {
         x = x * x;
         nn = nn / 2;
      }
      else if (n % 2 == 1)
      {
         ans = ans * x;
         nn = nn - 1;
      }
   }
}

// daily temperature leecode monotonic stack.....

/*
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]


brute force -->
using 2 loops and whenever we get any value greater the current value take the difference of both the indexes and store it...
*/

vector<int> dailyTemperatures(vector<int> &temperatures)
{
   int n = temperatures.size();
   stack<int> st;
   vector<int> ans;
   for (int i = n - 1; i >= 0; i--)
   {
      if (st.empty())
      {

         ans.push_back(0);
      }
      else if (!st.empty() and temperatures[st.top()] > temperatures[i])
      {
         ans.push_back(st.top() - i);
      }
      else
      {
         while (!st.empty() and temperatures[st.top()] <= temperatures[i])
         {
            st.pop();
         }

         if (st.empty())
         {
            ans.push_back(0);
         }
         else
         {
            ans.push_back(st.top() - i);
         }
      }
      st.push(i);
   }
   reverse(ans.begin(), ans.end());
   return ans;
}
// heaps....

// top k frequnt elements...
vector<int> topKFrequent(vector<int> &nums, int k)
{
   map<int, int> m;
   for (auto it : nums)
   {
      m[it]++;
   }

   //   priority_queue<frequency, number> so that it sort on the basis of frequency...
   priority_queue<pair<int, int>> pq;
   for (auto it : m)
   {
      pq.push({it.second, it.first});
   }
   vector<int> ans;
   for (int i = 0; i < k; i++)
   {
      int element = pq.top().second;
      ans.push_back(element);
      pq.pop();
   }
   return ans;
}

string frequencySort(string s)
{
   map<char, int> m;
   for (auto it : s)
   {
      m[it]++;
   }
   priority_queue<pair<int, char>> pq;
   for (auto it : m)
   {
      pq.push({it.second, it.first});
   }

   string ans = "";
   while (!pq.empty())
   {
      char elem = pq.top().second;
      int cnt = pq.top().first;
      while (cnt--)
      {
         ans.push_back(elem);
      }

      pq.pop();
   }
   return ans;
}

int findPeakElement(vector<int> &nums)
{
   int n = nums.size();
   if (n == 1)
      return 0;
}

long long power(long long x, long long y, int mod)
{
   if (y == 0)
      return 1;
   long long ans = power(x, y / 2, mod);
   if (y % 2 == 0)
   {
      ans = (ans * ans) % mod;
   }
   else
   {
      ans = ((ans * ans) % mod) * x;
      ans = ans % mod;
   }
   return ans;
}

int countGoodNumbers(long long n)
{
   int mod = 1e9 + 7;
   long long odd = n / 2;
   long long even = (n / 2 + n % 2);
   return (power(5, even, mod) * power(4, odd, mod)) % mod;
}

/*
input--> 1 2 3 4 5 , k = 2
output--> 4 5 1 2 3

approach -->
 we found the breakindex from where we have to rotate which is equal to n-k (k=k%n) in above example idx=3 so
 1 2 3 ->NULL 4 5
 4 5 ->1 2 3 ->NULL

*/
int size(ListNode *head)
{
   int cnt = 0;
   while (head != NULL)
   {
      head = head->next;
      cnt++;
   }
   return cnt;
}

ListNode *rotateRight(ListNode *head, int k)
{
   if (head == NULL)
   {
      return head;
   }

   int n = size(head);
   if (n == 1 or k % n == 0)
   {
      return head;
   }

   k = k % n;
   int breakidx = n - k;

   ListNode *temp = head;
   int cnt = 0;
   while (temp != NULL and cnt < breakidx)
   {
      temp = temp->next;
      cnt++;
   }

   ListNode *newhead = temp->next;

   temp->next = NULL;

   temp = newhead;
   while (temp->next != NULL)
   {
      temp = temp->next;
   }
   temp->next = head;
   head = newhead;
   return head;
}

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
   priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
   for (auto it : points)
   {
      int dist = sqrt(it[0] * it[0] + it[1] * it[1]);
      pq.push({dist, {it[0], it[1]}});
   }
   vector<vector<int>> ans;
   for (int i = 0; i < k; i++)
   {
      auto it = pq.top();
      pq.pop();
      vector<int> temp;
      temp.push_back(it.second.first);
      temp.push_back(it.second.second);
      ans.push_back(temp);
   }
   return ans;
}

// the words which have same frequency we have to return them in laxicographical order....

vector<string> topKFrequent(vector<string> &words, int k)
{
   map<string, int> m;
   for (auto it : words)
   {
      m[it]++;
   }
   priority_queue<pair<int, string>> pq;
   for (auto it : m)
   {
      pq.push({it.second, it.first});
   }

   vector<string> ans;

   ans.push_back(pq.top().second);
   int prevfreq = pq.top().first;
   pq.pop();
   for (int i = 1; i < k; i++)
   {
      string temp = pq.top().second;
      int currfreq = pq.top().first;
      pq.pop();
      if (currfreq == prevfreq)
      {
         ans.push_back(temp);
         sort(ans.begin(), ans.end());
      }
      else
      {
         ans.push_back(temp);
      }
      prevfreq = currfreq;
   }

   return ans;
}

/*
during reversing a linked list -->

   ListNode *curr = head;
   ListNode *prev = NULL;
   ListNode *next;

   // either this loop we can use....
   while (curr != NULL)
   {
      next = prev;
      prev = curr;
      curr = curr->next;
      prev->next = next;
   }
   here in this method after the entire loop  terminates --->
   prev = newhead
   next=newhead->nex
   curr=NULL

   and we return prev as new head pointer...


   // or this loop we can use ....
   while (curr != NULL)
   {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
   }

   here in this method after the entire loop terminates ---->
   prev=newhead;
   next=NULL
   curr=NULL

   and here also we return the prev as new head pointer...


*/

// check palindrome linked list.....

ListNode *getmiddle(ListNode *head)
{
   ListNode *slow = head;
   ListNode *fast = head->next;
   while (fast != NULL and fast->next != NULL)
   {
      fast = fast->next->next;
      slow = slow->next;
   }
   return slow;
}

ListNode *reverse(ListNode *head)
{
   ListNode *curr = head;
   ListNode *prev = NULL;
   ListNode *next;

   while (curr != NULL)
   {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
   }

   return prev;
}

bool isPalindrome(ListNode *head)
{
   if (head == NULL or head->next == NULL)
   {
      return head;
   }
   ListNode *middle = getmiddle(head);
   ListNode *currhead = middle->next;

   // change the linked list structure by reversing it from the middle....
   middle->next = reverse(currhead);

   ListNode *temp1 = head;
   ListNode *temp2 = middle->next;

   while (temp2 != NULL)
   {
      if (temp1->val != temp2->val)
      {
         return false;
      }
      temp1 = temp1->next;
      temp2 = temp2->next;
   }
   // again reform the linked list .....
   currhead = middle->next;
   middle->next = reverse(currhead);
   return true;
}

/*
add 2 no given if form of 2 linked list.....

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
   ListNode *l3 = new ListNode(-1);
   ListNode *head = l3;
   int carry = 0;
   while (l1 != NULL and l2 != NULL)
   {
      int value = l1->val + l2->val + carry;
      carry = value / 10;
      value = value % 10;
      l3->next = new ListNode(value);

      l1 = l1->next;
      l2 = l2->next;
      l3 = l3->next;
   }

   while (l1 != NULL)
   {
      int value = l1->val + carry;
      carry = value / 10;
      value = value % 10;
      l3->next = new ListNode(value);

      l3 = l3->next;
      l1 = l1->next;
   }

   while (l2 != NULL)
   {
      int value = l2->val + carry;
      carry = value / 10;
      value = value % 10;
      l3->next = new ListNode(value);

      l3 = l3->next;
      l2 = l2->next;
   }

   while (carry != 0)
   {
      int value = carry;
      carry = value / 10;
      value = value % 10;
      l3->next = new ListNode(value);
      l3 = l3->next;
   }
   return head->next;
}

// merge 2 sorted linked list....

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
   ListNode *temp1 = list1;
   ListNode *temp2 = list2;

   ListNode *dummy = new ListNode(-1);
   ListNode *temp3 = dummy;
   // we have to use and because if any of them become NULL then the while loop terminate.....
   while (temp1 != NULL and temp2 != NULL)
   {
      if (temp1->val > temp2->val)
      {
         temp3->next = temp2;
         temp2 = temp2->next;
      }
      else if (temp1->val <= temp2->val)
      {
         temp3->next = temp1;
         temp1 = temp1->next;
      }
      temp3 = temp3->next;
   }

   while (temp1 != NULL)
   {
      temp3->next = temp1;
      temp1 = temp1->next;
      temp3 = temp3->next;
   }
   while (temp2 != NULL)
   {
      temp3->next = temp2;
      temp2 = temp2->next;
      temp3 = temp3->next;
   }
   temp3 = dummy->next;
   delete (dummy);
   return temp3;
}

ListNode *mergesort(ListNode *&head)
{
   // base conditions...
   if (head == NULL or head->next == NULL)
      return head;

   ListNode *mid = getmiddle(head);
   ListNode *left = head;
   ListNode *right = mid->next;
   mid->next = NULL;

   // recursive calls...
   left = mergesort(left);
   right = mergesort(right);
   ListNode *result = mergeTwoLists(left, right);

   return result;
}

ListNode *sortList(ListNode *head)
{
   ListNode *result = mergesort(head);
   return result;
}

// we have to sort a linked list , so here we mainly use merge sort.....

int subarrayGCD(vector<int> &nums, int k)
{
   int n = nums.size();

   int cnt = 0;
   for (int i = 0; i < n; i++)
   {
      int currentgcd = 0;
      for (int j = i; j < n; j++)
      {
         currentgcd = __gcd(currentgcd, nums[j]);
         if (currentgcd == k)
            cnt++;
      }
   }

   return cnt;
}

// this will give tle for nums size 10^4....

int subarraySum(vector<int> &nums, int k)
{
   int n = nums.size();
   int cnt = 0;
   for (int i = 0; i < n; i++)
   {
      int currentsum = 0;
      for (int j = i; j < n; j++)
      {
         currentsum += nums[j];
         if (currentsum == k)
            cnt++;
      }
   }
   return cnt;
}

// max consecutive ones.....
// we have to find the length of subarray which has 1 only....
int findMaxConsecutiveOnes(vector<int> &nums)
{
   int i = 0, j = 0, len = 0, maxlen = 0, n = nums.size();
   while (i < n and j < n)
   {
      if (nums[j] == 1)
      {
         // do nothing...
      }
      else if (nums[j] == 0)
      {
         i = j + 1;
      }
      j++;
      len = j - i + 1;
      maxlen = max(maxlen, len);
   }
   return maxlen;
}

// reverse bits leetcode....
uint32_t reverseBits(uint32_t n)
{
   uint32_t result = 0;
   for (int i = 0; i < 32; i++)
   {
      int lsb = n & 1;
      int reverselsb = lsb << (31 - i);
      result = result | reverselsb;
      n = n >> 1;
   }
   return result;
}

// it is given that out of the grid there is only water so for boundary 1 automatically based on no of boundaries it has that added to parmeter ....
int islandPerimeter(vector<vector<int>> &grid)
{
   int n = grid.size();
   int m = grid[0].size();

   int parameter = 0;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (grid[i][j] == 0)
         {
            continue;
         }
         else if (grid[i][j] == 1)
         {
            parameter += 4;
            if (i > 0)
               parameter -= grid[i - 1][j];
            if (j > 0)
               parameter -= grid[i][j - 1];
            if (i < n - 1)
               parameter -= grid[i + 1][j];
            if (j < m - 1)
               parameter -= grid[i][j + 1];
         }
      }
   }
   return parameter;
}

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<int> &r, vector<int> &c, int &area)
{
   int n = grid.size();
   int m = grid[0].size();
   vis[row][col] = 1;
   area++;
   for (int i = 0; i < 4; i++)
   {
      int newrow = row + r[i];
      int newcol = col + c[i];
      if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m and vis[newrow][newcol] == 0 and grid[newrow][newcol] == 1)
      {
         dfs(newrow, newcol, grid, vis, r, c, area);
      }
   }
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
   int n = grid.size();
   int m = grid[0].size();
   vector<vector<int>> vis(n, vector<int>(m, 0));
   vector<int> r = {0, -1, 0, 1};
   vector<int> c = {-1, 0, 1, 0};
   int area = 0;
   int mxarea = 0;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (vis[i][j] == 0 and grid[i][j] == 1)
         {
            dfs(i, j, grid, vis, r, c, area);
         }
         mxarea = max(area, mxarea);
         area = 0;
      }
   }
   return mxarea;
}

bool isIsomorphic(string s, string t)
{
   int n = s.length();
   int m = t.length();
   if (n != m)
      return false;

   map<char, char> m1;
   map<char, char> m2;

   for (int i = 0; i < n; i++)
   {
      if (m1.find(s[i]) == m1.end() and m2.find(t[i]) == m2.end())
      {
         m1[s[i]] = t[i];
         m2[t[i]] = s[i];
      }
      else if ((m1.find(s[i]) != m1.end() and m1[s[i]] != t[i]) or (m2.find(t[i]) != m2.end() and m2[t[i]] != s[i]))
      {
         return false;
      }
   }
   return true;
}

bool wordPattern(string pattern, string s)
{
   vector<string> v;
   for (int i = 0; i < s.length(); i++)
   {
      string temp = "";
      while (s[i] != ' ' and i < s.length())
      {
         temp += s[i];
         i++;
      }
      v.push_back(temp);
   }

   if (pattern.size() != v.size())
      return false;

   map<char, string> m1;
   map<string, char> m2;
   for (int i = 0; i < v.size(); i++)
   {
      if (m1.find(pattern[i]) == m1.end() and m2.find(v[i]) == m2.end())
      {
         m1[pattern[i]] = v[i];
         m2[v[i]] = pattern[i];
      }
      else if ((m1.find(pattern[i]) != m1.end() and m1[pattern[i]] != v[i]) or (m2.find(v[i]) != m2.end() and m2[v[i]] != pattern[i]))
      {
         return false;
      }
   }

   return true;
}

int minimumSum(int num)
{
   int n = num;
   vector<int> v;
   while (n != 0)
   {
      v.push_back(n % 10);
      n = n / 10;
   }
   sort(v.begin(), v.end());
   int n1 = v[0] * 10 + v[2];
   int n2 = v[1] * 10 + v[3];
   return n1 + n2;
}

int digsum(int n)
{
   int sum = 0;
   while (n != 0)
   {
      sum += n % 10;
      n = n / 10;
   }
   return sum;
}

int differenceOfSum(vector<int> &nums)
{
   int sum = 0;
   int digitsum = 0;
   for (auto it : nums)
   {
      sum += it;
      digitsum += digsum(it);
   }
   int ans = abs(sum - digitsum);
   return ans;
}

int maximizeSum(vector<int> &nums, int k)
{
   sort(nums.rbegin(), nums.rend());

   int n = nums[0];
   int sum = 0;
   while (k--)
   {
      sum += n;
      n = n + 1;
   }
   return sum;
}

int minOperations(vector<int> &nums)
{
   int n = nums.size();
   int operation = 0;
   for (int i = 0; i < n - 1; i++)
   {
      if (nums[i + 1] <= nums[i])
      {
         int change = (nums[i] - nums[i + 1]) + 1;
         operation = operation + change;
         nums[i + 1] += change;
      }
   }
   return operation;
}

// here we sort the array and then pair in the same order ....
int arrayPairSum(vector<int> &nums)
{
   sort(nums.begin(), nums.end());
   int maxsum = 0;
   int n = nums.size();
   vector<pair<int, int>> v;
   for (int i = 0; i < n; i += 2)
   {
      v.push_back({nums[i], nums[i + 1]});
   }
   for (auto it : v)
   {
      int currmax = max(it.first, it.second);
      maxsum += currmax;
   }

   return maxsum;
}

int minimumDifference(vector<int> &nums, int k)
{
   int n = nums.size();
   sort(nums.begin(), nums.end());
   int mindiff = INT_MAX;
   int currdif = nums[k - 1] - nums[0];
   mindiff = min(mindiff, currdif);

   int i = k;
   while (i < n)
   {
      currdif = nums[i] - nums[i - k + 1];

      mindiff = min(currdif, mindiff);
      i++;
   }
   return mindiff;
}

// maximum no of units ....

// boxtype[i]=no of box, no of unit per box.

int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
{
   priority_queue<pair<int, int>> pq;
   for (auto it : boxTypes)
   {
      pq.push({it[1], it[0]});
   }
   int ans = 0;
   int currsize = 0;

   while (currsize < truckSize and !pq.empty())
   {
      auto it = pq.top();
      pq.pop();

      if (currsize + it.second <= truckSize)
      {
         ans += (it.second * it.first);
         currsize += it.second;
      }
      else
      {
         ans += ((truckSize - currsize) * it.first);
         currsize += (truckSize - currsize);
      }
   }
   return ans;
}

int minTimeToType(string word)
{
   char a = 'a'; // since initially the pointer is at a ..
   int cnt = 0;
   int minn = 0;
   int currdif;
   char ch;
   for (int i = 0; i < word.length(); i++)
   {
      ch = word[i];
      if (ch > a)
      {
         currdif = ch - a;
      }
      else
      {
         currdif = a - ch;
      }
      if (currdif <= 13)
      {
         minn = currdif;
      }
      else
      {
         minn = 26 - currdif;
      }
      cnt += minn;
      cnt += 1; // for 1 unit of typing...

      // make a equals to current letter so that next time it compare from here...
      a = word[i];
   }

   return cnt;
}

// in this question the minimun no of operations is equal to the no of unique no....
int minimumOperations(vector<int> &nums)
{
   set<int> st;
   for (auto it : nums)
   {
      st.insert(it);
   }
   return st.size();
}

// merge intervals........

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
   int n = intervals.size();
   sort(intervals.begin(), intervals.end());
   vector<vector<int>> ans;
   vector<int> tempinterval = intervals[0];
   for (int i = 1; i < n; i++)
   {
      if (intervals[i][0] <= tempinterval[1])
      {
         tempinterval[1] = max(tempinterval[1], intervals[i][1]);
      }
      else
      {
         ans.push_back(tempinterval);
         //   where we got seperate interval start we make it our current value to check for the next...
         tempinterval = intervals[i];
      }
   }
   //  there is last one is still remaining...
   ans.push_back(tempinterval);
   return ans;
}

int deepestLeavesSum(TreeNode *root)
{
   if (root == NULL)
      return 0;
   queue<TreeNode *> q;

   q.push(root);
   vector<int> v;
   while (!q.empty())
   {
      int size = q.size();
      int sum = 0;
      for (int i = 0; i < size; i++)
      {
         TreeNode *curr = q.front();
         q.pop();
         sum += curr->val;

         if (curr->left != NULL)
         {
            q.push(curr->left);
         }
         if (curr->right != NULL)
         {
            q.push(curr->right);
         }
      }
      v.push_back(sum);
   }

   int ans = v[v.size() - 1];
   return ans;
}

// sort array by parity....

// we just swap whenver we found any even no with the array of 0 1 2 .. and so on....
vector<int> sortArrayByParity(vector<int> &nums)
{
   int i = 0, j = 0, n = nums.size();
   while (i < n and j < n)
   {
      if (nums[i] % 2 != 0)
      {
         i++;
      }
      else if (nums[i] % 2 == 0)
      {
         swap(nums[i], nums[j]);
         j++;
         i++;
      }
   }
   return nums;
}

// kth smallest node in bst...

void inorder(TreeNode *root, vector<int> &in)
{
   if (root == NULL)
      return;
   inorder(root->left, in);
   in.push_back(root->val);
   inorder(root->right, in);
}
int kthSmallest(TreeNode *root, int k)
{
   vector<int> in;
   inorder(root, in);
   int ans = in[k - 1];
   return ans;
}

int minPairSum(vector<int> &nums)
{
   sort(nums.begin(), nums.end());
   int s = 0;
   int e = nums.size() - 1;
   vector<int> sum;
   while (s < e)
   {
      sum.push_back(nums[s++] + nums[e--]);
   }

   sort(sum.rbegin(), sum.rend());
   return sum[0];
}

// 1337. The K Weakest Rows in a Matrix ........

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
   int n = mat.size();
   int m = mat[0].size();
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

   for (int i = 0; i < n; i++)
   {
      int cnt1 = 0;
      for (int j = 0; j < m; j++)
      {
         if (mat[i][j] == 1)
            cnt1++;
      }
      pq.push(make_pair(cnt1, i));
   }
   vector<int> ans;
   for (int i = 0; i < k; i++)
   {
      auto it = pq.top();
      pq.pop();
      ans.push_back(it.second);
   }

   return ans;
}

// if we want to optimize the space then we can use max heap....

// farhest building we can reach.....

int furthestBuilding(vector<int> &heights, int bricks, int ladders)
{
}

// the number of airthmatic triplets....
/*
i < j < k,
nums[j] - nums[i] == diff, and
nums[k] - nums[j] == diff.


we take the the first if condition because for input --> 1 1 1 4 7
there is only 1 aithmatic triple --> (1 4 7) we dont count each triple corresponding to each 1 because we have to count only the unique triplets...

*/
int arithmeticTriplets(vector<int> &nums, int diff)
{

   int n = nums.size();
   int cnt = 0;
   for (int i = 0; i < n; i++)
   {
      if (i > 0)
         while (nums[i - 1] == nums[i] and i < n - 1)
            i++;

      int lb = lower_bound(nums.begin() + i + 1, nums.end(), nums[i] + diff) - nums.begin();
      if (lb != n and nums[lb] - nums[i] == diff)
      {
         int secondlb = lower_bound(nums.begin() + lb + 1, nums.end(), nums[lb] + diff) - nums.begin();
         if (secondlb != n and nums[secondlb] - nums[lb] == diff)
            cnt++;
      }
   }
   return cnt;
}

// no of uuequal triplets in the array.....
/*
0 <= i < j < k < nums.length
nums[i], nums[j], and nums[k] are pairwise distinct.
In other words, nums[i] != nums[j], nums[i] != nums[k], and nums[j] != nums[k].

here nums.length = 100 so we can use brute force approach...
*/

int unequalTriplets(vector<int> &nums)
{
   int n = nums.size();
   int cnt = 0;
   for (int i = 0; i < n; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         for (int k = j + 1; k < n; k++)
         {
            if (nums[i] != nums[j] and nums[j] != nums[k] and nums[k] != nums[i])
               cnt++;
         }
      }
   }
   return cnt;
}

// count square sum triplets.....
/*
A square triple (a,b,c) is a triple where a, b, and c are integers and a^2 + b^2 = c^2.
Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

Input: n = 5
Output: 2
Explanation: The square triples are (3,4,5) and (4,3,5).

n(max )=250
so we can use 2 or 3 loops to solve them....

*/

// brute force using 3 loops....
int countTriples(int n)
{
   int count = 0;
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= n; j++)
      {
         for (int k = 1; k <= n; k++)
         {
            if (pow(i, 2) + pow(j, 2) == pow(k, 2))
               count++;
         }
      }
   }
   return count;
}

// optimize approach using only 2 loops.....
int countTriples(int n)
{
   int cnt = 0;
   for (int i = 1; i <= n; i++)
   {
      for (int j = i + 1; j <= n; j++)
      {
         int sqrsum = i * i + j * j;
         int k = (int)sqrt(sqrsum);
         // because then thera are 2 pairs (i,j,k) and (j,i,k) so we increase the cnt by 2....
         if (k * k == sqrsum and k <= n)
            cnt += 2;
      }
   }

   return cnt;
}

// winner of the bowling game......
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
         if (player1[i - 1] == 10 or player1[i - 2] == 10)
            sum1 += (2 * player1[i]);
         else
            sum1 += player1[i];
      }
   }

   for (int i = 0; i < player2.size(); i++)
   {
      if (i == 0)
         sum2 += player2[i];
      else if (i == 1)
      {
         if (player2[i - 1] == 10)
            sum2 += (2 * player2[i]);
         else
            sum2 += player2[i];
      }
      else
      {
         if (player2[i - 1] == 10 or player2[i - 2] == 10)
            sum2 += (2 * player2[i]);
         else
            sum2 += player2[i];
      }
   }

   if (sum1 == sum2)
      return 0;
   else if (sum1 > sum2)
      return 1;
   else
      return 2;
}

// if both the array has same size then we can merge the 2 loops.....

int isWinner(vector<int> &player1, vector<int> &player2)
{
   int n = player1.size();
}

// delete columns to make sorted...........
int minDeletionSize(vector<string> &strs)
{
   int n = strs.size();
   int m = strs[0].size();
   int cnt = 0;

   if (n == 0)
      return cnt;

   // we have to traverse the vector of string column wise.....
   for (int j = 0; j < m; j++)
   {
      for (int i = 1; i < n; i++)
      {
         if (strs[i - 1][j] <= strs[i][j])
         {
            continue;
         }
         else if (strs[i - 1][j] > strs[i][j])
         {
            cnt++;
            break;
         }
      }
   }

   return cnt;
}

// leetcode 2670.........

vector<int> distinctDifferenceArray(vector<int> &nums)
{
   int n = nums.size();
   vector<int> pre, suf;
   unordered_set<int> st;
   for (int i = 0; i < n; i++)
   {
      st.insert(nums[i]);
      pre.push_back(st.size());
   }

   st.clear();
   for (int i = n - 1; i >= 0; i--)
   {
      st.insert(nums[i]);
      suf.push_back(st.size());
   }
   reverse(suf.begin(), suf.end());
   suf.push_back(0);

   vector<int> ans;
   for (int i = 0; i < n; i++)
   {
      ans.push_back(pre[i] - suf[i + 1]);
   }

   return ans;
}

// leetcode 1941........
bool areOccurrencesEqual(string s)
{
   map<char, int> m;
   for (auto it : s)
   {
      m[it]++;
   }
   vector<int> temp;
   for (auto it : m)
      temp.push_back(it.second);

   if (temp.size() == 1)
      return true;
   int a = temp[0];
   for (int i = 1; i < temp.size(); i++)
   {
      if (temp[i] != a)
         return false;
   }
   return true;
}

// leetcode 2283.......
bool digitCount(string num)
{
   map<char, int> m;
   for (auto it : num)
      m[it]++;

   for (int i = 0; i < num.size(); i++)
   {
      int digit = i, fre = num[i] - '0';
      // if at any index we found the condition is not match then we return false .....
      if (m[digit + '0'] != fre)
         return false;
   }
   return true;
}

// leetcode 2053.......

string kthDistinct(vector<string> &arr, int k)
{
   unordered_map<string, int> m;
   for (auto it : arr)
      m[it]++;

   vector<string> temp;
   for (auto it : m)
   {
      if (it.second == 1)
         temp.push_back(it.first);
   }

   if (temp.size() < k)
      return "";
   else
      return temp[k - 1];
}

bool isconsistent(string allow, string s)
{
   unordered_map<char, int> m;
   for (auto it : s)
      m[it]++;

   for (auto it : m)
   {
      if (allow.find(it.first) == string::npos)
         return false;
   }
   return true;
}
int countConsistentStrings(string allowed, vector<string> &words)
{
   int n = words.size();
   int cnt = 0;
   for (int i = 0; i < n; i++)
   {
      if (isconsistent(allowed, words[i]) == true)
         cnt++;
   }
   return cnt;
}
// optimized version of the code........
int countConsistentStrings(string allowed, vector<string> &words)
{
   unordered_set<char> st(allowed.begin(), allowed.end());
   int cnt = 0;
   for (int i = 0; i < words.size(); i++)
   {
      string temp = words[i];
      bool ispresent = true;
      for (int j = 0; j < temp.length(); j++)
      {
         if (st.find(temp[j]) == st.end())
         {
            ispresent = false;
            break;
         }
      }
      if (ispresent)
         cnt++;
   }

   return cnt;
}

vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
{
   vector<vector<int>> mat(rows, vector<int>(cols, 0));
   priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         mat[i][j] = abs(i - rCenter) + abs(j - cCenter);
         pq.push({mat[i][j], {i, j}});
      }
   }
   vector<vector<int>> ans;
   while (!pq.empty())
   {
      ans.push_back(pq.top().second);
      pq.pop();
   }
   return ans;
}

vector<int> maxSubsequence(vector<int> &nums, int k)
{
}

// leetcode 2087 ...............

int minCost(vector<int> &startPos, vector<int> &homePos, vector<int> &rowCosts, vector<int> &colCosts)
{
   int ans = 0;

   // this is cost for row traversal....
   if (homePos[0] >= startPos[0])
   {
      for (int i = startPos[0] + 1; i <= homePos[0]; i++)
         ans += rowCosts[i];
   }
   else
   {
      for (int i = startPos[0] - 1; i >= homePos[0]; i--)
         ans += rowCosts[i];
   }

   // similarly we have to found the cost for column traversal.....

   if (homePos[1] >= startPos[1])
   {
      for (int i = startPos[1] + 1; i <= homePos[1]; i++)
         ans += colCosts[i];
   }
   else
   {
      for (int i = startPos[1] - 1; i >= homePos[1]; i--)
         ans += colCosts[i];
   }

   return ans;
}

// rooms and keys....

void bfs(int src, vector<vector<int>> &rooms, vector<int> &vis)
{
   queue<int> q;
   vis[src] = 1;
   q.push(src);
   while (!q.empty())
   {
      int key = q.front();
      q.pop();
      for (auto it : rooms[key])
      {
         if (vis[it] == 0)
         {
            vis[it] = 1;
            q.push(it);
         }
      }
   }
}

void dfs(int src, vector<vector<int>> &rooms, vector<int> &vis)
{
   vis[src] = 1;
   for (auto it : rooms[src])
   {
      if (vis[it] == 0)
      {
         dfs(it, rooms, vis);
      }
   }
}

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
   int n = rooms.size();
   vector<int> visit(n, 0);

   // here in the function we pass 0 as the source because initially we only have the key of room 0 ....

   // we can use any of them.....
   dfs(0, rooms, visit);
   bfs(0, rooms, visit);

   for (auto it : visit)
   {
      if (it == 0)
         return false;
   }
   return true;
}

// largest value in each tree row.....

vector<int> largestValues(TreeNode *root)
{
   vector<int> ans;
   queue<TreeNode *> q;
   if (root == NULL)
      return ans;
   q.push(root);
   while (!q.empty())
   {

      int size = q.size();
      int maxi = 0;
      for (int i = 0; i < size; i++)
      {
         TreeNode *node = q.front();
         q.pop();
         maxi = max(node->val, maxi);

         if (node->left != NULL)
            q.push(node->left);
         if (node->right != NULL)
            q.push(node->right);
      }
      ans.push_back(maxi);
   }
   return ans;
}

int timeRequiredToBuy(vector<int> &tickets, int k)
{
   int n = tickets.size(), target = tickets[k];
   int cnt = 0;
   int flag = false;
   while (true)
   {
      for (int i = 0; i < n; i++)
      {
         if (tickets[i] > 0 and tickets[k] > 0)
         {
            tickets[i] -= 1;
            cnt++;
         }
         if (tickets[k] == 0)
         {
            flag = true;
            break;
         }
      }
      if (flag == true)
         break;
   }
   return cnt;
}

// optimized.....
int timeRequiredToBuy(vector<int> &tickets, int k)
{
   int n = tickets.size(), time = 0;
   for (int i = 0; i < n; i++)
   {
      if (tickets[i] < tickets[k])
         time += tickets[i];
      else
         time += tickets[k];

      if (i > k and tickets[i] >= tickets[k])
         time--;
   }

   return time;
}

// contain duplicate 2 ......
// we have to find 2 distinct indexes such that nums[i] == nums[j] and abs(i - j) <= k.....

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
   int n = nums.size();
   unordered_map<int, int> m;
   for (int i = 0; i < n; i++)
   {
      if (m.find(nums[i]) != m.end())
      {
         if (abs(i - nums[i]) <= k)
            return true;
      }
      m[nums[i]] = i;
   }
   // if after the entire traversal we cant return true it means there is no such indexes exist so we return false.....
   return false;
}

// contains duplicate 3 .........
bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
{
   int n = nums.size();
   vector<pair<int, int>> v(n);
   for (int i = 0; i < n; i++)
   {
      v[i].first = nums[i];
      v[i].second = i;
   }
   sort(v.begin(), v.end());
   for (int i = 0; i < n; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         if (v[i].first + valueDiff >= v[j].first)
         {
            if (abs(v[i].second - v[j].second) <= indexDiff)
            {
               return true;
            }
         }
         else
         {
            break;
         }
      }
   }
   return false;
}

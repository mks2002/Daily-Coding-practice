// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long int
// #define rep(i, a, b) for (int i = a; i < b; i++)
// #define vi vector<int>
// #define vvi vector<vector<int>>
// #define pi pair<int, int>
// #define vpi vector<pair<int, int>>
// #define mii map<int, int>
// #define pb push_back
// #define __mayuk                      \
//    ios_base::sync_with_stdio(false); \
//    cin.tie(NULL);

// vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
// {
//    int n = nums1.size();
//    int m = nums2.size();
//    int total = n + m;
//    vector<vector<int>> ans;
//    int i = 0;
//    int j = 0;
//    while (i < n and j < m)
//    {
//       if (nums1[i][0] == nums2[j][0])
//       {
//          vector<int> temp(2);
//          temp[0] = nums1[i][0];
//          temp[1] = (nums1[i][1] + nums2[j][1]);
//          ans.push_back(temp);
//          i++;
//          j++;
//       }
//       else if (nums1[i][0] < nums2[j][0])
//       {
//          vector<int> temp(2);
//          temp[0] = nums1[i][0];
//          temp[1] = (nums1[i][1]);
//          ans.push_back(temp);
//          i++;
//       }
//       else
//       {
//          vector<int> temp(2);
//          temp[0] = nums2[j][0];
//          temp[1] = (nums2[j][1]);
//          ans.push_back(temp);
//          j++;
//       }
//    }
//    while (i < n)
//    {
//       vector<int> temp(2);
//       temp[0] = nums1[i][0];
//       temp[1] = (nums1[i][1]);
//       ans.push_back(temp);
//       i++;
//    }
//    while (j < m)
//    {
//       vector<int> temp(2);
//       temp[0] = nums2[j][0];
//       temp[1] = (nums2[j][1]);
//       ans.push_back(temp);
//       j++;
//    }
//    return ans;
// }

// int minOperations(int n)
// {
//    int ans = __popcount(n);
//    return ans + 1;
// }

// int main()
// {
//    __mayuk;

//    return 0;
// }

#include <bits/stdc++.h>
using namespace std;
// #define int long long int
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

int passThePillow(int n, int time)
{
   int ans = 0;
   if (time == n)
      ans = n - 1;
   else if (time < n)
   {
      ans = 1 + time;
   }
   else
   {

      int div = time / (n - 1);
      if (div % 2 == 1)
      {
         time = time % (n - 1);
         ans = n - time;
      }
      else
      {
         time = time % (n - 1);
         ans = time + 1;
      }
   }
   return ans;
}

// if (t <= sum)
// {
//    for (int i = 0; i < n; i++)
//    {
//       if (t <= sum1[i])
//       {
//          ans1 = i + 1;
//          if (t <= sum1[0])
//          {
//             ans2 = t;
//          }
//          else
//          {
//             ans2 = t - sum1[i - 1];
//          }

//          break;
//       }
//    }
// }
// else
// {
//    int temp = t % sum;

//    for (int i = 0; i < n; i++)
//    {
//       if (temp <= sum1[i])
//       {
//          ans1 = i + 1;
//          if (temp <= sum1[0])
//          {
//             ans2 = temp;
//          }
//          else
//          {
//             ans2 = temp - sum1[i - 1];
//          }

//          break;
//       }
//    }
// }

// int height(TreeNode *root)
// {
//    if (root == NULL)
//       return 0;
//    int lh = height(root->left);
//    int rh = height(root->right);
//    return max(lh, rh) + 1;
// }

// long long kthLargestLevelSum(TreeNode *root, int k)
// {
//    int level = height(root);

//    if (level < k)
//    {
//       return -1;
//    }

//    long long sum = 0;
//    queue<TreeNode *> q;
//    vector<long long int> ans;
//    if (root == NULL)
//    {
//       ans.push_back(sum);
//       return 0;
//    }
//    q.push(root);

//    while (!q.empty())
//    {
//       int x = q.size();
//       vector<int> v;
//       while (x--)
//       {
//          TreeNode *front = q.front();
//          q.pop();
//          if (front->left != NULL)
//          {
//             q.push(front->left);
//          }
//          if (front->right != NULL)
//          {
//             q.push(front->right);
//          }
//          sum += front->val;
//       }
//       ans.push_back(sum);
//    }

//    sort(ans.begin(), ans.end());
//    reverse(ans.begin(), ans.end();) return ans[k - 1];
// }

int findValidSplit(vector<int> &nums)
{
   if (nums.size() == 0)
      return -1;
   int n = nums.size();
   vector<long long int> preprod(n, 1);
   vector<long long int> suffprod(n, 1);

   preprod[0] = nums[0];
   for (int i = 1; i < n; i++)
   {
      preprod[i] = (nums[i] * preprod[i - 1]) % 1000000;
   }
   suffprod[n - 1] = nums[n - 1];
   for (int i = n - 2; i >= 0; i--)
   {
      suffprod[i] = (nums[i] * suffprod[i + 1]) % 1000000;
   }
   // reverse(suffprod.begin(), suffprod.end());

   vector<long long int> sec(n - 1, 1);
   for (int i = 0; i < n - 1; i++)
   {
      sec[i] = suffprod[i + 1];
   }

   int ans = -1;
   for (int i = 0; i < n - 1; i++)
   {
      if (__gcd(preprod[i], sec[i]) == 1)
      {
         ans = i;
         break;
      }
   }
   return ans;
}

int main()
{
   __mayuk;
   int n;
   cin >> n;
   vector<int> arr(n);
   rep(i, 0, n) cin >> arr[i];

   int ans = findValidSplit(arr);
   cout << ans << endl;
   return 0;
}

//  for (int i = 0; i < n; i++)
//    {
//       cout << preprod[i] << " ";
//    }
//    cout << endl;
//    for (int i = 0; i < n; i++)
//    {
//       cout << suffprod[i] << " ";
//    }
//    cout<<endl;
//    for(int i=0;i<n-1;i++){
//       cout<<sec[i]<<" ";
//    }
//    cout << endl;
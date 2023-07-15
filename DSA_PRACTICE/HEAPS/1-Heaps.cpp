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

   return 0;
}

// using min heap....
int kthSmallest(int arr[], int l, int r, int k)
{
   priority_queue<int, vector<int>, greater<int>> pq;
   for (int i = 0; i <= r; i++)
   {
      pq.push(arr[i]);
   }
   for (int i = 0; i < k - 1; i++)
   {
      pq.pop();
   }
   int ans = pq.top();
   return ans;
}

// using max heap .....
int kthSmallest(int arr[], int l, int r, int k)
{
   priority_queue<int> pq;
   for (int i = 0; i < k; i++)
   {
      pq.push(arr[i]);
   }
   for (int i = k; i <= r; i++)
   {
      if (arr[i] < pq.top())
      {
         pq.pop();
         pq.push(arr[i]);
      }
   }
   int ans = pq.top();
   return ans;
}

// ___________________________________________________________
// leetcode .......

// using max heap....
int findKthLargest(vector<int> &nums, int k)
{
   priority_queue<int> pq;
   for (int i = 0; i < nums.size(); i++)
   {
      pq.push(nums[i]);
   }
   for (int i = 0; i < k - 1; i++)
   {
      pq.pop();
   }
   int ans = pq.top();
   return ans;
}

// using mean heap....
int findKthLargest(vector<int> &nums, int k)
{
   priority_queue<int, vector<int>, greater<int>> pq;
   for (int i = 0; i < k; i++)
   {
      pq.push(nums[i]);
   }
   for (int i = k; i < nums.size(); i++)
   {
      if (nums[i] > pq.top())
      {
         pq.pop();
         pq.push(nums[i]);
      }
   }
   int ans = pq.top();
   return ans;
}

//______________________________________________________________________
// check a binary tree is a max heap or not......
struct Node
{
   int data;
   Node *left;
   Node *right;

   Node(int val)
   {
      data = val;
      left = right = NULL;
   }
};

int nodecount(struct Node *root)
{
   if (root == NULL)
      return 0;
   return (1 + nodecount(root->left) + nodecount(root->right));
}

// we assume 0 based indexing.....
bool isCBT(struct Node *root, int idx, int totalcount)
{
   if (root == NULL)
      return true;
   if (idx >= totalcount)
      return false;
   else
   {
      int left = isCBT(root->left, 2 * idx + 1, totalcount);
      int right = isCBT(root->right, 2 * idx + 2, totalcount);
      int ans = (left and right);
      return ans;
   }
}

// first 2 are of leaf nodes so there we dont need recursive calls but the 3rd one is middle node so there we requires recrursive call to solve it.....
bool isMaxorder(struct Node *root)
{
   //  if it is leaf node....
   if (root->left == NULL and root->right == NULL)
   {
      return true;
   }
   // it has only left child....
   else if (root->right == NULL)
   {
      int ans = (root->data > root->left->data);
      return ans;
   }
   // it has both the child....
   else
   { // this 3 are for current node....
      int left = (root->data > root->left->data);
      int right = (root->data > root->right->data);
      int tempans = (left and right);

      int leftsubtree = isMaxorder(root->left);
      int rightsubtree = isMaxorder(root->right);
      int ans = (tempans and leftsubtree and rightsubtree);
   }
}

bool isHeap(struct Node *tree)
{
   int idx = 0;
   int totalcount = nodecount(tree);
   if (isCBT(tree, idx, totalcount) == true and isMaxorder(tree) == true)
   {
      return true;
   }
   else
   {
      return false;
   }
}

// time complexity = O(n)+O(n)+O(n)...

//___________________________________________________________________
// merge 2 binary max heaps......

// for 1 based indexing....
void heapify(vector<int> &arr, int n, int i)
{
   int largest = i;
   int left = 2 * i;
   int right = 2 * i + 1;
   if (left <= n and arr[largest] < arr[left])
   {
      largest = left;
   }
   if (right <= n and arr[largest] < arr[right])
   {
      largest = right;
   }
   if (largest != i)
   {
      swap(arr[largest], arr[i]);
      heapify(arr, n, largest);
   }
}
// and here the loop runs from the ---->
// for(int i=size/2;i>0;i--){
//    heapify(arr,size,i);
// }

// for 0 based indexing....
void heapify(vector<int> &arr, int n, int i)
{
   int largest = i;
   int left = 2 * i + 1;
   int right = 2 * i + 2;
   if (left < n and arr[largest] < arr[left])
   {
      largest = left;
   }
   if (right < n and arr[largest] < arr[right])
   {
      largest = right;
   }
   if (largest != i)
   {
      swap(arr[largest], arr[i]);
      heapify(arr, n, largest);
   }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
   vector<int> ans;
   for (auto it : a)
   {
      ans.push_back(it);
   }
   for (auto it : b)
   {
      ans.push_back(it);
   }
   int size = ans.size();

   // converting the answer array into a heap ....
   for (int i = size / 2 - 1; i >= 0; i--)
   {
      heapify(ans, size, i);
   }
   return ans;
}

//___________________________________________________________________
// minimum cost of ropes.....

long long minCost(long long arr[], long long n)
{
   priority_queue<long long, vector<long long>, greater<long long>> pq;
   for (int i = 0; i < n; i++)
   {
      pq.push(arr[i]);
   }
   long long cost = 0;
   while (pq.size() > 1)
   {
      long long a = pq.top();
      pq.pop();
      long long b = pq.top();
      pq.pop();
      long long sum = a + b;
      cost += sum;
      pq.push(sum);
   }

   return cost;
}

//_________________________________________________________________________

// convert bst into a min heap.....
// given that the bst is also a complete binary tree.....

//_________________________________________________________

// Kth largest subarray sum......
// m1 ................
int getKthLargest(vector<int> &arr, int k)
{
   int n = arr.size();
   vector<int> subarrsum;
   for (int i = 0; i < n; i++)
   {
      int sum = 0;
      for (int j = i; j < n; j++)
      {
         sum += arr[j];
         subarrsum.push_back(sum);
      }
   }
   priority_queue<int> pq;
   for (int i = 0; i < subarrsum.size(); i++)
   {
      pq.push(subarrsum[i]);
   }
   for (int i = 0; i < k - 1; i++)
   {
      pq.pop();
   }
   int ans = pq.top();
   return ans;
}

// m2................
int getKthLargest(vector<int> &arr, int k)
{
   int n = arr.size();
   vector<int> subarrsum;
   for (int i = 0; i < n; i++)
   {
      int sum = 0;
      for (int j = i; j < n; j++)
      {
         sum += arr[j];
         subarrsum.push_back(sum);
      }
   }
   priority_queue<int, vector<int>, greater<int>> pq;
   for (int i = 0; i < k; i++)
   {
      pq.push(subarrsum[i]);
   }
   for (int i = k; i < subarrsum.size(); i++)
   {
      if (subarrsum[i] > pq.top())
      {
         pq.pop();
         pq.push(subarrsum[i]);
      }
   }
   int ans = pq.top();
   return ans;
}

// ____________________________________________________________________
// merge k sorted array.......

// ........kth smallest element in the sorted matrix.........
// the rows and the columns of the matrix is sorted....

int kthSmallest(vector<vector<int>> &matrix, int k)
{
   priority_queue<int, vector<int>, greater<int>> pq;
   int n = matrix.size();
   int m = matrix[0].size();
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         pq.push(matrix[i][j]);
      }
   }
   for (int i = 0; i < k - 1; i++)
   {
      pq.pop();
   }
   int ans = pq.top();
   return ans;
}

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

struct Node
{
   int data;
   struct Node *left;
   struct Node *right;

   Node(int val)
   {
      data = val;
      left = right = NULL;
   }
};

// Function to Build Tree
Node *buildTree(string str)
{
   // Corner Case
   if (str.length() == 0 || str[0] == 'N')
      return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for (string str; iss >> str;)
      ip.push_back(str);

   // Create the root of the tree
   Node *root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node *> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while (!queue.empty() && i < ip.size())
   {

      // Get and remove the front of the queue
      Node *currNode = queue.front();
      queue.pop();

      // Get the current node's value from the string
      string currVal = ip[i];

      // If the left child is not null
      if (currVal != "N")
      {

         // Create the left child for the current Node
         currNode->left = new Node(stoi(currVal));

         // Push it to the queue
         queue.push(currNode->left);
      }

      // For the right child
      i++;
      if (i >= ip.size())
         break;
      currVal = ip[i];

      // If the right child is not null
      if (currVal != "N")
      {

         // Create the right child for the current node
         currNode->right = new Node(stoi(currVal));

         // Push it to the queue
         queue.push(currNode->right);
      }
      i++;
   }

   return root;
}

int32_t main()
{
   __mayuk;
   Node *root = buildTree(treeString);
   Solution ob;
   cout << ob.height(root) << endl;
   return 0;
}

Node *buildTree(string str)
{
   if (str.length() == 0 || str[0] == 'N')
      return NULL;

   vector<string> ip;

   istringstream iss(str);
   for (string str; iss >> str;)
      ip.push_back(str);

   Node *root = new Node(stoi(ip[0]));

   queue<Node *> queue;
   queue.push(root);

   int i = 1;
   while (!queue.empty() && i < ip.size())
   {

      Node *currNode = queue.front();
      queue.pop();

      string currVal = ip[i];

      if (currVal != "N")
      {

         currNode->left = new Node(stoi(currVal));

         queue.push(currNode->left);
      }

      i++;
      if (i >= ip.size())
         break;
      currVal = ip[i];

      if (currVal != "N")
      {

         currNode->right = new Node(stoi(currVal));

         queue.push(currNode->right);
      }
      i++;
   }

   return root;
}

class Solution
{
public:
   // Function to find the height of a binary tree.
   int height(struct Node *node)
   {
      // base case
      if (node == NULL)
      {
         return 0;
      }

      int left = height(node->left);
      int right = height(node->right);

      int ans = max(left, right) + 1;
      return ans;
   }
};

struct Node
{
   int data;
   struct Node *left;
   struct Node *right;
   Node(int x)
   {
      data = x;
      left = right = NULL;
   }
};

int height(struct Node *node)
{
   // base case
   if (node == NULL)
   {
      return 0;
   }

   int left = height(node->left);
   int right = height(node->right);

   int ans = max(left, right) + 1;
   return ans;
}

int diameter(node *root)
{
   if (root == NULL)
      return 0;

   int ldiameter = diameter(root->left);
   int rdiameter = diameter(root->right);

   int lh = height(root - left);
   int rh = height(root - right);

   int currentdiameter = lh + rh + 1;

   return max(ldiameter, max(rdiameter, currentdiameter));
}

// Function to return the diameter of a Binary Tree.

pair<int, int> diameterFast(Node *root)
{
   // base case
   if (root == NULL)
   {
      pair<int, int> p = make_pair(0, 0);
      return p;
   }

   pair<int, int> left = diameterFast(root->left);
   pair<int, int> right = diameterFast(root->right);

   int op1 = left.first;
   int op2 = right.first;
   int op3 = left.second + right.second + 1;

   pair<int, int> ans;
   ans.first = max(op1, max(op2, op3));
   ;
   ans.second = max(left.second, right.second) + 1;

   return ans;
}
int diameter(Node *root)
{

   return diameterFast(root).first;
}

// this is fast checking code for isbalanced ....

pair<bool, int> isBalancedFast(Node *root)
{
   // base case
   if (root == NULL)
   {
      pair<bool, int> p = make_pair(true, 0);
      return p;
   }

   pair<int, int> left = isBalancedFast(root->left);
   pair<int, int> right = isBalancedFast(root->right);

   bool leftAns = left.first;
   bool rightAns = right.first;

   bool diff = abs(left.second - right.second) <= 1;

   pair<bool, int> ans;
   ans.second = max(left.second, right.second) + 1;

   if (leftAns && rightAns && diff)
   {
      ans.first = true;
   }
   else
   {
      ans.first = false;
   }
   return ans;
}

bool isBalanced(Node *root)
{
   return isBalancedFast(root).first;
}

// sum tree gfg solution here we have to check if the data of root is equal to sum of its left subtree and right subtree except the leafe nodes....

pair<bool, int> isSumTreeFast(Node *root)
{

   // base case
   if (root == NULL)
   {
      pair<bool, int> p = make_pair(true, 0);
      return p;
   }

   if (root->left == NULL && root->right == NULL)
   {
      pair<bool, int> p = make_pair(true, root->data);
      return p;
   }

   pair<bool, int> leftAns = isSumTreeFast(root->left);
   pair<bool, int> rightAns = isSumTreeFast(root->right);

   bool isLeftSumTree = leftAns.first;
   bool isRightSumTree = rightAns.first;

   int leftSum = leftAns.second;
   int rightSum = rightAns.second;

   bool condn = root->data == leftSum + rightSum;

   pair<bool, int> ans;

   if (isLeftSumTree && isRightSumTree && condn)
   {
      ans.first = true;
      ans.second = root->data + leftSum + rightSum;
   }
   else
   {
      ans.first = false;
      ans.second = root->data + leftSum + rightSum;
   }
   return ans;
}
bool isSumTree(Node *root)
{
   return isSumTreeFast(root).first;
}
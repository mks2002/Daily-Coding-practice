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

struct TreeNode
{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// insertion in bst.....

TreeNode *insertIntoBST(TreeNode *root, int val)
{
   if (root == NULL)
      return new TreeNode(val);
   else if (root->val > val)
   {
      root->left = insertIntoBST(root->left, val);
   }
   else if (root->val < val)
   {
      root->right = insertIntoBST(root->right, val);
   }
   else
   {
      // if (root-> val==val)
      // cant insert the given data because it is already present in the bst...
   }
   return root;
}

// searching in bst...
TreeNode *searchBST(TreeNode *root, int val)
{
   if (root == NULL)
      return NULL;
   if (root->val == val)
   {
      return root;
   }
   else if (root->val < val)
   {
      return searchBST(root->right, val);
   }
   else
   {
      return searchBST(root->left, val);
   }
}

// delete in bst leetcode.....
TreeNode *inordersuccessor(TreeNode *root)
{
   root = root->right;
   while (root->left != NULL)
   {
      root = root->left;
   }
   return root;
}

TreeNode *inorderpredecessor(TreeNode *root)
{
   root = root->left;
   while (root->right != NULL)
   {
      root = root->right;
   }
   return root;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
   if (root == NULL)
      return NULL;

   if (key < root->val)
   {
      root->left = deleteNode(root->left, key);
   }
   else if (key > root->val)
   {
      root->right = deleteNode(root->right, key);
   }
   else
   {
      // ( if root->val == key )

      if (root->left == NULL and root->right == NULL)
      {
         delete (root);
         return NULL;
      }
      else if (root->left == NULL)
      {
         TreeNode *temp = root->right;
         delete (root);
         return temp;
      }
      else if (root->right == NULL)
      {
         TreeNode *temp = root->left;
         delete (root);
         return temp;
      }
      else
      {

         // either......
         TreeNode *temp = inordersuccessor(root);
         root->val = temp->val;
         root->right = deleteNode(root->right, temp->val);

         // Or....
         TreeNode *temp = inorderpredecessor(root);
         root->val = temp->val;
         root->left = deleteNode(root->left, temp->val);
      }
   }
   return root;
}

int32_t main()
{
   __mayuk;

   return 0;
}

// range sum in bst....

void inorder(TreeNode *root, vector<int> in)
{
   if (root == NULL)
      return;
   inorder(root->left, in);
   in.push_back(root->val);
   inorder(root->right, in);
}

int rangeSumBST(TreeNode *root, int low, int high)
{
   vector<int> inordrTrav;
   inorder(root, inordrTrav);
   int n = inordrTrav.size();
   int sum = 0;
   for (int i = 0; i < n; i++)
   {
      if (inordrTrav[i] >= low and inordrTrav[i] <= high)
      {
         sum += inordrTrav[i];
      }
   }
   return sum;
}

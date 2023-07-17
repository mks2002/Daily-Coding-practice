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
#define __mayuk                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// Tree Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function for Inorder Traversal
void printInorder(Node *root)
{
    if (!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// we have to find lowest common ancestor of 2 nodes in a binary tree......

/*
first approach -->
find path of root to first node .
find path of root to second node .
traverse both the path from end and where we found common element it is our lowest common ancestor ......
*/

// Function to return the lowest common ancestor in a Binary Tree.
Node *lca(Node *root, int n1, int n2)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftAns = lca(root->left, n1, n2);
    Node *rightAns = lca(root->right, n1, n2);

    // if for a particular node both its left and right answers are not null then it means this node is the lca so return it .....
    if (leftAns != NULL && rightAns != NULL)
        return root;
    else if (leftAns != NULL && rightAns == NULL)
        return leftAns;
    else if (leftAns == NULL && rightAns != NULL)
        return rightAns;
    else
        return NULL;
}

// time complexity --> O(n)  space complexity --> O(height )........

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
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// utility function to create a new node....
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

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

// diameter using the height function....
// t.c. ---> O(n^2)...
int diameter(Node *root)
{
    if (root == NULL)
        return 0;
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    int cd = height(root->left) + height(root->right) + 1;

    int ans = max(cd, max(ld, rd));
    return ans;
}

// Function to return the diameter of a Binary Tree in O(n)..........

// tihs is pair < diameter, height> in the given function.....

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

    int ld = left.first;
    int rd = right.first;
    int cd = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(cd, max(ld, rd));

    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(Node *root)
{
    pair<int, int> ans = diameterFast(root);

    int diameter = ans.first;
    return diameter;
}

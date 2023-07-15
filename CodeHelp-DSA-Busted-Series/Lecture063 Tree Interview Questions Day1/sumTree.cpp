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

// for each node the value of it is equal to the sum of left and right subtree nodes except the leaf nodes then it is sum tree.....

// we use pair< bool , sum> to check whether it is sum tree or not...

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

    bool condition = root->data == (leftSum + rightSum);

    pair<bool, int> ans;

    if (isLeftSumTree && isRightSumTree && condition)
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

int32_t main()
{
    __mayuk;

    return 0;
}

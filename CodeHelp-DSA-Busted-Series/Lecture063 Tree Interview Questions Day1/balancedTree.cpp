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

// Tree Node.....
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// difference between height of left and right subtree must be less than 1 for each node.....

int height(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left, right) + 1;
    return ans;
}

// this is O(n^2) time complexity.....
bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    
    // this is for left and right subtree...
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    // this is for current node....
    int lh = height(root->left);
    int rh = height(root->right);

    if (left == true and right == true and abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* the structure of the pair which we used in this function -->
 pair< isbalance(bool), height(int)>.......
*/

// this is O(n) time complexity....
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

    // checking for left and right subtree...
    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    //    if all this 3 values are true then the answer is true otherwise it is false....
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

int32_t main()
{
    __mayuk;

    return 0;
}

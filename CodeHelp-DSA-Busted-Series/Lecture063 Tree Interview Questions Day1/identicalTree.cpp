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

// Function to check if two trees are identical....

// time complexity of the tree O(n)...........
bool isIdentical(Node *r1, Node *r2)
{
    // base case
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }

    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }

    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }

    // check for left and right subtree...
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    // check the value of current node.....
    bool value = (r1->data == r2->data);

    // if all 3 are true then the answer is true otherwise it is false ....
    if (left && right && value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int32_t main()
{
    __mayuk;

    return 0;
}
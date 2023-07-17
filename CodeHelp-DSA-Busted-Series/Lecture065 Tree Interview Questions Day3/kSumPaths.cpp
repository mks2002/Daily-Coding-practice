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
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

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

// in this question we have to return the total such number of paths whose elements sum is equal to k ( a path can start from any node and can be ends at any node )...........

void solve(Node *root, int k, int &count, vector<int> path)
{
    // base case
    if (root == NULL)
        return;

    path.push_back(root->data);

    // left
    solve(root->left, k, count, path);
    // right
    solve(root->right, k, count, path);

    // check for K Sum

    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            count++;
    }

    // during returning from the recursion we need to again pop this current node from the path .....
    path.pop_back();
}

int sumK(Node *root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
}
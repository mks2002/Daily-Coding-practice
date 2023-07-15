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

// structure of the node ...
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// function to create a new node of a given value....
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

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

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, int> topNode;
    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;

        topNode[hd] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

/*

the code for topview and bottom view is almost same in case of topview whenever for a particular horizontal distance we found a node first time we store it into the map and for all other node of that same horizontal distance we dont store them in map because they are hidden below it from top view...

but in case of bottom view whenever we found new nodes value for a same horizontal distance we update this in the map so that all the above layer nodes values are updated with the bottom layer nodes values....

ex  -->     1
          /   \
         2     8
       /   \  /   \
      3    4 6    9

if we take this example then bottom view of this is 3 2 6 8 9
since  4 6 all are at the same horizontal distance so since 6 is at last from level order so it is visible in bottom view...

 */
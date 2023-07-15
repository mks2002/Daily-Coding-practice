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

/*
for solving the vertical order traversal we required a map<int,map<int,vector<int>>>nodes
which is storing
 m.first=horizontal distance (hd)
 m.second.first=current level (cl)
 m.second.second is a vector which store all the nodes of a particular hd and cl...

 one queue is also required queue<pair<Node *, pair<int, int>>> q;
 it storing node ,hd ,cl..
*/

vector<int> verticalOrder(Node *root)
{
    map<int, map<int, vector<int>>> nodes;

    queue<pair<Node *, pair<int, int>>> q;

    vector<int> ans;

    if (root == NULL)
        return ans;

    // for root both the horizontal distance and current level both are 0.....
    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if (frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));

        if (frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
for the leetcode solution we have to use map<int, map<int, multiset<int>>> m; because they are also given this condition -->
There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
if we try to do this using vector then it is very complex for sort each time the values based on the current level so we use the multiset because in multise all the values are stored in sorted order.....

*/

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> q;
    vector<vector<int>> ans;

    if (root == NULL)
        return ans;

    // for root both the horizontal distance and current level both are 0.....
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        pair<TreeNode *, pair<int, int>> p = q.front();
        q.pop();
        TreeNode *currnode = p.first;
        int horizontaldist = p.second.first;
        int currlevel = p.second.second;

        nodes[horizontaldist][currlevel].insert(currnode->val);

        if (currnode->left != NULL)
            q.push({currnode->left, {horizontaldist - 1, currlevel + 1}});

        if (currnode->right != NULL)
            q.push({currnode->right, {horizontaldist + 1, currlevel + 1}});
    }

    for (auto i : nodes)
    {
        vector<int> temp;
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                temp.push_back(k);
            }
        }

        ans.push_back(temp);
    }

    return ans;
}
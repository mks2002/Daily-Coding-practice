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
struct Node
{
    int data;
    struct Node *left, *right;
};


// since here in the main function the target is given in form of integer so we required this to get the node value corresponding to that integer target....
Node *getRef(Node *root, int target)
{
    if (root == NULL || root->data == target)
        return root;
    Node *left = getRef(root->left, target);
    Node *right = getRef(root->right, target);
    if (left != NULL)
        return left;
    if (right != NULL)
        return right;
}

vector<int> KDistanceNodes(Node *root, int target, int k)
{
    unordered_map<int, int> parent;
    queue<Node *> q;
    q.push(root);

    // by the end of first traversal we mark all the nodes with there respective parents .....
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *currnode = q.front();
            q.pop();

            if (currnode->left != NULL)
            {
                q.push(currnode->left);
                parent[currnode->left->data] = currnode->data;
            }
            if (currnode->right != NULL)
            {
                q.push(currnode->right);
                parent[currnode->right->data] = currnode->data;
            }
        }
    }

    unordered_map<int, int> visited;
    // after the first traversal the queue is empty....
    Node *tar = getRef(root, target);
    q.push(tar);
    while (!q.empty() and k--)
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *curnode = q.front();
            q.pop();
            visited[curnode->data] = 1;

            if (curnode->left != NULL and visited[curnode->left->data] == 0)
                q.push(curnode->left);

            if (curnode->right != NULL and visited[curnode->right->data] == 0)
                q.push(curnode->right);

            int parentnode = parent[curnode->data];
            Node *parentref = getRef(root, parentnode);
            if (parentref != NULL and visited[parentref->data] == 0)
                q.push(parentref);
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        ans.push_back(q.front()->data);
        q.pop();
    }

    sort(ans.begin(),ans.end());
    return ans;
}
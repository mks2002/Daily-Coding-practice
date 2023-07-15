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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

// first we do inorder preorder postorder traversal of a binary tree....

void solve_inorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    solve_inorder(root->left, ans);
    ans.push_back(root->val);
    solve_inorder(root->right, ans);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    solve_inorder(root, ans);
    return ans;
}

// 2...   preorder traversal...
void solve_preorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    ans.push_back(root->val);
    solve_preorder(root->left, ans);
    solve_preorder(root->right, ans);
}

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    solve_preorder(root, ans);
    return ans;
}

void solve_postorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    solve_postorder(root->left, ans);
    solve_postorder(root->right, ans);
    ans.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    solve_postorder(root, ans);
    return ans;
}

/*
stack<pair<TreeNode *, int>> st;
 1 2 3 --> pre in post --> left right nothing ...
*/

vector<int> AllTraversal(TreeNode *root)
{
    vector<int> pre, post, in;
    if (root == NULL)
        return pre;

    stack<pair<TreeNode *, int>> st;

    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else if (it.second == 3)
        {
            post.push_back(it.first->val);
        }
    }

    return pre;
}

// we have all the traversals store in this .....
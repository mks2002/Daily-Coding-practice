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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp;

        // this loop is for 1 entire level....
        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            temp.push_back(curr->val);

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

/*
we have to return average of each level as a result....

Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
*/

vector<double> averageOfLevels(TreeNode *root)
{
    vector<double> ans;
    if (root == NULL)
        return ans;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();

        long long sum = 0;
        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = q.front();
            q.pop();

            sum += curr->val;
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }

        double avg = sum * (1.0) / size;
        ans.push_back(avg);
    }
    return ans;
}

// zig zag traversal of binary tree....

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    bool leftoright = true;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);

        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            // based on this value the array is either in same order or in reverse order...
            int idx = leftoright ? i : size - i - 1;
            temp[idx] = curr->val;

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
        ans.push_back(temp);
        leftoright = !leftoright;
    }
    return ans;
}

/*
we have to return that level in answer which has the maximum levelOrder sum and level start from 1...

Constraints:
The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105

Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation:
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
*/

int maxLevelSum(TreeNode *root)
{
    int ans = 1;
    int maxsum = INT_MIN;
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (i == size - 1)
            {
                ans.push_back(curr->val);
            }

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
    return ans;
}

vector<int> leftSideView(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (i == 0)
            {
                ans.push_back(curr->val);
            }

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
    return ans;
}

// left=1 , right=2 roo=0 ....
// this code gives wrong answer in input  1 null 2 output should be 0 but it gives 2....

int sumOfLeftLeaves(TreeNode *root)
{
    int sum = 0;
    if (root == NULL)
        return sum;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = q.front().first;
            int position = q.front().second;
            q.pop();
            if (i == 0 and position == 1)
            {
                sum += curr->val;
            }

            if (curr->left != NULL)
            {
                q.push({curr->left, 1});
            }
            if (curr->right != NULL)
            {
                q.push({curr->right, 2});
            }
        }
    }

    return sum;
}
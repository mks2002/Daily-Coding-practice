// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to return a list of nodes visible from the top view
// from left to right in Binary Tree.

/*
in top view for one particular horizontal level there is only one node because rest nodes are not visible because of this ...
ex  -->     1
          /   \
         2     8
       /   \  /   \
      3     4 6    9

 output--> 3 2 1 8 9  because 4 6 are hide below 1 since they all are in same horizontal distance from root which is 0...


in top view code we have to use this 2 data structures...
map<int, int> topNode;   --> m[horizontal_dist]=node->data
queue<pair<Node *, int>> q;  --> pair<node*,horizontal_dist>

in case of topview whenever for a particular horizontal distance we found a node first time we store it into the map and for all other node of that same horizontal distance we dont store them in map because they are hidden below it from top view...
*/

vector<int> topView(Node *root)
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

        // if one value is present for a HD, then do nothing
        if (topNode.find(hd) == topNode.end())
        {
            topNode[hd] = frontNode->data;
        }

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



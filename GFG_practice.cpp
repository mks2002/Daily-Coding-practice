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

    sort(ans.begin(), ans.end());
    return ans;
}

int uniquePositions(string moves, long long k)
{
    int curridx = 0;
    unordered_set<int> unique;
    unique.insert(curridx);

    for (int i = 0; i < moves.length(); i++)
    {
        if (moves[i] == 'F')
        {
            curridx += k;
        }
        else if (moves[i] == 'B')
        {
            curridx -= k;
        }
        unique.insert(curridx);
    }

    return unique.size();
}

// Function to perform DFS and find the farthest node and its distance from a given source node
pair<long long, int> dfs(int node, const unordered_map<int, vector<pair<int, int>>> &graph, vector<bool> &visited, long long distance)
{
    visited[node] = true;
    long long max_distance = distance;
    int farthest_node = node;
    for (const auto &neighbor : graph.at(node))
    {
        int next_node = neighbor.first;
        int weight = neighbor.second;
        if (!visited[next_node])
        {
            auto [new_distance, new_farthest] = dfs(next_node, graph, visited, distance + weight);
            if (new_distance > max_distance)
            {
                max_distance = new_distance;
                farthest_node = new_farthest;
            }
        }
    }
    return {max_distance, farthest_node};
}

class Solution
{
public:
    bool check(int n, vector<int> &v, long long d, long long k)
    {

        for (int i = 0; i < n; i++)
        {
            if (i + 1 < n)
            {
                long long diff = v[i + 1] - v[i];
                if (diff <= k)
                {
                    long long total = diff * (k - diff) + diff * (diff + 1) / 2;
                    d -= total;
                }
                else
                {
                    long long total = k * (k + 1) / 2;
                    d -= total;
                }
            }
            else
            {
                long long total = k * (k + 1) / 2;
                d -= total;
            }

            if (d <= 0)
                return true;
        }
        return false;
    }
    int minimizeTopSpeed(int n, vector<int> &spells, long long trackLength)
    {
        long long l = 1, h = 1e9;
        long long ans = h;
        while (l <= h)
        {
            long long mid = l + (h - l) / 2;
            if (check(n, spells, trackLength, mid))
            {
                ans = min(ans, mid);
                h = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};

struct HashPair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Solution
{
public:
    vector<long long> longDrive(int n, vector<vector<int>> &edges, int q, vector<int> &query)
    {
        // Create an adjacency list to represent the tree structure
        vector<vector<pair<int, int>>> adj_list(n + 1);
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            adj_list[u].emplace_back(make_pair(v, weight));
            adj_list[v].emplace_back(make_pair(u, weight));
        }

        unordered_map<pair<int, int>, int, HashPair> memo;
        vector<int> result;

        function<int(int, int)> dfs = [&](int node, int parent)
        {
            auto key = make_pair(node, parent);
            if (memo.count(key))
            {
                return memo[key];
            }
            int max_dist = 0;
            for (const auto &neighbor : adj_list[node])
            {
                int neighbor_node = neighbor.first;
                int weight = neighbor.second;
                if (neighbor_node != parent)
                {
                    max_dist = max(max_dist, dfs(neighbor_node, node) + weight);
                }
            }
            memo[key] = max_dist;
            return max_dist;
        };

        for (int start_city : query)
        {
            int max_distance = dfs(start_city, 0);
            result.push_back(max_distance);
        }

        return result;
    }
};

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

// alien dictonary.........
vector<int> topoSort(int V, vector<int> adj[])
{
    int indegree[V] = {0};
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return ans;
}

// gfg version of the problem.....
string findOrder(string dict[], int N, int K)
{

    vector<int> adj[K];
    for (int i = 0; i < N - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.length(), s2.length());
        for (int j = 0; j < len; j++)
        {
            // similar to course schedule question which will come first that come in left during adjacency list conversion.....
            if (s1[j] != s2[j])
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }

    vector<int> topo = topoSort(K, adj);
    string ans = "";
    for (auto it : topo)
    {
        ans += (it + 'a');
    }

    return ans;
}

// in many cases the value of k is not given in that cases we have to use the value of k as 26 .....

// coding ninjas code studio.....
vector<char> getAlienLanguage(string *dictionary, int n)
{
    int k = 26;
    vector<int> adj[k];
    for (int i = 0; i < n - 1; i++)
    {
        string s1 = dictionary[i];
        string s2 = dictionary[i + 1];
        int len = min(s1.length(), s2.length());
        for (int j = 0; j < len; j++)
        {
            if (s1[j] != s2[j])
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }

    vector<int> topo = topoSort(k, adj);
    vector<char> ans;
    for (auto it : topo)
    {
        ans.push_back(it + 'a');
    }
    return ans;
}

// this is the leetcode version of the same problem but it is premium...
string alienOrder(vector<string> &words)
{
    int n = words.size(), k = 26;
    vector<int> adj[k];
    for (int i = 0; i < n - 1; i++)
    {
        string s1 = words[i];
        string s2 = words[i + 1];
        int len = min(s1.length(), s2.length());
        for (int j = 0; j < len; j++)
        {
            if (s1[j] != s2[j])
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }

    vector<int> topo = topoSort(k, adj);
    string ans = "";
    for (auto it : topo)
    {
        ans += (it + 'a');
    }

    return ans;
}

// now if it is asked when the order is not possible.......

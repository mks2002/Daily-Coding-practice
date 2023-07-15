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

// 1337. The K Weakest Rows in a Matrix......

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    int n = mat.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        int c1 = 0, m = mat[i].size();
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1)
                c1++;
        }

        pq.push(make_pair(c1, i));
    }

    // after the entire traversal the most weaker elements based on their 1 cnt and then based on their indexes if the 1 cnt is same for any 2 are in this heap.....
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

// if we want to optimize the space then we can use max heap.....

int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> pq;
    for (auto it : stones)
        pq.push(it);

    while (pq.size() > 1)
    {
        int largest = pq.top();
        pq.pop();
        int secondlargest = pq.top();
        pq.pop();

        if (largest != secondlargest)
            pq.push(largest - secondlargest);
        // else if both has same weights then do nothing....
    }

    if (pq.size() == 0)
        return 0;
    else
        return pq.top();
}


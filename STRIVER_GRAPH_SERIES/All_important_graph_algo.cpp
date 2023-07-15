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

// floyyd warshell algorithm.....

/*
this algorithm is used to compute the minimum distance of all nodes from all other remaining nodes...
T. C --> O(n^3)

alternative of this algorithm is we can use djkhastra on each of the vertex to calculate the distance of all other nodes from that vertex  its  T . C . --> O(v * elogv)

it is still better then floyd warshell time complexity..

but djkhastra fails under negative cycle or negative edges but there this algorithm can work .....
*/

// gfg problem....
// If Matrix[i][j]=-1, it means there is no edge from i to j....

void shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 1e9;
            if (i == j)
                matrix[i][j] = 0;
        }
    }

    //  this is the main algorithm....
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // checking if there is negative cycle or not ....
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][i] < 0)
        {
            // there exist negative cycle ....
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1e9)
                matrix[i][j] = -1;
        }
    }
}

// question based on floyd warshell algorithm .....
// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance....

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    // we have to create a dist matrix....
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    for (auto it : edges)
    {
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }

    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] == INT_MAX or dist[k][j] == INT_MAX)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int cntcity = n, cityno = -1;

    // now we have to traverse on each of the row to find how many nodes are at less then threshold distance......
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] <= distanceThreshold)
                cnt++;
        }

        if (cnt <= cntcity)
        {
            cntcity = cnt;
            cityno = i;
        }
    }
    return cityno;
}
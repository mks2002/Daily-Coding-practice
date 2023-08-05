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

// rotate image by 90 degree clockwise and anticlockwise ....

/*
for anticlockwise --> this is gfg version ...
take transpose and swap first and last row for all rows ...
*/
void rotateby90(vector<vector<int>> &matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            swap(matrix[i][j], matrix[j][i]);
    }

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
            swap(matrix[i][j], matrix[n - i - 1][j]);
    }
}

/*
for clockwise --> this is leetcode problem ...
take transpose and swap first and last col for all cols ...
*/
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    // taking transpose ...
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            swap(matrix[i][j], matrix[j][i]);
    }

    for (int j = 0; j < n / 2; j++)
    {
        for (int i = 0; i < n; i++)
        {
            swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }
}
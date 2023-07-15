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


// Input:
// N=5
// A=3, B=2
// x=1, y=2
// Output:
// 2
// Explanation:
// Current floor of the person is 3 (A=3)
// In first step ,lift can go x=1 floors up ,then 
// current floor will be 3+1=4 
// In second step ,lift can go y=2 floors down.then
// current floor will be 4-2 =2
// 2 steps is required to reach the floor B

int minSteps(int N, int A, int B, int x, int y)
{
    if (A == B)
        return 0;
    else if (A > B)
    {
        int temp=A-B;
        

    }
    else if (A < B)
    {

    }
}
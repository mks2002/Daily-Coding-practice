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

int maximum69Number(int num)
{
    string s = to_string(num);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '6')
        {
            s[i] = '9';
            break;
        }
    }

    int ans = stoi(s);
    return ans;
}

int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
{
    if (numOnes >= k)
        return k;
    else if ((numOnes + numZeros) >= k)
    {
        return numOnes;
    }
    else
    {

        int diff = k - (numOnes + numZeros);
        int ans = numOnes - diff;
        return ans;
    }
}
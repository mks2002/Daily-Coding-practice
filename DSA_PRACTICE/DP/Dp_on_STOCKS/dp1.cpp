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

/*
algorithm....

1. first we take the array[0] as initial buying price..
2. run a loop from 1 to n and in each step we consider array [i] as current selling price and calculate profit = sell - buy
3. change the mxprofit by maximum of it and current profit.
4. change the buying price by minimum of initial buying price and current array[i]..
*/

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int buyPrice = prices[0];
    int mxprofit = 0;

    for (int i = 1; i < n; i++)
    {
        int profit = prices[i] - buyPrice;
        mxprofit = max(mxprofit, profit);
        buyPrice = min(buyPrice, prices[i]);
    }

    return mxprofit;
}
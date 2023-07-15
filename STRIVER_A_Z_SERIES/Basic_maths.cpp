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

void sieve(int n)
{
    int *arr = new int(n + 1);
    for (int i = 0; i <= n; i++)
    {
        arr[i] = 1;
    }

    // O(n*n/2) ---> not optimized
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 1)
        {
            for (int j = 2 * i; j <= n; j = j + i)
            {
                arr[j] = 0;
            }
        }
    }

    /*
        try to optimize -->
        we have to start the inner loop from i*i becaue all other multiple of i like (2i , 3i , .. (i-1)*i)
        they are already marked by the number which come before i...
        ex 2i is marked by 2 because it is multiple of 2.
           3i is marked by 3
           (i-1)*i is marked by i-1 because it is multiple of i-1..

        since the inner loop starts from i*i we also run the outer loop upto sqrt(n) because if we run it more than sqrt(n) like upto n then the inner loops automatically breaks.
        ex n=25 and i=5
        so j starts from i*i =25
        but if we suppose i=6 --> then j=i*i =36  which is not correct .

    */

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (arr[i] == 1)
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                arr[j] = 0;
            }
        }
    }
}

// leetcode...
int countPrimes(int n)
{
    bool *arr = new bool[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = true;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (arr[i] == true)
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                arr[j] = false;
            }
        }
    }
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == true)
            cnt++;
    }
    return cnt;
}

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
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
#define __mayuk                      \
   ios_base::sync_with_stdio(false); \
   cin.tie(NULL);

void solve()
{
   int n, q;
   cin >> n >> q;
   vector<int> v(n), pre(n, 0);
   int sm = 0;
   for (int i = 0; i < n; i++)
   {
      cin >> v[i];
      sm += v[i];
   }
   pre[0] = v[0];
   for (int i = 1; i < n; i++)
      pre[i] = v[i] + pre[i - 1];
   while (q--)
   {
      int l, r, k;
      cin >> l >> r >> k;
      int kss = pre[r - 1] - (pre[l - 1] - v[l - 1]);
      int nsm = sm - kss + (r - l + 1) * k;
      if (nsm % 2)
         cout << "YES" << endl;
      else
         cout << "NO" << endl;
   }
}

int32_t main()
{
   __mayuk;
   int t;
   cin >> t;
   while (t--)
   {
      solve();
   }
   return 0;
}

int32_t main()
{
   __mayuk;
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      string s;
      cin >> s;
      map<char, vector<int>> m;
      char temp = 'a';
      for (int i = 0; i < 26; i++)
      {
         char curr = temp + i;
         for (int i = 0; i < n; i++)
         {
            if (s[i] == curr)
            {
               m[curr].push_back(i);
            }
         }
      }
      bool curr2 = true;
      for (auto it : m)
      {
         vector<int> temp = it.second;
         for (int i = 0; i < it.second.size() - 1; i++)
         {
            if ((temp[i + 1] - temp[i]) % 2 != 0)
            {

               curr2 = false;
               break;
            }
         }
      }

      if (curr2 == true)
      {
         cout << "YES" << endl;
      }
      else
      {
         cout << "NO" << endl;
      }
   }
   return 0;
}

int32_t main()
{
   __mayuk;
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      int arr[n];
      rep(i, 0, n) cin >> arr[i];
      int odd = 0;
      int even = 0;
      rep(i, 0, n)
      {
         if (arr[i] % 2 == 0)
            even += arr[i];
         else
         {
            odd += arr[i];
         }
      }
      if (even > odd)
      {
         cout << "YES" << endl;
      }
      else
      {
         cout << "NO" << endl;
      }
   }
   return 0;
}

int32_t main()
{
   __mayuk;
   int t;
   cin >> t;
   while (t--)
   {
      int a, b, c;
      cin >> a >> b >> c;
      if (a + b == c)
      {
         cout << "+" << endl;
      }
      else
      {
         cout << "-" << endl;
      }
   }
   return 0;
}

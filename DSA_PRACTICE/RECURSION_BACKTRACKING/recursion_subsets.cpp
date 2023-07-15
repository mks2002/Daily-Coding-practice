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

void print_subsequence(int idx, int n, vi &ds, vi &arr)
{
   if (idx == n)
   {
      if (ds.size() == 0)
      {
         cout << "{}" << endl;
      }
      for (auto it : ds)
      {
         cout << it << ' ';
      }
      cout << endl;
      return;
   }
   ds.push_back(arr[idx]);
   print_subsequence(idx + 1, n, ds, arr);
   ds.pop_back();

   print_subsequence(idx + 1, n, ds, arr);
}

void subsequnce_given_sum(int idx, int n, int sum, int s, vi &ds, vi &arr)
{
   if (idx == n)
   {
      if (s == sum)
      {
         for (auto it : ds)
         {
            cout << it << ' ';
         }
         cout << endl;
      }
      return;
   }
   ds.push_back(arr[idx]);
   s = s + arr[idx];
   subsequnce_given_sum(idx + 1, n, sum, s, ds, arr);
   ds.pop_back();
   s = s - arr[idx];

   subsequnce_given_sum(idx + 1, n, sum, s, ds, arr);
}

// in the same above question we have to print the first i.e. only subsequnce with the given sum....

bool subsequnce_sum(int idx, int n, int sum, int s, vi &ds, vi &arr)
{

   if (idx == n)
   {
      if (s == sum)
      {
         for (auto it : ds)
         {
            cout << it << ' ';
         }
         cout << endl;
         return true;
      }
      else
      {
         return false;
      }
   }
   ds.push_back(arr[idx]);
   s += arr[idx];
   if (subsequnce_sum(idx + 1, n, sum, s, ds, arr) == true)
   {
      return true;
   }
   ds.pop_back();
   s -= arr[idx];

   if (subsequnce_sum(idx + 1, n, sum, s, ds, arr) == true)
   {
      return true;
   }

   return false;
}

// count the no of subsequnce with the given sum......

int subsequnce_count(int idx, int n, int sum, int s, vi &ds, vi &arr)
{
   if (idx == n)
   {
      if (s == sum)
      {
         return 1;
      }
      else
      {
         return 0;
      }
   }
   ds.push_back(arr[idx]);
   
   s += arr[idx];
   int take = subsequnce_count(idx + 1, n, sum, s, ds, arr);
   ds.pop_back();
   s -= arr[idx];

   int nontake = subsequnce_count(idx + 1, n, sum, s, ds, arr);

   int ans = take + nontake;
   return ans;
}

int32_t main()
{
   __mayuk;

   int n;
   cin >> n;
   vi arr;
   rep(i, 0, n)
   {
      int x;
      cin >> x;
      arr.push_back(x);
   }
   int sum;
   cin >> sum;
   vi ds;
   cout << endl;
   // print_subsequence(0, n, ds, arr);
   subsequnce_given_sum(0, n, sum, 0, ds, arr);
   cout << "---------------------------------------------------------------------" << endl;
   subsequnce_sum(0, n, sum, 0, ds, arr);
   cout<<"-------------------------------------------------------------------------"<<endl;
   int ans=subsequnce_count(0,n,sum,0,ds,arr);
   cout<<ans<<endl;
   return 0;
}
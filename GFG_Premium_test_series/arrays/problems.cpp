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

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
   int i = 0;
   int j = 0;
   vector<int> temp;
   while (i < n and j < m)
   {
      if (arr1[i] < arr2[j])
      {
         temp.push_back(arr1[i]);
         i++;
      }
      else if (arr1[i] > arr2[j])
      {
         temp.push_back(arr2[j]);
         j++;
      }
      else
      {
         temp.push_back(arr1[i]);
         i++;
         j++;
      }
   }
   while (i < n)
   {
      temp.push_back(arr1[i++]);
   }
   while (j < m)
   {
      temp.push_back(arr2[j++]);
   }
   set<int> s;
   for (auto it : temp)
   {
      s.insert(it);
   }
   vector<int> ans;
   for (auto it : s)
   {
      ans.push_back(it);
   }
   return ans;
}

int NumberofElementsInIntersection(int a[], int b[], int n, int m)
{
   
}

int32_t main()
{
   __mayuk;

   return 0;
}
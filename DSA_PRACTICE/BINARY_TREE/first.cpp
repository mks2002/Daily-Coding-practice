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

struct node
{
   int data;
   node *left;
   node *right;
   node(int val)
   {
      data = val;
      left = NULL;
      right = NULL;
   }
};

int32_t main()
{
   __mayuk;
   node *root = new node(1);
   root->left = new node(2);
   root->right = new node(4);

   return 0;
}
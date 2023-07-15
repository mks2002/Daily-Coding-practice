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
#define __mayuk                     \
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
void rotate(vector<int> &nums, int k)
{

  // just to practice the modulus approach
  int n = nums.size();
  vector<int> temp(n);

  for (int i = 0; i < n; i++)
  {

    temp[(i + k) % n] = nums[i];
  }

  for (int i = 0; i < nums.size(); i++)
  {
    nums[i] = temp[i];
  }
}

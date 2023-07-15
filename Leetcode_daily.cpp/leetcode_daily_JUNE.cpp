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

int32_t main()
{
   __mayuk;

   return 0;
}

int maxProduct(vector<int> &nums)
{
   sort(nums.begin(), nums.end());
   reverse(nums.begin(), nums.end());
   return (nums[0] - 1) * (nums[1] - 1);
}
int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
{
   int cnt = 0;
   for (int i = 0; i < arr1.size(); i++)
   {
      for (int j = 0; j < arr2.size(); j++)
      {
         if (abs(arr1[i] - arr2[j]) < d)
         {
            cnt++;
         }
      }
   }
   return cnt;
}

// in binary search the ending index we have to always take as n-1 not n.....
vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
   sort(potions.begin(), potions.end());

   vector<int> ans;
   for (auto it : spells)
   {
      int s = 0;
      int e = potions.size() - 1;
      int mid = s + (e - s) / 2;
      int cnt = 0;
      while (s <= e)
      {
         if (potions[mid] * it >= success)
         {
            cnt += e - mid + 1;
            e = mid - 1;
         }
         else
         {
            s = mid + 1;
         }
         mid = s + (e - s) / 2;
      }
      ans.push_back(cnt);
   }
   return ans;
}

// in this question to maintain the balance of the boat we always try to put one heavy weight with one ligh weight people....
int numRescueBoats(vector<int> &people, int limit)
{
   sort(people.begin(), people.end());
   int left = 0;
   int right = people.size() - 1;
   int boat_count = 0;
   while (left <= right)
   {
      int sum = people[left] + people[right];
      if (sum <= limit)
      {
         boat_count++;
         left++;
         right--;
      }
      else
      {
         boat_count++;
         // we have to take only the heavy one and only shift the right pointer...
         right--;
      }
   }
   return boat_count;
}

int bfs(vector<vector<int>> &bombs, int src)
{
   int n = bombs.size();
   vector<int> vis(n, 0);
   queue<pair<pair<int, int>, int>> q;
   q.push({{bombs[src][0], bombs[src][1]}, bombs[src][2]});
   vis[src] = 1;
   int cnt = 1;

   while (!q.empty())
   {
      long long x = q.front().first.first;
      long long y = q.front().first.second;
      long long radius = q.front().second;
      q.pop();

      for (int i = 0; i < n; i++)
      {
         if (vis[i] == 0)
         {
            long long newx = bombs[i][0];
            long long newy = bombs[i][1];
            long long newradius = bombs[i][2];
            //  dist between both the centers ----->  x^2 + y^2
            // long long currdist = abs(newx - x) * abs(newx - x) + abs(newy - y) * abs(newy - y);

            long long xdiff = abs(x - newx) * abs(x - newx);
            long long ydiff = abs(y - newy) * abs(y - newy);
            // this is the main condition.....
            if (xdiff + ydiff <= radius * radius)
            {
               cnt++;
               vis[i] = 1;
               q.push({{newx, newy}, newradius});
            }
         }
      }
   }
   return cnt;
}

int maximumDetonation(vector<vector<int>> &bombs)
{
   int n = bombs.size();
   int maxi = 0;
   for (int i = 0; i < n; i++)
   {
      maxi = max(maxi, bfs(bombs, i));
   }

   return maxi;
}

bool checkStraightLine(vector<vector<int>> &coordinates)
{
   int n = coordinates.size();
   int x0 = coordinates[0][0];
   int y0 = coordinates[0][1];
   int x1 = coordinates[1][0];
   int y1 = coordinates[1][1];

   for (int i = 2; i < n; i++)
   {
      int xi = coordinates[i][0];
      int yi = coordinates[i][1];

      if ((y1 - y0) * (xi - x0) != (x1 - x0) * (yi - y0))
      {
         return false;
      }
   }
   return true;
}

int32_t main()
{
   __mayuk;

   return 0;
}

char nextGreatestLetter(vector<char> &letters, char target)
{
   int n = letters.size();
   for (int i = 0; i < n; i++)
   {
      if (letters[i] - target > 0)
      {
         return letters[i];
      }
   }
   return letters[0];
}

string stringbuilder(vector<int> &row)
{
   string ans = "";
   for (auto it : row)
   {
      ans += to_string(it);
      ans += '#';
   }
   return ans;
}

int equalPairs(vector<vector<int>> &grid)
{
   unordered_map<string, int> m;

   // each it is a vector<int> ...
   for (auto it : grid)
   {
      string temp = stringbuilder(it);
      m[temp]++;
   }
   int ans = 0;
   // now we have to travese column wise to check whether it is matching with row or not.....
   for (int j = 0; j < grid[0].size(); j++)
   {
      string temp2 = "";
      for (int i = 0; i < grid.size(); i++)
      {
         temp2 += to_string(grid[i][j]);
         temp2 += '#';
      }
      // if it exist in map then answer updated otherwise remain 0.....
      ans += m[temp2];
   }
   return ans;
}

// if we directly want to use vector as a key then we have to use map because in case of unordered_map the key cant be a complex data type it must be simple data type.....

int equalPairs(vector<vector<int>> &grid)
{
   map<vector<int>, int> m;
   for (auto it : grid)
   {
      m[it]++;
   }

   int ans = 0;
   for (int j = 0; j < grid[0].size(); j++)
   {
      vector<int> temp;
      for (int i = 0; i < grid.size(); i++)
      {
         temp.push_back(grid[i][j]);
      }
      ans += m[temp];
   }
   return ans;
}

// this question is based on weighted median....

long long solve(vector<int> &nums, vector<int> &cost, long long median)
{
   long long ans = 0;
   for (int i = 0; i < nums.size(); i++)
   {
      ans += abs(1ll * nums[i] - median) * (1ll * cost[i]);
   }
   return ans;
}

long long minCost(vector<int> &nums, vector<int> &cost)
{
   int n = nums.size();
   long long total = 0, sum = 0;
   vector<pair<int, int>> v;
   for (int i = 0; i < n; i++)
   {
      v.push_back({nums[i], cost[i]});
   }

   sort(v.begin(), v.end());

   // calculate the total frequncy...
   for (int i = 0; i < n; i++)
   {
      sum = sum + (1ll * v[i].second);
   }

   long long median;
   int i = 0;
   while (total < (sum + 1) / 2 and i < n)
   {
      total = total + (1ll * v[i].second);
      median = v[i].first;
      i++;
   }

   long long ans = solve(nums, cost, median);
   return ans;
}

// total cost to hire k workers...

long long totalCost(vector<int> &costs, int k, int candidates)
{
   int n = costs.size();
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

   int s = 0, e = n - 1;
   for (int i = 0; i < candidates; i++)
   {
      if (s <= e)
      {
         pq.push({costs[i], i});
         s = i + 1; // s always points to the next index..
      }
   }

   for (int i = n - 1; i >= n - candidates; i--)
   {
      if (s <= e)
      {
         pq.push({costs[i], i});
         e = i - 1; // s always points to the next index..
      }
   }

   long long ans = 0;
   for (int i = 0; i < k; i++)
   {
      auto it = pq.top();
      pq.pop();
      ans += it.first;

      // based on the  current value which we have take we have to increment the window size by taking the next elements...
      if (it.second < s and s <= e)
      {
         // since s is already pointing to the next index so first we insert and then increment again....
         pq.push({costs[s], s});
         s++;
      }
      else if (it.second > e and s <= e)
      {
         // e is pointing to the next index...
         pq.push({costs[e], e});
         e--;
      }
   }
   return ans;
}

// find k pairs with smallest sums.....

// using min heap...
vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
   int n = nums1.size();
   int m = nums2.size();
   priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         int sum = nums1[i] + nums2[j];
         pq.push({sum, {nums1[i], nums2[j]}});
      }
   }
   vector<vector<int>> ans;

   int i = 0;
   while (i < k and !pq.empty())
   {
      auto it = pq.top();
      pq.pop();
      vector<int> temp;
      temp.push_back(it.second.first);
      temp.push_back(it.second.second);
      ans.push_back(temp);
      i++;
   }

   return ans;
}
/*
but it gives tle because here we need to insert all the elements in the heap which will take O(n^2) time and n=10^5..
Also here it is given that both the arrays are in sorted order so as we move from left to right the value of sum increases , so it is waste to put all the elements into the priority_queue...
*/

// so now the main solution using the max heap....

vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
   int n = nums1.size();
   int m = nums2.size();
   priority_queue<pair<int, pair<int, int>>> pq;

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         int sum = nums1[i] + nums2[j];
         if (pq.size() < k)
         {
            pq.push({sum, {nums1[i], nums2[j]}});
         }
         else if (pq.size() >= k and pq.top().first > sum)
         {
            pq.pop();
            pq.push({sum, {nums1[i], nums2[j]}});
         }
         else if (pq.top().first < sum)
         {
            // once we get the sum value greater then the value at top of max heap it means we dont need to further process because the array is in sorted order for all upcoming values of nums1[i] and nums2[j] the sum value is greater so our minimum value must be in the max heap...
            break;
         }
      }
   }
   vector<vector<int>> ans;
   int i = 0;
   // we have to check the pq.empty() condition it is not necessary that there is always atleast k pairs exist in the max heap may be there are less elements than k...
   while (i < k and !pq.empty())
   {
      auto it = pq.top();
      pq.pop();
      vector<int> temp;
      temp.push_back(it.second.first);
      temp.push_back(it.second.second);
      ans.push_back(temp);
      i++;
   }
   return ans;
}

int shortestPathAllKeys(vector<string> &grid)
{
   int n = grid.size();
   int m = grid[0].size();
   int x = -1, y = -1, maxlen = -1;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         char ch = grid[i][j];
         if (ch == '@')
         {
            x = i;
            y = j;
         }
         if (ch >= 'a' and ch <= 'f')
         {
            int len = ch - 'a' + 1;
            maxlen = max(maxlen, len);
         }
      }
   }

   vector<int> r = {0, -1, 0, 1};
   vector<int> c = {-1, 0, 1, 0};
   int steps = 0;

   vector<int> start = {0, x, y};
   queue<vector<int>> q;
   unordered_set<string> visit;
   visit.insert(to_string(0) + " " + to_string(x) + " " + to_string(y));
   q.push(start);

   while (!q.empty())
   {
      int size = q.size();
      for (int i = 0; i < size; i++)
      {
         vector<int> curr = q.front();
         q.pop();

         if (curr[0] == (1 << maxlen) - 1)
            return steps;
         for (int i = 0; i < 4; i++)
         {
            int newrow = curr[1] + r[i];
            int newcol = curr[2] + c[i];
            int keys = curr[0];
            if (newrow >= 0 and newrow < n and newcol >= 0 and newcol < m)
            {
               char ch = grid[newrow][newcol];
               if (ch == '#')
                  continue;
               if (ch >= 'a' and ch <= 'f')
               {
                  keys = keys | 1 << (ch - 'a');
               }
               if (ch >= 'A' and ch <= 'F' and (keys >> (ch - 'A') & 1) == 0)
                  continue;
               if (!visit.count(to_string(keys) + " " + to_string(newrow) + " " + to_string(newcol)))
               {
                  visit.insert(to_string(keys) + " " + to_string(newrow) + " " + to_string(newcol));
                  q.push({keys, newrow, newcol});
               }
            }
         }
      }
      ++steps;
   }
   return -1;
}

bool canwalk(vector<vector<int>> &cells, int row, int col, int day)
{

   vector<int> r = {0, -1, 0, 1};
   vector<int> c = {-1, 0, 1, 0};
   vector<vector<int>> vis(row, vector<int>(col, 0));
   for (int i = 0; i < day; i++)
      vis[cells[i][0] - 1][cells[i][1] - 1] = 1;
   queue<pair<int, int>> q;
   for (int j = 0; j < col; j++)
   {
      if (vis[0][j] == 0)
      {
         q.push({0, j});
         vis[0][j] = 1;
      }
   }

   while (!q.empty())
   {
      auto [crow, ccol] = q.front();
      q.pop();
      if (crow == row - 1)
         return true;
      for (int i = 0; i < 4; i++)
      {
         int newr = crow + r[i];
         int newc = ccol + c[i];
         if (newr < 0 or newr >= row or newc < 0 or newc >= col or vis[newr][newc] == 1)
            continue;
         vis[newr][newc] = 1;
         q.push({newr, newc});
      }
   }
   return false;
}

int latestDayToCross(int row, int col, vector<vector<int>> &cells)
{
   // it is 1 based indexing...
   int left = 1, right = cells.size(), ans = 0;
   while (left <= right)
   {
      int mid = left + (right - left) / 2;
      if (canwalk(cells, row, col, mid) == true)
      {
         ans = mid;
         left = mid + 1;
      }
      else
      {
         right = mid - 1;
      }
      mid = left + (right - left) / 2;
   }
   return ans;
}
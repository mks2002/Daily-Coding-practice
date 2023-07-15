
#include <bits/stdc++.h>
using namespace std;

// Structure for an item which stores weight and
// corresponding value of Item
struct Item
{
   int value, weight;

   // Constructor
   Item(int value, int weight)
   {
      this->value = value;
      this->weight = weight;
   }
};

// Comparison function to sort Item
// according to val/weight ratio
static bool cmp(struct Item a, struct Item b)
{
   double r1 = (double)a.value / (double)a.weight;
   double r2 = (double)b.value / (double)b.weight;
   return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int N)
{
   // Sorting Item on basis of ratio
   sort(arr, arr + N, cmp);

   double finalvalue = 0.0;

   // Looping through all items
   for (int i = 0; i < N; i++)
   {

      // If adding Item won't overflow,
      // add it completely
      if (arr[i].weight <= W)
      {
         W -= arr[i].weight;
         finalvalue += arr[i].value;
      }

      // If we can't add current Item,
      // add fractional part of it
      else
      {
         finalvalue += arr[i].value * ((double)W / (double)arr[i].weight);
         break;
      }
   }

   // Returning final value
   return finalvalue;
}

// Driver code
int main()
{
   int W = 50;
   Item arr[] = {{60, 10}, {100, 20}, {120, 30}};

   int N = sizeof(arr) / sizeof(arr[0]);

   // Function call
   cout << fractionalKnapsack(W, arr, N);
   return 0;
}
//____________________________________________________________________________________

// n meetings in one room .....
static bool comp(pair<int, int> a, pair<int, int> b)
{
   return a.second < b.second;
}
// Function to find the maximum number of meetings that can
// be performed in a meeting room.
int maxMeetings(int start[], int end[], int n)
{
   vector<pair<int, int>> v;
   for (int i = 0; i < n; i++)
   {
      // pair<int, int> p = {start[i], end[i]};
      v.push_back({start[i], end[i]});
   }

   sort(v.begin(), v.end(), comp);
   int initial = 0;
   int cnt = 0;
   for (int i = 0; i < n; i++)
   {
      if (v[i].first > initial)
      {
         cnt++;
         initial = v[i].second;
      }
   }
   return cnt;
}
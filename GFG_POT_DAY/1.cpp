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
struct Node
{
   int data;
   struct Node *next;

   Node(int x)
   {
      data = x;
      next = NULL;
   }
};

struct Node *modifyTheList(struct Node *head)
{
   vector<int> temparr;
   struct Node *temp = head;
   int cnt = 1;
   while (temp != NULL)
   {
      temparr.push_back(temp->data);
      temp = temp->next;
      cnt++;
   }

   if (cnt % 2 == 0)
   {
      vector<int> upd = temparr;
      int s = 0;
      int end = temparr.size() - 1;
      for (int i = 0; i < temparr.size() / 2; i++)
      {
         int curr = temparr[end] - temparr[s];
         upd.push_back(curr);
         end--;
         s++;
      }
      end = temparr.size() / 2 - 1;
      for (int i = temparr.size() / 2; i < temparr.size(); i++)
      {
         upd.push_back(temparr[end--]);
      }
      temp = head;
      int idx = 0;
      while (temp != NULL)
      {
         temp->data = upd[idx];
         temp = temp->next;
         idx++;
      }
      head = temp;
   }
   else
   {
      vector<int> upd = temparr;
      int s = 0;
      int end = temparr.size() - 1;
      for (int i = 0; i < temparr.size() / 2; i++)
      {
         int curr = temparr[end] - temparr[s];
         upd.push_back(curr);
         end--;
         s++;
      }
      upd.push_back(temparr[temparr.size() / 2]);
      end = temparr.size() / 2 - 1;
      for (int i = temparr.size() / 2 + 1; i < temparr.size(); i++)
      {
         upd.push_back(temparr[end--]);
      }
      temp = head;
      int idx = 0;
      while (temp != NULL)
      {
         temp->data = upd[idx];
         temp = temp->next;
         idx++;
      }
      head = temp;
   }
   return head;
}
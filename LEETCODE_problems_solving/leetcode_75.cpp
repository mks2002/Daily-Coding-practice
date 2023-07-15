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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

string removeStars(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '*')
        {
            st.push(s[i]);
        }
        else if (s[i] == '*')
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> asteroidCollision(vector<int> &asteroids)
{
    int n = asteroids.size();
    int i = 0;
    stack<int> st;
    while (i < n)
    {
        if (st.empty())
        {
            st.push(asteroids[i]);
            i++;
        }
        else
        {
            if ((st.top() > 0 and asteroids[i] > 0) or (st.top() < 0 and asteroids[i] < 0) or (st.top() < 0 and asteroids[i] > 0))
            {
                st.push(asteroids[i]);
                i++;
            }
            else if (st.top() > 0 and asteroids[i] < 0)
            {
                int current = st.top();
                st.pop();
                if (current == abs(asteroids[i]))
                {
                    // both the astroids are destroyed.....
                    i++;
                }
                else if (current > abs(asteroids[i]))
                {
                    // it again push the current value of stack top .....
                    st.push(current);
                    i++;
                }
                else if (current < abs(asteroids[i]))
                {
                    // it keeps on destroying untill its found a larger or equal value then itself.....
                    continue;
                }
            }
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int32_t main()
{
    __mayuk;
    int t;
    cin >> t;
    while (t--)
    {
        string s = "";
        int n = stoi(s);
        cout << n << endl;
        cout << s << endl;
    }
    return 0;
}

// max number of k sum pairs.....

/*

// this solution is wrong it gives wrong answer for many cases like -->
// nums = [3,1,3,4,3] ,k = 6
// Output = 3   , Expected= 1

int maxOperations(vector<int> &nums, int k)
{
   multiset<int> st;
   int cnt = 0;
   for (int i = 0; i < nums.size(); i++)
   {
      st.insert(nums[i]);
      if (st.find(k - nums[i]) != st.end())
      {
         int num = k - nums[i];
         st.erase(nums[i]);
         st.erase(num);
         cnt++;
      }
   }
   return cnt;
}

// we have to use hashmap instead of using hashset to correctly solve this...

*/

int maxOperations(vector<int> &nums, int k)
{
    unordered_map<int, int> m;
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int targetsum = k - nums[i];
        if (m.find(targetsum) != m.end())
        {
            cnt++;
            m[targetsum]--;
            if (m[targetsum] == 0)
                m.erase(targetsum);
        }
        else
        {
            // if the targetsum value not exist in the map....
            m[nums[i]]++;
        }
    }
    return cnt;
}

// this is another approach without using map just using sorting and 2 pointers....

int maxOperations(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1, ans = 0;
    while (i < j)
    {
        if (nums[i] + nums[j] == k)
        {
            ans++;
            i++;
            j--;
        }
        else if (nums[i] + nums[j] > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return ans;
}

// odd even linkedlist........
/*
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

*/

ListNode *oddEvenList(ListNode *head)
{
    ListNode *oddh = NULL, *oddt = NULL, *evenh = NULL, *event = NULL;

    // initially the cnt is 1 because the starting node is odd given in the question....
    int cnt = 1;
    while (head != NULL)
    {
        if (cnt % 2 == 0)
        {
            if (evenh == NULL)
            {
                evenh = head;
                event = head;
                head = head->next;
            }
            else
            {
                event->next = head;
                event = event->next;
                head = head->next;
            }
        }
        else
        {
            if (oddh == NULL)
            {
                oddh = head;
                oddt = head;
                head = head->next;
            }
            else
            {
                oddt->next = head;
                oddt = oddt->next;
                head = head->next;
            }
        }
        cnt++;
    }

    if (oddh == NULL)
        return evenh;
    if (evenh == NULL)
        return oddh;

    oddt->next = evenh;
    event->next = NULL;

    return oddh;
}

// maximum twin sum of linkedlist.........
ListNode *getmid(ListNode *&head)
{
    ListNode *slow = head, *fast = head->next;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *reverse(ListNode *&head)
{
    ListNode *currptr = head, *prevptr = NULL;
    ListNode *nextptr;
    while (currptr != NULL)
    {
        nextptr = prevptr;
        prevptr = currptr;
        currptr = currptr->next;
        prevptr->next = nextptr;
    }
}

int pairSum(ListNode *head)
{
    ListNode *mid = getmid(head);
    mid->next = reverse(mid->next);

    ListNode *temp1 = head, *temp2 = mid->next;
    int mxtwinsum = 0;
    while (temp1 != NULL and temp2 != NULL)
    {
        int currsum = temp1->val + temp2->val;
        mxtwinsum = max(mxtwinsum, currsum);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    // we have to again make the linkedlist similar to original linked list ....
    mid->next = reverse(mid->next);
    return mxtwinsum;
}
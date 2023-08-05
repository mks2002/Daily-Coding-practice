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

bool countBalancedBuilding(vector<int> &buildings)
{
    for (auto it : buildings)
    {
        if (it != 0)
            return false;
    }
    return true;
}

void calculatePossibleRequest(int idx, int possiblerequest, int requestcnt, vector<vector<int>> &request, vector<int> &buildings)
{
    if (countBalancedBuilding(buildings) == true)
        possiblerequest = max(possiblerequest, requestcnt);

    if (idx == request.size())
        return;

    int livingBuild = request[idx][0], enteringbuild = request[idx][1];

    // take calls...
    buildings[livingBuild] -= 1;
    buildings[enteringbuild] += 1;
    calculatePossibleRequest(idx + 1, possiblerequest, requestcnt + 1, request, buildings);
    buildings[livingBuild] += 1;
    buildings[enteringbuild] -= 1;

    // non take calls....
    calculatePossibleRequest(idx + 1, possiblerequest, requestcnt, request, buildings);
}

int maximumRequests(int n, vector<vector<int>> &requests)
{
    int possiblerequest = 0;
    vector<int> buildings(n, 0);
    int idx = 0;
    int requestcnt = 0;
    calculatePossibleRequest(idx, possiblerequest, requestcnt, requests, buildings);
    return possiblerequest;
}

int minSubArrayLen(int target, vector<int> &nums)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    int mn = INT_MAX;
    while (j < nums.size())
    {
        sum += nums[j];
        if (sum >= target)
        {
            // we have to do the comparison inside this while loop because once we get out of the loop the sum value may be less then target so if we compare at that time then it is possible that we got wrong answer so inside this loop untill we have last time sum>= target we reduce the window size and hence we can get the smallest window size by doing this.....
            while (sum >= target)
            {
                sum -= nums[i];
                mn = min(j - i + 1, mn);
                i++;
            }
        }

        j++;
    }
    if (mn == INT_MAX)
    {
        return 0;
    }
    return mn;
}

// 7 july.....
// maximum confusion of a exam....

int longestOnes(vector<int> &nums, int k)
{
    int i = 0, j = 0, zerocnt = 0, size = 0, ans = 0;
    int n = nums.size();
    while (i < n and j < n)
    {
        if (nums[j] == 1)
        {
            // do nothing...
        }
        else if (nums[j] == 0)
        {
            zerocnt++;

            if (zerocnt > k)
            {
                while (zerocnt > k)
                {
                    if (nums[i] == 1)
                    {
                        // do nothing...
                    }
                    else if (nums[i] == 0)
                    {
                        zerocnt--;
                    }

                    i++;
                }
            }
        }

        size = j - i + 1;
        ans = max(size, ans);

        j++;
    }
    return ans;
}

int maxConsecutiveAnswers(string answerKey, int k)
{
    int i = 0, j = 0, n = answerKey.length();
    int ans = 0;
    int charcnt = 0;

    int mxTlen = 0, mxFlen = 0;

    // once try to change F to T ....
    while (i < n and j < n)
    {
        if (answerKey[j] == 'T')
        {
            // do nothing....
        }
        else if (answerKey[j] == 'F')
        {
            charcnt++;

            if (charcnt > k)
            {
                while (charcnt > k)
                {
                    if (answerKey[i] == 'T')
                    {
                        // do nothing...
                    }
                    else if (answerKey[i] == 'F')
                    {
                        charcnt--;
                    }
                    i++;
                }
            }
        }

        int size = j - i + 1;
        mxTlen = max(size, mxTlen);
        j++;
    }

    // then try to change T to F.....

    i = 0, j = 0, charcnt = 0;
    while (i < n and j < n)
    {
        if (answerKey[j] == 'F')
        {
            // do nothing....
        }
        else if (answerKey[j] == 'T')
        {
            charcnt++;

            if (charcnt > k)
            {
                while (charcnt > k)
                {
                    if (answerKey[i] == 'F')
                    {
                        // do nothing...
                    }
                    else if (answerKey[i] == 'T')
                    {
                        charcnt--;
                    }
                    i++;
                }
            }
        }

        int size = j - i + 1;
        mxFlen = max(size, mxFlen);
        j++;
    }

    // after both the loops end we have the final answer ....
    ans = max(mxTlen, mxFlen);
    return ans;
}

long long putMarbles(vector<int> &weights, int k)
{
    int n = weights.size();
    vector<int> partition;
    for (int i = 0; i < n - 1; i++)
        partition.push_back(weights[i] + weights[i + 1]);

    sort(partition.begin(), partition.end());
    long long mxsum = 0, minsum = 0;
    int x = partition.size();
    for (int i = 0; i < k - 1; i++)
    {
        minsum += partition[i];
        mxsum += partition[x - 1 - i];
    }

    long long ans = mxsum - minsum;
    return ans;
}

int largestVariance(string s)
{
    int ans = 0;
    unordered_map<char, int> freq;
    for (auto it : s)
        freq[it]++;

    for (char c1 = 'a'; c1 <= 'z'; c1++)
    {
        for (char c2 = 'a'; c2 <= 'z'; c2++)
        {
            if (c1 == c2 or freq[c1] == 0 or freq[c2] == 0)
                continue;

            for (int rev = 1; rev <= 2; rev++)
            {
                int cnt1 = 0, cnt2 = 0;
                for (auto it : s)
                {
                    cnt1 += (it == c1);
                    cnt2 += (it == c2);

                    // we dont have to break and take cnt1, cnt2 forward same as kadanes algorithm.....
                    if (cnt1 < cnt2)
                        cnt1 = cnt2 = 0;

                    if (cnt1 > 0 and cnt2 > 0)
                        ans = max(ans, cnt1 - cnt2);
                }

                reverse(s.begin(), s.end());
            }
        }
    }
    return ans;
}

/*

the third loop of rev and the reverse of string is used here because of a particular case

ex input --> lripaa and baa
output --> 0  0
but expected output --> 1 and 1

so lets take the example baa if we take cnt1 for a , cnt2 for b

in the first step cnt2 =1 cnt1=0 (cnt2 > cnt1)cnt1=cnt2=0 and if we further go on then our answer is not updated because cnt2 is always remain 0 and hence it cant update our answer ...

now if we reverse the cnt variable according to external character loop -->
if we take cnt1 for b , cnt2 for a  then for b a a  cn1=1,cnt2=0 | cnt1=1,cnt2=1 | cnt1=1,cnt2=2 and again (cnt2> cnt1) cnt2=cnt1=0..

now to get rid of this if we reverse the string then s = aab

if we take cnt1 for a and cnt2 for b at the end of string cnt1=2, cnt2=1 and this not violate our condition and hence it will update the answer ...

similarly if we take cnt1 for b or cnt2 for a --> after each step a a b --> cnt1=0, cnt2=1 ( cnt1<cnt2)cnt1=cnt2=0
                                                                            cnt1=0, cnt2=1 ( cnt1<cnt2)cnt1=cnt2=0
                                                                            cnt1=1, cnt2=0
 and we can see at the end of the traversal it will update the answer.....

 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    queue<TreeNode *> q;
    unordered_map<int, TreeNode *> parent;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *currnode = q.front();
            q.pop();

            if (currnode->left != NULL)
            {
                q.push(currnode->left);
                parent[currnode->left->val] = currnode;
            }
            if (currnode->right != NULL)
            {
                q.push(currnode->right);
                parent[currnode->right->val] = currnode;
            }
        }
    }

    // after first traversal the queue is empty again .....
    unordered_map<int, int> visited;
    q.push(target);
    while (!q.empty() and k--)
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *currnode = q.front();
            q.pop();
            visited[currnode->val] = 1;
            if (currnode->left != NULL and visited[currnode->left->val] == 0)
            {
                q.push(currnode->left);
            }

            if (currnode->right != NULL and visited[currnode->right->val] == 0)
            {
                q.push(currnode->right);
            }
            //  if its parent is exist and also not visited.....
            if (parent[currnode->val] != 0 and visited[(parent[currnode->val])->val] == 0)
            {
                q.push(parent[currnode->val]);
            }
        }
    }

    // after the second travesal all the nodes which has k distance from the target node remaining in the queue .....

    vector<int> ans;
    while (!q.empty())
    {
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}

int longestSubsequence(vector<int> &arr, int difference)
{
    unordered_map<int, int> m;
    int mxlen = 0;
    for (auto it : arr)
    {
        m[it] = m[it - difference] + 1;
        mxlen = max(mxlen, m[it]);
    }
    return mxlen;
}

// maximum number of events that can be attended 2....
int solve(vector<vector<int>> &dp, vector<vector<int>> &events, int n, int pos, int k)
{
    if (pos >= n || k == 0)
        return 0;
    if (dp[pos][k] != -1)
        return dp[pos][k];
    int i;
    vector<int> temp = {events[pos][1], INT_MAX, INT_MAX};
    i = upper_bound(events.begin() + pos + 1, events.end(), temp) - events.begin();
    return dp[pos][k] = max(solve(dp, events, n, pos + 1, k), events[pos][2] + solve(dp, events, n, i, k - 1));
}
int maxValue(vector<vector<int>> &events, int k)
{
    int n = events.size();
    sort(events.begin(), events.end());
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return solve(dp, events, n, 0, k);
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    return prevptr;
}
ListNode *helperadd(ListNode *l1, ListNode *l2)
{
    ListNode *l3 = new ListNode(-1);
    ListNode *head = l3;
    int carry = 0;
    while (l1 != NULL and l2 != NULL)
    {
        int value = l1->val + l2->val + carry;
        carry = value / 10;
        value = value % 10;
        l3->next = new ListNode(value);

        l1 = l1->next;
        l2 = l2->next;
        l3 = l3->next;
    }

    while (l1 != NULL)
    {
        int value = l1->val + carry;
        carry = value / 10;
        value = value % 10;
        l3->next = new ListNode(value);

        l3 = l3->next;
        l1 = l1->next;
    }

    while (l2 != NULL)
    {
        int value = l2->val + carry;
        carry = value / 10;
        value = value % 10;
        l3->next = new ListNode(value);

        l3 = l3->next;
        l2 = l2->next;
    }

    while (carry != 0)
    {
        int value = carry;
        carry = value / 10;
        value = value % 10;
        l3->next = new ListNode(value);
        l3 = l3->next;
    }
    return head->next;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    l1 = reverse(l1);
    l2 = reverse(l2);
    ListNode *ans = helperadd(l1, l2);

    // reverse all the linked list again.....
    ans = reverse(ans);
    l1 = reverse(l1);
    l2 = reverse(l2);
    return ans;
}

class LRUCache
{
public:
    int capacity;
    queue<int> used_history;
    unordered_map<int, int> q_counter;
    unordered_map<int, int> dict;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (dict.count(key) != 0)
        {
            used_history.push(key);
            q_counter[key]++;
            return dict[key];
        }
        // if the key not exist in the dictonary ....
        return -1;
    }

    void remove_lru()
    {
        while (!used_history.empty())
        {
            int curr = used_history.front();
            used_history.pop();

            q_counter[curr]--;
            if (q_counter[curr] == 0)
            {
                dict.erase(curr);
                break;
            }
        }
    }

    void put(int key, int value)
    {
        used_history.push(key);
        q_counter[key]++;
        dict[key] = value;
        if (dict.size() > this->capacity)
        {
            remove_lru();
        }
    }
};

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

// we have to find number of intervals which we have to remove to make all seperate ....
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    int cnt = 1;
    int prevans = intervals[0][1];
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] > prevans)
        {
            cnt++;
            prevans = intervals[i][1];
        }
    }
    int ans = n - cnt;
    return ans;
}

unordered_map<string, double> mp;
int dir[8][8] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};

double find(int n, int moves, int r, int c)
{
    if (r < 0 || r >= n || c < 0 || c >= n)
        return 0;
    if (moves == 0)
        return 1;
    string key = to_string(r) + "mayuk" + to_string(c) + "sarkar" + to_string(moves);
    if (mp.find(key) != mp.end())
        return mp[key];
    double probability = 0;
    for (int i = 0; i < 8; i++)
        probability += find(n, moves - 1, r + dir[i][0], c + dir[i][1]) / 8.0;
    mp[key] = probability;
    return mp[key];
}

double knightProbability(int n, int k, int row, int column)
{
    return find(n, k, row, column);
}
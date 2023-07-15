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
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

struct Node *mergeTwoLists(struct Node *list1, struct Node *list2)
{
    struct Node *temp1 = list1;
    struct Node *temp2 = list2;

    struct Node *dummy = new Node(-1);
    struct Node *temp3 = dummy;
    // we have to use and because if any of them become NULL then the while loop terminate.....
    while (temp1 != NULL and temp2 != NULL)
    {
        if (temp1->data > temp2->data)
        {
            temp3->next = temp2;
            temp2 = temp2->next;
        }
        else if (temp1->data <= temp2->data)
        {
            temp3->next = temp1;
            temp1 = temp1->next;
        }
        temp3 = temp3->next;
    }

    while (temp1 != NULL)
    {
        temp3->next = temp1;
        temp1 = temp1->next;
        temp3 = temp3->next;
    }
    while (temp2 != NULL)
    {
        temp3->next = temp2;
        temp2 = temp2->next;
        temp3 = temp3->next;
    }
    temp3 = dummy->next;
    delete (dummy);
    return temp3;
}

struct Node *getmiddle(struct Node *&head)
{
    struct Node *slow = head;
    struct Node *fast = head->next;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

struct Node *mergesort(struct Node *&head)
{
    // base conditions...
    if (head == NULL or head->next == NULL)
        return head;

    struct Node *mid = getmiddle(head);
    struct Node *left = head;
    struct Node *right = mid->next;
    mid->next = NULL;

    // recursive calls...
    left = mergesort(left);
    right = mergesort(right);
    struct Node *result = mergeTwoLists(left, right);

    return result;
}

struct Node *makeUnion(struct Node *head1, struct Node *head2)
{
    struct Node *temp1 = mergesort(head1);
    struct Node *temp2 = mergesort(head2);

    struct Node *dummy = new Node(-1);
    struct Node *temp3 = dummy;

    while (temp1 != NULL and temp2 != NULL)
    {
        if (temp1->data > temp2->data)
        {
            temp3->next = temp2;
            temp3 = temp3->next;
            temp2 = temp2->next;
        }
        else if (temp1->data < temp2->data)
        {
            temp3->next = temp1;
            temp3 = temp3->next;
            temp1 = temp1->next;
        }
        else if (temp1->data == temp2->data)
        {
            // if both nodes have equal value....
            temp3->next = temp1;
            temp3 = temp3->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL)
    {
        temp3->next = temp1;
        temp3 = temp3->next;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        temp3->next = temp2;
        temp3 = temp3->next;
        temp2 = temp2->next;
    }

    temp3 = dummy->next;
    delete (dummy);
    return temp3;
}

// count of subarray less than k........

// o(n^2)...
int countlessK(vector<int> &nums, int k)
{
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = 1;
        for (int j = i; j < n; j++)
        {
            temp = temp * nums[j];
            if (temp < k)
                cnt++;
        }
    }
    return cnt;
}

// for optimizing this we have to use sliding window teqnique...

int countlessK(vector<int> &nums, int k)
{
}

// merge sorted array and rearrage them after sortin ....

/*
input --> ar1 = (1, 3 , 5, 7)  ar2= (0, 2, 6, 8, 9)
output --> ar1= (0, 1, 2, 3)  ar2 =( 5, 6, 7, 8 ,9)

*/

// naive approach using extra space.....

// t.c. O(m+n)  and s.c --> O(m+n)

void merge(long long arr1[], long long arr2[], int n, int m)
{
    long long ar3[m + n];
    int i = 0, j = 0, k = 0;

    while (i < n and j < m)
    {
        if (arr1[i] >= arr2[j])
        {
            ar3[k++] = arr2[j++];
        }
        else
        {
            ar3[k++] = arr1[i++];
        }
    }

    while (i < n)
    {
        ar3[k++] = arr1[i++];
    }
    while (j < m)
    {
        ar3[k++] = arr2[j++];
    }

    // because after sorting we have to copy it in the main array also....
    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
        {
            arr1[i] = ar3[i];
        }
        else
        {
            arr2[i] = ar3[i];
        }
    }
}

// here we reduce the space complexity to O(1) but the time complexity O(nlongn + mlogm)

void merge(long long arr1[], long long arr2[], int n, int m)
{
    int i = n - 1, j = 0;
    while (i >= 0 and j < m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[i], arr2[j]);
            i--;
            j++;
        }
        else
        {
            break;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

// we have to find if there exist any triplet whose sum is equal to 0 ...........

// try to optimize.....

int missingNumber(int arr[], int n)
{
    unordered_map<int, int> m;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
        maxi = max(maxi, arr[i]);
    }
    // if 1 is absent in the map then surely it is the smallest positive missing number....
    if (m[1] == 0)
        return 1;

    for (int i = 2; i <= maxi; i++)
    {
        if (m[i] == 0)
            return i;
    }
    // if all the elements upto the max element are present in the map then the smallest element which is not present is the (max + 1).....
    return maxi + 1;
}

int helper(int i, int j, string &str, vector<vector<int>> &dp)
{
    if (i >= str.size() || j >= str.size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (str[i] == str[j] && i != j)
        return 1 + helper(i + 1, j + 1, str, dp);
    return dp[i][j] = max(helper(i + 1, j, str, dp), helper(i, j + 1, str, dp));
}
int LongestRepeatingSubsequence(string &str)
{
    vector<vector<int>> dp(str.size(), vector<int>(str.size(), -1));
    return helper(0, 0, str, dp);
}

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }

} *head;

struct node *reverse(struct node *head, int k)
{
    node *currptr = head, *prevptr = NULL;
    node *nextptr;
    int cnt = 0;
    while (currptr != NULL and cnt < k)
    {
        nextptr = prevptr;
        prevptr = currptr;
        currptr = currptr->next;
        prevptr->next = nextptr;
        cnt++;
    }

    if (currptr != NULL)
    {
        head->next = reverse(currptr, k);
    }

    return prevptr;
}

Node *segregate(Node *head)
{
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            cnt0++;
        else if (temp->data == 1)
            cnt1++;
        else if (temp->data == 2)
            cnt2++;
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        if (cnt0 > 0)
        {
            temp->data = 0;
            cnt0--;
        }
        else if (cnt1 > 0)
        {
            temp->data = 1;
            cnt1--;
        }
        else if (cnt2 > 0)
        {
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    return head;
}

vector<int> findSpiral(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    q.push(root);
    bool rightLeft = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();
            int idx = rightLeft ? size - i - 1 : i;
            temp[idx] = front->data;

            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }
        rightLeft = !rightLeft;
        for (auto it : temp)
            ans.push_back(it);
    }
    return ans;
}



int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
{
    if (A[0][0] == 0 or A[X][Y] == 0)
        return -1;

    vector<vector<int>> vis(N, vector<int>(M, 0));
    queue<pair<pair<int, int>, int>> q;

    vector<int> r = {0, -1, 0, 1};
    vector<int> c = {-1, 0, 1, 0};

    q.push({{0, 0}, 1});
    vis[0][0] = 1;
    while (!q.empty())
    {
        int currrow = q.front().first.first;
        int currcol = q.front().first.second;
        int currdist = q.front().second;
        q.pop();

        if (currrow == X and currcol == Y)
            return currdist-1;

        for (int i = 0; i < 4; i++)
        {
            int newrow = currrow + r[i], newcol = currcol + c[i];
            if (newrow >= 0 and newrow < N and newcol >= 0 and newcol < M and A[newrow][newcol] == 1 and vis[newrow][newcol] == 0)
            {
                q.push({{newrow, newcol}, currdist + 1});
                vis[newrow][newcol] = 1;
            }
        }
    }

    return -1;
}
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

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// this is beginner approach.....

// O(n+n)
Node *sortList(Node *head)
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

// second approach without changing the data of the nodes by changing the links........

void insertAtTail(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}
// O(n)..
Node *sortList(Node *head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;

    // create separate list 0s, 1s and 2s
    while (curr != NULL)
    {

        int value = curr->data;

        if (value == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if (value == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if (value == 2)
        {
            insertAtTail(twoTail, curr);
        }

        curr = curr->next;
    }

    // merge 3 sublist

    // 1s list not empty
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        // 1s list -> empty
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // setup head
    head = zeroHead->next;

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

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

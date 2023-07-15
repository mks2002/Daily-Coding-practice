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

// this is the structure of the node of the linked list....
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

// 1.. Remove Linked List Elements..

ListNode *removeElements(ListNode *head, int val)
{
    if (head == NULL)
        return head;

    while (head != NULL and head->val == val)
    {
        head = head->next;
    }

    ListNode *temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->val == val)
        {

            temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

int intersectPoint(Node *head1, Node *head2)
{
    Node *temp1 = head1, *temp2 = head2;
    int data = 0;
    while (temp1->next != NULL and temp2->next != NULL)
    {
        if (temp1->next == temp2->next)
        {
            data = temp1->next->data;
            break;
        }
        else
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return data;
}

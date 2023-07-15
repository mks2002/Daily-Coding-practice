
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
    int data;
    Node * next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *getMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}
Node *reverse(Node *head)
{

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to check whether the list is palindrome.
bool isPalindrome(Node *head)
{
    if (head->next == NULL)
    {
        return true;
    }

    // step 1 -> find Middle
    Node *middle = getMid(head);
    // cout << "Middle " << middle->data << endl;

    // step2 -> reverse List after Middle
    Node *temp = middle->next;
    middle->next = reverse(temp);

    // step3 - Compare both halves
    Node *head1 = head;
    Node *head2 = middle->next;

    while (head2 != NULL)
    {
        if (head2->data != head1->data)
        {
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // step4 - repeat step 2
    temp = middle->next;
    middle->next = reverse(temp);

    return true;
}

int32_t main()
{
    __mayuk;

    return 0;
}
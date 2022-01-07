#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node()
    {
        this->next = NULL;
    }

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

Node *insertionSortList(Node *head)
{
    if (head == NULL && head->next == NULL)
    {
        return head;
    }
    Node *preInsertNode;
    Node *toInsertNode;
    Node *dummy = new Node(-5001);
    dummy->next = head;
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->val <= curr->next->val)
        {
            curr = curr->next;
        }
        else
        {
            toInsertNode = curr->next;
            preInsertNode = dummy;
            while (preInsertNode->next->val < toInsertNode->val)
            {
                preInsertNode = preInsertNode->next;
            }
            curr->next = toInsertNode->next;
            toInsertNode->next = preInsertNode->next;
            preInsertNode->next = toInsertNode;
        }
    }
    return dummy->next;
}

void printList(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *p = head;
    while (p != NULL)
    {
        cout << p->val << " -> ";
        p = p->next;
    }
}

int main()
{

    Node *head = new Node(-1);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(0);

    printList(head);
    cout << endl;

    Node *newHead=insertionSortList(head);
    printList(newHead);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class tNode
{

public:
    // Propetires
    int data;
    tNode *next;

    // Constructor
    tNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Methoods
void insertAtHead(tNode *&head, int data)
{
    tNode *temp = new tNode(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(tNode *&tail, int data)
{
    tNode *temp = new tNode(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(tNode *&head, tNode *&tail, int p, int data)
{
    tNode *temp = head;
    tNode *temp1 = new tNode(data);
    if (p == 1)
    {
        insertAtHead(head, data);
        return;
    }
    int cnt = 1;
    while (cnt < (p - 1))
    {
        temp = temp->next;
        cnt++;
    }

    // When insert at end/tail
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    temp1->next = temp->next;
    temp->next = temp1;
}

void deleteNode(tNode *&head, tNode *&tail, int pos)
{
    tNode *temp = head;
    tNode *dele = head;
    int cnt = 1;

    if (pos == 1)
    {
        head = temp->next;
        delete (dele);
        return;
    }

    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    dele = temp->next;
    temp->next = temp->next->next;

    if (temp->next == NULL)
    {
        tail = temp;
    }

    dele->next = NULL;
    delete (dele);
}

void print(tNode *&head)
{
    tNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    tNode *node1 = new tNode(10);
    tNode *head = node1;
    tNode *tail = node1;

    insertAtHead(head, 12);
    insertAtTail(tail, 9);
    insertAtTail(tail, 13);
    insertAtPosition(head, tail, 3, 20);
    insertAtPosition(head, tail, 6, 100);

    print(head);
    deleteNode(head, tail, 6);
    print(head);

    cout << "Head ka data -> " << head->data << endl;
    cout << "Tail ka data -> " << tail->data << endl;

    // cout << "data = " << node1->data << endl;
    // cout << "next = " << node1->next << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    // Propetires
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Methoods
void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int p, int data)
{
    Node *temp = head;
    Node *temp1 = new Node(data);
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

void deleteNode(Node *&head, Node *&tail, int pos)
{
    Node *temp = head;
    Node *dele = head;
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

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

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
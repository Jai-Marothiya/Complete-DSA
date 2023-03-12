/*** Doubly Linked List ***/
#include <iostream>
using namespace std;

class tNode
{
public:
    int data;
    tNode *prev;
    tNode *next;

    // constructor
    tNode(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~tNode()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data " << val << endl;
    }
};

// traversing a linked list
void print(tNode *head)
{
    tNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// gives length of Linked List
int getLength(tNode *head)
{
    int len = 0;
    tNode *temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}
void insertAtHead(tNode *&tail, tNode *&head, int d)
{

    // empty list
    if (head == NULL)
    {
        tNode *temp = new tNode(d);
        head = temp;
        tail = temp;
    }
    else
    {
        tNode *temp = new tNode(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(tNode *&tail, tNode *&head, int d)
{
    if (tail == NULL)
    {
        tNode *temp = new tNode(d);
        tail = temp;
        head = temp;
    }
    else
    {
        tNode *temp = new tNode(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(tNode *&tail, tNode *&head, int position, int d)
{

    // insert at Start
    if (position == 1)
    {
        insertAtHead(tail, head, d);
        return;
    }

    tNode *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if (temp->next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }

    // creating a node for d
    tNode *nodeToInsert = new tNode(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(int position, tNode *&head, tNode *&tail)
{

    // deleting first or start node
    if (position == 1)
    {
        tNode *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        tNode *curr = head;
        tNode *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr->next == NULL)
        {
            tail = prev;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
    }
}

int main()
{

    tNode *head = NULL;
    tNode *tail = NULL;

    print(head);
    // cout << getLength(head) << endl;

    insertAtHead(tail, head, 11);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtHead(tail, head, 13);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtHead(tail, head, 8);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtTail(tail, head, 25);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtPosition(tail, head, 2, 100);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtPosition(tail, head, 1, 101);
    print(head);

    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtPosition(tail, head, 7, 102);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    deleteNode(7, head, tail);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    return 0;
}
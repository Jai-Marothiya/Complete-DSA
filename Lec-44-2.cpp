/******* Circular linked list *******/
#include <iostream>
#include <map>
using namespace std;

class tNode
{
public:
    int data;
    tNode *next;

    // constrcutor
    tNode(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~tNode()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void insertNode(tNode *&tail, int element, int d)
{

    // empty list
    if (tail == NULL)
    {
        tNode *newNode = new tNode(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non-empty list
        // assuming that the element is present in the list

        tNode *curr = tail;

        while (curr->data != element && curr != NULL)
        {
            curr = curr->next;
        }

        // element found -> curr is representing element wala node
        tNode *temp = new tNode(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(tNode *tail)
{

    tNode *temp = tail;

    // empty list
    if (tail == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}

void deleteNode(tNode *&tail, int value)
{

    // empty list
    if (tail == NULL)
    {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else
    {
        // non-empty

        // assuming that "value" is present in the Linked List
        tNode *prev = tail;
        tNode *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // 1 Node Linked List
        if (curr == prev)
        {
            tail = NULL;
        }

        // >=2 Node linked list
        else if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

bool isCircularList(tNode *head)
{
    // empty list
    if (head == NULL)
    {
        return true;
    }

    tNode *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }

    return false;
}

bool detectLoop(tNode *head)
{

    if (head == NULL)
        return false;

    map<tNode *, bool> visited;

    tNode *temp = head;

    while (temp != NULL)
    {

        // cycle is present
        if (visited[temp] == true)
        {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

int main()
{

    tNode *tail = NULL;

    // insertNode(tail, 5, 3);
    // print(tail);

    //  insertNode(tail, 3, 5);
    // print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    deleteNode(tail, 5);
    print(tail);

    if (isCircularList(tail))
    {
        cout << " Linked List is Circular in nature" << endl;
    }
    else
    {
        cout << "Linked List is not Circular " << endl;
    }

    return 0;
}
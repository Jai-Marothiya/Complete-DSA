// Creating a BST : T.C. of Insertion = O(log(N)) , where N = size of BST at that time
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// This function will print our binary tree in proper order
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child nodes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node *InsertNode(Node *&root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        // Insert in right part
        root->right = InsertNode(root->right, d);
    }
    else
    {
        // Insert in left part
        root->left = InsertNode(root->left, d);
    }

    return root;
}

void takeInput(Node *&root)
{
    int d;
    cin >> d;

    // Take input till user not enter "-1"
    while (d != -1)
    {
        root = InsertNode(root, d);
        cin >> d;
    }
}

// Function to find minimun value of BST
int minValue(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

// Function to find maximun value of BST
int maxValue(Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    // Base case
    if (root == NULL)
        return;

    // If key is present at root
    if (root->data == key)
    {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            Node *tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp;
        }

        // the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            Node *tmp = root->right;
            while (tmp->left)
                tmp = tmp->left;
            suc = tmp;
        }
        return;
    }

    // If key is smaller than root's key, go to left subtree
    if (root->data > key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else // go to right subtree
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

// Function to delete node
// T.C. : Avg = O(log(N)) , worst case = O(N)
Node *deleteNode(Node *root, int x)
{
    // base case
    if (root == NULL)
    {
        return root;
    }

    if (root->data == x)
    {
        // Element is found

        // Case 1: 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // Case 2: 1 child
        if (root->left != NULL && root->right == NULL)
        {
            Node *left = root->left;
            delete root;
            return left;
        }

        if (root->left == NULL && root->right != NULL)
        {
            Node *right = root->right;
            delete root;
            return right;
        }

        // Case 3: 2-child
        if (root->left != NULL && root->right != NULL)
        {
            // find minimun value from right part
            int mini = minValue(root->right);
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
    else if (root->data > x)
    {
        root->left = deleteNode(root->left, x);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, x);
        return root;
    }
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST: ";
    takeInput(root);

    cout << "Printing BST: " << endl;
    levelOrderTraversal(root);

    cout << "\nPrinting BST in Inorder: " << endl;
    inorder(root);

    cout << "\nPrinting BST in preOrder: " << endl;
    preorder(root);

    cout << "\nPrinting BST in postOrder: " << endl;
    postorder(root);

    cout << "\n\nMinimum value: " << minValue(root) << endl;
    cout << "Maximum value: " << maxValue(root) << endl;

    // BST: 8 3 10 1 6 14 4 7 13 -1
    Node *pre;
    Node *suc;
    findPreSuc(root, pre, suc, 7);
    cout << "Predecessor and Successor of 7 in BST is: " << pre->data << " and " << suc->data << endl;

    // After deletion
    cout << "\n\nAfter Deletion \n\n";
    root = deleteNode(root, 8);

    cout << "Printing BST: " << endl;
    levelOrderTraversal(root);

    cout << "\nPrinting BST in Inorder: " << endl;
    inorder(root);

    cout << "\nPrinting BST in preOrder: " << endl;
    preorder(root);

    cout << "\nPrinting BST in postOrder: " << endl;
    postorder(root);

    cout << "\n\nMinimum value: " << minValue(root) << endl;
    cout << "Maximum value: " << maxValue(root) << endl;
}

// Enter data to create BST: 8 3 10 1 6 14 4 7 13 -1
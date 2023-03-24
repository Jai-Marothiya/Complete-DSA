// Heaps : It is a CBT(complete binary tree: Every order/level should be completely filled except the last one and nodes always added from left to right) that comes with heap order property.

// Here I add some important functions

#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size = 0;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size += 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        // step -1: Put last element to first step
        arr[1] = arr[size];
        size--;

        // Step - 2:take root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[leftIndex] > arr[i])
            {
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[rightIndex] > arr[i])
            {
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Heapify function: Used to make normar CBT to heap(every node should be less than its parent node)
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    // first we make normal array a heap: (means in tree every node is less than its parent(i.e. largest element is always a root node))
    buildHeap(arr, n);

    // Now we start sorting:
    for (int i = n - 1; i > 0; i--)
    {
        // move current root(i.e. largest element) to end
        swap(arr[0], arr[i]);
        // Now move root node to its correct position(i.e. call heapify for root position)
        heapify(arr, i, 0);
    }
}

// Print an array
void print(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    heap h;

    h.insert(3);
    h.insert(7);
    h.insert(19);
    h.insert(4);
    h.insert(8);
    h.insert(0);

    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    cout << "Before heapify: ";
    print(arr, 5);

    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, 5, 1);
    }
    cout << "After heapify: ";
    print(arr, 5);

    return 0;
}
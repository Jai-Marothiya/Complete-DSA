// Code Binary search using recursion
#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int BinarySearch(int arr[], int s, int e, int key)
{
    print(arr, s, e);

    // Base case 1 - element not found
    if (s > e)
    {
        return -1;
    }

    int mid = s + (e - s) / 2;
    cout << "mid element is : " << arr[(s + (e - s) / 2)] << "\n\n";
    // Base case 2 - element found
    if (arr[mid] == key)
    {
        return mid;
    }

    if (arr[mid] > key)
    {
        return BinarySearch(arr, s, mid - 1, key);
    }
    else
    {
        return BinarySearch(arr, mid + 1, e, key);
    }
}

int main()
{
    int arr[6] = {2, 6, 8, 19, 46, 98};
    int key = 98;

    if (BinarySearch(arr, 0, 5, key) >= 0)
    {
        cout << key << " is present in array";
    }
    else
    {
        cout << key << " is not present in array.";
    }
}
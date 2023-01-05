#include <iostream>

using namespace std;

// Recursive form of Binary Search
int RecursiveBinarySearch(int arr[], int start, int end, int key)
{
    // This will be fail when value of s and e are en values lik 2^31 or some thing. So sum of s+e is out of range and it will give runtime error.
    //  int mid = (start + end) / 2;

    // That we write our mid in different form that is mid = start/2 + end/2 = start + (end-start)/2;
    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }

    if (end >= start)
    {
        if (arr[mid] < key)
        {
            // go to right part
            return RecursiveBinarySearch(arr, mid + 1, end, key);
        }
        else
        {
            // go to left part
            return RecursiveBinarySearch(arr, start, mid - 1, key);
        }
    }
    else
    {
        return -1;
    }
}

// Normal form of Binary Search
int BinarySearch(int arr[], int size, int key)
{
    // This will be fail when value of s and e are en values lik 2^31 or some thing. So sum of s+e is out of range and it will give runtime error.
    //  int mid = (start + end) / 2;

    // That we write our mid in different form that is m = start/2 + end/2 = start + (end-start)/2;
    int start = 0, end = size - 1;

    while (end >= start)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] < key)
        {
            // go to right part
            start = mid + 1;
        }
        else
        {
            // go to left part
            end = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int even[6] = {2, 4, 6, 10, 13, 18};
    int odd[5] = {4, 22, 24, 27, 33};

    // Call Normal function
    cout << BinarySearch(even, 6, 12) << endl;
    cout << BinarySearch(even, 6, 18) << "\n\n";

    cout << BinarySearch(odd, 5, 4) << endl;
    cout << BinarySearch(odd, 5, -2) << "\n\n";

    // Call Recursive function
    cout << RecursiveBinarySearch(even, 0, 5, 12) << endl;
    cout << RecursiveBinarySearch(even, 0, 5, 18) << "\n\n";

    cout << RecursiveBinarySearch(odd, 0, 4, 4) << endl;
    cout << RecursiveBinarySearch(odd, 0, 4, -2) << endl;

    return 0;
}
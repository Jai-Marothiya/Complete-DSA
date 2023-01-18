// Check whether an array is "sorted or not" using recursion
// Also find sum of array using recursion
#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int size)
{
    // Base case : when array has only one or zero elemet then it is sorted.
    if (size <= 0)
        return 0;

    return arr[size - 1] + sum(arr, size - 1);
}

bool isSorted(int arr[], int size)
{
    // Base case : when array has only one or zero elemet then it is sorted.
    if (size == 0 || size == 1)
        return true;

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        return isSorted(arr + 1, size - 1);
    }
}

int main()
{
    int arr[5] = {1, 9, 5, 12, 13};

    if (isSorted(arr, 5))
    {
        cout << "Array is sorted " << endl;
    }
    else
    {
        cout << "Array is not sorted " << endl;
    }

    cout << "Sum of element of array is : " << sum(arr, 5) << endl;

    return 0;
}
// Code linear search using recursion
#include <bits/stdc++.h>
using namespace std;

bool check(int arr[], int size, int key)
{
    // Base case : when array has only one or zero elemet then it is sorted.
    if (size == 0)
        return false;

    if (arr[size - 1] == key)
        return true;
    else
        return check(arr, size - 1, key);
}

int main()
{
    int arr[5] = {1, 9, 7, 5, 12};
    int size = 5, key = 7;

    if (check(arr, size, key))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }

    return 0;
}
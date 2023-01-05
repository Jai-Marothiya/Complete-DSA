// Find index of pivot element in given sorted rotated array, Eg. arr = [7,8,9,10,2,3,5]. So here pivot element is 2 and its index is 4.
#include <bits/stdc++.h>
using namespace std;

int getPivot(vector<int> &arr)
{
    int start = 0, end = arr.size() - 1;

    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (arr[mid] > arr[0])
        {
            start = mid + 1;
        }
        else
        {
            // we are not write end = mid-1 because when mid is out mounted element then mid -1 will be on left side then we never get our answer;
            end = mid;
        }
        mid = start + (end - start) / 2;
    }

    return mid; // Here we can return anyone start or end or mid because all are same better understand by dry run.
}

int main()
{
    // vector<int> arr = {1, 2, 3, 3, 5};
    vector<int> arr = {9, 13, 1, 2, 4, 5, 7, 8};           // ans = 2;
    vector<int> arr2 = {19, 20, 21, 28, 37, 48, 7, 8, 10}; // ans = 6;

    cout << "Mounted element index in arr is " << getPivot(arr) << endl;
    cout << "Mounted element index in arr2 is " << getPivot(arr2) << endl;

    return 0;
}
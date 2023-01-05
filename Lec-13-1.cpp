// Find index of largest element in given mounted array(i.e. first increasing then decreasing), array.length()>=3.
#include <bits/stdc++.h>
using namespace std;

int mountedElement(vector<int> &arr)
{
    int start = 0, end = arr.size() - 1;

    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (arr[mid] < arr[mid + 1])
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

    return mid;
}

int main()
{
    // vector<int> arr = {1, 2, 3, 3, 5};
    vector<int> arr = {1, 2, 4, 5, 7, 8, 9, 13, 5, 3, 2};
    vector<int> arr2 = {1, 2, 21, 20, 9, 8, 7, 6, 5, 3, 2};

    cout << "Mounted element index in arr is " << mountedElement(arr) << endl;
    cout << "Mounted element index in arr2 is " << mountedElement(arr2) << endl;

    return 0;
}
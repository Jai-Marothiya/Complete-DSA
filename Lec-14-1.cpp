// Search given element in given sorted rotated array, Eg. arr = [7,8,9,10,2,3,5].
// Main concept Approach 1:- First find your key is in first part before the pivot of other part.To check first we find pivot from last question concept. Then check it key>=arr[pivot] && key<=arr[n-1] then key present in second line otherwise in first line. Then simply pply binary search in that part.

// Approach 2 given in function DirectSearch();

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

int BinarySearch(vector<int> &arr, int start, int end, int key)
{
    // This will be fail when value of s and e are en values lik 2^31 or some thing. So sum of s+e is out of range and it will give runtime error.
    //  int mid = (start + end) / 2;

    // That we write our mid in different form that is m = start/2 + end/2 = start + (end-start)/2;

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

int DirectSearch(vector<int> &arr, int start, int end, int key)
{
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
            return mid;

        if (arr[mid] >= arr[start])
        {
            // If mid is in first line
            if (key >= arr[start] && key <= arr[mid])
            {
                // this means key lie on first line and key less than arr[mid]
                end = mid - 1;
            }
            else
            {
                // this means key lie on first line but key greater than arr[mid]
                start = mid + 1;
            }
        }
        else
        {
            // mid element is in second line
            if (key <= arr[end] && key >= arr[mid])
            {
                // this means key lie on second line and key greater than arr[mid] and less than end;
                start = mid + 1;
            }
            else
            {
                // this means key lie on left side of mid anywhere so just put end = mid-1 and repeat process;
                end = mid - 1;
            }
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    // vector<int> arr = {1, 2, 3, 3, 5};
    vector<int> arr = {9, 13, 1, 2, 4, 5, 7, 8};
    // vector<int> arr2 = {19, 20, 21, 28, 37, 48, 7, 8, 10};

    int pivot = getPivot(arr), key = 18, n = arr.size();

    if (key >= arr[pivot] && key <= arr[n - 1])
    {
        cout << "Index of " << key << " in the given array is : " << BinarySearch(arr, pivot, n - 1, key);
    }
    else
    {
        cout << "Index of " << key << " in the given array is : " << BinarySearch(arr, 0, pivot - 1, key);
    }

    cout << "Index of " << key << " in the given array from Direct search function is : " << DirectSearch(arr, 0, n - 1, key);

    return 0;
}
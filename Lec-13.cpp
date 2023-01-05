// Find index of first and last occurence of key in your given sorted array, if not found return -1,-1.
#include <bits/stdc++.h>
using namespace std;

/********* We can also find Total number of Occurence of Key by using Count = (lastOcc - firstOcc) +1;  ********/

int firstOcc(vector<int> &arr, int n, int key)
{
    int start = 0, end = n - 1, ans = -1;

    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            // Main concept :- we find first occurrence so if we found our key then we try to find its left side occurence that's why we move our end = mid-1;
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}

int lastOcc(vector<int> &arr, int n, int key)
{
    int start = 0, end = n - 1, ans = -1;

    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            // Main concept :- we find last occurrence so if we found our key then we try to find its right side occurence that's why we move our start = mid+1;
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}

pair<int, int> firstAndLastOccurence(vector<int> &arr, int n, int key)
{
    pair<int, int> ans;
    ans.first = firstOcc(arr, n, key);
    ans.second = lastOcc(arr, n, key);

    return ans;
}

int main()
{
    // vector<int> arr = {1, 2, 3, 3, 5};
    vector<int> arr = {1, 2, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 7, 12, 12, 12, 12, 12, 35};

    pair<int, int> ans5, ans12;
    ans5 = firstAndLastOccurence(arr, 21, 5);
    ans12 = firstAndLastOccurence(arr, 21, 12);

    cout << "First occurence of 5 is at " << ans5.first << endl;
    cout << "last occurence of 5 is at " << ans5.second << endl;

    cout << "First occurence of 12 is at " << ans12.first << endl;
    cout << "last occurence of 12 is at " << ans12.second << endl;

    return 0;
}
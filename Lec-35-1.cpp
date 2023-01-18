// Given an array a[]. The task is to find the inversion count of a[]. Where two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
#include <bits/stdc++.h>
using namespace std;

int merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2, count = 0;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] <= second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
            count += len1 - index1; // if first[index1] > second[index2], then all element in first index greater than index1 are greater than second[index2]. So len1-index1 inversion are here.
        }
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    // free storage
    delete[] first;
    delete[] second;

    return count;
}

void countInversion(int *arr, int s, int e, int *count)
{
    // base case
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    countInversion(arr, s, mid, count);
    countInversion(arr, mid + 1, e, count);
    *count = *count + merge(arr, s, e);
}

int main()
{
    int arr[] = {1, 2, 7, 8, 7, 6};

    int n = sizeof(arr) / sizeof(arr[0]);

    int count = 0;
    countInversion(arr, 0, n - 1, &count);

    cout << "Total number of inversion in giver array is : " << count << endl;

    return 0;
}
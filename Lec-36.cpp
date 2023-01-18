// Quick sort
#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int s, int e)
{
    int count = 0;
    for (int i = s; i <= e; i++)
    {
        if (arr[i] < arr[s])
            count++;
    }

    swap(arr[s], arr[s + count]);
    int pivot = s + count;

    while (s < pivot && pivot < e)
    {
        while (arr[s] < arr[pivot])
        {
            s++;
        }

        while (arr[e] > arr[pivot])
        {
            e--;
        }

        if (s < pivot && pivot < e)
        {
            swap(arr[s++], arr[e--]);
        }
    }

    return pivot;
}

void quickSort(int *arr, int s, int e)
{
    // Base condition
    if (s >= e)
        return;

    // Partition
    int p = partition(arr, s, e);

    // Recursive calls
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[15] = {3, 7, 0, 1, 5, 8, 3, 2, 34, 66, 87, 23, 12, 12, 12};
    int n = 15;

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

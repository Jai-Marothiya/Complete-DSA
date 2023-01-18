// Sort array with recursive Bubble Sort
#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void BubbleSort(int *arr, int n) // pass string by reference
{
    // Base case
    if (n == 0 || n == 1)
        return;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }

    return BubbleSort(arr, n - 1);
}

int main()
{
    int arr[10] = {3, 5, 2, 35, 6, 9, 30, 45, 16, 38};

    cout << "Before :";
    print(arr, 10);

    BubbleSort(arr, 10);

    cout << "Before :";
    print(arr, 10);

    return 0;
}

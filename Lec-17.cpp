// Bubble sort wih Optimisation.
#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void BubbleSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

int main()
{
    vector<int> arr = {19, 20, 21, 28, 37, 48, 7, 8, 10};
    BubbleSort(arr);
    cout << "Array after BubbleSort is : ";
    printArr(arr);

    return 0;
}
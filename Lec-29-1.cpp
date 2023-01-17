// Home work: Create a Jaggered Array dynamically
// It is an array whose elements are, possibly of different sizes.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row;
    cout << "Enter the number of rows you want : ";
    cin >> row;
    int *col = new int[row];

    cout << "Enter the size of " << row << " different arrays : ";
    for (int i = 0; i < row; i++)
    {
        cin >> col[i];
    }

    int **arr = new int *[row];

    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col[i]];
    }

    // Creation is done

    // taking input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col[i]; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Print output
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Releasing memory
    for (int i = 0; i < row; i++)
    {
        delete[] arr[col[i]];
    }

    delete[] arr;

    return 0;
}
// We have to paint n boards of length {A1, A2…An}. There are k painters available and each takes 1 unit of time to paint 1 unit of the board. The problem is to find the minimum time to get this job was done under the constraints that any painter will only paint continuous sections of boards, say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int mid)
{
    int currBoard = 0, count = 1; // count use to count students
    for (int i = 0; i < n; i++)
    {
        // if Boards alot to painter is less than mid then continue
        if (currBoard + arr[i] <= mid)
        {
            currBoard += arr[i];
        }
        else
        {
            // if pages alot to student is exceed then move to next student by count ++ and check whether count not more than m and that arr[i] also not more than mid and set currPages = arr[i];
            count++;
            if (count > m || arr[i] > mid)
            {
                return false;
            }

            currBoard = arr[i];
        }
    }

    return true;
}

// Firstly set a range in which our answer lie that is basically between 0 to sum of pages of all books then apply binary search with proper conditions.
int allocatePainters(vector<int> &arr, int n, int m)
{
    int s = 0, sum = 0, ans = -1;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int e = sum;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        // if mid is possible answer then set ans =mid , as we have to minimum ans so set new range to left
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            // if mid is not possible answer then shift search area to right.
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int main()
{
    vector<int> arr = {10, 20, 60, 50, 30, 40};
    vector<int> arr2 = {19, 20, 21, 28, 37, 48, 7, 8, 10};

    cout << "Minimum book pages allocate is : " << allocatePainters(arr, 6, 3) << endl; // m=number of painters = 2, n= number of boards = 4

    return 0;
}
// Given a number of pages in N different books and M students. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.(Book Allocation Problem)
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int mid)
{
    int currPages = 0, count = 1; // count use to count students
    for (int i = 0; i < n; i++)
    {
        // if pages alot to student is less than mid then continue
        if (currPages + arr[i] <= mid)
        {
            currPages += arr[i];
        }
        else
        {
            // if pages alot to student is exceed then move to next student by count ++ and check whether count not more than m and that arr[i] also not more than mid and set currPages = arr[i];
            count++;
            if (count > m || arr[i] > mid)
            {
                return false;
            }

            currPages = arr[i];
        }
    }

    return true;
}

// Firstly set a range in which our answer lie that is basically between 0 to sum of pages of all books then apply binary search with proper conditions.
int allocateBooks(vector<int> &arr, int n, int m)
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
    vector<int> arr = {10, 40, 20, 30};
    vector<int> arr2 = {19, 20, 21, 28, 37, 48, 7, 8, 10};

    cout << "Minimum book pages allocate is : " << allocateBooks(arr, 4, 2) << endl; // m=number of student = 2, n= number of books = 4

    return 0;
}
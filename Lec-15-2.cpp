// You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.

#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &stalls, int n, int mid, int m)
{
    int currDistance = 0, count = 1, lastPos = 0;

    for (int i = 1; i < n; i++)
    {
        if ((stalls[i] - stalls[lastPos]) >= mid)
        {
            count++;
            if (count == m)
            {
                return true;
            }
            lastPos = i;
        }
    }
    return false;
}

int minDistance(vector<int> &stalls, int n, int m)
{
    int s = 0, maxi = INT_MIN;
    sort(stalls.begin(), stalls.end());

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, stalls[i]);
    }

    int e = maxi;

    int mid = s + (e - s) / 2, ans = -1;

    while (s <= e)
    {
        if (isPossible(stalls, n, mid, m))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int main()
{

    vector<int> stalls = {1, 2, 4, 8, 9};

    cout << "Minimum distance bewtween any two cows is : " << minDistance(stalls, 5, 3);

    return 0;
}
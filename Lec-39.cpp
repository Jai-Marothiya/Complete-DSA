// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order
#include <bits/stdc++.h>
using namespace std;

void permutation(vector<vector<int>> &ans, int index, vector<int> &arr)
{
    // base case
    if (index >= arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int j = index; j < arr.size(); j++)
    {
        swap(arr[index], arr[j]);
        permutation(ans, index + 1, arr);
        // Backtrack
        swap(arr[index], arr[j]);
    }
}

void print(vector<vector<int>> &ans)
{
    int n = ans.size();
    int m = ans[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans;

    permutation(ans, 0, arr);

    sort(ans.begin(), ans.end()); // sort the permutations in increasing order

    print(ans);

    return 0;
}
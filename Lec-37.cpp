// Find the power set of given array
#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &ans, vector<int> output, int index, vector<int> &nums)
{
    // Base case
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // Exclude index element
    solve(ans, output, index + 1, nums);

    // Include index element
    output.push_back(nums[index]);
    solve(ans, output, index + 1, nums);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;

    solve(ans, output, 0, nums);

    return ans;
}

void print(vector<vector<int>> &v)
{
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> v = {1, 2, 3};
    int n = v.size();

    vector<vector<int>> ans = subsets(v);

    print(ans);

    return 0;
}

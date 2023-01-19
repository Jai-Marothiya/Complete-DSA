// Find the power set of given array using bits approach
// Concept : If array has n element then we have 8 positions where either element present or not. So in bits also same game is going. Eg for 3 bits numbers each position have value either 0/1. 0 signify absence and 1 signify presence. So we take number fom 0 to 2^(nums.size()), check each bit of every number is if is 0 we leave corresponding position element and if 1 then include it.
#include <bits/stdc++.h>
using namespace std;

bool getbit(int n, int pos)
{
    return n & (1 << pos);
}

void solve(vector<vector<int>> &ans, int val, vector<int> &nums)
{
    for (int i = val; i >= 0; i--) // loop for all numbers from 0 to 2^(nums.size())
    {
        vector<int> output;
        for (int j = 0; j < nums.size(); j++)
        {
            if (getbit(i, j)) // check bit of jth position in number i
            {
                output.push_back(nums[j]); // if 1 then add in output
            }
        }
        ans.push_back(output);
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;

    solve(ans, pow(2, nums.size()), nums);

    return ans;
}

// Function print final answer
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

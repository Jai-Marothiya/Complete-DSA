// Find all the subsequences of a string
#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &ans, string output, int index, string &str)
{
    // Base case
    if (index >= str.length())
    {
        if (!output.empty())
            ans.push_back(output);
        return;
    }

    // Exclude index element
    solve(ans, output, index + 1, str);

    // Include index element
    output.push_back(str[index]);
    solve(ans, output, index + 1, str);
}

vector<string> subsequences(string &str)
{
    vector<string> ans;
    string output = "";

    solve(ans, output, 0, str);

    return ans;
}

void print(vector<string> &v)
{
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i].length(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    string str = "Jai";
    int n = str.length();

    vector<string> ans = subsequences(str);

    print(ans);

    return 0;
}

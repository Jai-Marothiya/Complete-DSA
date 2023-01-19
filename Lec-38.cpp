// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order. map<int, string> = {2->"abc",3-."def",4->"ghi",5->"jkl",6->"mno",7->"pqrs",8->"tuv",9->"wxyz"}
#include <bits/stdc++.h>
using namespace std;

string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void combination(vector<string> &ans, string output, int index, string &digit)
{
    // base case
    if (index >= digit.length())
    {
        if (!output.empty()) // push abck only if output is not empty
            ans.push_back(output);
        return;
    }

    //
    int number = digit[index] - '0'; // digit[index] give me character of equivalent number that's why we subtract '0'.
    string val = mapping[number];    // give string from mapping at index = number

    for (int i = 0; i < val.length(); i++)
    {
        output.push_back(val[i]);
        combination(ans, output, index + 1, digit);
        output.pop_back(); // clear output when move to next character. Follow tree from notes on 19/1/23
    }
}

void print(vector<string> &ans)
{
    int n = ans.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
}

int main()
{
    string str;

    cout << "Enter the digits of phone from 2-9 : ";
    cin >> str;
    vector<string> ans;
    string output;

    combination(ans, output, 0, str);

    print(ans);

    return 0;
}
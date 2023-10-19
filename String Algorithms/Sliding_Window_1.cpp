// Find all occurances of string s in string t and return starting index of all occurences
// Example s="Cod" and t="CodeNCode is an coding platform", So s occur at index 0,5.
//TC: O(N*M)
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string t, s;

    getline(cin, t);
    getline(cin, s);
    int n = s.length(), m = t.length(), i = 0, j = 0, k = 0;
    vector<int> ans;
    string temp = "";
    while (i < m && j < m)
    {
        if (temp.compare(s) == 0)
        {
            ans.push_back(i);
            i++;
            j = i;
            k = 0;
            temp = "";
        }

        if (t[j] == s[k])
        {
            temp += t[j];
            j++, k++;
        }
        else if (t[j] != s[k] || k >= n)
        {
            k = 0;
            i++;
            j = i;
            temp = "";
        }
    }
    if (temp.compare(s) == 0)
    {
        ans.push_back(i);
        i++;
        j = i;
        k = 0;
        temp = "";
    }

    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
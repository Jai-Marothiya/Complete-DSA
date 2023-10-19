// Find minimum length string need to append to given string to make it palindrome
// let's say s="abcbaghh" so in this case we have need to append "hhg" to make s palindrome
// TC: O(N)
#include <bits/stdc++.h>

using namespace std;

// this function return maximum length of prefix which is palindrome
int pre_Func(string s)
{
    int n = s.length();
    vector<int> res(n, 0);

    for (int i = 1; i < n; i++)
    {
        int j = res[i - 1];

        while (j > 0 && s[j] != s[i])
        {
            j = res[j - 1];
        }

        if (s[j] == s[i])
        {
            j++;
        }
        res[i] = j;
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return res[n - 1];
}

int main()
{
    string s;

    getline(cin, s);
    int n = s.length();
    string t = s;
    reverse(t.begin(), t.end());
    string st = s + "#" + t;
    int pre = pre_Func(st);

    if (pre == n)
    {
        cout << (n - pre) << " " << s << endl;
    }
    else
    {
        string newS = s.substr(pre, n - pre);
        reverse(newS.begin(), newS.end());
        cout << (n - pre) << " " << newS + s << endl;
    }

    cout << endl;
    return 0;
}
// Find all occurances of string s in string t and return starting index of all occurences
// Example s="Cod" and t="CodeNCode is an coding platform", So s occur at index 0,5.
// TC: O(N+M)
// Here we make a array called z-array and z[i] store length of maximum substring start at ith index and is equal to proper prefix of given string
// given string abbabac
// z[7]= {0,0,0,2,0,1,0}
#include <bits/stdc++.h>

using namespace std;

vector<int> z_Func(string s)
{
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++)
    {
        if (i <= r)
        {
            z[i] = min(r - i + 1, z[i - l]);
        }

        while (s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }

        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i]-1;
        }
    }
    return z;
}

int main()
{
    string t, s;

    getline(cin, t);
    getline(cin, s);
    int n = s.length(), m = t.length();
    string st = s + "#" + t;
    vector<int> pre = z_Func(st);

    for (int i = n + 1; i <= n + m; i++)
    {
        if (pre[i] == n)
        {
            cout << i - n -1 << endl;
        }
    }

    cout << endl;
    return 0;
}
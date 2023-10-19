// Given two string s and t you have to find out is it possible to make s equal to t by rotating string s any number of times, if yes then return index from where you rotate it and if not return -1;
//  Lets take an example s="pepcoding" and t="dingpepco" if we rotate string from index 5 then we can make it equal to t

#include <bits/stdc++.h>

using namespace std;

vector<int> pre_Func(string s)
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
    return res;
}

int main()
{
    string t, s;

    getline(cin, t);
    getline(cin, s);
    int n = s.length(), m = t.length();
    if (s == t)
    {
        cout << n << endl;
    }
    else
    {
        string st = t + "#" + s + s;
        vector<int> pre = pre_Func(st);
        int idx=-1;
        for (int i = n + 1; i <= 3*n; i++)
        {
            if (pre[i] == n)
            {
                idx=i;
                break;
            }
        }
        cout<<idx-2*n+1<<endl;
    }

    cout << endl;
    return 0;
}
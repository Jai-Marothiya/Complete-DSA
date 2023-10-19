// Find all occurances of string s in string t and return starting index of all occurences
// Example s="Cod" and t="CodeNCode is an coding platform", So s occur at index 0,5.
// TC: O(N+M)
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
            j=res[j-1];
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
    string st = s+"#"+t;
    vector<int> pre = pre_Func(st);

    for(int i=n+1;i<=n+m;i++){
        if(pre[i]==n){
            cout<<i-2*n<<endl;
        }
    }

    cout << endl;
    return 0;
}
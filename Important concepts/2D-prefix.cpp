#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007
#define ll long long int

ll prefix(vector<vector<ll>> a, vector<vector<ll>> &pre, int n, int m)
{
    if (n == 0 && m == 0)
    {
        return pre[0][0] = a[0][0];
    }

    if (n < 0 || m < 0)
        return 0;

    pre[n][m] = a[n][m] + prefix(a, pre, n - 1, m) + prefix(a, pre, n, m - 1) - prefix(a, pre, n - 1, m - 1);

    return pre[n][m];
}

int main()
{
    int n, m, U, L, D, R, ans;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m, 0));
    vector<vector<ll>> pre(n, vector<ll>(m, 0));

    cout << "Enter value of matrix: " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    prefix(a, pre, n - 1, m - 1);

    cout << "Prefix sum vector is : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << pre[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter U,L and D,R corner of rectangle whose area you want to find: " << endl;
    cin >> U >> L >> D >> R;

    ans = pre[D][R] - (L - 1 >= 0 ? pre[D][L - 1] : 0) - (U - 1 >= 0 ? pre[U - 1][R] : 0) + ((L - 1 >= 0 && U - 1 >= 0) ? pre[L - 1][U - 1] : 0);
    cout << ans << endl;
    return 0;
}
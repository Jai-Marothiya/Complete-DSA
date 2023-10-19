// we have given array of n integers, calculate number of subsets whose sum less than 'x'
#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007
#define ll long long int
#define vll vector<ll>
#define pr(a, n)                \
    for (int i = 0; i < n; i++) \
        cout << a[i] << " ";
#define in(a, n)                \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
#define all(a) a.begin(), a.end()

vll subsetSum(vll a)
{
    int n = a.size();
    vll ans;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        ll subsum = 0;
        for (int j = 0; j < n; j++)
        {
            if (mask & (1 << j))
            {
                subsum += a[j];
            }
        }
        ans.push_back(subsum);
    }
    sort(all(ans));
    // pr(ans, ans.size());
    // cout << endl;
    return ans;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vll v(n);
    vll a, b;
    in(v, n);
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            a.push_back(v[i]);
        else
            b.push_back(v[i]);
    }
    a = subsetSum(a);
    b = subsetSum(b);
    pr(a, a.size());
    cout << endl;
    pr(b, a.size());
    cout << endl;

    ll ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int flag = x - a[i];
        ans += upper_bound(all(b), flag) - b.begin();
    }
    cout << ans << endl;
}

int main()
{
    solve();

    return 0;
}
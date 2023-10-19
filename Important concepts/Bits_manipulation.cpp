// Given an array of size N<=10^5 and a[i]<=10^9, Find sum of XOR(a[i],a[j]) i.e. j>i and 0<=i<N;

#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007
#define ll long long int

ll solve(int n, vector<int> a)
{
    ll ans = 0;

    vector<int> cnt(31, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            if ((a[i] >> j) & 1)
            {
                cnt[j]++;
            }
        }
    }

    for (int i = 0; i < 31; i++)
    {
        ans += (1LL * cnt[i] * (n - cnt[i])) * (1LL * 1 << i);
    }

    return ans;
}

int main()
{
    int n; // pow(n,k)
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, a);

    return 0;
}
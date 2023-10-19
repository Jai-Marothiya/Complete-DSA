// we have given N regions(Li,Ri) on number line, calculate sum of regions which covered by more than k segments. N<=100000, 0<= Li,Ri <= 10^(18).
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
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> seg;

    for (int i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;
        seg.push_back(make_pair(l, 1));
        seg.push_back(make_pair(r, -1));
    }

    sort(seg.begin(), seg.end());
    int cnt = 0;
    vector<int> len(n + 1, 0);

    for (int i = 0; i < seg.size(); i++)
    {
        int j = i;
        while (j < seg.size() && seg[j].first == seg[i].first)
        {
            cnt += seg[j].second;
            j++;
        }
        i = j - 1;
        if (i != (seg.size() - 1))
        {
            ll seglen = seg[i + 1].first - seg[i].first;
            len[cnt] += seglen;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        len[i] += len[i + 1];
    }

    pr(len, n + 1);
    cout << endl;
}

int main()
{
    solve();

    return 0;
}
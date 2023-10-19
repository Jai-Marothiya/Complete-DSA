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

ll fact(ll n)
{
    if (n == 1)
        return 1;

    return (n * (fact(n - 1) % mod)) % mod;
}

ll fastExpo(ll temp)
{
    ll b = mod - 2, ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * temp) % mod;

        temp = (temp * temp) % mod;
        b = b >> 1;
    }
    return temp;
}

// ll nCr(ll n, ll r)
// {
//     ll num = fact(n) % mod, deno = (fact(n - r) * fact(r));
//     deno = fastExpo(deno) % mod;
//     return (num * deno) % mod;
// }

ll power(ll a, ll b)
{
    ll x = 1, y = a;
    while (b > 0)
    {
        if (b % 2)
        {
            x = (x * y) % mod;
        }
        y = (y * y) % mod;
        b /= 2;
    }
    return x % mod;
}

ll modular_inverse(ll n)
{
    return power(n, mod - 2);
}

ll nCr(ll n, ll k)
{
    cout << fact(n) << " " << (((modular_inverse(fact(k) * (fact(n - k))) % mod)) % mod);
    return (fact(n) * ((modular_inverse(fact(k) * (fact(n - k))) % mod)) % mod);
}

int main()
{
    int n, r;
    cin >> n >> r;

    cout << nCr(n, r);

    return 0;
}
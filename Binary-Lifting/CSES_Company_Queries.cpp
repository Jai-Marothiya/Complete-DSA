#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define int long long
#define ll long long
#define lld long double
#define PI 3.141592653589793238462
#define pb push_back
#define sz(x) ((int)(x).size())
#define INF 1e18
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()

/*...............................................................*/
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
void extendgcd(ll a, ll b, ll *v)
{
    if (b == 0)
    {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return;
    }
    extendgcd(b, a % b, v);
    ll x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;
} // pass an arry of size1 3
ll mminv(ll a, ll b)
{
    ll arr[3];
    extendgcd(a, b, arr);
    return arr[0];
} // for non prime b
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact)
{
    ll val1 = fact[n];
    ll val2 = ifact[n - r];
    ll val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}
vector<ll> sieve(int n)
{
    int *arr = new int[n + 1]();
    vector<ll> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m
ll phin(ll n)
{
    ll number = n;
    if (n % 2 == 0)
    {
        number /= 2;
        while (n % 2 == 0)
            n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            number = (number / i * (i - 1));
        }
    }
    if (n > 1)
        number = (number / n * (n - 1));
    return number;
} // O(sqrt(N))
void google(int t) { cout << "Case #" << t << ": "; }
/*.....................................................*/
bool static cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first > b.first)
        return true;
    else if (a.first == b.first)
        return a.second < b.second;
    else
        return false;
}

signed main()
{
    fastio();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1, -1);
        for (int i = 2; i <= n; i++)
        {
            cin >> a[i];
            // cout << a[i] << " ";
        }

        int lg = log2(n) + 1;
        // cout << lg << endl;
        vector<vector<int>> par(n + 2, vector<int>(lg + 1, -1));
        for (int i = 1; i <= n; i++)
        {
            par[i][0] = a[i];
            // cout << par[i][0] << " ";
        }
        for (int j = 1; j <= lg; j++)
        {
            for (int i = 2; i <= n; i++)
            {
                // cout << i << " " << j << endl;
                par[i][j] = par[i][j - 1] == -1 ? -1 : par[par[i][j - 1]][j - 1];
            }
            // cout << endl;
        }

        for (int i = 0; i < q; i++)
        {
            int node, k;
            cin >> node >> k;
            // node--;
            for (int j = lg; j >= 0; j--)
            {
                if(node==-1)break;
                if (k >> j & 1)
                {
                    node = par[node][j];
                    // cout<<node<<" ";
                }
            }
            cout << node << endl;
        }
    }

    return 0;
}

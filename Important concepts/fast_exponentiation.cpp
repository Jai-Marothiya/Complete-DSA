#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007

long long int fast(int n, int k)
{
    long long int ans = 1;

    while (k)
    {
        if (k & 1)
            ans = (ans * n) % mod;
        n = (n * n) % mod;
        k = k >> 1;
    }
    return ans;
}

int main()
{
    int n, k; // pow(n,k)
    cin >> n >> k;

    vector<int> dp(n + 1, -1);
    cout << fast(n, k);

    return 0;
}
// Catalon number: C0=1, C(n+1)= C(0)*C(n-0) + C(1)*C(n-1)+ C(2)*C(n-2) + .... + C(n)*C(n-n);
#include <bits/stdc++.h>

using namespace std;

long long int catalon(int n, vector<int> &dp)
{
    // base case
    if (n == 0 || n == 1)
        return 1;

    long long int ans = 0;

    if (dp[n] != -1)
        return dp[n];
    for (int i = 0; i < n; i++)
    {
        ans += catalon(i, dp) * catalon(n - i - 1, dp);
        // cout << ans << endl;
    }
    return dp[n] = ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);
    cout << catalon(n, dp);

    return 0;
}
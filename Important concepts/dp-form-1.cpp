// Given an n numbers , find if any subsets present in it with sum T;
// n<=100 , x[i]<=10000, t<=10000
#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007
#define ll long long int
int n, t;
int x[101];
int dp[105][10100];

int rec(int level, int sum)
{
    // base cases
    if (level == n + 1)
    {
        if (sum == t)
        {
            return 1;
        }
        else
            return 0;
    }

    if (dp[level][sum] != -1)
        return dp[level][sum];

    // compute
    int ans = rec(level + 1, sum);

    if (sum + x[level] <= t && rec(level + 1, sum + x[level]))
    {
        ans = 1;
    }

    return dp[level][sum] = ans;
}

void solve()
{
    cin >> n >> t;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    cout << rec(1, 0);
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}
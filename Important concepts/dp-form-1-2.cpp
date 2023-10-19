// Given an n numbers , find if any subsets present in it with sum T and print the subset if present(if more then one print anyone);
// n<=100 , x[i]<=10000, t<=10000 and we have given q queries for each array. q<=10000

#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007
#define ll long long int
int n, t;
int x[101];
int dp[105][10100];
// vector<int> curr;

int rec(int level, int sumleft)
{
    // base cases
    if (level == n + 1)
    {
        if (sumleft == 0)
        {
            return 1;
        }
        else
            return 0;
    }

    if (dp[level][sumleft] != -1)
        return dp[level][sumleft];

    // compute
    int ans = rec(level + 1, sumleft);

    if (sumleft - x[level] >= 0 && rec(level + 1, sumleft - x[level]))
    {
        ans = 1;
    }

    return dp[level][sumleft] = ans;
}

void printset(int level, int target)
{
    if (level == n + 1)
        return;

    if (dp[level + 1][target] == 1) // don't take
    {
        printset(level + 1, target);
    }
    else if (dp[level + 1][target - x[level]] == 1 || target - x[level] == 0) // take
    {
        cout << x[level] << " ";
        printset(level + 1, target - x[level]);
    }
}

// Print function to print all solution
void printset2(int level, int target, vector<int> &curr)
{
    if (level == n + 1 || target == 0)
    {
        for (auto a : curr)
        {
            cout << a << " ";
        }
        cout << endl;
        return;
    }

    if (dp[level + 1][target] == 1) // don't take
    {
        printset2(level + 1, target, curr);
    }
    if (dp[level + 1][target - x[level]] == 1 || target - x[level] == 0) // take
    {
        // cout << x[level] << endl;
        curr.push_back(x[level]);
        printset2(level + 1, target - x[level], curr);
        curr.pop_back();
    }
}

void solve()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    int q;
    cin >> q;
    vector<int> curr;
    while (q--)
    {
        cin >> t;
        if (rec(1, t))
            printset2(1, t, curr);
        else
            cout << "Not Possible";

        cout << endl;
    }

    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[n][0];
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
// Given two integers N (1<=N<=9) and K. Find the kth permutation sequence of first N natural numbers. Return the answer in string format.
#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007

void next_per(vector<int> &a, int n, int k)
{
    int i, j;
    for (i = n - 1; i >= 1; i--)
    {
        if (a[i] > a[i - 1])
        {
            break;
        }
    }

    j = i - 1;
    while (i < n)
    {
        if (a[i] > a[j])
        {
            i++;
        }
        else
        {
            break;
        }
    }
    i--;
    swap(a[i], a[j]);

    reverse(a.begin() + j + 1, a.end());
}

string kthPermutation(int n, int k)
{
    vector<int> a;

    for (int i = 1; i <= n; i++)
    {
        a.push_back(i);
    }

    for (int i = 1; i < k; i++)
    {
        next_per(a, n, k);
    }

    string ans;
    for (int i = 0; i < a.size(); i++)
    {
        ans += '0' + a[i];
    }

    return ans;
}

int main()
{
    int n, k; // pow(n,k)
    cin >> n >> k;
    // considering 1 as composite number
    cout << kthPermutation(n, k);

    return 0;
}
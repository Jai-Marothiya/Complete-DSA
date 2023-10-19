#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007

int isPrime(int k)
{
    // Corner cases
    if (k <= 1)
        return 0;
    if (k == 2 || k == 3)
        return 1;

    // below 5 there is only two prime numbers 2 and 3
    if (k % 2 == 0 || k % 3 == 0)
        return 0;

    // Using concept of prime number can be represented in form of (6*k + 1) or(6*k - 1)
    for (int i = 5; i * i <= k; i = i + 6)
        if (k % i == 0 || k % (i + 2) == 0)
            return 0;

    return 1;
}

int nthPrime(int n)
{
    int i = 2;
    while (n)
    {
        if (isPrime(i))
            n--;
        i++;
    }

    return i - 1;
}

int main()
{
    int n; // pow(n,k)
    cin >> n;
    // considering 1 as composite number
    cout << nthPrime(n);

    return 0;
}
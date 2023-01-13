// Find count of prime number less than given interger n;
//  Concept : Sieve of Eratosthenes : set all number less than to true. then start from 2 and set multiple of 2 to false and repeat this till n-1
// Time Complexity : n/2 + n/3 + n/5 ....  = n(1/2 + 1/3 + 1/5 + 1/7 ....) . So it is harmonic progression its sum is log(log(n));
// Time Complexity : O(n*log(log(n)))
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, count = 0;
    cout << "Enter a number : ";
    cin >> n;

    vector<bool> ans(n + 1, true);

    for (int i = 2; i < n; i++)
    {
        if (ans[i] == 1)
        {
            count++;
            for (int j = 2 * i; j < n; j += i)
            {
                ans[j] = 0;
            }
        }
    }

    cout << "Count of prime number less than " << n << " is : " << count << endl;

    return 0;
}
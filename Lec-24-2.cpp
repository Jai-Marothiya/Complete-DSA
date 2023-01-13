// find GCD/HCF of two number
// Concept gcd(a,b)=gcd(a%b,b) such that a>b;
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    // we always store max of a and b in a for ease
    while (a && b)
    {
        if (b > a)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        a = a % b;

        int temp = a;
        a = b;
        b = temp;
    }

    return a;
}

int main()
{
    int a, b;
    cout << "Enter two number a and b : ";
    cin >> a >> b;

    cout << "GCD of " << a << " and " << b << " is : " << gcd(a, b) << endl;

    return 0;
}
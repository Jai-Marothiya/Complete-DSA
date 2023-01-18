// Find a^b using recursion
#include <bits/stdc++.h>
using namespace std;

// Methood -1
int power(int a, int b)
{
    // Base case - b==0
    if (b == 0)
        return 1;

    return a * power(a, b - 1);
}

// Methood - 2
int power2(int a, int b)
{
    // Base case - b==0
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    // Recursive call
    int ans = power2(a, b / 2);

    if (b % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return a * ans * ans;
    }
}

int main()
{
    int a, b;
    cout << "Enter two numbers : ";
    cin >> a >> b;

    cout << a << " raise to power " << b << " is : " << power(a, b) << endl;
    cout << a << " raise to power " << b << " is : " << power2(a, b) << endl;

    return 0;
}

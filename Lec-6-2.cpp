#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, i = 0, ans = 0;
    cin >> n;
    int b = n;

    // Binary to Decimal Approach
    while (n != 0)
    {
        int bit = n % 10; // take bit from right
        if (bit == 1)
            ans = pow(2, i) + ans;

        n = n / 10;
        i++;
    }

    cout << "Decimal of " << b << " is " << ans << endl;
    cout << (-734 / 10) << endl;

    return 0;
}
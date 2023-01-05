#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, i = 0, ans = 0;
    cin >> n;
    int b = n;

    // Decimal to binary Approach
    while (n != 0)
    {
        int bit = n & 1; // if right most bit is 1 give 1 otherwise 0
        ans = (bit * pow(10, i)) + ans;

        n = n >> 1; // shift all bit to right by 1 position
        i++;
    }

    cout << "Binary of " << b << " is " << ans << endl;

    return 0;
}
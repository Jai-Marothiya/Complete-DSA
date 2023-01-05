#include <iostream>
using namespace std;

int main()
{
    int a = 4, b = 6;

    cout << "a&b = " << (a & b) << endl;
    cout << "a|b = " << (a | b) << endl;
    cout << "~a = " << ~a << endl;
    // so a=000000.....0100 in binary now , ~a= 1111111.....1011, so it is negative we have to take 2's complemet of it to print it.
    // 1's complement of ~a = 000000.....0100, now add 1 in LSB so we get 0000000.....0101 which in 5 and ~a is negative so o/p is -5.
    cout << "a^b = " << (a ^ b) << endl;

    // Left shift(<<) and right shift(>>) operators

    cout << (17 >> 1) << endl;
    cout << (17 >> 3) << endl;
    cout << (19 << 1) << endl;
    cout << (21 << 2) << endl;

    return 0;
}
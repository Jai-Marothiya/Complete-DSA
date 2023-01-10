// Negative integer to Binary
// approach
// 1st find binary number of given number (asume number is positive)
// 2nd find 1's complement of binary number
// 3dr find 2's complement of binary number
#include <iostream>
#include <math.h>

using namespace std;

void print_binary(int n)
{
    int bi_num[32] = {0};

    for (int i = 31; i >= 0 && n > 0; --i)
    {
        if (n % 2)
        {
            bi_num[i] = 1;
        }
        n /= 2;
    }

    // now find 1's complement
    for (int i = 0; i < 32; i++)
    {
        if (bi_num[i] == 0)
        {
            bi_num[i] = 1;
        }
        else
        {
            bi_num[i] = 0;
        }
    }

    // now find 2's complement
    for (int i = 31; i >= 0; i--)
    {
        if (bi_num[i] == 1)
        {
            bi_num[i] = 0;
        }
        else
        {
            bi_num[i] = 1;
            break;
        }
    }
    // now print binary form of given negative number
    cout << "It's binary form is : ";
    for (int i = 0; i < 32; i++)
    {
        cout << bi_num[i];
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter a negative number : ";
    cin >> n;

    print_binary(-n);
}
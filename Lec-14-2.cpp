// Find square root of number with O(log(n)) time complexity
#include <bits/stdc++.h>
using namespace std;

// Basically square root is lie between 0 to num, and it is monotonic series so we can apply binary search here;
long long int squareRootInt(int num)
{
    int start = 0, end = num;

    long long int mid = start + (end - start) / 2, ans = -1;
    while (start <= end)
    {
        if (mid * mid == num)
        {
            return mid;
        }
        else if (mid * mid > num)
        {
            end = mid - 1;
        }
        else
        {
            ans = mid;
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}

double preciseRoot(int num, int tempSol, int preciseDigit)
{
    double factor = 1, ans = tempSol;

    for (int i = 0; i < preciseDigit; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < num; j += factor)
        {
            ans = j;
        }
    }

    return ans;
}

int main()
{
    int num;
    cout << "Enter a number : ";
    cin >> num;
    int tempSol = squareRootInt(num);

    cout << "Square root of " << num << " is " << preciseRoot(num, tempSol, 10) << endl;

    return 0;
}
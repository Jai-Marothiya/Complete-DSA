// Recursion problem : Print given number as like Eg. n=412 print: Four One Two
#include <bits/stdc++.h>
using namespace std;

void callDigits(int n, string arr[])
{
    // Base case
    if (n == 0)
        return;

    int digit = n % 10;
    n /= 10;
    callDigits(n, arr);

    cout << arr[digit] << " ";
}

int main()
{
    int n;
    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    cin >> n;

    callDigits(n, arr);

    return 0;
}
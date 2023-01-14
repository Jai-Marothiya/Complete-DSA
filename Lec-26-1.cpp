// Play with pointers in Functions
#include <bits/stdc++.h>
using namespace std;

void print(int *p)
{
    cout << "Address inside print ->" << p << endl;
    cout << "Value inside print ->" << *p << endl;
}

void update(int *p)
{
    *p = *p + 2;

    // If we write this *p = *p + 2; after p++ then value will update at next address that contain garbage value
    p++;
    cout << "Address of p+1 inside update ->" << p << endl;
}

int getSum(int arr[], int n)
{
    cout << "Size of arr in getsum is : " << sizeof(arr) << endl; // Because it it a pointer
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += i[arr];
    }

    return sum;
}

int main()
{
    /*
    int a = 5;
    int *p = &a;

    // print(p);

    //  Important
    // We cannot change the address from function but we can change the value
    cout << "Before Address ->" << p << endl;
    cout << "Before value ->" << *p << endl;
    update(p);
    cout << "After Address ->" << p << endl;
    cout << "After value ->" << *p << endl; */

    int arr[6] = {1, 2, 3, 4, 5, 6};

    cout << "Size of Actual arr is : " << sizeof(arr) << endl;
    int sum = getSum(arr + 3, 3); // sum of element from index 3
    cout << "Sum of array is : " << sum << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// It is a bad practice to return ref variable because we function call is finished memory of variable inside func is clear so we are not approachable to that memory
int &func(int a)
{
    int p = a;
    int &ans = p;
    return ans;
}

void update(int &n)
{
    // ref variable of n is made that also point to same memory so original variable is editable
    n++;
}

void update1(int n)
{
    // copy of n is made so original variable is not changed
    n++;
}

int main()
{
    /*
        int i = 5;
        // Create a ref variable
        int &j = i;

        cout << "i = " << i << endl;
        i++;
        cout << "i = " << i << endl;
        j++;
        cout << "i = " << i << endl;
        cout << "j = " << j << endl;
    */

    int n = 5;
    cout << "Before " << n << endl;
    update(n);
    cout << "After " << n << endl;

    // cout << func(n) << endl; // Bad practice to use ref variable in return part
    return 0;
}
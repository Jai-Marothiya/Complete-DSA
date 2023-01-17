// Macros : A piece of code in a program that is replaced by value of macro
// For more info go with this article : https://www.geeksforgeeks.org/macros-and-its-types-in-c-cpp/
#include <bits/stdc++.h>
using namespace std;

#define Pi 3.14              // Here Pi is macro
#define area(r) (Pi * r * r) // Here area(r) is macro. Whenever the compiler finds area(r) in the program it replaces it with the macros definition i.e., (Pi * r * r)

int main()
{
    int r = 5;
    // double pi=3.14;

    cout << "Area is : " << area(r) << endl;

    return 0;
}
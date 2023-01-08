// Normal array Vs STL array
#include <iostream>
#include <array>
using namespace std;

int main()
{
    int basic[] = {1, 2, 3};

    array<int, 4> a = {1, 2, 3, 4};

    int size = a.size();

    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Element at index 2 is : " << a.at(2) << endl;

    cout << "Array a is empty or not : " << a.empty() << endl; // if empty return 1 otherwise 0;

    cout << "First element of a is : " << a.front() << endl;
    cout << "Last element of a is : " << a.back() << endl;

    return 0;
}
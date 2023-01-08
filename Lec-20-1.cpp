// STL Vector
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v; // first way to initialise

    vector<int> a(5, 1); // second way to initialise : a = {1,1,1,1,1};
    cout << "Vector a -> ";
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> last(a); // copy a in last;

    cout << "Capacity -> " << v.capacity() << endl;

    v.push_back(1);
    cout << "Capacity -> " << v.capacity() << endl;

    v.push_back(2);
    cout << "Capacity -> " << v.capacity() << endl;

    v.push_back(3);
    cout << "Capacity -> " << v.capacity() << endl;
    cout << "Size -> " << v.size() << endl;
    // Whenever we push element in vector if is capacity is full then it doubles its capacity
    // Size = number of element in the vector
    v.push_back(4);

    cout << "Element at index 2 is : " << v.at(2) << endl;

    cout << "Front -> " << v.front() << endl;
    cout << "Back -> " << v.back() << endl;

    cout << "Before pop" << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    v.pop_back();
    cout << "After pop" << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Before clear size ->" << v.size() << endl;
    cout << "Before clear capacity ->" << v.capacity() << endl;
    v.clear();
    cout << "After clear size ->" << v.size() << endl;
    cout << "After clear capacity ->" << v.capacity() << endl;

    return 0;
}
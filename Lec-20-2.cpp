// STL Container : Deque or doubly ended queue. Benefits : operate from both ends;
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> v; // first way to initialise

    deque<int> a(5, 1); // second way to initialise : a = {1,1,1,1,1};

    deque<int> last(a); // copy a in last;

    cout << "deque last -> ";
    for (int i : last)
    {
        cout << i << " ";
    }
    cout << endl;

    v.push_back(1);
    v.push_front(2);
    v.push_front(3);
    v.push_back(4);
    cout << "Size -> " << v.size() << endl; // Size = number of element in the vector

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

    // We can use clear or erase for clean deque
    cout << "Before erase size ->" << v.size() << endl;
    v.erase(v.begin(), v.begin() + 2); // first iterator show starting index pointer and second iterator show end index pointer
    cout << "After erase size ->" << v.size() << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
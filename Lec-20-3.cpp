// STL Container : List , random excess not available;
// cout << l[3] << endl; it will give error "no match for 'operator[]' ";
#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l; // first way to initialise

    list<int> a(5, 100); // second way to initialise : a = {1,1,1,1,1};

    list<int> last(a); // copy a in last;

    cout << "List last -> ";
    for (int i : last)
    {
        cout << i << " ";
    }
    cout << endl;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    cout << "Size -> " << l.size() << endl; // Size = number of element in the vector

    cout << "Front -> " << l.front() << endl;
    cout << "Back -> " << l.back() << endl;

    cout << "Before pop" << endl;
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    l.pop_back();
    cout << "After pop" << endl;
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    // We can use clear or erase for clean deque
    cout << "Before erase size ->" << l.size() << endl;
    // advance() function will increment the position of iterator 2 by 3
    list<int>::iterator itr1, itr2;
    itr1 = l.begin();
    itr2 = l.begin();
    advance(itr2, 2);
    l.erase(itr1, itr2); // first iterator show starting index pointer and second iterator show end index pointer
    cout << "After erase size ->" << l.size() << endl;
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
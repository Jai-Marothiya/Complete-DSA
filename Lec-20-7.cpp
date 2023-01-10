// STL container : Set.
// Features : 1. store unique elements, 2. We cannot modify elements (only add or delete elements), 3. Sorted order
#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> s;

    s.insert(6); // Time-complexity of insert, find, erase, count - O(log(n))
    s.insert(6);
    s.insert(7);
    s.insert(6);
    s.insert(3);
    s.insert(7);
    s.insert(2);
    s.insert(3);
    s.insert(5);

    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    set<int>::iterator it = s.begin();
    advance(it, 3);
    s.erase(it);

    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "5 is present or not? : " << s.count(5) << endl;

    set<int>::iterator itr = s.find(3);
    cout << "Print element after 3 : ";
    for (auto i = itr; i != s.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    return 0;
}

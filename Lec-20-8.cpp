// STl container : Map.
// Features : 1. store elements with key, 2. Sorted order
#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, string> m;

    m[1] = "Jai";
    m[13] = "Dad";
    m[7] = "His";
    m[3] = "Loves";

    m.insert({18, "Too Much"});

    cout << "Before erase: " << endl;
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    cout << "Finding 7  : " << m.count(7) << endl;

    m.erase(18);
    cout << "After erase: " << endl;
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    auto it = m.find(3);

    cout << "Print element after key >=3 : " << endl;
    for (auto i = it; i != m.end(); i++)
    {
        cout << (*i).first << " " << (*i).second << endl;
    }

    return 0;
}

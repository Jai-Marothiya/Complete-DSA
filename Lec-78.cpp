// Hashmaps: T.C. of insertion/deletion/search = O(1)
// Ordering of map:increasing order of keys(by default)
// Ordering of unordered_map: no ordering

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Creation:
    unordered_map<string, int> m;

    // insertion
    pair<string, int> p = make_pair("Jai", 9);
    m.insert(p);

    // other way
    pair<string, int> q("Div", 4);
    m.insert(q);

    // 3rd way
    m["Tani"] = 8;

    // Now "Tani" will map with '12'
    m["Tani"] = 12;

    // Search

    cout << m["Tani"] << endl;   // If we call unknown entry with this method then it will create that entry with '0' value;
    cout << m.at("Div") << endl; // If we call unknown entry with this method then it will give error;

    // cout << m.at("Zero") << endl; //If we call unknown entry with this method then it will give error;
    cout << m["Zero"] << endl;    // If we call unknown entry with this method then it will give error;
    cout << m.at("Zero") << endl; // If we call unknown entry with this method then it will give error;

    // Size
    cout << "Size of map is: " << m.size() << endl;

    // To check presence: count return 0 in absence and 1 in presence
    cout << "Is 'Love' word is present: " << m.count("love") << endl;

    // Erase
    m.erase("Div");
    cout << "Size after erase is: " << m.size() << endl;

    // iteration- way-1
    /*for (auto i : m)
    {
        cout << i.first << " -> " << i.second << endl;
    }*/

    // iteration - way -2
    unordered_map<string, int>::iterator it = m.begin();

    while (it != m.end())
    {
        cout << it->first << " -> " << it->second << endl;
        it++;
    }

    return 0;
}
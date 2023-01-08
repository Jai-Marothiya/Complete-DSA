// STl Algoriths.
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;

    v.push_back(3);
    v.push_back(6);
    v.push_back(4);
    v.push_back(2);

    sort(v.begin(), v.end()); // Based on intro sort

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Finding 6 -> " << binary_search(v.begin(), v.end(), 6) << endl;

    cout << "Lower Bound of 3 -> " << lower_bound(v.begin(), v.end(), 3) - v.begin() << endl;
    cout << "Upper Bound of 3 -> " << upper_bound(v.begin(), v.end(), 3) - v.begin() << endl;

    int a = 3, b = 7;

    cout << "Max from 3 and 7 is : " << max(a, b) << endl;
    cout << "Min from 3 and 7 is : " << min(a, b) << endl;

    cout << "After swap : " << endl;
    swap(a, b);
    cout << "a = " << a << " , b = " << b << endl;

    string abcd = "abcd";
    reverse(abcd.begin(), abcd.end());
    cout << "After reverse : " << abcd << endl;

    rotate(v.begin(), v.begin() + 2, v.end());
    cout << "Vector v after rotation : ";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

// Reverse String using recursion
#include <bits/stdc++.h>
using namespace std;

void reverse(string &s, int i) // pass string by reference
{
    cout << "Call recieved for " << s << endl;
    // Base case - when i>=j
    if (i >= s.length() - i - 1)
    {
        return;
    }

    swap(s[i], s[s.length() - i - 1]);
    i++;

    return reverse(s, i);
}

int main()
{
    string s = "syug olleH";

    reverse(s, 0);

    cout << s << endl;

    return 0;
}

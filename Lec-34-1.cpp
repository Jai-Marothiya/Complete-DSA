// Check Palindrome String using recursion
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int i) // pass string by reference
{
    int j = s.length() - i - 1;
    // Base case - when s[i]!=s[j]
    if (s[i] != s[j])
        return false;

    // Base case - when i>=j
    if (i >= j)
        return true;

    return isPalindrome(s, i + 1);
}

int main()
{
    string s = "logoogol";

    cout << isPalindrome(s, 0) << endl;

    return 0;
}

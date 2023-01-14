// Play with pointers in interger and char array
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int arr[5] = {1, 5, 2, 9, 7};
    // char ch[9] = "ILoveYou";

    // // So conclusion is cout is work differently for character and integer array;
    // cout << "->" << arr << endl; // print address of arr[0]
    // cout << "->" << ch << endl;  // print complete charracter array i.e. abcde

    // char *p = &ch[0];
    // cout << "->" << p << endl;  // print string
    // cout << "->" << *p << endl; // only print first element
    // p++;
    // cout << "->" << *p << endl; // only print second element

    char temp = 'c';
    char *ptr = &temp;

    cout << ptr << endl; // It will print c then print any character til ptr not get '\0' or null character

    return 0;
}
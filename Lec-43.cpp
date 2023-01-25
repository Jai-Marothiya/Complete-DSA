// 4 - Pillars of OOPs
// 1. Encapsulation = wrapping up data-members and functions,
// -> Fully Encapsulation = All data-members are private.
// Advantage -> 1.) "Data-hiding" or "information-hiding", 2.) if we want we can make class "Read only".

#include <bits/stdc++.h>
using namespace std;

class student
{
private:
    string name;
    int age;
    int weight;

public:
    string gender;

    getAge()
    {
        return this->age;
    }
};

int main()
{
    student raman;

    cout << raman.getAge();
    return 0;
}

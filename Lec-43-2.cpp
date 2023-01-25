// Single Level Inheritance : The inheritance in which a single derived class is inherited from a single base class

#include <iostream>
using namespace std;

class Animal
{

public:
    int age;
    int weight;

public:
    void speak()
    {
        cout << "Speaking " << endl;
    }
};

class Dog : public Animal
{
};

int main()
{

    Dog d;
    d.speak();
    cout << d.age << endl;

    return 0;
}
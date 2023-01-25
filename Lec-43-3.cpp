// Multi-level Inheritance : The multi-level inheritance includes the involvement of at least two or more than two classes.
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

class GermanShepherd : public Dog
{
};

int main()
{

    GermanShepherd g;
    g.speak();

    return 0;
}
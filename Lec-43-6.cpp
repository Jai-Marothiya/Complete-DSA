// Inheritance Ambiguity : In multiple inheritances, when one class is derived from two or more base classes then there may be a possibility that the base classes have functions with the same name, and the derived class may not have functions with that name as those of its base classes.
#include <iostream>
using namespace std;

class A
{
public:
    void func()
    {
        cout << " I am A" << endl;
    }
};

class B
{
public:
    void func()
    {
        cout << " I am B" << endl;
    }
};

class C : public A, public B
{
};

int main()
{

    C obj;
    // obj.func();

    obj.A::func(); // I am A
    obj.B::func(); // I am B

    return 0;
}
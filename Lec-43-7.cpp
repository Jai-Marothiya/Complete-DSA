#include <iostream>
using namespace std;

class A
{

public:
    // Function overloading : if we want to create multiple function with same name then we have to change atleast argument pass in them.
    void sayHello()
    {
        cout << "Hello Love Babbar" << endl;
    }

    int sayHello(char name)
    {
        cout << "Hello Love Babbar" << endl;
        return 1;
    }

    void sayHello(string name)
    {
        cout << "Hello " << name << endl;
    }
};

class B
{
public:
    int a;
    int b;

public:
    int add()
    {
        return a + b;
    }

    void operator+(B &obj)
    {
        int value1 = this->a; // value of operand 1
        int value2 = obj.a;   // value of operand 2 after '+'
        cout << "output " << value2 - value1 << endl;

        cout << "Hello Babbar" << endl;
    }

    void operator()()
    {
        cout << "main Bracket hu " << this->a << endl;
    }
};

class Animal
{
public:
    void speak()
    {
        cout << "Speaking " << endl;
    }
};

class Dog : public Animal
{

public:
    // Method overriding : we inherit speak from Animal but we override speak function so whenever we call call speak() function this this one is called
    void speak()
    {
        cout << "Barking " << endl;
    }
};

int main()
{

    Dog obj;
    obj.speak();

    B obj1, obj2;

    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;
    obj1(); // Here we overload '()' parenthesis operator

    A obj3;
    obj3.sayHello();

    return 0;
}
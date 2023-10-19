// 4 - Pillars of OOPs
// 2. Inheritance = passing properties of one class(parent/super class) to other(child/sub-class class),
// Advantage -> 1.) if common properties required for multiple class then write in one class and pass in all, so reduce code. 2.) if we want we can make class "Read only".
// Private DM(Data Members) of super class never be inherited

#include <iostream>
using namespace std;

class Human
{

private:
    int height;

public:
    int weight;

private:
    int age;

public:
    int getAge()
    {
        return this->age;
    }

    void setWeight(int w)
    {
        this->weight = w;
    }
};

class Male : private Human
{

public:
    string color;

    void sleep()
    {
        cout << "Male Sleeping" << endl;
    }

    // Give error because height is private member
    /* int getHeight()
    {
        return this->height;
    }  */
};

class Female : public Human
{

public:
    string color;

    void sleep()
    {
        cout << "Female Sleeping" << endl;
    }

    // Give error because height is private member
    /* int getHeight()
    {
        return this->height;
    }  */
};

int main()
{

    Male m1;
    // cout << m1.weight << endl; //not accessible

    Female object1;
    // cout << object1.age << endl; ->Give error because it is private member
    cout << object1.weight << endl;
    // cout << object1.height << endl; ->Give error because it is private member

    cout << object1.color << endl;

    object1.setWeight(84);
    cout << object1.weight << endl;
    object1.sleep();

    return 0;
}

// OOPs concept in C++
// Part-2 - dynamic memory allocation of object
#include <bits/stdc++.h>
using namespace std;

// Creating a class Hero
class Hero
{
    // To access private members of class we use getter and setter(Basically they are functions)
private:
    int health;

public:
    // Data-members or properties
    char level;

    // constructor
    Hero()
    {
        cout << "Default Constructor Called!" << endl;
    }

    // Parametrised Constructor
    // If we pass one parameter then this constructor us called
    Hero(int health)
    {
        // cout << "this = " << this << endl;
        this->health = health;
    }

    // If we pass two parameters then this constructor us called
    Hero(int health, char level)
    {
        this->level = level;
        this->health = health;
    }

    int getHealth()
    {
        return health;
    }

    int getLevel()
    {
        return level;
    }

    void setHealth(int n)
    {
        health = n;
    }

    void setLevel(char ch)
    {
        level = ch;
    }

    void print(string name)
    {
        cout << "Health of " << name << " = " << this->health << " and Level = " << this->level << endl;
    }
};

int main()
{
    // Part-2 - dynamic memory allocation of object
    // static memory allocation
    Hero a;
    a.setHealth(70);
    a.level = 'A';
    cout << "Health of a is : " << a.getHealth() << endl;
    cout << "Level of a is : " << a.level << endl;

    // dynamic memory allocation
    Hero *b = new Hero;
    b->setHealth(80);
    b->level = 'B';
    cout << "Health of b is : " << (*b).getHealth() << endl;
    cout << "Level of b is : " << (*b).level << endl;

    cout << "Health of b is : " << b->getHealth() << endl;
    cout << "Level of b is : " << b->level << endl;

    return 0;
}
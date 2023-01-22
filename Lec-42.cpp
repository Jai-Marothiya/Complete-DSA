// OOPs concept in C++
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
    // Part-1 - getter setter
    // Creating an object ganesh of class Hero
    Hero ganesh;
    cout << "Health of ganesh is : " << ganesh.getHealth() << endl;
    ganesh.setHealth(70);
    ganesh.level = 'A';

    // cout << "size of object ganesh is : " << sizeof(ganesh) << endl;

    cout << "Health of ganesh is : " << ganesh.getHealth() << endl;
    cout << "Level of ganesh is : " << ganesh.level << endl;

    return 0;
}
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

    // Copy Constructor
    // If pass object by value then a copy of object is made in temp which again call copy constructr which create infinite loop. That's why here we pass object by reference
    Hero(Hero &temp)
    {
        cout << "\nCopy Constructor is Called" << endl;
        this->health = temp.health;
        this->level = temp.level;
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
    // Part-3- constructor

    // statically
    Hero ganesh(10);
    ganesh.print("ganesh");

    // dynamically
    Hero *h = new Hero;
    (*h).print("h");

    Hero temp(60, 'D');
    temp.print("temp");

    Hero S(50, 'S');
    S.print("S");
    Hero R(S);
    R.print("R");

    return 0;
}
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
    char *name;

    // constructor
    Hero()
    {
        cout << "Default Constructor Called!" << endl;
        name = new char[100];
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
    Hero(Hero &temp)
    {
        // Deep Copy, here we create a new copy so if we change original one then it will not change
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        cout << "Copy constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void setHealth(int n)
    {
        health = n;
    }

    void setLevel(char ch)
    {
        level = ch;
    }

    void setName(char ch[])
    {
        strcpy(this->name, ch);
    }

    void print(string name = "Jai")
    {
        cout << "[ Name: " << this->name << ", Health: " << this->health << ", Level: " << this->level << " ]" << endl;
    }
};

int main()
{
    // Part-4 - Shallow and Deep copy
    // In shallow copy when we not made custom copy constructor then name of both hero1 and hero2 point to same memory block that's why if we change anyone, other will automatically change.
    // While in Deep copy we create a new copy of name array so name(data member) of both hero1 and hero2 point to different memory block, that's why if we change anyone, other will Not Change.
    Hero hero1;

    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Babbar";
    hero1.setName(name);

    // hero1.print("hero1");

    // use default copy constructor

    Hero hero2(hero1);
    // hero2.print("hero2");
    //    Hero hero2 = hero1;

    hero1.name[0] = 'G';
    hero1.print("hero1");

    hero2.print("hero2");

    hero1 = hero2;

    hero1.print();

    hero2.print();

    return 0;
}
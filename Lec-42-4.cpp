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
        // cout << "Default Constructor Called!" << endl;
        name = new char[100];
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

    // destructor
    ~Hero()
    {
        cout << "Destructor is called" << endl;
    }
};

int main()
{
    // Part-5 - destructor

    // Static
    // Destructor call automatically
    Hero hero1;

    // Dynamic
    Hero *hero2 = new Hero();
    // We have to call destructor manually for dynamically memory allocation
    delete (hero2);

    return 0;
}
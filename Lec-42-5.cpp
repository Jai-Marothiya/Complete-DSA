// OOPs concept in C++
// Part-6 - static keyword
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
    static int timeToComplete;

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

    // static function only access static data members. Here random only access timeTocomplete. Not level, health.
    static int random()
    {
        return timeToComplete;
    }

    // destructor
    ~Hero()
    {
        cout << "Destructor is called" << endl;
    }
};

int Hero::timeToComplete = 5;

int main()
{
    // Part-6 - static keyword

    // cout << Hero::timeToComplete << endl; // timeToComplete is print without create an object
    cout << Hero::random() << endl;

    // Hero a;

    // cout << a.timeToComplete << endl;

    // Hero b;
    // b.timeToComplete = 10 ;
    // cout  << a.timeToComplete << endl;
    // cout << b.timeToComplete << endl;

    return 0;
}
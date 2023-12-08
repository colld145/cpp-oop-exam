#include <iostream>
#include "Person.h"

using namespace std;

void Person::Fill()
{
    cout << "Enter a first name: ";
    cin >> first_name;
    cout << "Enter a second name: ";
    cin >> last_name;
    cout << "Enter an age: ";
    cin >> age;
}

void Person::Show() const
{
    cout << "Full name: " << first_name << " " << last_name << endl;
    cout << "Age: " << age << endl;
}

ostream& operator << (ostream& out, const Person& person)
{
    out << person.first_name << endl;
    out << person.last_name << endl;
    out << person.age;
    return out;
}

istream& operator >> (istream& in, Person& person)
{
    in >> person.first_name >> person.last_name >> person.age;
    return in;
}

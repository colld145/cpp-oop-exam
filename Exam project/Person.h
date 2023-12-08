#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    string first_name;
    string last_name;
    unsigned int age;
public:
    Person(): first_name("No First Name"), last_name("No Last Name") {}

    Person(string fn, string ln, int age): first_name(fn), last_name(ln)
    {
        age > 0 ? this->age = age : this->age = 0;
    }

    bool operator == (const Person& other)
    {
        return (this->first_name == other.first_name && this->last_name == other.last_name && this->age == other.age);
    }

    void Fill();

    void Show() const;

    friend ostream& operator << (ostream& out, const Person& person);
    friend istream& operator >> (istream& in, Person& person);
};


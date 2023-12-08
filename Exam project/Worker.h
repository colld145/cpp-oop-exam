#include <iostream>
#include "Person.h"

using namespace std;

class Worker : public Person
{
private:
    string pos;
    unsigned int salary;
public:
    Worker(): pos("No position"), salary(0), Person() {}

    Worker(string fn, string ln, int age, string p, int salary): pos(p), salary(salary), Person(fn, ln, age) {}

    void Fill();

    void Show() const;

    friend ostream& operator << (ostream& out, const Worker& worker);
    friend istream& operator >> (istream& in, Worker& worker);
};


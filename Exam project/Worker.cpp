#include "Worker.h"
#include <iostream>
using namespace std;

void Worker::Fill()
{
    Person::Fill();
    cin.ignore();
    cout << "Enter a position: ";
    getline(cin, pos);
    cout << "Enter a salary: ";
    cin >> salary;
}

void Worker::Show() const
{
    Person::Show();
    cout << "Position: " << pos << endl;
    cout << "Salary: " << salary << " $" << endl;
}

ostream& operator << (ostream& out, const Worker& worker)
{
    out << worker.first_name << endl;
    out << worker.last_name << endl;
    out << worker.age << endl;
    out << worker.pos << endl;
    out << worker.salary;
    return out;
}

istream& operator >> (istream& in, Worker& worker)
{
    in >> worker.first_name >> worker.last_name >> worker.age;
    in.ignore();
    getline(in, worker.pos);
    in >> worker.salary;
    return in;
}
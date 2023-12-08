#include <iostream>
#include "Service.h"

using namespace std;

void Service::Fill()
{
    cin.ignore();
    cout << "Enter a service name: ";
    getline(cin, name);
    cout << "Enter a service price: ";
    cin >> price;
}

void Service::Show() const
{
    cout << "Name: " << name << endl;
    cout << "Price: " << price << " $" << endl;
}

ostream& operator << (ostream& out, const Service& service)
{
    out << service.name << endl;
    out << service.price;
    return out;
}

istream& operator >> (istream& in, Service& service)
{
    getline(in, service.name);
    in >> service.price;
    return in;
}


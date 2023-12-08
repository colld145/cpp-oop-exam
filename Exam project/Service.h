#include <iostream>
using namespace std;


class Service
{
protected:
    string name;
    unsigned int price;
public:
    Service():name("No name"), price(0) {}

    Service(string n, int p): name(n), price(p) {}

    void Show() const;

    void Fill();

    friend istream& operator >> (istream& in, Service& service);
    friend ostream& operator << (ostream& out, const Service& service);
};
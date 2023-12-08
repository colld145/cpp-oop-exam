#include <iostream>
#include "Service.h"
#include "Worker.h"
using namespace std;

class Order
{
private:
    Person customer;
    Worker master;
    Service service;
public:
    Order():customer(), master(), service() {}
    Order(Person c, Worker m, Service s):customer(c), master(m), service(s) {}

    void Show() const;

    friend ostream& operator << (ostream& out, const Order& order);
    friend istream& operator >> (istream& in, Order& order);
};


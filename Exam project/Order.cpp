#include "Order.h"

void Order::Show() const
{
    cout << "----- Order -----" << endl;
    cout << "Customer: " << endl;
    customer.Show();
    cout << "Master: " << endl;
    master.Show();
    cout << "Service: " << endl;
    service.Show();
}

ostream& operator << (ostream& out, const Order& order)
{
    out << order.customer << endl;
    out << order.master << endl;
    out << order.service;
    return out;
}

istream& operator >> (istream& in, Order& order)
{
    in >> order.customer >> order.master;
    in.ignore();
    in >> order.service;
    return in;
}

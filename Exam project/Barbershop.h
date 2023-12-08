#include <iostream>
#include <vector>
#include "Order.h"
#include <fstream>

using namespace std;

class Barbershop
{
private:
    string name;
    vector <Worker> workers;
    vector <Service> services;
    vector <Order> orders;
    vector <Person> customers;
    int workers_size;
    int services_size;
    int orders_size;
    int customers_size;
public:
    Barbershop(): name("No name"),workers_size(0), services_size(0), orders_size(0), customers_size(0) {}

    Barbershop(string n): name(n), workers_size(0), services_size(0), orders_size(0), customers_size(0) {}

    void AddWorker();
    void ShowWorkers() const;

    void AddService();
    void ShowServices() const;

    void AddOrder();
    void ShowOrders() const;
    void MakeOrder();

    void AddCustomer();
    void AddCustomer(Person new_customer);
    void ShowCustomers();

    string GetName() const
    {
        return name;
    }


    bool WorkersIsEmpty();
    bool ServicesIsEmpty();
    bool OrdersIsEmpty();
    bool CustomersIsEmpty();

    void SaveWorkers();
    void LoadWorkers();

    void SaveServices();
    void LoadServices();

    void SaveOrders();
    void LoadOrders();

    void SaveCustomers();
    void LoadCustomers();

    void SaveBarbershop();
    void LoadBarbershop();
};



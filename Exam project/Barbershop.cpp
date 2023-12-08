#include "Barbershop.h"

void Barbershop::AddWorker()
{
    Worker new_worker;
    new_worker.Fill();
    workers.push_back(new_worker);
    workers_size++;
}

void Barbershop::AddService()
{
    Service new_service;
    new_service.Fill();
    services.push_back(new_service);
    services_size++;
}

void Barbershop::ShowWorkers() const
{
    int i = 1;
    for(auto worker : workers)
    {
        cout << i << ". ";
        worker.Show();
        cout << "-------------" << endl;
        i++;
    }
}

void Barbershop::ShowServices() const
{
    int i = 1;
    for(auto service : services)
    {
        cout << i << ". ";
        service.Show();
        cout << "-------------" << endl;
        i++;
    }
}

void Barbershop::AddOrder()
{
    int choice = 0;
    cout << "Add a new customer: " << endl;
    Person new_customer;
    new_customer.Fill();

    int counter = 0;
    for(auto customer : customers)
    {
        if(new_customer == customer)
            counter++;
    }
    if(counter == 0)
        AddCustomer(new_customer);

    cout << endl;
    ShowWorkers();
    cout << "Enter a number of master: "; cin >> choice;
    Worker new_worker = workers[choice - 1];
    ShowServices();
    cout << "Enter a number of service: "; cin >> choice;
    Service new_service = services[choice - 1];
    Order new_order(new_customer, new_worker, new_service);
    orders.push_back(new_order);
    orders_size++;
}



void Barbershop::ShowOrders() const
{
    int i = 1;
    for(auto order : orders)
    {
        cout << i << ". ";
        order.Show();
        cout << "-------------" << endl;
        i++;
    }
}

void Barbershop::MakeOrder()
{
    ShowOrders();
    int choice = 0;
    cout << "Enter an order number to finish: ";
    cin >> choice;
    orders.erase(orders.begin() + (choice - 1));
    cout << "Order has finished!" << endl;
}

void Barbershop::AddCustomer()
{
    Person new_customer;
    new_customer.Fill();
    customers.push_back(new_customer);
    customers_size++;
}

void Barbershop::AddCustomer(Person new_customer)
{
    customers.push_back(new_customer);
    customers_size++;
}

void Barbershop::ShowCustomers()
{
    int i = 1;
    for(auto customer : customers)
    {
        cout << i << ". ";
        customer.Show();
        cout << "-------------" << endl;
        i++;
    }
}

bool Barbershop::WorkersIsEmpty()
{
    return workers_size == 0;
}

bool Barbershop::ServicesIsEmpty()
{
    return services_size == 0;
}

bool Barbershop::OrdersIsEmpty()
{
    return orders_size == 0;
}

bool Barbershop::CustomersIsEmpty()
{
    return customers_size == 0;
}

void Barbershop::SaveWorkers()
{
    ofstream out("workers.txt", ios_base::out);
    out << workers_size << endl;
    for (int i = 0; i < workers_size; i++)
    {
        out << workers[i] << endl;
    }
    out.close();
}

void Barbershop::LoadWorkers()
{
    ifstream in("workers.txt", ios_base::in);

    string workers_size;
    getline(in, workers_size);
    this->workers_size = stoi(workers_size);

    Worker new_worker;
    for (int i = 0; i < this->workers_size; ++i) {
        in >> new_worker;
        workers.push_back(new_worker);
    }
    in.close();
}

void Barbershop::SaveServices()
{
    ofstream out("services.txt", ios_base::out);
    out << services_size << endl;
    for (int i = 0; i < services_size; i++)
    {
        out << services[i] << endl;
    }
    out.close();
}

void Barbershop::LoadServices()
{
    ifstream in("services.txt", ios_base::in);

    string services_size;
    getline(in, services_size);
    this->services_size = stoi(services_size);

    Service new_service;
    for (int i = 0; i < this->services_size; ++i) {
        in >> new_service;
        in.ignore();
        services.push_back(new_service);
    }
    in.close();
}

void Barbershop::SaveOrders()
{
    ofstream out("orders.txt", ios_base::out);
    out << orders_size << endl;
    for (int i = 0; i < orders_size; i++)
    {
        out << orders[i] << endl;
    }
    out.close();
}

void Barbershop::LoadOrders()
{
    ifstream in("orders.txt", ios_base::in);

    string orders_size;
    getline(in, orders_size);
    this->orders_size = stoi(orders_size);

    Order new_order;
    for (int i = 0; i < this->orders_size; ++i) {
        in >> new_order;
        orders.push_back(new_order);
    }
    in.close();
}

void Barbershop::SaveCustomers()
{
    ofstream out("customers.txt", ios_base::out);
    out << customers_size << endl;
    for (int i = 0; i < customers_size; i++)
    {
        out << customers[i] << endl;
    }
    out.close();
}

void Barbershop::LoadCustomers()
{
    ifstream in("customers.txt", ios_base::in);

    string customers_size;
    getline(in, customers_size);
    this->customers_size = stoi(customers_size);

    Person new_customer;
    for (int i = 0; i < this->customers_size; ++i) {
        in >> new_customer;
        customers.push_back(new_customer);
    }
    in.close();
}

void Barbershop::SaveBarbershop()
{
    SaveOrders();
    SaveServices();
    SaveWorkers();
    SaveCustomers();
}

void Barbershop::LoadBarbershop()
{
    LoadOrders();
    LoadServices();
    LoadWorkers();
    LoadCustomers();
}
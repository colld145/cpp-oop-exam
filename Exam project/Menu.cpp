#include "Menu.h"
#include "Barbershop.h"
#include <iostream>

using namespace std;

void Menu::Start()
{
    string str_name = "Kostia's Barbershop";
    Barbershop barbershop(str_name);
    barbershop.LoadBarbershop();
    barbershop.ShowCustomers();
    bool exit = false;
    int choice = 0;
    while(!exit)
    {
        cout << "---------- " << barbershop.GetName() << " ----------" << endl;
        cout << "1. Add a new order\n2. Make an exist order\n3. Show all orders\n4. Add a new service\n5. Add a new master\n\n0. Exit\n\nEnter a choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                if(barbershop.WorkersIsEmpty())
                {
                    cout << "Position Masters is empty." << endl;
                    break;
                }
                if(barbershop.ServicesIsEmpty())
                {
                    cout << "Position Services is empty." << endl;
                    break;
                }
//                cout << "1. With new customer\n2. With exist customer\n\nEnter a choice: ";
//                cin >> choice;
//                if(choice == 1)
//                {
//                    barbershop.AddOrder();
//                }
//                else if(choice == 2)
//                {
//                    barbershop.AddOrder();
//                }
                barbershop.AddOrder();
                barbershop.SaveOrders();
                break;
            case 2:
                if(barbershop.OrdersIsEmpty())
                {
                    cout << "Position Orders is empty." << endl;
                    break;
                }
                barbershop.MakeOrder();
                barbershop.SaveOrders();
                break;
            case 3:
                if(barbershop.OrdersIsEmpty())
                {
                    cout << "Position Orders is empty." << endl;
                    break;
                }
                barbershop.ShowOrders();
                break;
            case 4:
                barbershop.AddService();
                barbershop.SaveServices();
                break;
            case 5:
                barbershop.AddWorker();
                barbershop.SaveWorkers();
                break;
            case 0:
                cout << "Bye!" << endl;
                barbershop.SaveBarbershop();
                exit = true;
                break;
            default:
                cout << "Incorrect choice. Try again." << endl;
                break;
        }
    }

}

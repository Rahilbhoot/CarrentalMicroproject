#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class Car
{
    // details of cars
public:
    string mark[10] = {"Hyundai", "BMW", "Mercedes", "Audi", "Tesla", "Skoda", "Volkswagun", "Toyota", "Ford"};
    string model[10] = {"2016MD", "2018AS", "2018DS", "2017LA", "2018OW", "2005Ps", "2008PW", "2010QW", "2016SA"};
    string color[10] = {"Red", "black", "yellow", "Blue", "Red", "Brown", "Silver", "Black", "grey"};
    string max_speed[10] = {"100 Km/h ", "150 Km/h", "150 Km/h", "170 Km/h", "130 Km/h", "140 Km/h", "130 Km/h", "120 Km/h", "150 Km/h"};
    int price[10] = {10000, 20000, 30000, 50000, 20000, 25000, 40000, 60000, 90000};
    int date[10] = {2010, 2012, 2013, 2017, 2018, 2005, 2008, 2010, 2014};
};

class Lessee
{
    // Lesse:- a person who has a legal agreement (a lease) allowing him/her use of a building, an area of land, etc.
public:
    // information about buyer.
    string Name[10];
    string Natio_ID[10];
    int payment_acc[10];
};

void Minu(Car &car)
{
    // this function gives list of the cars available.
    int num = 1;
    for (int i = 0; i < 9; ++i)
    {
        cout << "\t\t\t";
        cout << "Enter " << num << "\t- To Select  " << car.mark[i] << endl;
        num++;
    }
}

void Details(Car &car, int theChoice)
{
    // details of cars user have choosen.
    system("CLS");
    cout << "\n\n\n\t\t\t-----------------------------\n";
    cout << "\t\t\tYou Have Selected - " << car.mark[theChoice - 1] << endl;
    cout << "\t\t\t-----------------------------\n\n\n";
    cout << "\t\t\tModel : " << car.model[theChoice - 1] << endl;
    cout << "\t\t\tColor : " << car.color[theChoice - 1] << endl;
    cout << "\t\t\tMaximum Speed : " << car.max_speed[theChoice - 1] << endl;
    cout << "\t\t\tPrice : " << car.price[theChoice - 1] << "$" << endl;
}

void check(Car &car, Lessee &lessee, int j)
{
    // this function checks if the payment of user is enough or not.
    if (lessee.payment_acc[j] >= car.price[j])
        cout << "\n\n\n\t\t\tProcess has been done successfully!! " << endl;
    else
        cout << "\n\n\n\t\t\tNot Available " << endl;
}

void user_input(Car &car, Lessee &lessee, int theChoice)
{
    // this will take personal information and payment amount by user.
    system("CLS");
    int j = theChoice - 1;
    cout << "\t\t\t----------------------------------------\n";
    cout << "\t\t\tPlease Provide Your Personal Details  : \n";
    cout << "\t\t\t----------------------------------------\n\n";
    cout << "\n\tNOTE: PROVIDE FIRST NAME, \n\tPAYMENT WON'T PROCEED IF THE GIVEN AMOUNT IS LESS THAN THE RATE OF CAR\n\n\n\n";
    cout << "\t\t\tEnter Your First Name : ";
    cin >> lessee.Name[j];
    cout << "\t\t\tEnter Your National ID : ";
    cin >> lessee.Natio_ID[j];
    cout << "\t\t\tPayment Amount: ";
    cin >> lessee.payment_acc[j];

    check(car, lessee, j);
}

int login()
{
    // it checks the password while login.
    string pass = "";
    char ch;
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t  Simple Car Rental System Login";
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
    ch = _getch();
    while (ch != 13)
    {                       // character 13 is enter
        pass.push_back(ch); // push_back:- This function is used to add new character ch at the end of the   string, increasing its length by one.
        cout << '*';
        ch = _getch();
    }
    if (pass == "login")
    {
        cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
        system("PAUSE"); // it is used to continue the paused program
        system("CLS");   // it is used to clear screen
    }
    else
    {
        cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
        system("PAUSE");
        system("CLS");
        login();
    }
}

int main()
{
    login();

    Car car;
    Lessee lessee;

    string decide = "yes";
    cout << "\t\t\t----------------------------------------------\n";
    cout << "\t\t\t\tSIMPLE CAR RENTAL SYSTEM \n";
    cout << "\t\t\tWelcome to Our Company, Choose from the menu : " << endl;
    cout << "\t\t\t----------------------------------------------\n";
    while (decide != "exit")
    {
        Minu(car);
        cout << "\n\n\n\t\t\tYour Choice: ";
        int theChoice;
        cin >> theChoice;
        Details(car, theChoice);
        cout << "\n\n\n\t\t\tAre You Sure, you want to rent this Car? (yes / no / exit): ";
        cin >> decide;
        if (decide == "yes")
        {
            user_input(car, lessee, theChoice);
            cout << "\n\n\t\t\tDo you want to continue? (yes/no) ";
            cin >> decide;
            if (decide == "no")
                break;
            system("CLS");
        }
        else
        {
            if (decide == "no")
            {
                system("CLS");
                continue;
            }
            else if (decide == "exit")
            {
                system("CLS");
                cout << "\n\n\n\t\t\tThis Project Is made by Rahil A. Bhoot(226250307009) and Manan B. Katarmal(226250307059)";
                break;
            }
        }
    }
    return 0;
}

//"Made some improvements in formatting"-   manoskie 2025
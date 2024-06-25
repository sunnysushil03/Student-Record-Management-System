// Student-Record-Management-System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NOMINMAX            // For clear() and ignore() (window specific). Always use before #include <windows.h>
#include <windows.h>

#include "adminFunction.h"
#include "studentFunction.h"
#include "constants.h"

using namespace std;

void mainMenu();
void loadingBar();

// Loading animation.
void loadingBar()
{
    system("cls");
    COLOR();

    char a = 177, b = 219;
    cout<<"\n\n\n\n\n\t\t\t\t\tStudent's Data Management System";
    //cout << "\n\t\t\t\t\tProject By Sushil Sah";
    cout << "\n\n\n\t\t\t\t\tLoading...\n";
    cout << std::endl;
    cout << "\t\t\t\t\t";

    for (int i = 0; i < 32; i++)

        cout << a;

    cout << "\r";
    cout << "\t\t\t\t\t";
    for (int i = 0; i < 32; i++)
    {
        cout << b;
        Sleep(100);
    }

}

// Main Menu
void mainMenu()
{
    system("cls");

    cout << "\n\n\n\n\n\t\t\t\t\t Login As...";
    cout << "\n\n\n\t\t\t\t\t 1. Admin ";
    cout << "\n\n\t\t\t\t\t 2. Student";
    cout << "\n\n\t\t\t\t\t 3. Exit\n\n\n";

    int choice;
    int count = 0;

    // check if valid input is provided by user or not?
    // If user attemp invalid inputs for 3 times, Terminate the program.
    for (int i = 0; i < 3; i++)
    {
        cout << "\n\t\t\t\t\t Enter your choice : ";
        cin >> choice;
        if (choice >= 1 && choice <= 3) 
        { 
            break;
        }
        else
        {
            // Clear the previous input.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (i == 2)
            {
                cout << "\t\t\t\t\t You have reached maximum limit. Terminating the program.";
                for (int i = 0; i < 6; i++)
                {

                    Sleep(1000);
                    cout << ".";
                }
                exit(0);
            }
            cout << "\t\t\t\t\t Invalid Input. " << 3 - i - 1 << " times left.\n";
        }
    }

    switch (choice)
    {
    case 1:
        system("cls");
        adminVerification();
        break;

    case 2:
        system("cls");
        cout << "Welcome as Student";
        studentFunction();
        mainMenu();
        break;

    case 3:
        system("cls");
        cout << "\t\t\n\n\n\n\n\n\n\n\t\t\t\t\t\tQuitting The Program";

        for (int i = 0; i < 5; i++)
        {

            Sleep(800);
            cout << ".";
        }

        exit(0);
        break;

    default:
        cout << "\n\t\t\t\t\t Invalid Input,  ";
        
    }

    // Pause the console (Windows specific)
    system("pause");
}


int main()
{

    // loading animation.
    loadingBar(); 

    // Set font color and background color.
    COLOR();

    // Main Menu
    mainMenu();
    return 0;
}















// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

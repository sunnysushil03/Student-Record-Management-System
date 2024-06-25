

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>

#include "studentFunction.h"
#include "constants.h"

using namespace std;


// Student operations.
void studentFunction()
{
    system("cls");  // Clear the screen (Windows specific)

    fstream file("data.csv");
    if (!file.is_open())
    {
        cout << "Failed to open the file!" << endl;
        return;
    }

    cout << "\n\t\t\t\t\t|..........Students` Record..........|\n\n";
    cout << "\n-----------------------------------------------------------------------------------------------------------------------\n\n";
    cout << "Roll \t Name \t\t\t College \t branch \t Attendance \t Physics \t Chemistry \t Maths" << std::endl;
    cout << "\n-----------------------------------------------------------------------------------------------------------------------\n\n";

    string rollNumber, name, college, branch, attendance, physics, chemistry, maths;
    char comma;  // To handle the commas between fields

    while (getline(file, rollNumber, ',') &&
        getline(file, name, ',') &&
        getline(file, college, ',') &&
        getline(file, branch, ',') &&
        getline(file, attendance, ',') &&
        getline(file, physics, ',') &&
        getline(file, chemistry, ',') &&
        getline(file, maths, '\n'))
    {
        // Output each field with appropriate formatting
        if (!rollNumber.empty())
        {
            cout << rollNumber << " \t" 
                << name << "\t\t\t" 
                << college << "\t\t" 
                << branch  << "\t\t" 
                << attendance << "\t\t" 
                << physics << "\t\t" 
                << chemistry << "\t\t" 
                << maths << endl << endl;
        }
    }

    cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
    file.close();

    // Pause the console (Windows specific)
    system("pause");  
}



#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdio.h>
#define NOMINMAX                  // For clear() and ignore() (window specific). Always use before #include <windows.h>
#include <windows.h>

#include "adminFunction.h"
#include "constants.h"

using namespace std;
void mainMenu();

bool isDeleted = false;

// Admin operations.
void adminFunction()
{
    system("cls");
    cout << "\n\n\t\t\t\t\t ..........Welcome Admin..........\n";
    cout << "\n\t\t\t-----------------------------------------------------------------------" << endl;
   
    cout << "\n\n\t\t\t\t\t 1. Add Student`s Detail";
    cout << "\n\n\t\t\t\t\t 2. Delete Record";
    cout << "\n\n\t\t\t\t\t 3. Update Record";
    cout << "\n\n\t\t\t\t\t 4. View Table ";
    cout << "\n\n\t\t\t\t\t 5. Main Menu ";
    cout << "\n\n\t\t\t\t\t 6. Exit";

    int option;
    cout << "\n\n\t\t\t\t\t Enter choice : ";
    do
    {
        cin >> option;

        switch (option)
        {
     
        case 1:
            addData();
            break;
     
        case 2:
            deleteData();
            break;
     
        case 3:
            cout << "\t\t\t\t\t This option is not available currently.\n"; //updateData();
            cout << "\n\t\t\t\t\t Returning to Admin Menu";
            for (int i = 0; i < 6; i++)
            {
     
                Sleep(1000);
                cout << ".";
            }
            
            adminFunction();
            break;
     
        case 4:
            viewData();
            break;
     
        case 5:
            mainMenu();
            break;
     
        case 6:
            system("cls");
            cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\t Quitting The Program";
     
            for (int i = 0; i < 4; i++)
            {
     
                Sleep(1000);
                cout << ".";
            }
            exit(0);
            break;
     
        default:
            system("cls");
            // Clear the previous input.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\n\n\t\t\t\t\t ..........Welcome Admin..........\n";    
            cout << "\n\t\t\t-----------------------------------------------------------------------" << endl;
        
            cout << "\n\n\t\t\t\t\t 1. Add Student`s Detail";
            cout << "\n\n\t\t\t\t\t 2. Delete Record";
            cout << "\n\n\t\t\t\t\t 3. Update Record";
            cout << "\n\n\t\t\t\t\t 4. View Table ";
            cout << "\n\n\t\t\t\t\t 5. Main Menu ";
            cout << "\n\n\t\t\t\t\t 6. Exit";
     
            cout << "\n\n\t\t\t\t\t Invalid Input!";
            cout << "\n\n\t\t\t\t\t Enter Choice : ";
        }
     

    } while (option != '6');
}

// Delete Student`s Details.
void deleteData()
{
    system("cls");

    fstream fin, fout;

    // Open the existing file
    fin.open("data.csv", ios::in);

    if (!fin.is_open()) {
        cout << "Error opening input file!\n";
        return;
    }
    else
    {
        cout << "\n\n\t\t\t\t\t|..........Delete Student`s Details..........|\n\n" << endl << endl;
    }

    // Create a new file to store the non-deleted data
    fout.open("datanew.csv", ios::out);

    if (!fout.is_open()) {
        cout << "Error opening output file!\n";
        fin.close();
        return;
    }

    int rollnum, roll1, count = 0;
    string line;
    vector<string> row;

    // Get the roll number to decide which data to be deleted.
    cout << "Enter the roll number of the record to be deleted: ";
    cin >> rollnum;

    // Check if this record exists
    while (getline(fin, line))
    {
        row.clear();

        stringstream s(line);

        while (getline(s, line, ',')) {
            row.push_back(line);
        }

        if (row.size() > 0) {
            roll1 = stoi(row[0]);

            if (roll1 != rollnum) {
                for (size_t i = 0; i < row.size() - 1; ++i) {
                    fout << row[i] << ",";
                }
                fout << row[row.size() - 1] << "\n";
            }
            else {
                count = 1;
            }
        }
    }

    if (count == 1) {
        cout << "\nRecord deleted successfully.\n\n";
        isDeleted = true;
    }
    else {
        cout << "\nRecord not found\n\n";
    }

    fin.close();
    fout.close();

    // Remove the old file and rename the new file.
    if (remove("data.csv") != 0) {
        perror("Error deleting file");
    }
    else if (rename("datanew.csv", "data.csv") != 0) {
        perror("Error renaming file");
    }
    cout << "Transiting to Admin Menu";
    for (int i = 0; i < 4; i++)
    {

        Sleep(1000);
        cout << ".";
    }
    // Handle further admin operations.
    adminFunction(); 
}

// Update Student`s Details.
/*
void updateData()
{
    system("cls");
    cout << "in update function\n";
        // File pointer
        fstream fin, fout;

        // Open an existing record
        fin.open("data.csv", ios::in);

        // Create a new file to store updated data
        fout.open("datanew.csv", ios::out);

        int rollnum, roll1, marks, count = 0, i;
        char sub;
        int index;
        string new_marks;
        string line, word;
        vector<string> row;

        // Get the roll number from the user
        cout << "Enter the roll number "
             << "of the record to be updated: ";
        cin >> rollnum;

        // Get the data to be updated
        cout << "Enter the first letter fo the Fields (Eg. b for branch & G for college)"
             << "to be updated(N/G/B/A/P/C/M): ";
        cin >> sub;

        // Determine the index of the subject
        // where Maths has index 7,
        // Physics has index 6, and so on

        if (sub == 'n' || 'N')
            index = 1;

        else if (sub == 'g' || sub == 'G')
            index = 2;

        else if (sub == 'b' || sub == 'B')
            index = 3;

        else if (sub == 'a' || sub == 'A')
            index = 4;

        else if (sub == 'p' || sub == 'P')
            index = 5;

        else if (sub == 'c' || sub == 'C')
            index = 6;

        else if (sub == 'm' || sub == 'M')
            index = 7;

        else
        {
            cout << "Wrong choice.Enter again\n";
            updateData();
        }

        // Get the new marks
        cout << "Enter new Detail: ";
        cin >> new_marks;

        // Traverse the file
        while (!fin.eof())
        {

            row.clear();

            getline(fin, line);
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            roll1 = stoi(row[0]);
            int row_size = row.size();

            if (roll1 == rollnum)
            {
                count = 1;
                stringstream convert;

                // sending a number as a stream into output string
                convert << new_marks;

                // the str() converts number into string
                row[index] = convert.str();

                if (!fin.eof())
                {
                    for (i = 0; i < row_size - 1; i++)
                    {

                        // write the updated data
                        // into a new file 'reportcardnew.csv'
                        // using fout
                        fout << row[i] << ", ";
                    }

                    fout << row[row_size - 1] << "\n";
                }
            }
            else
            {
                if (!fin.eof())
                {
                    for (i = 0; i < row_size - 1; i++)
                    {

                        // writing other existing records
                        // into the new file using fout.
                        fout << row[i] << ", ";
                    }

                    // the last column data ends with a '\n'
                    fout << row[row_size - 1] << "\n";
                }
            }
            if (fin.eof())
                break;
        }
        if (count == 0)
            cout << "Record not found\n";

        fin.close();
        fout.close();

        // removing the existing file
        remove("data.csv");

        // renaming the updated file with the existing file name
        rename("datadnew.csv", "data.csv");

}

*/

// Check if file is Empty or not?
bool isCSVFileBlank(const string& filename) {
    std::ifstream fin(filename);

    if (!fin) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return true; // Consider file as blank if cannot be opened
    }

    string line;
    getline(fin, line);  // Attempt to read the first line

    // Check if file is empty or blank
    if (fin.eof() && line.empty()) {
        fin.close();
        return true;  // File is blank
    }

    fin.close();
    return false;  // File is not blank
}

// Add Student`s details.
void addData()
{
    system("cls");
    fstream file("data.csv", ios::out | ios::app);
    if (!file)
    {
        cout << "\n Failed to open data.csv / data.csv file not found!";
    }

    else
        cout << "\n\n\t\t\t\t\t|..........Enter Below Details..........|" << endl << endl;

    string rollNumber, name, college, branch, attendance, physics, chemistry, maths;
    string moreData;

    cout << "\nEnter Student's roll Number : ";
    cin >> rollNumber;

    // check if file is blank?
    string filename = "data.csv";
    if (isCSVFileBlank(filename)) {
        file << rollNumber << ", ";
    }
    else if (isDeleted == true)
    {
        file << rollNumber << ", ";
        isDeleted = false;
    }
    else {
        file << "\n" << rollNumber << ", ";
    }

    cout << "\nEnter Studnet's Name : ";
    cin >> name;
    file << name << ", ";

    cout << "\nEnter College : ";
    cin >> college;
    file << college << ", ";

    cout << "\nEnter Branch : ";
    cin >> branch;
    file << branch << ", ";

    cout << "\nEnter Attendance : ";
    cin >> attendance;
    file << attendance << ", ";

    cout << "\nEnter Physic's Marks : ";
    cin >> physics;
    file << physics << ", ";

    cout << "\nEnter Chemistry Marks : ";
    cin >> chemistry;
    file << chemistry << ", ";

    cout << "\nEnter Maths Marks : ";
    cin >> maths;
    file << maths;

    file.close();

    cout << "\nAdd more Record? (Y / N) : ";

    cin >> moreData;
    if (moreData == "y" || moreData == "Y" || moreData == "yes" || moreData == "Yes")
    {
        addData();
    }
    else if (moreData == "n" || moreData == "N" || moreData == "no" || moreData == "No")

        // Transit to perform admin operations.
        adminFunction();

    else
        cout << "\nEnter a valid option";

    // Transit to perform admin operations.
    adminFunction();
}

// View student`s details.
void viewData()
{
    system("cls");

    ifstream file("data.csv");

    if (!file.is_open())
    {
        cout << "Failed to open the file." << endl;
        return;
    }

    cout << "\n\t\t\t\t\t|..........Students` Record..........|\n\n";
    cout << "\n-----------------------------------------------------------------------------------------------------------------------\n\n";
    cout << "Roll \t Name \t\t\t College \t branch \t Attendance \t Physics \t Chemistry \t Maths" << endl;
    cout << "\n-----------------------------------------------------------------------------------------------------------------------\n\n";

    string rollNumber, name, college, branch, attendance, physics, chemistry, maths;

    // Read data until end of file
    while (getline(file, rollNumber, ',') && getline(file, name, ',') && getline(file, college, ',') &&
        getline(file, branch, ',') && getline(file, attendance, ',') && getline(file, physics, ',') &&
        getline(file, chemistry, ',') && getline(file, maths, '\n'))
    {
        // Check if rollNumber is not empty to avoid displaying an extra empty line at the end.
        if (!rollNumber.empty())
        {
            cout << rollNumber << " \t" << name << "\t\t\t" << college << "\t\t" << branch << "\t\t" << attendance << "\t\t" << physics << "\t\t" << chemistry << "\t\t" << maths << endl;
        }
    }

    cout << "\n-----------------------------------------------------------------------------------------------------------------------" << endl;

    file.close();

    cout << "\n\n 1. Add Student`s Details\n";
    cout << " 2. Delete Record\n";
    cout << " 3. Update Record\n";
    cout << " 5. Main Menu\n";
    cout << " 6. Exit\n";
    cout << "\n Enter choice : ";
}

// Verify the admin
void adminVerification()
{
    string password;
    int count = 0;

    cout << "\n\n\n\n\n\t\t\t\t\t Enter Password (Password is password): ";

    do
    {
        cin >> password;

        if (password != "password")
        {
            //system("cls");
            count++;
            cout << "\n\t\t\t\t\t Wrong Password!, Try Again or Type 'menu' to Navigate to Main Menu";
            if (count != 3)
            {
                cout << "\n\n\n\t\t\t\t\t Enter Password (Password is password): ";
            }     
        }

        if ((password == "Menu" || password == "menu" || password == "MENU") || (count == 3))
        {
            cout << "\n\n\n\t\t\t\t\t Sorry, Transiting to Main Menu.";
            for (int i = 0; i < 3; i++)
            {

                Sleep(1000);
                cout << ".";
            }
            mainMenu();
        }
        
    } while (password != "password");

    // Once admin is verified,
    // Transit to perform admin operations.
    adminFunction();
}


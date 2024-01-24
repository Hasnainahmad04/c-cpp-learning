#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Structure to represent a student
struct Student
{
    string rollNo;
    string username;
    char status; // Student Status: p or a
};

// admin credentials
const string adminUsername = "admin";
const string adminPassword = "admin@123";

// Function prototypes
void login();
void takeAttendance();
void markAttendance(Student &student);
void addNewStudent();
void displayMenu();

int main()
{
    while (1)
    {
        displayMenu();

        int choice;
        cout << "\n Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            studentLogin();
            break;
        case 0:
            cout << "\n Are you sure you want to exit? (y/n): ";
            char exitChoice;
            cin >> exitChoice;
            if (exitChoice == 'y' || exitChoice == 'Y')
            {
                exit(0);
            }
            break;
        default:
            cout << "\n Invalid choice. Enter again.";
            getchar();
        }
    }

    return 0;
}

void displayMenu()
{
    cout << "\n Student Attendance Management System\n";
    cout << "------------------------------------\n\n";
    cout << "2. Login\n";
    cout << "0. Exit\n";
}

void login()
{
    cout << "\n ------- Login -------";

    string username, password;
    cout << "\n Enter username: ";
    cin >> username;
    cout << " Enter password: ";
    cin >> password;

    // Check admin credentials
    if (username == adminUsername && password == adminPassword)
    {
        int adminChoice;
        do
        {
            system("cls");
            cout << "\n Admin Options:";
            cout << "\n 1. Take Attendance";
            cout << "\n 2. Add New Student";
            cout << "\n 0. Go Back to Main Menu";
            cout << "\n Enter your choice: ";
            cin >> adminChoice;

            switch (adminChoice)
            {
            case 1:
                takeAttendance();
                break;
            case 2:
                addNewStudent();
                break;
            case 0:
                break; // Go back to the main menu
            default:
                cout << "\n Invalid choice. Enter again.";
                getchar();
            }
        } while (adminChoice != 0);
    }
    else
    {
        cout << "\n Error! Invalid Credentials.";
        cout << "\n Press any key to return to the main menu.";
        getchar();
        getchar();
    }
}

void takeAttendance()
{
    ifstream read("students.csv");
    if (!read.is_open())
    {
        cout << "\n Error opening students.csv";
        return;
    }

    Student student;
    string line;

    while (getline(read, line))
    {
        stringstream ss(line);
        getline(ss, student.username, ',');
        getline(ss, student.rollNo, ',');
        ss >> student.status;

        markAttendance(student);
    }

    read.close();
}

void markAttendance(Student &student)
{
    cout << "\n Marking attendance for student: " << student.username;
    cout << "\n Enter 'p' for present or 'a' for absent: ";
    cin >> student.status;

    // Update the status in the CSV file
    ifstream read("students.csv");
    ofstream write("temp.csv");

    string line;
    while (getline(read, line))
    {
        stringstream ss(line);
        string tempUsername, tempPassword;
        char tempStatus;
        getline(ss, tempUsername, ',');
        getline(ss, tempPassword, ',');
        ss >> tempStatus;

        if (tempUsername == student.username)
        {
            write << student.username << "," << student.password << "," << student.status << "\n";
        }
        else
        {
            write << tempUsername << "," << tempPassword << "," << tempStatus << "\n";
        }
    }

    read.close();
    write.close();

    // Rename the temp file to overwrite the original file
    remove("students.csv");
    rename("temp.csv", "students.csv");

    cout << "\n Attendance marked successfully!";
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
}

void addNewStudent()
{
    cout << "\n ------- Add New Student -------";

    Student newStudent;
    cout << "\n Enter Roll no for the new student: ";
    cin >> newStudent.rollNo;
    cout << " Enter Name for the new student: ";
    cin >> newStudent.username;
    newStudent.status = 'a';

    ofstream write("students.csv", ios::app);
    if (!write.is_open())
    {
        cout << "\n Error opening students.csv for writing";
        return;
    }

    write << newStudent.username << "," << newStudent.rollNo << "," << newStudent.status << "\n";
    write.close();

    cout << "\n Student added successfully!";
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
}

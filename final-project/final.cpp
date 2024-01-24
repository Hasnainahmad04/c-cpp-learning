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

// Admin credentials
const string adminUsername = "admin";
const string adminPassword = "admin@123";

// Function prototypes
void login();
void takeAttendance();
void addNewStudent();
void displayMenu();
void showAttendanceStats(int presentCount, int totalCount);

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
            login();
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
    cout << "------------------------------------\n";
    cout << "1. Login\n";
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

void showAttendanceStats(int presentCount, int totalCount)
{
    float attendancePercentage = (presentCount * 100.0) / totalCount;

    cout << "----------------------\n";
    cout << "\nAttendance Statistics\n";
    cout << "----------------------\n";
    cout << "Total Students: " << totalCount << endl;
    cout << "Present: " << presentCount << endl;
    cout << "Absent: " << totalCount - presentCount << endl;
    cout << "Attendance Percentage: " << attendancePercentage << "%" << endl;
}

void takeAttendance()
{
    ifstream read("students.csv");
    ofstream attendanceFile("attendance.csv", ios::app);

    int presentCount = 0;
    int totalCount = 0;

    Student student;
    string line;

    cout << "\nAttendance Interface\n";
    cout << "---------------------\n";
    cout << "Name\t\tStatus(p/a)\n";

    while (getline(read, line))
    {
        stringstream ss(line);
        getline(ss, student.rollNo, ',');
        getline(ss, student.username, ',');
        cout << student.username << "\t\t";
        cin >> student.status;
        attendanceFile << student.rollNo << "," << student.username << "," << student.status << "\n";

        if (student.status == 'p' || student.status == 'P')
        {

            presentCount++;
        }

        totalCount++;
    }

    cout << "\nAttendance marked successfully!";
    showAttendanceStats(presentCount, totalCount);
    cout << "\nPress any key to continue.";
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

    ofstream write("students.csv", ios::app);

    write << newStudent.rollNo << "," << newStudent.username << "\n";

    cout << "\n Student added successfully!";
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
}

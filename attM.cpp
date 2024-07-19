#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include <ctime>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <termios.h>
#include <iomanip>
#include <chrono>
#include <thread>

// Function to create a pause
using namespace std;

// Constants
const int MAX_ATTENDANCE = 100;

// Function declarations
void clearConsole();
void configureStdinEcho(bool enable = true);
void displayTitle();
void displayDate();
void pause(unsigned int milliseconds);

bool verifyStudentCredentials(const string& username, const string& password);

int adminAuthenticate();
int adminDashboard();
int registerNewStudent();
int viewRegisteredStudents();
int studentAuthenticate();
int studentDashboard();
int recordAttendance(const string& username);
int getAttendanceCount(const string& username);
int removeAllStudents();
int listRegisteredStudentsByUsername();
int removeStudentData();


void NewPart(){
    cout << "\nPress Enter key to continue ...   ";
    cin.get();
    cin.get();
}


void clearConsole() {
    cout << "\033[2J\033[1;1H";
}


int delay() {
    for (int i = 0; i < 3; i++) {
        cout << "\nSaving Records ...\n";
        for (int ii = 0; ii < 20000; ii++) {
            for (int iii = 0; iii < 20000; iii++) {}
        }
    }

    cout << "\nExiting Now ...";
    for (int i = 0; i < 3; i++) {
        for (int ii = 0; ii < 20000; ii++) {
            for (int iii = 0; iii < 20000; iii++) {}
        }
    }
    return 0;
}


void delay(unsigned int mseconds) {
    clock_t goal = mseconds + clock();
    while (goal > clock()) ;
}


void configureStdinEcho(bool enable) {
    termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if (enable) {
        tty.c_lflag |= ECHO;
    } else {
        tty.c_lflag &= ~ECHO;
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}


void displayTitle() {
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t-------------------------------------\n";
    cout << "\t\t\t| Attendance Management Of Students |\n";
    cout << "\t\t\t-------------------------------------\n";
    cout << "\n\n";
    cout << "\t\t\t\t";
}


void displayDate() {
    time_t T = time(nullptr);
    tm tm = *localtime(&T);
    cout << "\n\n\n";
    cout << "Date: " << setw(2) << setfill('0') << tm.tm_mday << "/"
         << setw(2) << setfill('0') << tm.tm_mon + 1 << "/"
         << tm.tm_year + 1900 << endl;
}


void pause(unsigned int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}


int adminAuthenticate() {
    clearConsole();
    displayDate();
    displayTitle();
    cout << "\n --------- Admin Login --------- \n\n";

    string username, password;
    cout << "\nEnter username: ";
    cin >> username;
    cout << "\nEnter password: ";
    configureStdinEcho(false);
    cin >> password;
    configureStdinEcho(true);
    cout << endl;

    if (username == "admin" && password == "spark") {
        adminDashboard();
        delay(3000); // Replace pause() with delay()
    } else {
        cout << "\n\nError! Invalid Credentials ...";
        NewPart();
    }
    return 0;
}


int adminDashboard() {
    int goBack = 0;
    while (1) {
        clearConsole();
        displayDate();
        displayTitle();
        cout << "\n\n\nPlease select an option ...\n";
        cout << "---------------------------\n";
        cout << "\n1. Register a Student";
        cout << "\n2. Check list of Students registered and view Roll No.";
        cout << "\n3. Get list of Students registered by Username";
        cout << "\n4. Delete Data of Student";
        cout << "\n5. Delete all registered Students";
        cout << "\n0. Go back \n";

        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                registerNewStudent();
                break;
            case 2:
                viewRegisteredStudents();
                break;
            case 3:
                listRegisteredStudentsByUsername();
                break;
            case 4:
                {
                    char confirm;
                    cout << "\nAre you sure you want to delete student data? (y/n): ";
                    cin >> confirm;
                    if (confirm == 'y' || confirm == 'Y')
                    {
                        removeStudentData();  
                    } else {
                        cout << "\nOperation canceled.";
                    }
                    break;
                }
            case 5:
                {
                    char confirm;
                    cout << "\nAre you sure you want to delete all registered students? (y/n): ";
                    cin >> confirm;
                    if (confirm == 'y' || confirm == 'Y') {
                        removeAllStudents();
                    } else {
                        cout << "\nOperation canceled.";
                    }
                    break;
                }
            case 0:
                goBack = 1;
                break;
            default:
                cout << "\nInvalid choice. Please enter again.";
                cin.ignore();
                cin.get();
        }
        if (goBack == 1) {
            break;
        }
    }
    return 0;
}


int registerNewStudent() {
    clearConsole();
    cout << "\n ------ Form to Register Student ------ \n\n";
    string name, username, password, rollno, address, fathersname, mothersname;
    int initialAttendance = 00; // Changed initial attendance to 0 by default

    cout << "\nEnter Name: ";
    getline(cin >> ws, name); // Use getline to capture full name, ignoring leading whitespace
    cout << "\nEnter Username: ";
    getline(cin >> ws, username); // Use getline to capture full username
    cout << "\nEnter Password: ";
    getline(cin >> ws, password); // Use getline to capture full password
    cout << "\nEnter Roll No.: ";
    getline(cin >> ws, rollno); // Use getline to capture full roll number
    cout << "\nEnter Address: ";
    getline(cin, address); // Read address (include spaces)
    cout << "\nEnter Father's Name: ";
    getline(cin, fathersname); // Read father's name (include spaces)
    cout << "\nEnter Mother's Name: ";
    getline(cin, mothersname); // Read mother's name (include spaces)

    // File operations
    ifstream dbFile("db.dat");
    if (dbFile) {
        string line;
        while (getline(dbFile, line)) {
            if (line == username + ".dat") {
                cout << "\nUsername already Registered. Please choose another username ...";
                cin.ignore();
                cin.get();
                return 0;
            }
        }
        dbFile.close();
    }

    ofstream dbFileOut("db.dat", ios::app);
    if (dbFileOut) {
        dbFileOut << username + ".dat" << "\n";
        dbFileOut.close();
    } else {
        cout << "\nError opening database file!";
        return 0;
    }

    ofstream studentFile(username + ".dat");
    if (studentFile) {
        studentFile << name << "\n";
        studentFile << username << "\n";
        studentFile << password << "\n";
        studentFile << rollno << "\n";
        studentFile << address << "\n";
        studentFile << fathersname << "\n";
        studentFile << mothersname << "\n";
        studentFile << initialAttendance << "\n";
        studentFile.close();
    } else {
        cout << "\nError creating student file!";
        return 0;
    }

    cout << "\nStudent Registered Successfully!!\n";
    NewPart();
    return 0;
}


int viewRegisteredStudents() {
    cout << "\n --- Get list of Students registered by Username --- \n\n";

    ifstream read("db.dat");
    if (read) {
        string line;
        while (getline(read, line)) {
            // Output the filename, which is the username + ".dat"
            cout << "\n" << line;
        }
        read.close();
    } else {
        cout << "\nNo Record found :(";
    }

    NewPart();
    return 0;
}


int studentAuthenticate() {
    clearConsole();
    displayDate();
    displayTitle();
    cout << "\n --------- Student Login --------- \n\n";
    studentDashboard();
    return 0;
}


int studentDashboard() {
    string username, password;
    cout << "\nEnter username: ";
    cin >> username;
    cout << "\nEnter password: ";
    configureStdinEcho(false);
    cin >> password;
    configureStdinEcho(true);
    cout << endl;

    if (verifyStudentCredentials(username, password)) {
        int goBack = 0;
        while (true) {
            clearConsole();
            displayDate();
            displayTitle();
            cout << "\n\n\nPlease select an option ...\n";
            cout << "-------------------------------\n";
            cout << "\n1. Mark Attendance for today";
            cout << "\n2. Check your Attendance Count";
            cout << "\n0. Go back \n";

            int choice;
            cout << "\nEnter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    recordAttendance(username);
                    break;
                case 2:
                    getAttendanceCount(username);
                    break;
                case 0:
                    goBack = 1;
                    break;
                default:
                    cout << "\nInvalid choice. Please enter again.";
                    cin.ignore();
                    cin.get();
            }
            if (goBack == 1) {
                break;
            }
        }
    } else {
        cout << "\n\nInvalid Credentials ...";
        NewPart();
    }
    return 0;
}


bool verifyStudentCredentials(const string& username, const string& password) {
    ifstream db("db.dat");
    if (!db) {
        return false;
    }

    string line;
    bool userExists = false;
    while (getline(db, line)) {
        if (line == username + ".dat") {
            userExists = true;
            break;
        }
    }
    db.close();

    if (!userExists) {
        return false;
    }

    ifstream studentFile(username + ".dat");
    if (!studentFile) {
        return false;
    }

    string filePassword;
    studentFile.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip name
    studentFile.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip username
    studentFile >> filePassword; // Read password
    studentFile.close();

    return password == filePassword;
}


int recordAttendance(const string& username) {
    time_t T = time(nullptr);
    tm tm = *localtime(&T);
    string currentDate = to_string(tm.tm_mday) + "/" + to_string(tm.tm_mon + 1) + "/" + to_string(tm.tm_year + 1900);

    ifstream studentFile(username + ".dat");
    if (!studentFile) {
        cout << "\nError opening student file!";
        return 0;
    }

    string line;
    bool attendanceMarked = false;
    while (getline(studentFile, line)) {
        if (line == currentDate) {
            attendanceMarked = true;
            break;
        }
    }
    studentFile.close();

    if (attendanceMarked) {
        cout << "\nAttendance already marked for today!\n";
        NewPart();
        return 0;
    }

    ofstream studentFileOut(username + ".dat", ios::app);
    if (studentFileOut) {
        studentFileOut << currentDate << "\n";
        studentFileOut.close();
        cout << "\nAttendance marked for today!\n";
    } else {
        cout << "\nError opening student file!\n";
    }
    NewPart();
    return 0;
}


int getAttendanceCount(const string& username) {
    ifstream studentFile(username + ".dat");
    if (!studentFile) {
        cout << "\nError opening student file!\n";
        return 0;
    }

    string line;
    int count = 0;
    while (getline(studentFile, line)) {
        ++count;
    }
    studentFile.close();

    cout << "\nYour total attendance count is: " << count << "\n";
    NewPart();
    return 0;
}


int removeAllStudents() {
    if (remove("db.dat") != 0) {
        perror("Error deleting database file");
        NewPart();
        return 1;
    }

    cout << "\nAll student records deleted successfully!\n";
    NewPart();
    return 0;
}


int listRegisteredStudentsByUsername() {
    cout << "\n --- Get list of Students registered by Username --- \n\n";

    ifstream read("db.dat");
    if (read) {
        string line;
        while (getline(read, line)) {
            string filename = line;
            ifstream studentFile(filename);
            string username;
            int lineCount = 0;
            while (getline(studentFile, line)) {
                if (++lineCount == 2) { // Username is on the 2nd line
                    username = line;
                    break;
                }
            }
            cout << "\n" << filename << " -> " << username;
        }
    } else {
        cout << "\nNo Record found :(\n";
    }

    NewPart();
    return 0;
}


int removeStudentData() {
    string username;
    cout << "\nEnter the username of the student whose data you want to delete: ";
    cin >> username;
    string fileName = username + ".dat";
    if (remove(fileName.c_str()) != 0) {
        cout << "\nError deleting student data.\n";
    } else {
        cout << "\nStudent data deleted successfully.\n";
    }

    NewPart();
    return 0;
}


int main() {
    while (true) {
        clearConsole();
        displayDate();
        displayTitle();
        cout << "\n\n\nPlease select an option ...\n";
        cout << "---------------------------\n";
        cout << "\n1. Student Login";
        cout << "\n2. Admin Login";
        cout << "\n0. Exit\n";

        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                studentAuthenticate();
                break;
            case 2:
                adminAuthenticate();
                break;
            case 0:
                cout<<"\nExiting ...\n\n\n\n\n";
                NewPart();
                clearConsole();
                return 0;
            default:
                cout << "\nInvalid choice. Please enter again.";
                cin.ignore();
                cin.get();
        }
    }
}


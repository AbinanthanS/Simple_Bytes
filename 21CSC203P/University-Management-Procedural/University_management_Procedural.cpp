#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <windows.h>
#include <sstream>

using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PW = "password";
const char* DB = "university";

// Global variables for student data
int Id, Age;
string Name, Subject;
float CGPA;

// Function prototypes
void insertStudent(MYSQL* conn);
void showRecords(MYSQL* conn);
void searchStudent(MYSQL* conn);
void updateStudent(MYSQL* conn);
void deleteStudent(MYSQL* conn);

void insertStudent(MYSQL* conn) {
    cout << "Enter Id: ";
    cin >> Id;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, Name);

    cout << "Enter Age: ";
    cin >> Age;

    cout << "Enter Subject: ";
    cin.ignore();
    getline(cin, Subject);

    cout << "Enter CGPA: ";
    cin >> CGPA;

    stringstream ss, sss, as;
    ss << Id;
    sss << Age;
    as << CGPA;

    string ins = "INSERT INTO student (Id, Age, Name, Subject, CGPA) VALUES ('" + ss.str() + "','" + sss.str() + "','" + Name + "', '" + Subject + "', '" + as.str() + "')";
    
    if (mysql_query(conn, ins.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        cout << "Data Inserted Successfully." << endl;
    }
    Sleep(3000);
}

void showRecords(MYSQL* conn) {
    string show = "SELECT * FROM student";
    if (mysql_query(conn, show.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        MYSQL_RES* res = mysql_store_result(conn);
        if (res) {
            int num = mysql_num_fields(res);
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res))) {
                for (int i = 0; i < num; i++) {
                    cout << " " << row[i];
                }
                cout << endl;
            }
            mysql_free_result(res);
        }
    }
    Sleep(5000);
}

void searchStudent(MYSQL* conn) {
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    stringstream ss;
    ss << id;
    string sId = ss.str();

    string show = "SELECT * FROM student WHERE Id ='" + sId + "'";

    if (mysql_query(conn, show.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        MYSQL_RES* res = mysql_store_result(conn);
        if (res) {
            MYSQL_ROW row = mysql_fetch_row(res);
            if (row) {
                int num = mysql_num_fields(res);
                for (int i = 0; i < num; i++) {
                    cout << " " << row[i];
                }
                cout << endl;
            }
            mysql_free_result(res);
        }
    }
    Sleep(5000);
}

void updateStudent(MYSQL* conn) {
    int id;
    cout << "Enter Id: ";
    cin >> id;

    string subject;
    cout << "Enter New Subject: ";
    cin.ignore();
    getline(cin, subject);

    stringstream ss;
    ss << id;
    string sId = ss.str();

    string upd = "UPDATE student SET Subject = '" + subject + "' WHERE Id = '" + sId + "'";
    if (mysql_query(conn, upd.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        cout << "Data Updated Successfully" << endl;
    }
    Sleep(3000);
}

void deleteStudent(MYSQL* conn) {
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    stringstream ss;
    ss << id;
    string sId = ss.str();

    string del = "DELETE FROM student WHERE Id ='" + sId + "' ";
    if (mysql_query(conn, del.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    } else {
        cout << "Data Deleted" << endl;
    }
    Sleep(3000);
}

int main() {
    MYSQL* conn;
    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, HOST, USER, PW, DB, 3306, NULL, 0)) {
        cout << "Error: " << mysql_error(conn) << endl;
        return 1;
    } else {
        cout << "Logged in!" << endl;
    }
    Sleep(3000);

    bool exit = false;

    while (!exit) {
        system("cls");
        int val;
        cout << "Welcome to University Management System" << endl;
        cout << "------------------------------------------" << endl;
        cout << "[1] Insert Student Data" << endl;
        cout << "[2] Show Student Data" << endl;
        cout << "[3] Search Student Data" << endl;
        cout << "[4] Update Student Data" << endl;
        cout << "[5] Delete Student Data" << endl;
        cout << "[0] Exit" << endl;
        cout << "Enter choice: ";
        cin >> val;

        cout << endl;

        if (val == 1) {
            insertStudent(conn);
        } else if (val == 2) {
            showRecords(conn);
        } else if (val == 3) {
            searchStudent(conn);
        } else if (val == 4) {
            updateStudent(conn);
        } else if (val == 5) {
            deleteStudent(conn);
        } else if (val == 0) {
            exit = true;
            cout << "Good Luck!" << endl;
            Sleep(3000);
        } else {
            cout << "Invalid Input" << endl;
            Sleep(300);
        }
    }

    mysql_close(conn); // Close the database connection
    return 0;
}


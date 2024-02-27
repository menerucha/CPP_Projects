#include <iostream>
#include <fstream>
using namespace std;

class temp
{
    string userName, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;

public:
    void login();
    void signUP();
    void forgot();

} obj;
int main()
{
    char choice;
    cout << "\n 1-Login";
    cout << "\n 2-Signup";
    cout << "\n 3-Forgot Password";
    cout << "\n 4-Exit";
    cout << "\n 5-Enter Your Choice";
    cin >> choice;
    switch (choice)
    {
    case '1':
        obj.login();
        break;
    case '2':
        obj.signUP();
        break;
    case '3':
        obj.forgot();
        break;
    case '4':
        return 0;
        break;
    default:
        cout << "Invalid Selection...!";
    }
}
void temp ::signUP()
{
    cout << "\n Enter your User Name :: ";
    getline(cin, userName);
    cout << "\n Enter your Email Address :: ";
    getline(cin, Email);
    cout << "\n Enter your Password :: ";
    getline(cin, password);

    file.open("loginData.txt", ios ::out | ios ::app);
    file << userName << "*" << Email << "*" << password << endl;
    file.close();
}
void temp ::login()
{
    string searchName, searchPass;
    cout << "------------LOGIN-------------" << endl;
    cout << "Enter Your User Name ::" << endl;
    getline(cin, searchName);
    cout << "Enter Your Password :: " << endl;
    getline(cin, searchPass);

    file.open("loginData.txt", ios ::in);
    getline(file, userName, '*');
    getline(file, Email, '*');
    getline(file, password, '\n');
    while (!file.eof())
    {
        if (userName == searchName)
        {
            if (Email == searchEmail)
            {
                cout << "\nAccount Found..!" << endl;
                cout << "Your Password :: " << password << endl;
            }
        }
        {
            if (password == searchPass)
            {
                cout << "\n Account Login Successful..!";
                cout << "\n Username :: " << userName << endl;
                cout << "\n Email :: " << Email << endl;
            }
        }
        getline(file, userName, '*');
        getline(file, Email, '*');
        getline(file, password, '\n');
    }
    file.close();
}
void temp ::forgot()
{
    cout << "\n Enter Your userName :: ";
    getline(cin, searchName);
    cout << "\n Enter Your Email Address ::";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios ::in);
    getline(file, userName, '*');
    getline(file, Email, '*');
    getline(file, password, '\n');
    while (!file.eof())
    {
        if (userName == searchName)
        {
            if (Email == searchEmail)
            {
                cout << "\n Account Found..!" << endl;
            }
            else
            {
                cout << "Not found..!\n";
            }
        }
        else
        {
            cout << "\n Not Found..!";
        }
    }
    file.close();
}
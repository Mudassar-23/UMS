#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class User {
protected:
    static const int MAX_USERS = 100;
   string usernames[MAX_USERS];
   string passwords[MAX_USERS];
    char accountTypes[MAX_USERS];
    int numUsers;

public:
    User();

    void loadDataFromFile(const string& Users);

    bool login(const string& username, const string& password, char expectedAccountType);

    virtual bool isAdmin(const string& username);

    virtual void Display_info() = 0;

    void saveDataToFile(const string& fileName);
};

class Student : public User {
public:
    Student();
    void Display_info();
};

class Faculty : public User {
public:
    Faculty();
    void Display_info();
};

class Administration : public User {
public:
    Administration();

    bool addUser(const string& username, const string& password, char accountType);

    bool deleteUser(const string& username);

    void Display_info();
};

#endif

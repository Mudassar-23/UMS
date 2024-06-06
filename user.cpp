#include "User.h"
using namespace std;
User::User() : numUsers(0) {}

void User::loadDataFromFile(const string& Users) {
    ifstream file(Users);
    if (!file.is_open()) {
        cout << "Error opening file: " << endl;
        return;
    }

    string line;
    while (getline(file, line) && numUsers < MAX_USERS) {
        string username, password;
        char accountType;
        istringstream iss(line);
        if (iss >> username >> password >> accountType) {
            usernames[numUsers] = username;
            passwords[numUsers] = password;
            accountTypes[numUsers] = accountType;
            numUsers++;
        }
    }
    file.close();
}

bool User::login(const string& username, const string& password, char expectedAccountType) {
    for (int i = 0; i < numUsers; ++i) {
        if (usernames[i] == username && passwords[i] == password && accountTypes[i] == expectedAccountType) {
            return true;
        }
    }
    return false;
}

bool User::isAdmin(const string& username) {
    for (int i = 0; i < numUsers; ++i) {
        if (usernames[i] == username) {
            return accountTypes[i] == 'A';
        }
    }
    return false;
}

void User::saveDataToFile(const string& fileName){
    ofstream file(fileName);
    if (!file.is_open()) {
        cout << "Error opening file: " << fileName << std::endl;
        return;
    }

    for (int i = 0; i < numUsers; ++i) {
        file << usernames[i] << "\t" << passwords[i] << "\t" << accountTypes[i] << endl;
    }

    file.close();
}

Student::Student() {}

void Student::Display_info() {
    cout << "Student Information Display" << endl;
}

Faculty::Faculty() {}

void Faculty::Display_info() {
    cout << "Faculty Information Display" << endl;
}

Administration::Administration() {}

bool Administration::addUser(const string& username, const string& password, char accountType) {
    if (numUsers >= MAX_USERS) {
        cout << "Maximum number of users reached." << endl;
        return false;
    }
    for (int i = 0; i < numUsers; ++i) {
        if (usernames[i] == username) {
            cout << "Username already exists." << endl;
            return false;
        }
    }
    usernames[numUsers] = username;
    passwords[numUsers] = password;
    accountTypes[numUsers] = accountType;
    numUsers++;
    saveDataToFile("Users.txt");
    return true;
}

bool Administration::deleteUser(const string& username) {
    int index = -1;
    for (int i = 0; i < numUsers; ++i) {
        if (usernames[i] == username) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "User not found." << endl;
        return false;
    }

    for (int i = index; i < numUsers - 1; ++i) {
        usernames[i] = usernames[i + 1];
        passwords[i] = passwords[i + 1];
        accountTypes[i] = accountTypes[i + 1];
    }
    numUsers--;
    saveDataToFile("Users.txt");
    return true;
}

void Administration::Display_info() {
    // Display Administration Info
    cout << "Administration Information Display" << endl;
}

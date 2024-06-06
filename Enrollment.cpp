#include "Enrollment.h"
#include<iostream>
using namespace std;

Enrollment::Enrollment() {
    numEnrollments = 0;
}

void Enrollment::loadDataFromFile(const string& enrollmentFile, const string& studentID) {
    this->studentID = studentID;
    ifstream file(enrollmentFile);
    if (!file.is_open()) {
        cout << "Error opening file: " << enrollmentFile << endl;
        return;
    }

    string line;
    while (getline(file, line) && numEnrollments < MAX_ENROLLMENTS) {
        string ID, courseCode;
        istringstream iss(line);
        if (iss >> ID >> courseCode && ID == studentID) {
            courseCodes[numEnrollments] = courseCode;
            numEnrollments++;
        }
    }
    file.close();
}

void Enrollment::saveDataToFile(const string& enrollmentFile) const {
    ofstream file(enrollmentFile, std::ios::app);
    if (!file.is_open()) {
        cout << "Error opening file: " << enrollmentFile << endl;
        return;
    }

    for (int i = 0; i < numEnrollments; ++i) {
        file << studentID << "\t" << courseCodes[i] << endl;
    }

    file.close();
}

bool Enrollment::enrollStudent(const string& courseCode) {
    if (numEnrollments >= MAX_ENROLLMENTS) {
        cout << "Maximum enrollments reached." << endl;
        return false;
    }

    courseCodes[numEnrollments] = courseCode;
    numEnrollments++;
    return true;
}

void Enrollment::displayEnrollments() const {
    cout << "Enrollments for student ID " << studentID << ":" << endl;
    for (int i = 0; i < numEnrollments; ++i) {
        cout << "Course Code: " << courseCodes[i] << endl;
    }
}

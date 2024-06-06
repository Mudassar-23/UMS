
#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Enrollment {
private:
    static const int MAX_ENROLLMENTS = 5;
    string studentID;
    string courseCodes[MAX_ENROLLMENTS];
    int numEnrollments;

public:
    Enrollment();

    void loadDataFromFile(const string& enrollmentFile, const string& studentID);

    void saveDataToFile(const string& enrollmentFile) const;

    bool enrollStudent(const string& courseCode);

    void displayEnrollments() const;
};

#endif      
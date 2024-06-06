#ifndef GRADE_H
#define GRADE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Grade {
private:
    string studentID;
    string courseCode;
    char grade;

public:
    Grade(const string& studentID, const string& courseCode);

    void saveDataToFile(const string& fileName) const;

    void assignGrade();

    void displaygrade() const;
};

#endif
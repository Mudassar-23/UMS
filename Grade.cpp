#include "Grade.h"
#include <iostream>
#include <fstream>


Grade::Grade(const string& studentID, const string& courseCode)
    : studentID(studentID), courseCode(courseCode), grade(' ') {} 

void Grade::saveDataToFile(const string& fileName) const {
    ofstream file(fileName);
    if (!file.is_open()) {
        cout << "Error opening file: " << fileName << endl;
        return;
    }

    file << studentID << "\t" << courseCode << "\t" << grade << endl;

    file.close();
}

void Grade::assignGrade() {
    cout << "Enter grade for student " << studentID << " in course " << courseCode << ": ";
    cin >> grade;
    if (grade < 'A' || grade > 'F') {  //grades  'A' to 'F'
        cout << "Invalid grade. Grade must be between 'A' and 'F'." << endl;
        return;
    }
}

void Grade::displaygrade() const {
    ifstream file("Grades.txt");
    if (!file.is_open()) {
        cout << "Error opening file: Grades.txt" << endl;
        return;
    }

    string line;
    bool gradeFound = false;
    while (getline(file, line)) {
        istringstream iss(line);
        string id, code;
        char studentGrade;
        if (iss >> id >> code >> studentGrade && id == studentID && code == courseCode) {
            gradeFound = true;
            cout << "Student ID: " << id << endl;
            cout << "Course Code: " << code << endl;
            cout << "Grade: " << studentGrade << endl;
            break;
        }
    }
    file.close();

    if (!gradeFound) {
        cout << "No grade found for student ID " << studentID << " in course " << courseCode << endl;
    }
}

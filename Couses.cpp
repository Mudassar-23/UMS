#include "Courses.h"
using namespace std;
Course::Course() {
    numCourse = 0;
    for (int i = 0; i < MAX_COURSE; i++) {
        courseCode[i] = "";
    }
}

Course::Course(string code, string name, int creditH, string instr, string prereq) {
    if (numCourse >= MAX_COURSE) {
        cout << "Maximum number of courses reached." << endl;
        return;
    }
    courseCode[numCourse] = code;
    courseName[numCourse] = name;
    credits[numCourse] = creditH;
    instructor[numCourse] = instr;
    prerequisites[numCourse] = prereq;
    numCourse++;
}

void Course::loadDataFromFile(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "Error opening file: " << fileName << endl;
        return;
    }

    string line;
    while (getline(file, line) && numCourse < MAX_COURSE) {
        string Code, Name, Instr, Prereq;
        int CreditH;
        istringstream iss(line);
        if (iss >> Code >> Name >> CreditH >> Instr >> Prereq) {
            courseCode[numCourse] = Code;
            courseName[numCourse] = Name;
            credits[numCourse] = CreditH;
            instructor[numCourse] = Instr;
            prerequisites[numCourse] = Prereq;
            numCourse++;
        }
    }
    file.close();
}

void Course::saveDataToFile(const string& fileName) const {
    ofstream file(fileName);
    if (!file.is_open()) {
        cout << "Error opening file: " << fileName <<  endl;
        return;
    }

    for (int i = 0; i < numCourse; ++i) {
        file << courseCode[i] << "\t" << courseName[i] << "\t" << credits[i] << "\t" << instructor[i] << "\t" << prerequisites[i] << std::endl;
    }

    file.close();
}

void Course::createCourse() {
    cout << "Enter course code: ";
    cin >> courseCode[numCourse];
    cout << "Enter course name: ";
    getline(cin >> ws, courseName[numCourse]);

    cout << "Enter credit hours: ";
    cin >> credits[numCourse];
    cin.ignore();

    cout << "Enter instructor name: ";
    getline(cin, instructor[numCourse]);

     cout << "Enter prerequisites (comma-separated): ";
    getline(cin, prerequisites[numCourse]);
    numCourse++;
    saveDataToFile("Courses.txt");
}

int Course::findCourseIndex(const string& courseCode) const {
    for (int i = 0; i < numCourse; ++i) {
        if (this->courseCode[i] == courseCode) {
            return i;
        }
    }
    return -1;
}

void Course::deleteCourse(const string& courseCodeToDelete) {
    int index = findCourseIndex(courseCodeToDelete);
    if (index == -1) {
        cout << "Course not found." << endl;
        return;
    }

    for (int i = index; i < numCourse - 1; ++i) {
        courseCode[i] = courseCode[i + 1];
        courseName[i] = courseName[i + 1];
        credits[i] = credits[i + 1];
        instructor[i] = instructor[i + 1];
        prerequisites[i] = prerequisites[i + 1];
    }

    courseCode[numCourse - 1] = "";
    courseName[numCourse - 1] = "";
    credits[numCourse - 1] = 0;
    instructor[numCourse - 1] = "";
    prerequisites[numCourse - 1] = "";
    numCourse--;
    saveDataToFile("Courses.txt");
}

void Course::displayCourses() const {
    cout << "Courses Available:" << std::endl;
    for (int i = 0; i < numCourse; ++i) {
         cout << "Course Code: " << courseCode[i] << endl;
         cout << "Course Name: " << courseName[i] << endl;
         cout << "Instructor: " << instructor[i] << endl;
         cout << "Credits: " << credits[i] << endl;
         cout << "Prerequisites: " << prerequisites[i] << endl << endl;
    }
}

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
class Course {
private:
    static const int MAX_COURSE = 10;
    string courseCode[MAX_COURSE];
    string courseName[MAX_COURSE];
    string instructor[MAX_COURSE];
    int credits[MAX_COURSE];
    string prerequisites[MAX_COURSE];
    int numCourse;
public:
    Course();
    Course(string code, string name, int credits, string instructor, string prerequisites);

    void createCourse();

    void saveDataToFile(const string& fileName) const;

    void loadDataFromFile(const string& fileName);

    void deleteCourse(const string& courseCode);

    int findCourseIndex(const string& courseCode) const;

   // string getCourseCode() const;

    void displayCourses() const;


};

#endif
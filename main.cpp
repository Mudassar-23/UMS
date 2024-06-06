#include <iostream>
#include "Courses.h"
#include "Grade.h"
#include "Enrollment.h"
#include "User.h"

using namespace std;

int main() {
    int choice;
    do {
        cout << "Menu" << endl;
        cout << "1. Login as Administration" << endl;
        cout << "2. Login as Faculty" << endl;
        cout << "3. Login as Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Administration admin;
            admin.loadDataFromFile("User.txt");

            string username, password;
            bool loggedIn = false;

            do {
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;

                loggedIn = admin.login(username, password, 'A');
                if (!loggedIn) {
                    cout << "Incorrect username or password. Please try again." << endl;
                }
            } while (!loggedIn);

            cout << "Logged in as Administration!" << endl;

            int adminChoice;
            do {
                cout << "\nAdministration Menu: " << endl;
                cout << "1. Add User" << endl;
                cout << "2. Delete User" << endl;
                cout << "3. Add Course" << endl;
                cout << "4. Delete Course" << endl;
                cout << "5. Logout" << endl;
                cout << "Enter your choice: ";
                cin >> adminChoice;

                switch (adminChoice) {
                case 1: {
                    // Add User
                    string newUsername, newPassword;
                    char newAccountType;
                    cout << "Enter new username: ";
                    cin >> newUsername;
                    cout << "Enter new password: ";
                    cin >> newPassword;
                    cout << "Enter new account type (A/F/S): ";
                    cin >> newAccountType;
                    admin.addUser(newUsername, newPassword, newAccountType);
                    cout << "User added successfully." << endl;
                    break;
                }
                case 2: {
                    // Delete User
                    string deleteUsername;
                    cout << "Enter username to delete: ";
                    cin >> deleteUsername;
                    admin.deleteUser(deleteUsername);
                    cout << "User deleted successfully." << endl;
                    break;
                }
                case 3: {
                    // Add Course
                    Course newCourse;
                    newCourse.loadDataFromFile("Courses.txt");
                    newCourse.createCourse();
                    newCourse.saveDataToFile("Courses.txt");
                    cout << "Course added successfully." << endl;
                    break;
                }
                case 4: {
                    // Delete Course
                    Course courseToDelete;
                    courseToDelete.loadDataFromFile("Courses.txt");
                    string courseCodeToDelete;
                    cout << "Enter course code to delete: ";
                    cin >> courseCodeToDelete;
                    courseToDelete.deleteCourse(courseCodeToDelete);
                    cout << "Course deleted successfully." << endl;
                    break;
                }
                case 5: {
                    cout << "Logged out from Administration." << endl;
                    break;
                }
                default:
                    cout << "Invalid choice." << endl;
                }
            } while (adminChoice != 5);
            break;
        }
        case 2: {
            Faculty fac;
            fac.loadDataFromFile("User.txt");

            string username, password;
            bool loggedIn = false;

            do {
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;

                loggedIn = fac.login(username, password, 'F');
                if (!loggedIn) {
                    cout << "Incorrect username or password. Please try again." << endl;
                }
            } while (!loggedIn);

            cout << "Logged in as Faculty!" << endl;

            int facultyChoice;
            do {
                cout << "\nFaculty Menu: " << endl;
                cout << "1. Add Course" << endl;
                cout << "2. Delete Course" << endl;
                cout << "3. Assign Grade" << endl;
                cout << "4. Display Grade" << endl;
                cout << "5. Logout" << endl;
                cout << "Enter your choice: ";
                cin >> facultyChoice;

                switch (facultyChoice) {
                case 1: {
                    // Add Course
                    Course newCourse;
                    newCourse.loadDataFromFile("Courses.txt");
                    newCourse.createCourse();
                    newCourse.saveDataToFile("Courses.txt");
                    cout << "Course added successfully." << endl;
                    break;
                }
                case 2: {
                    // Delete Course
                    Course courseToDelete;
                    courseToDelete.loadDataFromFile("Courses.txt");
                    string courseCodeToDelete;
                    cout << "Enter course code to delete: ";
                    cin >> courseCodeToDelete;
                    courseToDelete.deleteCourse(courseCodeToDelete);
                    cout << "Course deleted successfully." << endl;
                    break;
                }
                case 3: {
                    // Assign Grade
                    string studentID, courseCode;
                    cout << "Enter student ID: ";
                    cin >> studentID;
                    cout << "Enter course code: ";
                    cin >> courseCode;
                    Grade grade(studentID, courseCode);
                    grade.assignGrade();
                    grade.saveDataToFile("Grades.txt");
                    break;
                }
                case 4: {
                    // Display Grade
                    string studentID, courseCode;
                    cout << "Enter student ID: ";
                    cin >> studentID;
                    cout << "Enter course code: ";
                    cin >> courseCode;
                    Grade grade(studentID, courseCode);
                    grade.displaygrade();
                    break;
                }
                case 5: {
                    cout << "Logged out from Faculty." << endl;
                    break;
                }
                default:
                    cout << "Invalid choice." << endl;
                }
            } while (facultyChoice != 5);
            break;
        }
        case 3: {
            Student s1;
            s1.loadDataFromFile("User.txt");
            string username, password;
            bool loggedIn = false;

            do {
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;

                loggedIn = s1.login(username, password, 'S');
                if (!loggedIn) {
                    cout << "Incorrect username or password. Please try again." << endl;
                }
            } while (!loggedIn);

            cout << "Logged in as Student!" << endl;

            int studentChoice;
            Enrollment enrollment;
            enrollment.loadDataFromFile("Enrollments.txt", username); // Load enrollments for the logged-in student
            Course course;
            course.loadDataFromFile("Courses.txt");

            do {
                cout << "\nStudent Menu: " << endl;
                cout << "1. Display Courses" << endl;
                cout << "2. Enroll in Course" << endl;
                cout << "3. Display Enrollments" << endl;
                cout << "4. Logout" << endl;
                cout << "Enter your choice: ";
                cin >> studentChoice;

                switch (studentChoice) {
                case 1: {
                    // Display Courses
                    course.displayCourses();
                    break;
                }
                case 2: {
                    // Enroll in Course
                    string courseCode;
                    cout << "Enter the course code to enroll: ";
                    cin >> courseCode;
                    if (enrollment.enrollStudent(courseCode)) {
                        cout << "Enrolled successfully in course: " << courseCode << endl;
                    }
                    break;
                }
                case 3: {
                    // Display Enrollments
                    enrollment.displayEnrollments();
                    break;
                }
                case 4: {
                    cout << "Logged out from Student." << endl;
                    break;
                }
                default:
                    cout << "Invalid choice." << endl;
                }
            } while (studentChoice != 4);
            break;
        }

        }


    }while (choice != 4);
}

User Management System (UMS)
*)Overview
The User Management System (UMS) is a C++ application designed to manage user accounts and their associated data for a university setting. It supports three types of users: Students, Faculty, and Admins. The system allows for managing courses, grades, and enrollments, with all data stored in text files for simplicity and persistence.

Features:
-> Admin
Add, delete, and update student information.
View all users and their details.
-> Faculty
Add and manage student accounts.
Upload and update grades for students.
View courses and student information.
-> Student
View their own grades.
View their enrolled courses and associated information.
-> Files
course.txt: Stores information about courses.
grade.txt: Stores grades of students.
user.txt: Stores user account information (students, faculty, admins).
enrollment.txt: Stores enrollment details linking students to courses.

*)Usage Instructions:
-> Admin Commands
Add Student: Enter the details prompted by the system.
Delete Student: Provide the student ID to delete.
Update Student: Enter the student ID and the new details.
-> Faculty Commands
Add Student: Enter the details prompted by the system.
Upload Grades: Provide the student ID, course ID, and grade.
View Courses and Students: Display information about courses and enrolled students.
-> Student Commands
View Grades: Automatically displays grades for enrolled courses.
View Courses: Automatically displays information about enrolled courses.

*)Example Instructions:
-> Admin adds a USER( student/faculty ), if he adds a new student:
Enter user ID: 1001
Enter username: john
Enter password: pass123
Enter role: student

-> Faculty uploads a grade:
Enter student ID: 1001
Enter course ID: CS101
Enter grade: A

-> Student views their grades:
Courses:
CS101 - A

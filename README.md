# Student Information Management System

## Project Overview
This Student Information Management System is a console-based C program designed to manage and store student data. It allows users to add, find, update, and delete student records. The system can handle up to 100 students and stores essential details such as names, roll numbers, CGPA, and registered courses.

## Features
- **Add Student**: Add a new student record, including first name, last name, roll number, CGPA, and courses.
- **Find Student by Roll Number**: Search for a student using their roll number.
- **Find Student by First Name**: Search for students by their first name.
- **Find Students by Course**: Find all students enrolled in a specific course.
- **Count Students**: Display the total number of students in the system.
- **Delete Student**: Remove a student record by their roll number.
- **Update Student**: Update the details of an existing student by their roll number.

## How to Run
1. **Clone the Repository**:
    ```bash
    git clone https://github.com/Vedant-Gidra/student-information-system.git
    cd student-information-system
    ```

2. **Compile the Program**:
   - Using GCC:
     ```bash
     gcc -o student_management main.c
     ```

3. **Run the Program**:
    ```bash
    ./student_management
    ```

4. **Use the Program**:
   - Follow the on-screen instructions to add, find, update, delete, or count student records.
   - The program presents a menu for different operations.

## Example Usage
1. **Add a Student**:
   - Enter the student's first name, last name, roll number, CGPA, and registered courses when prompted.

2. **Find a Student by Roll Number**:
   - Enter the roll number, and the system will display the corresponding student's details if found.

3. **Update a Student's Information**:
   - Enter the roll number of the student to update, followed by the new details.

## Limitations
- The system can store information for a maximum of 100 students.
- The program does not persist data after exiting, meaning all records are lost when the program is closed.

## Contributing
If you'd like to contribute to this project, please follow these steps:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-name`).
3. Make your changes and commit them (`git commit -m "Describe your changes"`).
4. Push to the branch (`git push origin feature-name`).
5. Create a Pull Request.



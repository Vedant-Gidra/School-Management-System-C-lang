#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to hold student information
struct Student {
    char firstName[50];
    char lastName[50];
    int rollNumber;
    float cgpa;
    char courses[100];
};

// Global array to store student records
struct Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void addStudent();
void findStudentByRollNumber(int rollNumber);
void findStudentByFirstName(char *firstName);
void findStudentsByCourse(char *course);
void countStudents();
void deleteStudent(int rollNumber);
void updateStudent(int rollNumber);

int main() {
    int choice;
    do {
        printf("\nStudent Information Management System\n");
        printf("1. Add Student\n");
        printf("2. Find Student by Roll Number\n");
        printf("3. Find Student by First Name\n");
        printf("4. Find Students by Course\n");
        printf("5. Count Students\n");
        printf("6. Delete Student\n");
        printf("7. Update Student\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2: {
                int rollNumber;
                printf("Enter roll number: ");
                scanf("%d", &rollNumber);
                findStudentByRollNumber(rollNumber);
                break;
            }
            case 3: {
                char firstName[50];
                printf("Enter first name: ");
                scanf("%s", firstName);
                findStudentByFirstName(firstName);
                break;
            }
            case 4: {
                char course[100];
                printf("Enter course name: ");
                scanf("%s", course);
                findStudentsByCourse(course);
                break;
            }
            case 5:
                countStudents();
                break;
            case 6: {
                int rollNumber;
                printf("Enter roll number to delete: ");
                scanf("%d", &rollNumber);
                deleteStudent(rollNumber);
                break;
            }
            case 7: {
                int rollNumber;
                printf("Enter roll number to update: ");
                scanf("%d", &rollNumber);
                updateStudent(rollNumber);
                break;
            }
            case 8:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    struct Student newStudent;
    printf("Enter first name: ");
    scanf("%s", newStudent.firstName);
    printf("Enter last name: ");
    scanf("%s", newStudent.lastName);
    printf("Enter roll number: ");
    scanf("%d", &newStudent.rollNumber);
    printf("Enter CGPA: ");
    scanf("%f", &newStudent.cgpa);
    printf("Enter courses registered (comma-separated): ");
    scanf("%s", newStudent.courses);

    // Check for uniqueness of roll number
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == newStudent.rollNumber) {
            printf("Roll number already exists. Please enter a unique roll number.\n");
            return;
        }
    }

    students[studentCount++] = newStudent;
    printf("Student added successfully.\n");
}

void findStudentByRollNumber(int rollNumber) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Student found:\n");
            printf("Name: %s %s\n", students[i].firstName, students[i].lastName);
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("CGPA: %.2f\n", students[i].cgpa);
            printf("Courses: %s\n", students[i].courses);
            return;
        }
    }
    printf("Student not found with roll number %d.\n", rollNumber);
}

void findStudentByFirstName(char *firstName) {
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].firstName, firstName) == 0) {
            printf("Student found:\n");
            printf("Name: %s %s\n", students[i].firstName, students[i].lastName);
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("CGPA: %.2f\n", students[i].cgpa);
            printf("Courses: %s\n", students[i].courses);
            found = 1;
        }
    }
    if (!found) {
        printf("No students found with first name %s.\n", firstName);
    }
}

void findStudentsByCourse(char *course) {
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (strstr(students[i].courses, course) != NULL) {
            printf("Student found:\n");
            printf("Name: %s %s\n", students[i].firstName, students[i].lastName);
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("CGPA: %.2f\n", students[i].cgpa);
            printf("Courses: %s\n", students[i].courses);
            found = 1;
        }
    }
    if (!found) {
        printf("No students found registered in course %s.\n", course);
    }
}

void countStudents() {
    printf("Total number of students: %d\n", studentCount);
}

void deleteStudent(int rollNumber) {
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNumber) {
            found = 1;
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student with roll number %d deleted successfully.\n", rollNumber);
            break;
        }
    }
    if (!found) {
        printf("Student not found with roll number %d.\n", rollNumber);
    }
}

void updateStudent(int rollNumber) {
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNumber) {
            found = 1;
            printf("Student found. Enter new details:\n");
            printf("Enter first name: ");
            scanf("%s", students[i].firstName);
            printf("Enter last name: ");
            scanf("%s", students[i].lastName);
            printf("Enter CGPA: ");
            scanf("%f", &students[i].cgpa);
            printf("Enter courses registered (comma-separated): ");
            scanf("%s", students[i].courses);
            printf("Student details updated successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Student not found with roll number %d.\n", rollNumber);
    }
}

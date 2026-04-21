#ifndef STUDENT_H
#define STUDENT_H
void saveToFile();
void loadFromFile();

struct Student {
    int id;
    char name[50];
    float totalFees;
    float paidFees;
};

extern struct Student s[100];
extern int count;

// function declarations
void addStudent();
void displayStudent();
void payFees();
int login();
void searchStudentById();
void deleteStudent();
void sortByPendingFees();
void generateReport();

#endif
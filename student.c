#include <stdio.h>
#include "student.h"

struct Student s[100];
int count = 0;

void addStudent() {
    int n, i;

    printf("How many students you want to add: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {

        if(count > 100) {
            printf("Max limit reached!\n");
            break;
        }

        printf("\nEnter details of student %d\n", i );

        s[count].id=i;
        printf("ID= %d",s[count].id);
        
       /*printf("Enter ID: ");
        scanf("%d", &s[count].id);*/

        printf("Enter name: ");
        scanf(" %49[^\n]", s[count].name);

        printf("Enter total fees: ");
        scanf("%f", &s[count].totalFees);

        if(s[count].totalFees < 0) {
            printf("Invalid fees! \n");
            continue;
        }

        s[count].paidFees = 0;
        count++;
    }

    printf("\nSTUDENTS ADDED SUCCESSFULLY!\n");
}

void displayStudent() {
    int i;

    for(i = 0; i < count; i++) {
        printf("\nID: %d", s[i].id);
        printf("\nName: %s", s[i].name);
        printf("\nTotal Fees: %.2f", s[i].totalFees);
        printf("\nPaid Fees: %.2f", s[i].paidFees);
        printf("\nPending Fees: %.2f\n", s[i].totalFees - s[i].paidFees);
    }
}

void saveToFile() {
    FILE *fp = fopen("students.txt", "w");

    for(int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %f %f\n",
            s[i].id,
            s[i].name,
            s[i].totalFees,
            s[i].paidFees);
    }

    fclose(fp);
}

void loadFromFile() {
    FILE *fp = fopen("students.txt", "r");

    if(fp == NULL) return;

    count = 0;

    while(fscanf(fp, "%d %s %f %f",
        &s[count].id,
        s[count].name,
        &s[count].totalFees,
        &s[count].paidFees) == 4) {

        count++;
    }

    fclose(fp);
}

void searchStudentById() {
    int id, i, found = 0;

    printf("Enter student ID to search: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++) {
        if(s[i].id == id) {

            printf("\nStudent Found!\n");
            printf("ID: %d\n", s[i].id);
            printf("Name: %s\n", s[i].name);
            printf("Total Fees: %.2f\n", s[i].totalFees);
            printf("Paid Fees: %.2f\n", s[i].paidFees);
            printf("Pending Fees: %.2f\n",
                   s[i].totalFees - s[i].paidFees);

            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Student not found!\n");
    }
}

void deleteStudent() {
    int id, i, j, found = 0;

    printf("Enter student ID to delete: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++) {
        if(s[i].id == id) {

            // shift elements left
            for(j = i; j < count - 1; j++) {
                s[j] = s[j + 1];
            }

            count--;

            printf("Student deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Student not found!\n");
    }
}

void sortByPendingFees() {
    int i, j;
    struct Student temp;

    for(i = 0; i < count - 1; i++) {
        for(j = 0; j < count - i - 1; j++) {

            float pending1 = s[j].totalFees - s[j].paidFees;
            float pending2 = s[j+1].totalFees - s[j+1].paidFees;

            if(pending1 < pending2) {
                // swap
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("Students sorted by pending fees (highest first)\n");
}

void generateReport() {
    int i;
    float totalCollected = 0, totalPending = 0;

    printf("----- REPORT -----\n");

    for(i = 0; i < count; i++) {
        float pending = s[i].totalFees - s[i].paidFees;

        totalCollected += s[i].paidFees;
        totalPending += pending;
    }

    printf("Total Fees Collected: %.2f\n", totalCollected);
    printf("Total Pending Fees: %.2f\n", totalPending);

    printf("Students with Pending Fees:\n");

    for(i = 0; i < count; i++) {
        float pending = s[i].totalFees - s[i].paidFees;

        if(pending > 0) {
            printf("ID: %d | Name: %s | Pending: %.2f\n",
                   s[i].id, s[i].name, pending);
        }
    }
}

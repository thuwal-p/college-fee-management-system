#include <stdio.h>
#include "student.h"

void payFees() {
    int id, i, found = 0;
    float amount;

    printf("Enter student ID: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++) {

        if(s[i].id == id) {

            printf("\nStudent Found!\n");
            printf("Name: %s\n", s[i].name);
            printf("Total Fees: %.2f\n", s[i].totalFees);
            printf("Paid Fees: %.2f\n", s[i].paidFees);
            printf("Pending Fees: %.2f\n", s[i].totalFees - s[i].paidFees);

            printf("\nEnter the amount to pay: ");
            scanf("%f", &amount);

            if(amount <= 0) {
                printf("Invalid amount!\n");
                return;
            }

            if(s[i].paidFees + amount > s[i].totalFees) {
                printf("Amount exceeds pending fees!\n");
                return;
            }

            s[i].paidFees += amount;

            printf("\nPAYMENT SUCCESSFUL!\n");
            printf("Updated Paid Fees: %.2f\n", s[i].paidFees);
            printf("Remaining Fees: %.2f\n", s[i].totalFees - s[i].paidFees);

            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Student not found!\n");
    }
}
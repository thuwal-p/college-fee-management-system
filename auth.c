#include <stdio.h>
#include <string.h>
#include "student.h"

char savedUsername[20];
char savedPassword[20];

void registerAdmin() {
    printf("\nRegister New Admin\n");

    printf("Enter new username: ");
    scanf("%19s", savedUsername);

    printf("Enter new password: ");
    scanf("%19s", savedPassword);

    FILE *fp = fopen("admin.txt", "w");  // open file in write mode

    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "%s %s", savedUsername, savedPassword);

    fclose(fp);

    printf("Registration successful!\n");
}

int login() {
    int choice;
    char username[20], password[20];

    printf("\n1. Login\n2. Register New Admin\nEnter choice: ");
    scanf("%d", &choice);

    if(choice == 2) {
        registerAdmin();
        return 0;
    }

    FILE *fp = fopen("admin.txt", "r");

    if(fp != NULL) {
        fscanf(fp, "%s %s", savedUsername, savedPassword);
        fclose(fp);
    }
    

    printf("\nLogin\n");

    printf("Enter Username: ");
    scanf("%19s", username);

    printf("Enter Password: ");
    scanf("%19s", password);

    if(strcmp(username, savedUsername) == 0 &&
       strcmp(password, savedPassword) == 0) {

        printf("Login Successful!\n");
        return 1;
    } else {
        printf("Invalid Login!\n");
        return 0;
    }
}
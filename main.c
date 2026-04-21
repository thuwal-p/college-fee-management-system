#include <stdio.h>
#include "student.h"
int main()
{
   loadFromFile();
   if(login()){
int choice;
while(1)
 {
    printf(" FEE MANAGEMENT SYSTEM\n");
    printf(" Enter:\n");
    printf("1. Add student\n");
    printf("2. Pay fees\n");
    printf("3. Display students\n");
    printf("4. Search Student\n");
    printf("5. Delete Student\n");
    printf("6. Sorted list by pending fee\n");
    printf("7. Generate Report\n");
    printf("8. Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);


    if(choice == 1) {
    addStudent();
    saveToFile();
    }
    else if(choice == 2) {
     payFees();
    saveToFile();
 }
 else if(choice == 3) {
    displayStudent();
 }
 else if(choice == 4) {
    searchStudentById();
}
else if(choice == 5) {
    deleteStudent();
    saveToFile();  
}
else if(choice == 6) {
    sortByPendingFees();
    displayStudent();
}
else if(choice==7){
    generateReport();
}
else if(choice==8){
    break;
}
else{
    printf("Invalid choice!\n");
}
                }
return 0;
        }
}
#include <stdlib.h>
#include <stdio.h>

#define MAX_NAME_LENGTH 20
#define MAX_DEPT_NAME_LENGTH 20

struct Employee {
    int employeeID;
    char employeeName[MAX_NAME_LENGTH];
    char dept[MAX_DEPT_NAME_LENGTH];
    float salary;
};

void searchForEmployee(struct Employee *currEmployees, int numOfEmployees, int targetEmployee) {
    if (targetEmployee > numOfEmployees || targetEmployee < 0) {
        printf("Employee not in database!\n");
    } else {
        for (int i = 0; i < numOfEmployees; i++) {
            if (currEmployees[i].employeeID == targetEmployee) {
                printf("ID: %d\n", currEmployees[i].employeeID);
                printf("Name: %s\n", currEmployees[i].employeeName);
                printf("Department: %s\n", currEmployees[i].dept);
                printf("Salary: %f\n", currEmployees[i].salary);
            }
        }
    }
}

int main() {
    int numOfEmployees;
    printf("Enter the number of employees:");
    scanf("%d", &numOfEmployees);
    struct Employee *employees = malloc(numOfEmployees * sizeof(struct Employee));
    for (int i = 0; i < numOfEmployees; i++) {
        employees[i].employeeID = i + 1;
        printf("Enter the employee name:");
        scanf("%s", employees[i].employeeName);
        getchar();
        printf("Enter the employee department:");
        scanf("%s", employees[i].dept);
        getchar();
        printf("Enter the employee salary:");
        scanf("%f", &employees[i].salary);
        getchar();
    }
    searchForEmployee(employees, numOfEmployees, 2);
    return 0;
}
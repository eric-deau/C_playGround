#include <stdio.h>
#include <stdlib.h>
#define MAX_STUDENTS 30
#define MAX_STUDENT_NAME 30
#define MAX_COURSE_NAME 20
#define MAX_COURSES 2

struct studentRecords {
    int studentID;
    char studentName[MAX_STUDENT_NAME];
    char courses[MAX_COURSES][MAX_COURSE_NAME];
    char grades[MAX_COURSES];
};

void writeToFile(int numberOfStudents, struct studentRecords *studentRecord) {
    FILE* fp = fopen("student_records.txt", "w");
    if (fp == NULL) {
        printf("File can't be opened!");
        return;
    }
    for (int i = 0; i < numberOfStudents; i++) {
        fprintf(fp, "Student ID: %d\n", studentRecord[i].studentID);
        fprintf(fp, "Student Name: %s\n", studentRecord[i].studentName);
        fprintf(fp, "%s", "Courses and Grades :\n");
        for (int k = 0; k < MAX_COURSES; k++) {
            fprintf(fp, "%s: %c\n", studentRecord[i].courses[k], studentRecord[i].grades[k]);
        }
    }
    fclose(fp);
}

int main() {
    int numOfStudents = 0;

    printf("Enter the number of students: \n");
    scanf("%d", &numOfStudents);
    getchar();
    if (numOfStudents <= 0 || numOfStudents > MAX_STUDENTS) {
        printf("Invalid number of students!\n");
        return -1;
    }

    struct studentRecords *records_1 = malloc(numOfStudents * sizeof(struct studentRecords));

    for (int i = 0; i < numOfStudents; i++) {
        records_1[i].studentID = i + 1;
        printf("Enter a student's name:");
        scanf("%49s", records_1[i].studentName);
        getchar();
        for (int j = 0; j < MAX_COURSES; j++) {
            printf("Type \"q\" to quit. Enter a student's course:");
            scanf("%49s", records_1[i].courses[j]);
            printf("Enter their grade: \n");
            scanf(" %c", &records_1[i].grades[j]);
        }
    }
    writeToFile(numOfStudents, records_1);
    return 0;
}
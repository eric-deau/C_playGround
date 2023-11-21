#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int lookForIndex(int element, int arr[], int size){
    for(int i=0;i<size;i++){
        if (arr[i] == element){
            return i;
        }
    }
    return -1;
}

void reverseArray(int arr[], int size){
    int temp;
    int index = 0;
//    int ptr = 0;
    for (int i=size-1;i>=size/2;i--){
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
        index++;
//        arr[i] = arr[temp];
//        temp++;
    }
}

void removeDuplicate(int arr[], int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<=size;j++){
            if(arr[i] == arr[j]){
                arr[j] = 0;
            }
        }
    }
}

int secondLargest(int arr[], int size){
    int largest = 0;
    int secondLargest = 0;
    for (int i=0; i<=size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    for (int j=0; j <= size;j++) {
        if (secondLargest < arr[j] && arr[j] != largest){
            secondLargest = arr[j];
        }
    }
    return secondLargest;
}

int countVowels(char arr[]) {
    int count = 0;
    for (int i=0; arr[i] != '\0'; i++){
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u'){
            count++;
        }
    }
    return count;
}

bool isPalindrome(const char arr[]) {
    int start = 0;
    int end = strlen(arr) - 1;
    while (start < end) {
        if (arr[start] != arr[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool searchKeyword(const char *text, const char *keyword) {
    int textLen = strlen(text);
    int keywordLen = strlen(keyword);

    for (int i = 0; i <= textLen - keywordLen; i++) {
        int j;

        // Check if the keyword matches at the current position
        for (j = 0; j < keywordLen; j++) {
            if (text[i + j] != keyword[j]) {
                break;
            }
        }

        if (j == keywordLen) {
            return true; // Keyword found
        }
    }

    return false; // Keyword not found
}

bool wordSearch(char *fileName, char *target) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Could not open this file for reading.\n");
        return false;
    }
    char line[1000];
    while (fgets(line, sizeof(line), file)) {
//        if (strstr(line, target) != NULL) {
//            fclose(file);
//            return 1;
//        }
        if (searchKeyword(line, target) != NULL) {
            fclose(file);
            return true;
        }
    }
    return false;
}


void populateArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter a number: \n");
        scanf("%d", &arr[i]);
    }
}

int wordCount(char *fileName) {
    int count = 0;
    int inWord = 0;
    char ch;
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Could not open this file for reading. \n");
        return false;
    }
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == ' ' || ch == '\n') {
            if (inWord) {
                // We were inside a word, and we found a space character.
                inWord = 0;
            }
        } else {
            // We found a non-space character.
            if (!inWord) {
                // We were not inside a word, so we're starting a new word.
                count++;
                inWord = 1;
            }
        }
    }

//    if (ch == ' ' || ch == '\n' || ch == EOF) {
//        count++;
//    }
    fclose(fp);
    return count;
}

int wordFrequency(char *fileName, char *target) {
    FILE *fp = fopen(fileName, "r");
    int count = 0;
    int index = 0;
    char arr[strlen(target) + 1];
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch != ' ') {
            arr[index] = ch;
            index++;
            if (index == strlen(target)) {
                arr[index + 1] = '\0';
                if (strcmp(arr, target) == 0) {
                    count++;
                } else {
                    for (int i = 0; i < strlen(arr); i++) {
                        arr[i] = ' ';
                    }
                    index = 0;
                }
            }
        } else {
            for (int i = 0; i < strlen(arr); i++) {
                arr[i] = ' ';
            }
            index = 0;
        }
    }
    printf("count: %d\n", count);
    fclose(fp);
    return count;
}

void reverseWord(char *word) {
    for (int i = strlen(word) - 1; i >= 0; i--) {
        printf("%c", word[i]);
    }
    printf("\n");
}

void reverseSentence(char *sentence) {
//    int sentenceLen = strlen(sentence);
    int indexFlag = strlen(sentence);
    for (int i = strlen(sentence); i >= 0; i--) {
        if (i == 0 || sentence[i] == ' ') {
            if (i == 0) {
                printf("%c", sentence[i]);
            }
            for (int j = i + 1; j < indexFlag; j++) {
                printf("%c", sentence[j]);
            }
            printf(" ");
            indexFlag = i;
        }
    }
    printf("\n");
}


void eachWordFrequency(char *fileName) {
    FILE* file = fopen(fileName, "r");
    char wordArray[500][100] = {'\0'};
    int counterArray[500] = {0};
    int max_value = 0;
    int max_index = -1;
    char temp_word[100];
    if (file != NULL) {
        while (fscanf(file, "%s", temp_word) != EOF) {
            int wordExists = 0;
            for (int i = 0; i < 500; i++) {
                if (strcmp(temp_word, wordArray[i]) == 0) {
                    counterArray[i] += 1;
                    wordExists = 1;
                    if (counterArray[i] > max_value) {
                        max_value = counterArray[i];
                        max_index = i;
                    }
                    break;
                }
            }
            if (!wordExists) {
                // If the word doesn't exist in wordArray, add it and set the count to 1
                for (int i = 0; i < 500; i++) {
                    if (wordArray[i][0] == '\0') {
                        strcpy(wordArray[i], temp_word);
                        counterArray[i] = 1;
                        break;
                    }
                }
            }
        }
    }
    if (max_index != -1){
        printf("%s %d", wordArray[max_index], max_value);
    }
}


#define MAX_WORD_LENGTH 100
#define MAX_WORD 500
struct wordCounter {
    char string[MAX_WORD_LENGTH];
    int occurrence;
};

void structWordFreq(char *fileName) {
    FILE* file = fopen("hello.txt", "r");
    struct wordCounter counterArray[MAX_WORD];
    int numberOfValidWord = 0;
    char temp_word[MAX_WORD_LENGTH];

    if (file != NULL) {
        while (fscanf(file, "%s", temp_word) != EOF) {
            int wordExists = 0;
            for (int i = 0; i < numberOfValidWord; i++) {
                if (strcmp(temp_word, counterArray[i].string) == 0) {
                    counterArray[i].occurrence++;
                    wordExists = 1;
                    break;
                }
            }
            if (!wordExists && numberOfValidWord < MAX_WORD) {
                strcpy(counterArray[numberOfValidWord].string, temp_word);
                counterArray[numberOfValidWord].occurrence = 1;
                numberOfValidWord++;
            }
        }
        fclose(file);
        for (int i = 0; i < numberOfValidWord; i++) {
            printf("%s, %d\n", counterArray[i].string, counterArray[i].occurrence);
        }
    }
}

int countDigits(int n) {
    if (n < 0) {
        n = -n;
    }
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return n;
    } else if (n < 10) {
        return 1;
    }
    return 1 + countDigits(n / 10);
}

//int main() {
//    // 2023-11-06 practice
////    int result = wordCount("test.txt");
////    printf("%d\n", result);
//    int wordFreq = wordFrequency("test.txt", "eric");
//    printf("%d\n", wordFreq);
//
//    reverseWord("ofdsahbfdasuo");
//    reverseSentence("Hello my name is");
//
//    int count = countDigits(-9);
//    printf("count: %d\n", count);
//
//    // 2023-10-16 Practice
//
//    // Prompt user for array and elements
////    int arrSize;
////    printf("Enter the size of the array: \n");
////    scanf("%d", &arrSize);
////    int numArr[arrSize];
////    populateArray(numArr, arrSize);
////    printf("Before: \n");
////    for (int i = 0; i < arrSize; i++) {
////        printf("%d ", numArr[i]);
////    }
////    printf("\n");
////    reverseArray(numArr, arrSize);
////    printf("After: \n");
////    for (int i = 0; i < arrSize; i++) {
////        printf("%d ", numArr[i]);
////    }
////    printf("\n");
//    // Palindrome Checker
////    char palindrome[20];
////    printf("Please enter a palindrome.\n");
////    scanf("%s", palindrome);
////    if (isPalindrome(palindrome)) {
////        printf("This is a palindrome!\n");
////    } else {
////        printf("This is not a palindrome.\n");
////    }
//
//// Look for specific word in file
////    if (wordSearch("test.txt", "hello")) {
////        printf("Target found!\n");
////    } else {
////        printf("Target not found!\n");
////    }
//
//    // Exercise Week 3
////    char firstName[20];
////    char lastName[20];
////    printf("Please enter your full name.\n");
////    scanf("%s %s", firstName, lastName);
////    printf("Hello %s, your last name is %s.\n", firstName, lastName);
////    return 0;
//
////    int numArr[] = {1, 2, 3, 4, 5, 6};
////    int size = 5;
////    int element = 4;
////    int index = lookForIndex(element, numArr, size);
////    printf("The index is: %d", index);
//
////    int numArr[] = {1, 2, 3, 4, 5, 6};
////    int size = 6;
////    printf("Before: \n");
////    for (int j=0;j<size;j++){
////        printf("%d ", numArr[j]);
////    }
////    printf("\n");
////    reverseArray(numArr, size);
////    printf("After: \n");
////    for (int k=0;k<size;k++){
////        printf("%d ", numArr[k]);
////    }
//
////    int numArr[] = {1, 2, 2, 2, 5, 6};
////    int size = 5;
////    printf("Before: \n");
////    for (int j=0;j<=size;j++){
////        printf("%d ", numArr[j]);
////    }
////    removeDuplicate(numArr, size);
////    printf("After: \n");
////    for (int k=0;k<=size;k++){
////        printf("%d", numArr[k]);
////    }
//
////    int numArr[] = {1, 2, 6, 68, 69, 6};
////    int size = 5;
////    int num = secondLargest(numArr, size);
////    printf("%d\n", num);
//
////    char charStr[] = "voooooooooooooooowel!";
////    int num = countVowels(charStr);
////    printf("%d\n", num);
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#define MAX_STUDENTS 30
//#define MAX_STUDENT_NAME 30
//#define MAX_COURSE_NAME 20
//#define MAX_COURSES 2
//
//struct studentRecords {
//    int studentID;
//    char studentName[MAX_STUDENT_NAME];
//    char courses[MAX_COURSES][MAX_COURSE_NAME];
//    char grades[MAX_COURSES];
//};
//
//int main() {
//    int numOfStudents = 0;
//
//    printf("Enter the number of students: \n");
//    scanf("%d", &numOfStudents);
//    getchar();
//    if (numOfStudents <= 0 || numOfStudents > MAX_STUDENTS) {
//        printf("Invalid number of students!\n");
//        return -1;
//    }
//
//    struct studentRecords *records_1 = malloc(numOfStudents * sizeof(struct studentRecords));
//
//    for (int i = 0; i < numOfStudents; i++) {
//        records_1[i].studentID = i + 1;
//        printf("Enter a student's name:");
//        scanf("%49s", records_1[i].studentName);
//        getchar();
//        for (int j = 0; j < MAX_COURSES; j++) {
//            printf("Type \"q\" to quit. Enter a student's course:");
//            scanf("%49s", records_1[i].courses[j]);
//            printf("Enter their grade: \n");
//            scanf(" %c", &records_1[i].grades[j]);
//        }
//    }
//
//    for (int j = 0; j < numOfStudents; j++) {
//        printf("Student ID: %d\n", records_1[j].studentID);
//        printf("Student name: %s\n", records_1[j].studentName);
//        for (int k = 0; k < MAX_COURSES; k++) {
//            printf("Course: %s Grade: %c\n", records_1[j].courses[k], records_1[j].grades[j]);
//        }
//    }
//    return 0;
//}

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

//    while ((ch = fgetc(fp)) != EOF) {
//        printf("count: %d, char: %c\n", count, ch);
//        if (ch == ' ' || ch == '\n') {
//            count++;
//        }
//    }

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

int main() {
    int result = wordCount("test.txt");
    printf("%d\n", result);
    // 2023-10-16 Practice

    // Prompt user for array and elements
//    int arrSize;
//    printf("Enter the size of the array: \n");
//    scanf("%d", &arrSize);
//    int numArr[arrSize];
//    populateArray(numArr, arrSize);
//    printf("Before: \n");
//    for (int i = 0; i < arrSize; i++) {
//        printf("%d ", numArr[i]);
//    }
//    printf("\n");
//    reverseArray(numArr, arrSize);
//    printf("After: \n");
//    for (int i = 0; i < arrSize; i++) {
//        printf("%d ", numArr[i]);
//    }
//    printf("\n");
    // Palindrome Checker
//    char palindrome[20];
//    printf("Please enter a palindrome.\n");
//    scanf("%s", palindrome);
//    if (isPalindrome(palindrome)) {
//        printf("This is a palindrome!\n");
//    } else {
//        printf("This is not a palindrome.\n");
//    }

// Look for specific word in file
//    if (wordSearch("test.txt", "hello")) {
//        printf("Target found!\n");
//    } else {
//        printf("Target not found!\n");
//    }

    // Exercise Week 3
//    char firstName[20];
//    char lastName[20];
//    printf("Please enter your full name.\n");
//    scanf("%s %s", firstName, lastName);
//    printf("Hello %s, your last name is %s.\n", firstName, lastName);
//    return 0;

//    int numArr[] = {1, 2, 3, 4, 5, 6};
//    int size = 5;
//    int element = 4;
//    int index = lookForIndex(element, numArr, size);
//    printf("The index is: %d", index);

//    int numArr[] = {1, 2, 3, 4, 5, 6};
//    int size = 6;
//    printf("Before: \n");
//    for (int j=0;j<size;j++){
//        printf("%d ", numArr[j]);
//    }
//    printf("\n");
//    reverseArray(numArr, size);
//    printf("After: \n");
//    for (int k=0;k<size;k++){
//        printf("%d ", numArr[k]);
//    }

//    int numArr[] = {1, 2, 2, 2, 5, 6};
//    int size = 5;
//    printf("Before: \n");
//    for (int j=0;j<=size;j++){
//        printf("%d ", numArr[j]);
//    }
//    removeDuplicate(numArr, size);
//    printf("After: \n");
//    for (int k=0;k<=size;k++){
//        printf("%d", numArr[k]);
//    }

//    int numArr[] = {1, 2, 6, 68, 69, 6};
//    int size = 5;
//    int num = secondLargest(numArr, size);
//    printf("%d\n", num);

//    char charStr[] = "voooooooooooooooowel!";
//    int num = countVowels(charStr);
//    printf("%d\n", num);
    return 0;
}

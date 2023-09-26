#include <stdio.h>

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
    for (int i=size;i>size/2;i--){
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

int main() {
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
//    int size = 5;
//    printf("Before: \n");
//    for (int j=0;j<=size;j++){
//        printf("%d ", numArr[j]);
//    }
//    reverseArray(numArr, size);
//    printf("After: \n");
//    for (int k=0;k<=size;k++){
//        printf("%d", numArr[k]);
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

    int numArr[] = {1, 2, 6, 2, 5, 6};
    int size = 5;
    int num = secondLargest(numArr, size);
    printf("%d\n", num);
    return 0;
}

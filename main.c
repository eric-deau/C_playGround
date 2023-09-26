#include <stdio.h>

int lookForIndex(int element, int arr[], int size){
    for(int i=0;i<size;i++){
        if (arr[i] == element){
            return i;
        }
    }
    return -1;
}

int main() {
    // Exercise Week 3
//    char firstName[20];
//    char lastName[20];
//    printf("Please enter your full name.\n");
//    scanf("%s %s", firstName, lastName);
//    printf("Hello %s, your last name is %s.\n", firstName, lastName);
//    return 0;
    int numArr[] = {1, 2, 3, 4, 5, 6};
    int size = 5;
    int element = 4;
    int index = lookForIndex(element, numArr, size);
    printf("The index is: %d", index);
}

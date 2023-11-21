#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME_LENGTH 20
#define MAX_TITLE_LENGTH 30

struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_NAME_LENGTH];
    int pages;
};

void printBooks(struct Book *currBooks, int numBooks) {
    for (int j = 0; j < numBooks; j++) {
        printf("Title: %s Author: %s Pages: %d\n", currBooks[j].title, currBooks[j].author, currBooks[j].pages);
    }
}

int main() {
    int numOfBooks;
    printf("Enter the number of books:\n");
    scanf("%d", &numOfBooks);
    struct Book *books = (struct Book*)malloc(numOfBooks * sizeof(struct Book));
    if (books == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }
    for (int i = 0; i < numOfBooks; i++) {
        printf("Enter the book title:");
        scanf("%s", books[i].title);
        getchar();
        printf("Enter the author name:");
        scanf("%s", books[i].author);
        getchar();
        printf("Enter the number of pages:");
        scanf("%d", &books[i].pages);
        getchar();
    }
    printBooks(books, numOfBooks);
    free(books);
    return 0;
}
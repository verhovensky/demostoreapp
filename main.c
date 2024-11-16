#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct book
{
    int id;
    char title[50];
    char author[50];
    float price;
};

void addbook();
bool getbook();
bool deletebook();
void mainmenu();
struct book *allbooks();

struct book books[1000];
int BooksIndex = 0;

struct book *allbooks()
{
    for (int i = 0; i < BooksIndex; i++)
    {
        printf("Book id: %d\n", books[i].id);
        printf("Book title: %s\n", books[i].title);
        printf("Book author: %s\n", books[i].author);
        printf("Book price: %f\n", books[i].price);
        printf("\n");
    }
    return books;
}

void addbook()
{
    if (BooksIndex == 1000)
    {
        // Memory safety ))
        printf("Book store is full\n");
        printf("Please delete some books or restart the program\n");
        mainmenu();
    }
    struct book newbook;
    printf("Enter book title: \n");
    scanf("%s", newbook.title);
    printf("Enter book author: \n");
    scanf("%s", newbook.author);
    printf("Enter book price: \n");
    scanf("%f", &newbook.price);
    int newId = BooksIndex + 1;
    printf("Book id will be: %d\n", newId);
    newbook.id = newId;
    books[BooksIndex] = newbook;
    BooksIndex++;
    mainmenu();
}

bool deletebook()
{
    printf("Enter book id: ");
    int id;
    scanf("%d", &id);
    for (int i = 0; i < BooksIndex; i++)
    {
        if (books[i].id == id)
        {
            for (int j = i; j < BooksIndex - 1; j++)
            {
                books[j] = books[j + 1];
            }
            BooksIndex--;
            printf("Book deleted successfully\n");
            return true;
        }
    }
    printf("Book not found\n");
    return false;
}

bool updatebook()
{
    printf("Enter book id: ");
    int id;
    scanf("%d", &id);
    for (int i = 0; i < BooksIndex; i++)
    {
        if (books[i].id == id)
        {
            printf("Enter book title: \n");
            scanf("%s", books[i].title);
            printf("Enter book author: \n");
            scanf("%s", books[i].author);
            printf("Enter book price: \n");
            scanf("%f", &books[i].price);
            printf("Book updated successfully\n");
            return true;
        }
    }
    printf("Book not found\n");
    return false;
}

bool getbook()
{
    printf("Enter book id: ");
    int id;
    scanf("%d", &id);
    for (int i = 0; i < BooksIndex; i++)
    {
        if (books[i].id == id)
        {
            printf("Book title: %s\n", books[i].title);
            printf("Book author: %s\n", books[i].author);
            printf("Book price: %f\n", books[i].price);
            printf("\n");
            return true;
        }
    }
    printf("Book not found\n");
    return false;
}

void mainmenu()
{
    printf("You have the following options:\n");
    printf("1. Add Book\n");
    printf("2. View All Books\n");
    printf("3. Delete Book\n");
    printf("4. Update Book\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        addbook();
        mainmenu();
    case 2:
        allbooks();
        mainmenu();
    case 3:
        deletebook();
        mainmenu();
    case 4:
        updatebook();
        mainmenu();
    case 5:
        printf("Exiting...\n");
        exit(0);
    default:
        printf("Invalid choice\n");
        mainmenu();
    }
}

void main()
{
    printf("Welcome to Book Store\n");
    mainmenu();
}
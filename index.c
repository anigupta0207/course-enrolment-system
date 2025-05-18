#include <stdio.h>
#include <stdlib.h>
#include "Str.c"
#include "Authentication.c"
#include "course.c"
#include "Filemanger.c"
#include "delete.c"
int main()
{
    int choice, rest;

    printf("\n1. Register\n2. Login\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        rest = registeruser();
        break;
    case 2:
        rest = loginUser();
        break;
    case 3:
        printf("Exiting...\n");
        exit(0);
    default:
        printf("Invalid choice! Please try again.\n");
    }

    if (rest != 1)
    {
        printf("customer 101 signigfication error (bye bye !)");
    }
    printf("\n\t\t\t\t\tWelcome to the course enrolment System !\n");

    int nn = 1;
    while (nn)
    {
        printf(" 1.for adding user  \n 2.for deleting user \n 3. reading detail \n 4. editing detail\n 5. exit \n");
        printf("\nEnter your choice:\n ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            InputTaker();
            break;

        case 2:
            delete_user();
            break;

        case 3:
            read();
            break;

        case 4:
            edit();
            break;

        case 5:
            nn = 0;
            break;

        default:
            printf("invalid choice");
            break;
        }
    }
    printf("\n\t\t\t\t\t\t\t\t thank you for visting our sitie");
    return 0;
}
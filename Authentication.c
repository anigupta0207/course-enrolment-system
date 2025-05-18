#include <stdlib.h>
#include <stdio.h>
int loginUser()
{
        FILE *ptr;
        char username[25];
        char password[25];
        char sUsername[25];
        char sPassword[25];
        int found =0 ;     

        printf("Welcome to the login page \n");
        ptr = fopen("pssword.txt", "r");

        if (ptr == NULL) {
            printf("Error: Could not open file.\n");
            return -1; 
        }

        printf("enter the username ");
        scanf("%s", username);
        printf("enter the password ");
        scanf("%s", password);

        while (fscanf(ptr, "%s %s", sUsername, sPassword) != EOF)
        {
                if (strc( username,sUsername) == 1 && strc(password, sPassword) == 1)
                {
                       found =1;
                       break;
                }
        }
        fclose(ptr);
        
        if ( found ==0 )
        {
                printf("Invalid user or password retry ");
        }
        else 
        printf("\t\t\t\t\t\twelcome!!!");
        return found ; 
}


int registeruser() {
    FILE *ptr;
    char username[25];
    char password[25];

    ptr = fopen("pssword.txt", "a");
    if (ptr == NULL) {
        printf("Error: Could not open file.\n");
        return 0;
    }

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    fprintf(ptr, "\n%s %s", username, password);
    fclose(ptr);
    printf("User registered successfully!\n");
    return 1;
}
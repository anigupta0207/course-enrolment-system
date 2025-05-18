#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void registerUser() {
    FILE *ptr;
    char username[25];
    char password[25];

    ptr = fopen("pssword.txt", "a");
    if (ptr == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    fprintf(ptr, "%s %s\n", username, password);
    fclose(ptr);
    printf("User registered successfully!\n");
}

void loginUser() {
    FILE *ptr;
    char username[25];
    char password[25];
    char storedUsername[25];
    char storedPassword[25];
    int found = 0;

    ptr = fopen("pssword.txt", "r");
    if (ptr == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    while (fscanf(ptr, "%s %s", storedUsername, storedPassword) != EOF) {
        if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
            found = 1;
            break;
        }
    }

    fclose(ptr);

    if (found) {
        printf("Login successful! Welcome, %s.\n", username);
    } else {
        printf("Invalid username or password.\n");
    }
}

void readPasswords() {
    FILE *ptr;
    char username[25];
    char password[25];

    ptr = fopen("pssword.txt", "r");
    if (ptr == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    printf("Stored usernames and passwords:\n");
    while (fscanf(ptr, "%s %s", username, password) != EOF) {
        printf("Username: %s, Password: %s\n", username, password);
    }

    fclose(ptr);
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Register\n2. Login\n3. View Stored Passwords\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                readPasswords();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
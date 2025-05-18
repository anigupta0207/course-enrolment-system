#include <stdio.h>
void delete_user() {
    int del_roll, found = 0;
    printf("Enter the roll number to delete: ");
    scanf("%d", &del_roll);

    FILE *ptr = fopen("user.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (ptr == NULL || temp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    char name[25];
    int roll;
    char course[50];

    while (fscanf(ptr, "Name: %24[^,], Roll: %d, Course: %49[^\n]\n", name, &roll, course) == 3) {
        if (roll == del_roll) {
            found = 1;
            continue;
        }
        fprintf(temp, "Name: %s, Roll: %d, Course: %s\n", name, roll, course);
    }

    fclose(ptr);
    fclose(temp);

    remove("user.txt");
    rename("temp.txt", "user.txt");

    if (found)
        printf("Record with roll number %d deleted successfully.\n", del_roll);
    else
        printf("No record found for roll number %d.\n", del_roll);
}
#include <stdio.h>
#include <string.h>

int InputTaker()
{
    FILE *ptr;
    char name[25];
    int roll;
    char course[50];

    ptr = fopen("user.txt", "a");
    if (ptr == NULL)
    {
        printf("Error: Could not open file.\n");
        return 0;
    }

    printf("Enter student name: ");
    fgets(name, 25, stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Enter roll number: ");
    scanf("%d", &roll);
    getchar();
    printf("Enter course: ");
    fgets(course, 50, stdin);

    fprintf(ptr, "Name: %s, Roll: %d, Course: %s\n", name, roll, course);
    fclose(ptr);

    printf("Student record saved successfully.\n");
}

void read()
{
    printf("\nWelcome to the read mode\n");

    int no;
    printf("Enter the unique number publish by college!");
    scanf("%d", &no);

    FILE *ptr;
    ptr = fopen("user.txt", "a+");
    char name[25];
    int roll;
    char course[50];
    int found = 0;
    while (fscanf(ptr, "Name: %24[^,], Roll: %d, Course: %49[^\n]\n", name, &roll, course) == 3)
    {
        if (roll == no)
        {
            printf("Record found:\nName: %s\nRoll: %d\nCourse: %s\n", name, roll, course);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("No record found for roll number %d\n", no);
    }
    fclose(ptr);
}

void edit()
{
    int edit_roll, found = 0;
    printf("Enter the roll number to edit: ");
    scanf("%d", &edit_roll);
    getchar();

    FILE *ptr = fopen("user.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (ptr == NULL || temp == NULL)
    {
        printf("Error: Could not open file.\n");
        return;
    }

    char name[25], course[50];
    int roll;

    while (fscanf(ptr, "Name: %24[^,], Roll: %d, Course: %49[^\n]\n", name, &roll, course) == 3)
    {
        if (roll == edit_roll)
        {
            found = 1;
            printf("Editing record for Roll: %d\n", roll);
            printf(" welcome %s \n ", name);
            printf("Enter new course: ");
            fgets(course, 50, stdin);
            course[strcspn(course, "\n")] = 0;
            fprintf(temp, "Name: %s, Roll: %d, Course: %s\n", name, roll, course);
        }
        else
        {
            fprintf(temp, "Name: %s, Roll: %d, Course: %s\n", name, roll, course);
        }
    }

    fclose(ptr);
    fclose(temp);

    remove("user.txt");
    rename("temp.txt", "user.txt");

    if (found)
        printf("Record with roll number %d edited successfully.\n", edit_roll);
    else
        printf("No record found for roll number %d.\n", edit_roll);
}
#include<stdio.h>
void courses()
{
 FILE *ptr;
 ptr= fopen("course.txt","r");
 char ch;
  if (ptr == NULL) {             
        printf("Error: Could not open file.\n");
        return;
    }
 while((ch = fgetc(ptr)) != EOF)
 {
    printf("%c",ch);
 }
 fclose(ptr);
}
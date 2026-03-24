#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
typedef struct{
    char iD[20];
    char name[50];
    float gpa;
}Student;
void addRecord();
void searchRecord();
void deleteRecord();
void displayRecords();
void updateRecords();
void toUpper(char str[]);
int main()
{
    int choice;
    while(1)
    {
        printf("\n---STUDENT RECORD SYSTEM---");
        printf("\n1. Add record \n2. Search record \n3. Delete record \n4. Display records \n5. Update records \n6. Exit");
        printf("\nSelect your choice,(1,2,3,4,5,6): ");
        scanf(" %d", &choice);
        getchar();
        if (choice == 6)
        {
            printf("\nYou existed the system successfully, welcome again.\n");
            break;
        }
        switch(choice)
        {
            case 1: addRecord(); break;
            case 2: searchRecord(); break;
            case 3: deleteRecord(); break;
            case 4: displayRecords(); break;
            case 5: updateRecords(); break;
            default: printf("Invalid choice, try again!");
        }
    }
    return 0;
}
void addRecord()
{
    Student s, temp;
    int isDuplicate = 0;
    FILE *studrecordsfile = fopen("studrecords.dat", "ab+");
    if (studrecordsfile == NULL)
    {
        printf("Error opening file!");
        return;
    }
    printf("Enter student's ID: ");
    scanf("%s", s.iD);
    toUpper(s.iD);
    rewind(studrecordsfile);
    while(fread(&temp, sizeof(Student), 1, studrecordsfile))
    {
        if(strcmp(temp.iD, s.iD) == 0)
        {
            isDuplicate = 1;
            break;
        }
    }
    if(isDuplicate)
    {
        printf("ERROR: Student ID %s already exists, try a different ID.\n", s.iD);
        fclose(studrecordsfile);
        return;
    }
    getchar();
    printf("Enter student's name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0;
    printf("Enter student's gpa: ");
    scanf("%f", &s.gpa);
    fwrite(&s, sizeof(Student), 1, studrecordsfile);
    fclose(studrecordsfile);
    printf("Record added successfully!\n");
}
void searchRecord()
{
    Student s;
    int found = 0;
    char targetID[20];
    FILE *studrecordsfile = fopen("studrecords.dat", "rb");
    if (studrecordsfile == NULL)
    {
        printf("Error opening file!");
        return;
    }
    printf("\nEnter the student's ID you wish to search for: ");
    scanf("%s", targetID);
    toUpper(targetID);
    while(fread(&s, sizeof(Student), 1, studrecordsfile))
    {
        if(strcmp(targetID, s.iD) == 0)
        {
            found = 1;
            break;
        }
    }
    fclose(studrecordsfile);
    if(found)
    {
        printf("\n<< RECORD FOUND >>\n");
        printf("%-10s %-20s %-5s", "ID", "Name", "GPA");
        printf("\n");
        printf("%-10s %-20s %.2f\n", s.iD, s.name, s.gpa);
    }
    else
    {
        printf("Record of ID %s was not found!", targetID);
    }
}
void deleteRecord()
{
    Student s;
    int found = 0;
    char targetID[20];
    FILE *studrecordsfile = fopen("studrecords.dat", "rb");
    FILE *ftemp = fopen("temp.dat", "wb");
    if (studrecordsfile == NULL)
    {
        printf("Error opening file!");
        return;
    }
    printf("Enter student's ID to delete: ");
    scanf("%s", targetID);
    toUpper(targetID);
    while(fread(&s, sizeof(Student), 1, studrecordsfile))
    {
        if(strcmp(s.iD, targetID) != 0)
        {
            fwrite(&s, sizeof(Student), 1, ftemp);
        }
        else
        {
            found = 1;
        }
    }
    fclose(studrecordsfile);
    fclose(ftemp);
    if  (found)
    {
        remove("studrecords.dat");
        rename("temp.dat", "studrecords.dat");
        printf("Record deleted successfully!\n");
    }
    else
    {
        remove("temp.dat");
        printf("Student ID NOT FOUND!\n");
    }
}
void displayRecords()
{
    Student s;
    FILE *studrecordsfile = fopen("studrecords.dat", "rb");
    if (studrecordsfile == NULL)
    {
        printf("Error opening file! No records yet.\n");
        return;
    }
    printf("\n<< STUDENT RECORD SYSTEM DISPLAY >>\n");
    printf("\n%-10s %-20s %-5s", "ID", "Name", "Gpa");
    printf("\n");
    while(fread(&s, sizeof(Student), 1, studrecordsfile) == 1)
    {
        printf("%-10s %-20s %.2f\n", s.iD, s.name, s.gpa);
    }
    fclose(studrecordsfile);
}
void updateRecords()
{
    Student s;
    int found = 0;
    char targetID[20];
    FILE *studrecordsfile = fopen("studrecords.dat", "rb+");
    if (studrecordsfile == NULL)
    {
        printf("Error opening file!");
        return;
    }
    printf("\nEnter the student's ID you wish to update his/her GPA: ");
    scanf("%s", targetID);
    toUpper(targetID);
    while(fread(&s, sizeof(Student), 1, studrecordsfile))
    {
        if(strcmp(targetID, s.iD) == 0)
        {
            found = 1;
            printf("\n%.2f is the old GPA, enter new GPA: ", s.gpa);
            scanf("%f", &s.gpa);
            fseek(studrecordsfile, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, studrecordsfile);
            printf("Record updated successfully!\n");
        }
    }
    if(!found)
    {
        printf("Record NOT FOUND!\n");
    }
    fclose(studrecordsfile);
}
void toUpper(char str[])
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]);
    }
}

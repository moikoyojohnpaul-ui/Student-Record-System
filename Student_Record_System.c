#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char iD[20];
    char name[50];
    float gpa;
}Student;
void addRecord();
void searchRecord();
void deleteRecord();
void displayRecords();
int main()
{
    int choice;
    while(1)
    {
        printf("\n---STUDENT RECORD SYSTEM---");
        printf("\n1. Add record \n2. Search record \n3. Delete record \n4. Display records \n5. Exit\n");
        printf("Select your choice,(1,2,3,4,5): ");
        scanf(" %d", &choice);
        getchar();
        if (choice == 5)
        {
            printf("You existed the system successfully, welcome again.");
            break;
        }
        switch(choice)
        {
            case 1: addRecord(); break;
            case 2: searchRecord(); break;
            case 3: deleteRecord(); break;
            case 4: displayRecords(); break;
            default: printf("Invalid choice, try again!");
        }
    }
    return 0;
}
void addRecord()
{
    Student s;
    FILE *studrecordsfile = fopen("studrecords.dat", "ab");
    if (studrecordsfile == NULL)
    {
        printf("Error opening file!");
        return;
    }
    printf("Enter student's ID: ");
    scanf("%s", s.iD);
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
    printf("Feature coming up soon...\n");
}
void deleteRecord()
{
    printf("Feature coming up soon...\n");
}
void displayRecords()
{
    Student s;
    FILE *studrecordsfile = fopen("studrecords.dat", "rb");
    if (studrecordsfile == NULL)
    {
        printf("Error opening file! No records yet.");
        return;
    }
    printf("<< STUDENT RECORD SYSTEM DISPLAY >>")
    printf("\n%-10s %-20s %-5s", "ID", "Name", "Gpa");
    printf("\n");
    while(fread(&s, sizeof(Student), 1, studrecordsfile) == 1)
    {
        printf("%-10s %-20s %.2f\n", s.iD, s.name, s.gpa);
    }
    fclose(studrecordsfile);
}

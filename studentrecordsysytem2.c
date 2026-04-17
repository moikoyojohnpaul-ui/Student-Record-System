#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node
{
    char studName[50];
    int studID;
    int studMarks;
    struct Node *next;
}Node;
void enterRecords(Node **head);
void deleteRecord(Node **head, int ID);
void updateRecord(Node **head, int ID);
void diplayRecords(Node **head);
int main()
{
    int choice, ID;
    Node *head = NULL;
    while(1)
    {
        printf("\n------------------------------------\n");
        printf("\tSAMPLE STUDENT RECORD SYSTEM\n");
        printf("------------------------------------\n");
        printf("1. Enter record.\n");
        printf("2. Delete record.\n");
        printf("3. Update record.\n");
        printf("4. Display records.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        if (choice == 5)
        {
            printf("Exiting Program, Goodbye!\n");
            return 0;
        }
        switch(choice)
        {
            case 1:
            enterRecords(&head);
            break;
            case 2:
            printf("Enter Student ID to delete: ");
            scanf("%d", &ID);
            deleteRecord(&head, ID);
            break;
            case 3:
            printf("Enter Student ID to update: ");
            scanf("%d", &ID);
            updateRecord(&head, ID);
            break;
            case 4:
            diplayRecords(&head);
            break;
            default:
            printf("Invalid choice (1 - 5), try again!\n");
        }
    }
    return 0;
}
void enterRecords(Node **head)
{
    Node *newStud = (Node *)malloc(sizeof(Node));
    if (newStud == NULL)
    {
        perror("Could Not allocate memory!\n");
        return;
    }
    printf("Enter student name: ");
    fgets(newStud->studName, sizeof(newStud->studName), stdin);
    newStud->studName[strcspn(newStud->studName, "\n")] = '\0';
    printf("Enter student ID: ");
    scanf("%d", & newStud->studID);
    getchar();
    printf("Enter student marks: ");
    scanf("%d", & newStud->studMarks);
    getchar();
    newStud->next = NULL;
    if (*head == NULL)
    {
        *head = newStud;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newStud;
    }
}
void deleteRecord(Node **head, int ID)
{
    if(*head == NULL)
    {
        printf("There are no records to delete!\n");
    }
    Node *temp = *head, *prev = NULL;
    if (temp != NULL && temp->studID != ID)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Record with ID %d could not be found!\n", ID);
    }
    if (prev == NULL)
    {
        *head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    free(temp);
     printf("Deleted record with ID %d successfully!!\n", ID);
}
void updateRecord(Node **head, int ID)
{
    Node *temp = *head;
    if(temp != NULL && temp->studID != ID)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Record with ID %d was not found!\n", ID);
        return;
    }
    else
    {
        printf("Record found! Enter new marks: ");
        scanf("%d", &temp->studMarks);
        getchar();
    }
    printf("Record updated successfully\n");
}
void diplayRecords(Node **head)
{
    Node *temp = *head;
    if (temp == NULL)
    {
        printf("The record is empty!\n");
        return;
    }
    printf("**** STUDENT RECORDS ****\n");
    while (temp != NULL)
    {
        printf("Student Name | Student ID | Student Marks\n%-20s%-14d %-9d\n", temp->studName, temp->studID, temp->studMarks);
        temp = temp->next;
    }
}

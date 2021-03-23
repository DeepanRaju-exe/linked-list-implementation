#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct StudentRecord
{
    int regno;
    char name[100];
    char phone[12];
    int Total_marks;
    struct StudentRecord *next;

}* head;
void add(int regno, char* name, char* phone, int Total_marks)
{

    struct StudentRecord * studentRecord = (struct StudentRecord *) malloc(sizeof(struct StudentRecord));
    studentRecord->regno = regno;
    strcpy(studentRecord->name, name);
    strcpy(studentRecord->phone, phone);
    studentRecord->Total_marks = Total_marks;
    studentRecord->next = NULL;

    if(head==NULL)
    {
        // head is NULL then make student as head
        head = studentRecord;
    }
    else
    {
        // add student in beginning of head
        studentRecord->next = head;
        head = studentRecord;
    }

}
void search(char str2[100])
{
    if(head==NULL)
    {
      printf("There is no record as of now:press 1 to add new record");
    }
    else
    {
    struct StudentRecord * temp = head;
    while(temp!=NULL)
    {
        if(!strcmp(str2,temp->name))
        {
            printf("Roll Number: %d\n", temp->regno);
            printf("Name: %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            printf("Total_marks: %d\n", temp->Total_marks);
            return;
        }
        temp = temp->next;
    }
    }
    printf("Student %s  not found :( \n",str2);
}


void display()
{
    if(head==NULL)
    {
        printf("There is no record as of now:press 1 to add new record");
    }
    else
    {
    struct StudentRecord * temp = head;
    printf(" REG NO\tNAME\t\tPHONE     \tTOTAL_MARKS\n\n");
    while(temp!=NULL){

        printf("%d\t%s\t\t%s\t%d\n", temp->regno,temp->name,temp->phone,temp->Total_marks);
        temp = temp->next;

    }
    }
}
int main()
{
    head = NULL;
    int choice;
    char name[100];
    char phone[12];
    int regno;
    int Total_marks;
    printf(" 1.) To add new student\n 2.) To search  student with name\n 3.) To display all records \n 0.)EXIT!!!");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter reg no: ");
                scanf("%d", &regno);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                printf("Enter Total marks: ");
                scanf("%d", &Total_marks);
                add(regno, name, phone, Total_marks);
                break;
            case 2:
                printf("Enter  name of student need to be searched: ");
                scanf("%s", &name);
                search(name);
                break;

            case 3:
                display();
                break;
        }

    } while (choice != 0);
}

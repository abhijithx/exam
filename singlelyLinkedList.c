#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
void insertFirst(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}
void insertAfterValue(int value, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            
        }
      
        temp = temp->next;
    }
}

void insertEnd(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        insertFirst(value);
    }
    else
    {
        tail->next = newNode;
        newNode = tail;
    }
}

void deleteFirst(){
    struct node* temp = head;
    head = head->next;
    printf("%d deleted successfully", temp->data);
}

void deleteLast(){
    struct node* temp = head;
    while(temp->next->next != NULL){
         temp=temp ->next;
    }
    temp->next = NULL;
    tail = temp;
}
void deleteValue(int value){
    struct node* temp = head;

    if(head != NULL && head->data == value){
        head = head->next;
        return;
    }

    while(temp != NULL && temp->next != NULL){
        if(temp->next->data == value){
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
}


void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    insertFirst(10);
    insertFirst(20);
    insertFirst(30);
    insertFirst(40);
    insertFirst(50);
    insertFirst(60);
    insertFirst(70);
    insertEnd(80);
    insertAfterValue(20, 25);
    deleteValue(10);
    display();

    return 0;
}
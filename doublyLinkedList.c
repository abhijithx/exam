#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
struct node *tail = NULL;
void insertFirst(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insertLast(int value)
{
    if (head == NULL)
    {
        insertFirst(value);
    }
    else
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;
        struct node *temp = head;
        temp = tail;
        temp->next = newNode;
        newNode->prev = temp;
        tail = newNode;
    }
}
void insertAfterValue(int value, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next->prev = newNode;

        }

        temp=temp->next;
    }
}

void deleteFirst(){

     printf("%d deleted \n ",head->data );
     if(head == NULL){
        return;
     }
     head = head->next;

}
void deleteEnd(){
    struct node *temp = tail;
    tail = temp->prev;
    tail->next = NULL;
     
}
void deleteValue(int value){
  struct node *temp = head;
  while(temp != NULL){
     if(temp->data == value){
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
     }
  }

}
void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
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
    insertFirst(80);
    insertFirst(90);
    insertFirst(100);
    insertLast(5);
    insertLast(3);
    insertLast(2);
    insertAfterValue(100,95);
    deleteFirst();
    deleteEnd();
    deleteValue(10);
    display();

    return 0;
}

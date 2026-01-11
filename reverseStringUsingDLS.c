#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

void insertLast(char value)
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
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void reverseString()
{
    printf("\n reversed string: ");
    struct node *temp = tail;
    while (temp != NULL)
    {
        printf("%c", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void display()
{
    printf("\n original string: ");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    char str[] = "HELLO";
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        insertLast(str[i]);
    }
    display();
    reverseString();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\n %d enqueued to queue", value);
}

void dequeue()
{
    if (front == NULL)
    {
        printf("\n queue empty");
    }
    else
    {
        struct node *temp = front;
        printf("\n %d dequeued from queue", front->data);
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        free(temp);
    }
}

void display()
{
    printf("\n queue elements: ");
    struct node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}

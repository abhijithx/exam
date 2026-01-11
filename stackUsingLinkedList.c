#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if (top == NULL)
    {
        top = newNode;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
    printf("\n %d pushed to stack", value);
}

void pop()
{
    if (top == NULL)
    {
        printf("\n stack empty");
    }
    else
    {
        struct node *temp = top;
        printf("\n %d popped from stack", top->data);
        top = top->next;
        free(temp);
    }
}

void display()
{
    printf("\n stack elements: ");
    struct node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    pop();
    pop();
    display();
    return 0;
}

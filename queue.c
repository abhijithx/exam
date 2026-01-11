#include <stdio.h>
#define size 10

int queue[size];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if (rear == size - 1)
    {
        printf(" queue is full \n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        queue[++rear] = value;
        printf("%d \n ", rear);
        printf(" %d add into queue \n ", value);
    }
}

void dequeue(){
    if(rear == front == -1){
        printf("queue is empty \n");
    }
    else{
        printf("\n %d deleted \n ",queue[front++]);
        
    }
}
void display()
{
    int temp = front;
    while (temp <= rear)
    {
        printf("%d", queue[temp]);
        if (temp == rear)
        {
            break;
        }
        printf("->");

        temp++;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    dequeue();
    display();
}

#include<stdio.h>
#define size 10 

int stack[10];
int top   = -1;

void push (int value ){
    if(top == size-1){
        printf("\n stack in full");
    }
    else{
        top ++;
        stack[top] = value;
        printf("\n %d inserted " , value);
        printf("\n");
    }
}

void pop(){
    if(top == -1){
        printf("stack empty");
    }
    else{
        printf("\n %d popped \n " , stack[top]) ;
        stack[--top];


    }
}

void display(){
    printf("stack \n");
    int temp = top;
    while(temp > -1){
        
        printf("%d ",stack[temp]);
        printf("\n");
        temp--;

    }
}


int main(){
    int data  = 10;
    push(data);
    push(20);
    push(40);
    push(67);
    display();
    pop();
    display();
}

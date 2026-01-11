#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void insertFirst(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}

void insertLast(int value) {
    if (head == NULL) {
        insertFirst(value);
    } else {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAfterValue(int value, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    struct node *temp = head;
    if (head == NULL) return;
    do {
        if (temp->data == value) {
            newNode->next = temp->next;
            temp->next = newNode;
            if (temp == tail) {
                tail = newNode;
            }
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

void deleteFirst() {
    if (head == NULL) return;
    printf("%d deleted \n", head->data);
    if (head == tail) {
        free(head);
        head = NULL;
        tail = NULL;
    } else {
        struct node *temp = head;
        head = head->next;
        tail->next = head;
        free(temp);
    }
}

void deleteEnd() {
    if (head == NULL) return;
    if (head == tail) {
        free(head);
        head = NULL;
        tail = NULL;
    } else {
        struct node *temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = head;
        free(tail);
        tail = temp;
    }
}

void deleteValue(int value) {
    if (head == NULL) return;
    if (head->data == value) {
        deleteFirst();
        return;
    }
    struct node *temp = head;
    do {
        if (temp->next->data == value) {
            struct node *toDelete = temp->next;
            temp->next = toDelete->next;
            if (toDelete == tail) {
                tail = temp;
            }
            free(toDelete);
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
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
    insertAfterValue(100, 95);
    deleteFirst();
    deleteEnd();
    deleteValue(10);
    display();
    return 0;
}

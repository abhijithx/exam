#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node* createNode(int value) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void insert(int value) {
    struct node *newnode = createNode(value);

    if (root == NULL) {
        root = newnode;
        return;
    }

    struct node *parent = NULL;
    struct node *curr = root;

    while (curr != NULL) {
        parent = curr;
        if (value < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (value < parent->data)
        parent->left = newnode;
    else
        parent->right = newnode;
}

void inorder(struct node *temp) {
    if (temp != NULL) {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

void preorder(struct node *temp) {
    if (temp != NULL) {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(struct node *temp) {
    if (temp != NULL) {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}

void search(int key) {
    struct node *temp = root;

    while (temp != NULL) {
        if (key == temp->data) {
            printf("Element found\n");
            return;
        } else if (key < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    printf("Element not found\n");
}

struct node* findMin(struct node *temp) {
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

struct node* deleteNode(struct node *temp, int key) {
    if (temp == NULL)
        return temp;

    if (key < temp->data)
        temp->left = deleteNode(temp->left, key);
    else if (key > temp->data)
        temp->right = deleteNode(temp->right, key);
    else {
        if (temp->left == NULL) {
            struct node *t = temp->right;
            free(temp);
            return t;
        } else if (temp->right == NULL) {
            struct node *t = temp->left;
            free(temp);
            return t;
        }

        struct node *t = findMin(temp->right);
        temp->data = t->data;
        temp->right = deleteNode(temp->right, t->data);
    }
    return temp;
}

int main() {
    int ch, value, key;

    while (1) {
        printf("MENU\n1.Insert\n2.Delete\n3.Search\n4.Inorder\n5.Preorder\n6.Postorder\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                exit(0);
        }
    }
}
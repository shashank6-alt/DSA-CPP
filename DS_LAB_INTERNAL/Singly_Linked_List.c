#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void insertAtBegin(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void deleteByValue(struct Node** head, int value) {
    struct Node *temp = *head, *prev = NULL;
    if (temp && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp) {
        prev->next = temp->next;
        free(temp);
    }
}

void traverse(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBegin(&head, 5);
    printf("List after insertion: ");
    traverse(head);

    deleteByValue(&head, 10);
    printf("List after deleting 10: ");
    traverse(head);

    return 0;
}

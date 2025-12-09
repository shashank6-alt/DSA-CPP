#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
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
    newNode->prev = temp;
}

void insertAtBegin(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head)
        (*head)->prev = newNode;
    *head = newNode;
}

void deleteByValue(struct Node** head, int value) {
    struct Node* temp = *head;
    while (temp && temp->data != value)
        temp = temp->next;
    if (!temp)
        return;
    if (temp->prev)
        temp->prev->next = temp->next;
    else
        *head = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    free(temp);
}

void traverse(struct Node* head) {
    while (head) {
        printf("%d <-> ", head->data);
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

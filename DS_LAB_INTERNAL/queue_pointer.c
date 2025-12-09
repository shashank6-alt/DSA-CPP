#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x; temp->next = NULL;
    if (!front)
        front = rear = temp;
    else {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue() {
    if (front) {
        struct Node* temp = front;
        front = front->next;
        free(temp);
        if (!front) rear = NULL;
    }
}

void display() {
    struct Node* temp = front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(5); enqueue(10); enqueue(15);
    printf("Queue after enqueues: ");
    display();
    dequeue();
    printf("Queue after dequeue: ");
    display();
    return 0;
}

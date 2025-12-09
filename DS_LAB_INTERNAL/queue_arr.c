#include <stdio.h>
#define MAX 100

int queue[MAX], front = 0, rear = -1;

void enqueue(int x) {
    if (rear < MAX - 1)
        queue[++rear] = x;
}

void dequeue() {
    if (front <= rear)
        front++;
}

void display() {
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
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

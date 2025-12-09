#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

void pop() {
    if (top) {
        struct Node* temp = top;
        top = top->next;
        free(temp);
    }
}

int peek() {
    return top ? top->data : -1;
}

void display() {
    struct Node* temp = top;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(5); push(10); push(15);
    printf("Stack after pushes: ");
    display();
    pop();
    printf("Stack after pop: ");
    display();
    printf("Top element: %d\n", peek());
    return 0;
}

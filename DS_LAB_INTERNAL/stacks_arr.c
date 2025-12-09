#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int x) {
    if (top < MAX - 1)
        stack[++top] = x;
}

void pop() {
    if (top >= 0)
        top--;
}

int peek() {
    if (top >= 0)
        return stack[top];
    return -1;
}

void display() {
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
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

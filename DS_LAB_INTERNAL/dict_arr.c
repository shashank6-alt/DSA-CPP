#include <stdio.h>
#include <string.h>
#define MAX 100

char keys[MAX][50];
char values[MAX][50];
int count = 0;

void insert(char* key, char* value) {
    strcpy(keys[count], key);
    strcpy(values[count], value);
    count++;
}

char* search(char* key) {
    for (int i = 0; i < count; i++)
        if (strcmp(keys[i], key) == 0)
            return values[i];
    return NULL;
}

void display() {
    for (int i = 0; i < count; i++)
        printf("%s : %s\n", keys[i], values[i]);
}

int main() {
    insert("apple", "red");
    insert("banana", "yellow");
    printf("Dictionary:\n");
    display();
    printf("Search 'apple': %s\n", search("apple"));
    return 0;
}

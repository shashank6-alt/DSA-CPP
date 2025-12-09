#include <stdio.h>
#include <string.h>

int bruteForceSearch(char* text, char* pattern) {
    int n = strlen(text), m = strlen(pattern);
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++)
            if (text[i + j] != pattern[j])
                break;
        if (j == m)
            return i; // Pattern found at index i
    }
    return -1;
}

int main() {
    char text[] = "datastructures";
    char pattern[] = "struc";
    int index = bruteForceSearch(text, pattern);
    if (index != -1)
        printf("Pattern found at index %d\n", index);
    else
        printf("Pattern not found\n");
    return 0;
}
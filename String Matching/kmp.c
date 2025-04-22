#include <stdio.h>
#include <string.h>

#define N 40

int parent[N];

void COMPUTE_PREFIX(char P[]) {
    int m = strlen(P);
    int k = 0;
    parent[0] = 0; // First element is always 0

    for (int q = 1; q < m; q++) {
        while (k > 0 && P[k] != P[q]) 
            k = parent[k - 1];
        
        if (P[k] == P[q]) 
            k += 1;
        
        parent[q] = k;
    }
}

void kmp(char T[], char P[]) {
    int n = strlen(T);
    int m = strlen(P);
    COMPUTE_PREFIX(P);

    int q = 0; // Number of characters matched

    for (int i = 0; i < n; i++) {
        while (q > 0 && P[q] != T[i]) 
            q = parent[q - 1];
        
        if (P[q] == T[i]) 
            q += 1;
        
        if (q == m) {
            printf("Pattern matches with shift %d\n", i - m + 1);
            q = parent[q - 1];
        }
    }
}

int main() {
    char T[] = "abcccbccbbcabc";
    char P[] = "cbbc";

    kmp(T, P);

    return 0;
}

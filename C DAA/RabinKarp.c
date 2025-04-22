#include <stdio.h>
#include <string.h>
#define N 40

void rabinkarp(char T[], char P[], int d, int q) {
    int n = strlen(T);
    int m = strlen(P);
    int h = 1;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int i, s, j;

    for (i = 0; i < m - 1; i++) 
        h = (h * d) % q;
    

    for (i = 0; i < m; i++) {
        p = (d * p + P[i]) % q;
        t = (d * t + T[i]) % q;
    }

    for (s = 0; s <= n - m; s++) {
        if (p == t) {
            for (j = 0; j < m; j++) 
                if (T[s + j] != P[j])
                    break;

            if (j == m) 
                printf("Pattern found with shift %d\n", s);
            
        }

        if (s < n - m) {
            t = (d * (t - T[s] * h) + T[s + m]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    char T[] = "3141592653589793";
    char P[] = "26";
    int d = 10; 
    int q = 13; 
    rabinkarp(T, P, d, q);

    return 0;
}
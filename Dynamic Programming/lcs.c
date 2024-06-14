#include<stdio.h>
#include<string.h>
#define N 100
char s1[] = "BITTER";
char s2[] = "BUTTER";
char b[N][N];
int c[N][N];

void print_lcs(int i, int j, char b[][N]) {
    if(i == 0 || j == 0)
        return;
    if(b[i][j] == 'a') {
        print_lcs(i - 1, j - 1, b);
        printf("%c ", s1[i - 1]);
    }
    else if(b[i][j] == 'l')
        print_lcs(i, j - 1, b);
    else
        print_lcs(i - 1, j, b);
}


void lcs() {
    int i, j, m = strlen(s1), n = strlen(s2), k = 0;
     
    for(i = 0; i <= m; i++)
        c[0][i] = 0;
    
    for(j = 0; j <=n; j++)
        c[j][0] = 0;
    
    for(i = 1; i <= m; i++) {
        for(j = 1; j <= n; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'a';
            }
            else if(c[i][j - 1] >= c[i - 1][j]) {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l';
            }
            else {
                c[i][j] = c[i - 1][j];
                b[i][j] = 't';
            }
        }
    }
    for(int j = 0; j <= n; j++)
        j == 0 ? printf("    %c", s2[j]) : printf(" %c", s2[j]);
    
    printf("\n");
    
    for(i = 0; i <= m; i++){
        i != 0 ? printf("%c ", s1[k++]): printf("  ");
        for(j = 0; j <= n; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    printf("Solution: ");
    print_lcs(m, n, b);
}



int main() {
    lcs();
    return 0;
}
# include<stdio.h>
# define n 6

//  to get all the solutions sorted array
int w[n] = {5, 10, 12, 13, 15, 18}, m = 30, x[n] = {0};

void sos(int s, int k, int r) {
    x[k] = 1; 

    if(s + w[k] == m) {
        for(int i = 0; i < n; i++)
            printf("%d ", x[i]);
        
        printf("\n");
    }

    else if(s + w[k] + w[k + 1] <= m) 
        sos(s + w[k], k + 1, r - w[k]);

    if(s + w[k + 1] <= m && s + r - w[k] >= m) { 
        x[k] = 0; 
        sos(s, k + 1, r - w[k]);
    }
    x[k] = 0; 

}


int main(){

    sos(0, 0, 73);
    return 0;
}

// 1 1 0 0 1 0 
// 1 0 1 1 0 0
// 0 0 1 0 0 1
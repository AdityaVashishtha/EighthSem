#include <stdio.h>

void printO(int n){
    int i,j;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++){
            if(j>n/2 && j< (n/2 +2))
                printf("* ");
            printf("  ");
        }
        printf("\n");
    }
    // for(i=n-1;i>0;i--) {
    //     for(j=0;j<n;j++)
    //         printf("* ");
    //     printf("\n");
    // }
}

int main() {
    int n=2;
    scanf("%d",&n);
    printO(n);
}
#include <stdio.h>

void printO(int n){
    int i,j;
    int count=n*n;
    for(i=0;i<n;i++) {
        for(j=0;j<n-i;j++) {
                printf("  ");
        }
        for(j=0;j<i+1;j++)
            printf("%d   ",count--);
        printf("\n");
    }
    for(i=n-1;i>0;i--) {
        for(j=n-i;j>=0;j--)
            printf("  ");
        for(j=i;j>0;j--)
            printf("%d   ",count--);
        printf("\n");
    }
}

int main() {
    int n=2;
    scanf("%d",&n);
    printO(n);
}
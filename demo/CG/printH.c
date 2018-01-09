#include <stdio.h>

void printO(int n){
    int i,j;
    for(i=0;i<(3*n);i++) {
        for(j=0;j<3*n;j++){
            if(j<n || j>((3*n)-n-1)) {
                printf("* ");
            } else {
                if( (i<n) || (i>((3*n)-n-1)) ) {
                    printf("  ");
                } else {
                    printf("* ");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    int n=2;
    scanf("%d",&n);
    printO(n);
}
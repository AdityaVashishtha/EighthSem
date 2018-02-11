#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int alice(int n,int g);
int bob(int A,int n,int g);

int main() {
    int n,g,A,B;
    printf("Enter value of n and g \n");
    scanf("%d%d",&n,&g);
    alice(n,g);    
}

int alice(int n,int g) {
    int A,x = rand()%10;
    A = ((int)pow(g,x))%n;
    int B = bob(A,n,g);
    int k1 = ((int)pow(B,x)%n);
    printf("Alice' Key: %d\n",k1);
    return A;
}

int bob(int A,int n,int g) {
    int B,y = rand()%10;    
    B = ((int)pow(g,y)%n);
    int k2 = ((int)pow(A,y)%n);
    printf("BOB's Key: %d \n",k2);
    return B;
}

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <math.h>

long int findD(long int e,long int x) {
    long int i;
    for(i=1;i<x;i++) {
       if(((x*i+1)%e) == 0)
        return ((x*i+1)/e);
    }
}

int findFactor(int start, int n) {
    int i;
    for(i=start+1;i<sqrt(n);i++) {
        if(n%i ==0)
            return i;
    }
}

int main() {
    int p,q;
    long int n,temp,e,d;
    scanf("%ld",&n);
    scanf("%ld",&e);
    printf("Given E: %ld\n",e);
    printf("Given N: %ld\n",n);
    p = findFactor(1,n);
    printf("Calculated P : %d\n",p);
    q = n/p;
    printf("Calculated Q : %d\n",q);
    temp = (p-1)*(q-1);
    d=findD(e,temp);
    printf("Calculated D: %ld \n",d);
}

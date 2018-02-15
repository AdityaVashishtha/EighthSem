#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <math.h>


void encrypt(char str[], char enStr[], long int e ,long int n);
void decrypt(char enStr[], char decStr[], long int d, long int n,int strLen);

long int findE(long int x) {
    long int i;
    for(i=2;i<(x);i++) {
       if(x%i != 0)
        return i;
    }
}

long int findD(long int e,long int x) {
    long int i;
    for(i=1;i<x;i++) {
       if(((x*i+1)%e) == 0)
        return ((x*i+1)/e);
    }
}

int main() {
    int p,q;
    scanf("%d%d",&p,&q);
    long int n,temp,e,d;
    n = p*q;
    temp = (p-1)*(q-1);
    e = findE(temp);
    printf("E: %ld\n",e);
    d=findD(e,temp);
    printf("D: %ld \n",d);
    printf("Enter Ptext : \n");
    char str[100],enStr[100],decStr[100];
    scanf("%s",str);
    temp = 5;
    long int nn = ((long int)pow(temp,e)%n);
    //printf("E__%ld__",nn%n);
    //printf("D__%ld__",((long int)pow(nn,d)%n));
    encrypt(str,enStr,e,n);
    printf("\n");
    decrypt(enStr,decStr,e,n,strlen(str));
}

void encrypt(char str[], char enStr[],long int e ,long int n) {
    int strLen = strlen(str),i;
    for(i=0;i<strLen;i++) {
        int temp = str[i]-97;
        //printf("_%d_",temp);
        enStr[i]= (((long int)pow(temp,e))%n);
        printf("%d ",enStr[i]);
        //enStr[i]=temp;
    }
    enStr[i]='\0';
    printf("Encrypted String %s \n",enStr);
}

void decrypt(char enStr[], char decStr[],long int d,long int n,int strLen) {
    int i;
    for(i=0;i<strLen;i++) {
        //int temp = (((long int)pow(enStr[i],d))%n);
        //printf("_%d_",enStr[i]);
        decStr[i]= (((long int)pow(enStr[i],d))%n)+97;
        printf(" %d ",decStr[i]-97);
    }
    decStr[i]='\0';
    printf("\n");
    printf("decrypted String %s \n",decStr);
}
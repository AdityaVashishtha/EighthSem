#include <stdio.h>
#include <string.h>

#define MAT_SIZE 3

int keyMatrix[MAT_SIZE][MAT_SIZE]; 

void generateMatrix (char key[]) {
    int i,j,keyLen,count=0;
    keyLen = strlen(key)/MAT_SIZE;
    for(i=0;i<keyLen;i++) {
        for(j=0;j<keyLen;j++) {
            keyMatrix[i][j]=(key[count++]-65)%26;
        }
    }
}

void encrypt(int msg[]) {
    int i, j, k;
    int res[MAT_SIZE];
    for(i=0;i<MAT_SIZE;i++) {
        res[i]=0;
        for(j=0;j<MAT_SIZE;j++) {
            res[i] += keyMatrix[i][j]*msg[j]; 
        }
        printf("%c",(res[i]%26)+97);
    }
}

void printKeyMatrix(char key[]) {
    int i,j,keyLen;
    keyLen = strlen(key)/MAT_SIZE;
    for(i=0;i<keyLen;i++) {
        for(j=0;j<keyLen;j++) {
            printf(" %d ",keyMatrix[i][j]);
        }
        printf("\n");
    }
}

void chunk(int res[MAT_SIZE],char msg[],int start) {
    int i;
    for(i=0;i<MAT_SIZE;i++) {
        res[i]=(msg[start*MAT_SIZE+i]-97)%26;
        //printf("%c\n",res[1][i]);
    }
}


int main() {
    char key[] = "GYBNQKURP";
    char msg[100];
    printf("Key and Key matrix is :: \n%s \n",key);
    generateMatrix(key);
    printKeyMatrix(key);
    printf("Please Enter message :: \n");
    scanf("%[^\n]s",msg);
    printf("Message is :: %s \n",msg);
    int i,len=strlen(msg);
    int res[MAT_SIZE];
    printf("Encrypted text is :: ");
    for(i=0;i<(len/3);i++) {
        chunk(res,msg,i);
        encrypt(res);
    }
    printf("\n");    
}
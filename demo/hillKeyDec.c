#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAT_SIZE 4

int keyMatrix[MAT_SIZE][MAT_SIZE]; 

char *randstring(int length) {
    static char charset[] = "abcdefghijklmnopqrstuvwxyz";        
    char *randomString = NULL;
    if (length) {
        randomString = malloc(sizeof(char) * (length +1));
        if (randomString) {            
            for (int n = 0;n < length;n++) {            
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }
            randomString[length] = '\0';
        }
    }
    return randomString;
}

void generateMatrix (char key[]) {
    int i,j,keyLen,count=0;
    keyLen = strlen(key)/MAT_SIZE;
    for(i=0;i<keyLen;i++) {
        for(j=0;j<keyLen;j++) {
            keyMatrix[i][j]=(key[count++]-65)%26;
        }
    }
}

void encrypt(int msg[],char chk[]) {
    int i, j, k;
    int res[MAT_SIZE];
    for(i=0;i<MAT_SIZE;i++) {
        res[i]=0;
        for(j=0;j<MAT_SIZE;j++) {
            res[i] += keyMatrix[i][j]*msg[j]; 
        }
        //printf("%c",(res[i]%26)+97);
        chk[i]=(res[i]%26)+97;
    }
    chk[i]='\0';
}

void printKeyMatrix(char key[]) {
    int i,j,keyLen;
    keyLen = strlen(key)/MAT_SIZE;
    for(i=0;i<keyLen;i++) {
        for(j=0;j<keyLen;j++) {
            //printf(" %d ",keyMatrix[i][j]);
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

void genComb(char key[]);

int main() {    
    long int i=100000000;
    while(i--){
        char *key=randstring(MAT_SIZE*MAT_SIZE);
        genComb(key);
    }
}

void genComb(char key[]) {
    char msg[]="letusmeetnow";
    char ct[]="hbcdfnopiklb";
    //char msg[100];
    //printf("Key and Key matrix is :: \n%s \n",key);
    generateMatrix(key);
    printKeyMatrix(key);
    //printf("Please Enter message :: \n");
    //scanf("%[^\n]s",msg);
    // strcpy(msg,pt);
    //printf("Message is :: %s \n",msg);    
    int i,len=strlen(msg);
    int res[MAT_SIZE];
    char chk[MAT_SIZE+1],frChk[MAT_SIZE+1];
    for(i=0;i<MAT_SIZE;i++){
        frChk[i]=ct[i];
    }
    //frChk[i]=ct[i];
    //printf("Encrypted text is :: ");
    for(i=0;i<(len/MAT_SIZE);i++) {
        chunk(res,msg,i);
        encrypt(res,chk);
        if(strcmp(chk,frChk)==0){
            printf("_%s_\n",chk);
            continue;
        }
        else {
            return;
        }
    }
    //printf("%c -- \n",res[0]);
    printf("\n");    
}
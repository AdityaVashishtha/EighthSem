#include <stdio.h>
#include <string.h>

void encrypt(char str[],char enStr[],int n);
void decrypt(char enStr[],char decStr[],int n);

int main() {
    printf("Enter text to encrpt with railfence\n");
    char str[100],enStr[100],decStr[100];
    int i,j,n,m;
    scanf("%s",str);
    printf("Enter rows to use :: \n");
    scanf("%d",&n);
    encrypt(str,enStr,n);
    decrypt(enStr,decStr,n);
}

void encrypt(char str[],char enStr[],int n) {
    int strLen = strlen(str),i,j,count=0;
    if(strLen%n != 0) {
        for(i=strLen;i<(strLen+(strLen%n));i++){
            //printf("new body");
            str[i]='_';
        }
        str[i] = '\0';
        strLen = strLen+(strLen%n);
    }
    for(i=0;i<n;i++) {
        for(j=i;j<strLen;j += n) {
            //printf("%c",str[j]);
            enStr[count++]=str[j];
        }            
    }    
    printf("\nEncrypted String : %s \n",enStr);
}

void decrypt(char enStr[],char decStr[],int n) {
    int strLen = strlen(enStr),i,j,m,count=0;
    m = strLen/n;
    for(i=0;i<m;i++) {
        for(j=i;j<strLen;j += m) {
            //printf("%c",enStr[j]);
            decStr[count++]=enStr[j];
        }            
    }    
    decStr[count++] = '\0';
    //printf("\n");
    printf("Decrypted String : %s \n",decStr);
}
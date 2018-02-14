#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void simpleColumnarEncrypt(char str[],char enStr[],int order[],int numOfColumn);
void generateKeyOrder(char key[]);
void simpleColumnarDecrypt(char enStr[],char decStr[],int order[],int numOfColumn);

int main() {
    char str[100],enStr[100],decStr[100];
    int numOfColumn,order[10],i;
    printf("Enter String : \n");
    scanf("%s",str);
    printf("Input String : %s\n",str);
    printf("Enter the Column size and then order : \n");
    scanf("%d",&numOfColumn);    
    for(i=0;i<numOfColumn;i++)
        scanf("%d",&order[i]);
    simpleColumnarEncrypt(str,enStr,order,numOfColumn);
    printf("Encrpted String : %s\n",enStr);
    simpleColumnarDecrypt(enStr,decStr,order,numOfColumn);
}


void simpleColumnarEncrypt(char str[],char enStr[],int order[],int numOfColumn) {
    int i,j,k,strLen=strlen(str),count=0;        
    for(i=0;i<numOfColumn;i++) { 
        for(j=0;j<(strLen/numOfColumn)+1;j++) {
            char ch;
            int shift =(j*numOfColumn)+(order[i]-1);
            if(shift>(strLen -1))
                break;
            ch = str[shift];            
            enStr[count++]=ch;            
        }        
    }
    enStr[count++]='\0';    
}

void simpleColumnarDecrypt(char enStr[],char decStr[],int order[],int numOfColumn) {
    int i,j,k,strLen=strlen(enStr),count=0;        
    for(i=0;i<numOfColumn;i++) { 
        for(j=0;j<(strLen/numOfColumn)+1;j++) {
            char ch;
            int shift = (j*numOfColumn + (order[i] - 1));
            if(shift>(strLen -1))
                break;
            decStr[shift]=enStr[count++];
            //decStr[count++]=ch;                        
        }        
    }
    decStr[strLen] = '\0';
    printf("Decrpted String : %s\n",decStr);
}
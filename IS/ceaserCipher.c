#include <stdio.h>
#include <string.h>
int main() {
    printf("Enter string \n");
    char str[100],enStr[100],decStr[100];
    scanf("%[^\n]s",str);
    printf("Enter steps -ve for backward \n");
    int len=0,i,count;
    scanf("%d",&count);
    len = strlen(str);
    for(i=0;i<len;i++) {
        int ch = str[i];
        if(ch>=65 && ch<=90) {
            ch -= 65;
            ch += count;
            if(ch<0)
                ch = 26+ch;
            ch = ch%26;
            ch += 65; 
            enStr[i]=ch;
        } else if ( ch >= 97 && ch <= 122) {
            ch -= 97;
            ch += count;
            if(ch<0)
                ch = 26+ch;
            ch = ch%26;
            ch += 97; 
            enStr[i]=ch;
        } else {
            enStr[i]=ch;
        }
    }
    for(i=0;i<len;i++) {
        int ch = enStr[i];
        if(ch>=65 && ch<=90) {
            ch -= 65;
            ch -= count;
            if(ch<0)
                ch = 26+ch;
            ch = ch%26;
            ch += 65; 
            decStr[i]=ch;
        } else if ( ch >= 97 && ch <= 122) {
            ch -= 97;
            ch -= count;
            if(ch<0)
                ch = 26+ch;
            ch = ch%26;
            ch += 97; 
            decStr[i]=ch;
        } else {
            decStr[i]=ch;
        }
    }
    printf("\nEncrypted :: %s \n",enStr);
    printf("Dencrypted :: %s \n",decStr);
}

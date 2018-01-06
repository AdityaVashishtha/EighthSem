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
            //printf("%c",(ch));
            enStr[i]=ch;
            // dothis
        } else if ( ch >= 97 && ch <= 122) {
            ch -= 97;
            ch += count;
            if(ch<0)
                ch = 26+ch;
            ch = ch%26;
            ch += 97; 
            //printf("%c",(ch));
            enStr[i]=ch;
        } else {
            //printf("Not plain alphabate text \n");
            enStr[i]=ch;
        }

         //   printf("%d\n",str[i]);
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
            //printf("%c",(ch));
            decStr[i]=ch;
            // dothis
        } else if ( ch >= 97 && ch <= 122) {
            ch -= 97;
            //printf("ch %d",ch);
            ch -= count;
            //printf("ch %d",ch);
            if(ch<0)
                ch = 26+ch;
            ch = ch%26;
            ch += 97; 
            //printf("%c",(ch));
            decStr[i]=ch;
        } else {
            //printf("Not plain alphabate text \n");
            decStr[i]=ch;
        }

         //   printf("%d\n",str[i]);
    }
    printf("\nEncrypted :: %s \n",enStr);
    printf("Dencrypted :: %s \n",decStr);
}
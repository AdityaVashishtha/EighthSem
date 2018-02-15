#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    int main() {
        char str[100], enStr[100], decStr[100];
        printf("Enter the string: \n");
        scanf("%[^\n]%*c", str);
        int i, j, index = 0,len = strlen(str);
        char lKey[] = "qwertyuiopasdfghjklzxcvbnm";
        char uKey[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
        for (i = 0; i < len; i++) {
            if (str[i] >= 97 && str[i] <= 122) {
                index = str[i] % 97;
                enStr[i] = lKey[index];
            } else if (str[i] >= 65 && str[i] <= 90) {
                index = str[i] % 65;
                enStr[i] = uKey[index];
            } else {
                enStr[i] = str[i];
            }
        }
        printf("Encrypted String : %s\n",enStr);
        for (i = 0; i < len; i++) {
            for (j = 0; j < strlen(lKey); j++) {
                if (enStr[i] == lKey[j]) {
                    decStr[i] = j + 97;
                    break;
                }else if(enStr[i] == uKey[j]) {
                    decStr[i] = 65 + j;
                    break;
                } else {
                    decStr[i] = enStr[i];
                }
            }
            if (enStr[i] < 65 || enStr[i] > 122 || (enStr[i] > 90 && enStr[i] < 97)) {
                decStr[i] = enStr[i];
            }
        }
        printf("Decrpted String : %s \n",decStr);        
    }
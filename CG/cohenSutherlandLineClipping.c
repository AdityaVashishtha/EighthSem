#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

int CENTER_REGION_CODE = 0;
int LEFT_REGION_CODE = 1;
int RIGHT_REGION_CODE = 2;
int BOTTOM_REGION_CODE = 4;
int TOP_REGION_CODE = 8;

int xMax = 500;
int yMax = 400;
int xMin = 100;
int yMin = 100;

int calculateRegionCode(float x, float y) {
    int code = 0;
    if (x < xMin)
        code = code | LEFT_REGION_CODE;
    else if (x > xMax)
        code = code | RIGHT_REGION_CODE;
    if (y < yMin)
        code = code | BOTTOM_REGION_CODE;
    else if (y > yMax)
        code = code | TOP_REGION_CODE;
    return code;
}

int main() {    
    float x1,y1,x2,y2,flag=0;
    printf("Enter line cordinates (Cohen Sutherland) \n");
    scanf("%f%f%f%f",&x1,&y1,&x2,&y2);    
    float tx1,tx2,ty1,ty2;
    tx1=x1;
    tx2=x2;
    ty1=y1;
    ty2=y2;    
    int p1code = calculateRegionCode(x1,y1);
    int p2code = calculateRegionCode(x2,y2);  
    int i=0,tempCode=0;
    float x,y;
    while(i<100) {
        i++;
        if((p1code | p2code)==0) {                        
            flag=1;
            break;
        } else if((p1code & p2code)) {                        
            break;
        } else {
            if(p1code != 0)
                tempCode = p1code;
            else 
                tempCode = p2code;            
            x=y=0;
            
            if(tempCode & TOP_REGION_CODE) {
                y = yMax;
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
            } else if (tempCode & BOTTOM_REGION_CODE) {
                y = yMin;
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
            }
            else if(tempCode & RIGHT_REGION_CODE) {
                x = xMax;
                y =  y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);                
            } else if(tempCode & LEFT_REGION_CODE) {
                x = xMin;
                y =  y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
            }

            if(tempCode == p1code) {
                x1 = x;
                y1 = y;
                p1code = calculateRegionCode(x1,y1);
            } else {
                x2 = x;
                y2 = y;
                p2code = calculateRegionCode(x2,y2);
            }  
        }        
    }        
    if(flag == 1 && i==1) {
        printf("Line is completely accepted \n");
    }
    else if(flag == 1) {
        printf("Line is partially accepted and Clipped at \n");
        printf("P1 - x1 = %f y1 = %f \n",x1,y1);
        printf("P2 - x2 = %f y2 = %f \n",x2,y2);
    } else {
        printf("Line is rejected \n");
    }

    printf("\n\n\n");
    int gd = DETECT,gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE);
    setcolor(RED);
    rectangle(xMin,yMin,xMax,yMax);
    setcolor(BLUE);
    line(tx1,ty1,tx2,ty2);        
    delay(5000);
    closegraph();
    return 0;
}
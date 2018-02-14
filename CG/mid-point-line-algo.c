#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include <math.h>

void printMidPointLine(int x1,int y1, int x2,int y2);

int main() {
    int x1,y1,x2,y2;
    printf("(Mid Poit Algo) Enter both the points \n");
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);    
    printMidPointLine(x1,y1,x2,y2);
    return 0;
}

void printMidPointLine(int x1,int y1, int x2,int y2) {
    int i,dx,dy,count,stepSize=1,d0,dk,dk_1;
    dy = abs(y1 - y2);
    dx = abs(x1 - x2);
    count = dy>dx?dy:dx;
    float m = dy/(float)dx;
    int c = m>1 ? 1 : 0;
    int gd = DETECT,gm,x,y;
    initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE);     
    if(!c) {
        for(i=0;i<count;i++) {
            putpixel(x,y,RED);
            x+=1;
            if(dk<0)
                dk = dk + dy;
            else {
                dk = dk + dy - dx;
                y+=1;
            }
        }
    } else {
        for(i=0;i<count;i++) {
            putpixel(x,y,RED);
            y+=1;
            if(dk<0)
                dk = dk + dx;
            else {
                dk = dk + dx - dy;
                x+=1;
            }
        }
    }   
    delay(5000);
    closegraph();
}
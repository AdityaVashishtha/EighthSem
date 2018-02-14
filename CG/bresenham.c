#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include <math.h>

void printLineBresenHam(int x1,int y1, int x2,int y2);

int main() {
    int x1,y1,x2,y2;
    printf("(Bresenham) Enter both the points \n");
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);    
    printLineBresenHam(x1,y1,x2,y2);
    return 0;
}

void printLineBresenHam(int x1,int y1, int x2,int y2) {
    int i,dx,dy,count,stepSize=1,p0,pk,pk_1;
    dy = abs(y1 - y2);
    dx = abs(x1 - x2);
    count = dy>dx?dy:dx;
    float m = dy/(float)dx;
    int c = m>1 ? 1 : 0;
    int gd = DETECT,gm,x,y;
    initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE);
    switch(c) {
        case 0: // m<1 case        
            p0 = 2*dy - dx;            
            pk = p0,x=x1,y=y1;
            for(i=0;i<count;i++) {
                putpixel(x,y,BLUE);        
                x = x+1;
                if(pk > 0) {
                    y = y +1;
                    pk_1 = pk + 2*dy - 2*dx;
                }            
                else {
                    pk_1 = pk + 2*dy;
                }                            
                pk = pk_1;
            }
            break;
        case 1: // m>1 case
            p0 = 2*dx - dy;            
            pk = p0,x=x1,y=y1;
            for(i=0;i<count;i++) {
                putpixel(x,y,GREEN);        
                y = y+1;
                if(pk > 0) {
                    x = x +1;
                    pk_1 = pk + 2*dx - 2*dy;
                }            
                else {
                    pk_1 = pk + 2*dx;
                }                            
                pk = pk_1;
            }
            break;
    }        
    delay(5000);
    closegraph();
}
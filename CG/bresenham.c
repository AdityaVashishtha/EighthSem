#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include <math.h>

int main()
{
    int x1,y1,x2,y2,i,dx,dy,count,stepSize=1,p0,pk,pk_1;
    printf("(Bresenham) Enter both the points \n");
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    dy = y1 - y2;
    dx = x1 - x2;
    p0 = 2*dy - dx;
    count = dy>dx ? dy : dx ;
    int gd = DETECT,gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(LIGHTGRAY);
    pk = p0;
    int x=x1 , y=y1;
    while(x != x2 || y != y2) {
        putpixel(x,y,RED);
        //printf("%d %d",x,y);
        x = x+1;
        if(pk > 0) {
            y = y +1;
            pk_1 = pk + 2*dy - 2*dx;
        }            
        else {
            pk_1 = pk + 2*dy;
        }            
        //putpixel(x,y,RED);
        pk = pk_1;
    }    
    delay(5000);
    closegraph();
    return 0;
}
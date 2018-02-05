#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include <math.h>

int main()
{
    int x1,y1,x2,y2,i,dx,dy,count,stepSize=1;
    printf("Enter both the points \n");
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    dx = abs(x1-x2);
    dy = abs(y1-y2);    
    count = dy > dx ? dy : dx;
    printf("--%d",abs(-1*count));
    float y = y1,x = x1;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(LIGHTGRAY);
    for(i=0;i<count;i++) {
        if(dy<dx) {
            y = y + ((float)dy/(float)dx);
            x = x + stepSize;
        } else {
            x = x + ((float)dx/(float)dy);
            y = y + stepSize;
        }        
        putpixel(round(x),round(y),RED);
    }        
    delay(5000);
    closegraph();
    return 0;
}
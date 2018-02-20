#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

void printCircleBresenHam(int x1, int y1, int r);

int main() {
    int x1, y1, r;
    printf("(Bresenham) Enter Center points and radius \n");
    scanf("%d%d%d", &x1, &y1, &r);
    printCircleBresenHam(x1, y1, r);
    return 0;
}

void printCircleBresenHam(int x1, int y1, int r) {
    printf("%d",r);
    int i, x, y, d;
    // x1 += 320;
    // y1 += 240;
    x=0,y=r;
    d = 3-2*(r);
    int gd = DETECT,gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE);
    while(x <= y) {
        x+=1;
        putpixel(x1+x, y1+y, RED);
        putpixel(x1-x, y1+y, RED);
        putpixel(x1+x, y1-y, RED);
        putpixel(x1-x, y1-y, RED);
        putpixel(x1+y, y1+x, RED);
        putpixel(x1-y, y1+x, RED);
        putpixel(x1+y, y1-x, RED);
        putpixel(x1-y, y1-x, RED);
        if(d<0) {
            d = d + 4*x +6;
        } else {
            d = d+4*x-4*y+10;
            y -=1;
        }
    }
    delay(1000);
    closegraph();
}
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void printMidPointCircle(int x1, int y1, int r);

int main() {
    int x1, y1, r;
    printf("(Mid Point Circle) Enter Center points and radius \n");
    scanf("%d%d%d", &x1, &y1, &r);
    printMidPointCircle(x1, y1, r);
    return 0;
}

void printMidPointCircle(int x1, int y1, int r) {
    printf("%d",r);
    int i, x, y, d;
    x=0,y=r;
    d = 1-r;
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
            d = d + 2*x +3;
        } else {
            d = d+2*x-2*y+5;
            y -=1;
        }
    }
    delay(1000);
    closegraph();
}

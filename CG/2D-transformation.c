#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

#define PI 3.14159

int translate(int p,int t){
    return p+t;
}

int rotateXAntiClockwise(int x,int y,float rad) {
    printf("%f  \n",cos(rad));
    return (int)(x*cos(rad)-y*sin(rad));
}

int rotateYAntiClockwise(int x,int y,float rad) {
    return (int)(x*sin(rad)+y*cos(rad));
}

int scale(int p,float s) {
    return (int)(p*s);
}

int reflectionAboutX(int p) {
    return (240-p)+240;
}

int shear(int p1,int p2,float sh) {
    return (int)(p1+p2*sh);
}

int main()
{
    int x1, y1, x2, y2, transformation;
    int xn1=0,xn2=0,yn1=0,yn2=0;
    printf("Enter Initial points \n");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("Select Transformation \n");
    printf("1. Translate\n2. Scaling\n3. Reflection\n4. Shear\n5. Rotation\n");
    scanf("%d", &transformation);    
    switch (transformation)
    {
    case 1:
        printf("Enter translate value tx and ty\n");
        int tx,ty;
        scanf("%d%d",&tx,&ty);
        xn1=translate(x1,tx);
        xn2=translate(x2,tx);
        yn1=translate(y1,ty);
        yn2=translate(y2,ty);
        break;
    case 2:
        printf("Enter Scaling factor value sx and sy\n");
        float sx,sy;
        scanf("%f%f",&sx,&sy);
        xn1=scale(x1,sx);
        xn2=scale(x2,sx);
        yn1=scale(y1,sy);
        yn2=scale(y2,sy);
        break;
    case 3:
        printf("Enter Relecting with x axis\n");        
        xn1=x1;
        xn2=x2;
        yn1=reflectionAboutX(y1);
        yn2=reflectionAboutX(y2);
        break;
    case 4:
        printf("Enter Shear factor value shx and shy\n");
        float shx,shy;
        scanf("%f%f",&shx,&shy);
        xn1=shear(x1,y1,shx);
        xn2=shear(x2,y2,shx);
        yn1=shear(y1,x1,shy);
        yn2=shear(y2,x2,shy);
        break;
    case 5:
        printf("Enter degrees to rotate");
        float degree;
        scanf("%f",&degree);
        degree = PI*(degree/180.00);
        xn1=rotateXAntiClockwise(x1,y1,degree);
        yn1=y1-(rotateYAntiClockwise(x1,y1,degree)-y1);
        xn2=rotateXAntiClockwise(x2,y2,degree);
        yn2=y2 - (rotateYAntiClockwise(x2,y2,degree)-y2);
        // xn1=x1;
        // yn1=y1;
        printf("%d  %d %f = degrees ",xn2,yn2,degree);
        break;
    default:
        printf("Invalid Operation\n");
    }
    int gd = DETECT, gm;
    //init graphics
    initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE);
    setcolor(RED);
    line(x1, y1, x2, y2);
    if(transformation==3)
        line(0,240,640,240);
    line(xn1, yn1, xn2, yn2);
    delay(5000);
    // getch();
    closegraph();
    return 0;
}

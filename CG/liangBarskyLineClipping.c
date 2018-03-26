#include<stdio.h>
#include<graphics.h>

int xMax = 500;
int yMax = 400;
int xMin = 100;
int yMin = 100;

void main() {
    int i;
    int x1,y1,x2,y2,dx,dy;
    float t1,t2,p[4],q[4],temp;    
    printf("Enter line cordinates (Liang Barsky) \n");
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);    
    int tx1,tx2,ty1,ty2;
    tx1=x1;
    tx2=x2;
    ty1=y1;
    ty2=y2;
                        
    dx=x2-x1;
    dy=y2-y1;
    
    p[0]=-dx;
    p[1]=dx;
    p[2]=-dy;
    p[3]=dy;
    
    q[0]=x1-xMin;
    q[1]=xMax-x1;
    q[2]=y1-yMin;
    q[3]=yMax-y1;
    
    for(i=0;i<4;i++) {
        if(p[i]==0) {
            printf("Line is parallal to window sides \n");            
            if(q[i]>=0) {
                if(i<2) {
                    if(y1<yMin) 
                        ty1=yMin;
                    if(y2>yMax) 
                        ty2=yMax;
                }                
                if(i>1) {
                    if(x1<xMin) 
                        tx1=xMin;                    
                    if(x2>xMax) 
                        tx2=xMax;                                                 
                }
            }
        }
    }
    
    t1=0;
    t2=1;
    
    for(i=0;i<4;i++)
    {
        temp=q[i]/p[i];
        
        if(p[i]<0)
        {
            if(t1<=temp)
                t1=temp;
        }
        else
        {
            if(t2>temp)
                t2=temp;
        }
    }
    
    if(t1<t2)
    {
        tx1 = x1 + t1 * p[1];
        tx2 = x1 + t2 * p[1];
        ty1 = y1 + t1 * p[3];
        ty2 = y1 + t2 * p[3];
        //line(xx1,yy1,xx2,yy2);
    }
    
    if(tx1!=x1 || tx2!=x2 || ty1 != y1 || ty2 != y2)
        printf("Line clipped at points :: \n\t X1=%d Y1=%d \n\t X2=%d Y2=%d \n",tx1,ty1,tx2,ty2);
    else 
        printf("Line not clipped \n");
    
    
    int gd = DETECT,gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE);
    setcolor(RED);
    rectangle(xMin,yMin,xMax,yMax);
    setcolor(BLACK);
    line(x1,y1,x2,y2);
    setcolor(BLUE);
    line(tx1,ty1,tx2,ty2);
    //line(tx1,ty1,tx2,ty2);        
    delay(5000);
    closegraph();
    delay(5000);
    closegraph();
}
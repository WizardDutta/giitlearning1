#include<stdio.h>
#include<time.h>
#include<graphics.h>
#include<math.h>
#include<string.h>

#define RADIUS 100
#define CLOCKRADIUS RADIUS+20
#define PI 3.1415926535897

void drawClock();
void drawHands();
int main()
{
    drawClock();
    return 0;
}
void drawClock() //x and y coordinate of center
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    int a,b;
    a = getmaxx()/2;
    b = getmaxy()/2;
    circle(a,b,CLOCKRADIUS);
    int i=0;
    char ch[5];
    for(i=0;i<12;i++)
    {
        sprintf(ch,"%d",i+1);
        outtextxy(a+RADIUS*cos(PI/6*i-PI/3),b+RADIUS*sin(PI/6*i-PI/3),(char*)ch);
    }
    drawHands();
    getch();
    closegraph();
}
void drawHands()
{
    
}
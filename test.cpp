#include<stdio.h>
#include<time.h>
#include<graphics.h>
#include<math.h>
#include<string.h>

#define RADIUS 100
#define CLOCKRADIUS RADIUS+20
#define PI 3.1415926535897

void drawClock(int,int);
void drawHands();
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    int a,b;
    a = getmaxx()/2;
    b = getmaxy()/2;
    drawClock(a, b);
    drawHands(a, b);
    getch();
    closegraph();
    return 0;
}
void drawClock(int a, int b) //x and y coordinate of center
{
    
    
    circle(a,b,CLOCKRADIUS);
    int i=0;
    char ch[5];
    for(i=0;i<12;i++)
    {
        sprintf(ch,"%d",i+1);
        outtextxy(a+RADIUS*cos(PI/6*i-PI/3),b+RADIUS*sin(PI/6*i-PI/3),(char*)ch);
    }
}
void drawHands(int a, int b, struct tm *time)
{
    int hourX,hourY;
    
    hourX = a + (RADIUS-40)*cos(PI/6*time->tm_hour - PI/2);
}
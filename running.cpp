#include<stdio.h>
#include<graphics.h>

#define RADIUS 100
#define PI 3.1415926535897
void testing();
int main()
{
    testing();
    return 0;
}
void testing()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    int a = getmaxx()/2;
    int b = getmaxy()/2;
    circle(a,b,RADIUS+20);
    pieslice(a,b,0,90,RADIUS+20); //angle in degree
    getch();
    closegraph();
}
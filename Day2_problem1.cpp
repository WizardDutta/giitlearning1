#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void makecircle()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm,(char*) "");
   circle(250, 200, 50);
   printf("A.Translation by 100 units in 10 steps:\n");
    int i;
    for(i=0;i<100;i+=10)
        circle(250+i,200+i,50);
    printf("B.Scaling of circle by twice:\n");
    circle(250+i+10,200+i+10,100);
   getch();
   closegraph();
}
void makerectangle()
{
    int gd = DETECT, gm;
    int left = 50, top = 100;
    int right = 200, bottom = 150; //these specify corners
    initgraph(&gd, &gm,(char*) "");
    rectangle(left, top, right, bottom);
    // transition
    printf("A.  Creating transition effect\n\n");
    rectangle(left+300,top,right+300,bottom);
    getch();
    cleardevice();
    printf("B. Scaling: \n\n");
    rectangle(left,top,right+300,bottom+100);
    getch();
    closegraph();
}
void maketriangle() 
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm,(char*) "");
    // line(100,10,100,300);
    line(100,100,100,300);
    line(100,300,300,300);
    line(100,100,300,300);
    getch();  
    closegraph();
} 
void menu()
{
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    int n;
    printf("Input your option\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        makecircle();
        break;
        case 2:
        makerectangle();
        break;
        case 3:
        maketriangle();
        break;
    }
}
int main()
{
  menu();
  return 0;
}
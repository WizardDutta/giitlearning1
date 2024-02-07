#include <stdio.h>
#include <time.h>
#include <graphics.h>
#include<math.h>

#define RADIUS 100

void drawClock(int x, int y);
void drawHands(int x, int y, struct tm *time);
void drawDigitalClock(int x, int y, struct tm *time);

int main() 
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm,(char*) "");

    time_t rawTime;
    struct tm *currentTime;

    int x = getmaxx() / 2;
    int y = getmaxy() / 2;
    int page = 0;
    while (!kbhit()) {
        setactivepage(page); //These two lines are used to implement double buffering
        setvisualpage(1-page);
        cleardevice();
        rawTime = time(NULL);
        currentTime = localtime(&rawTime);

        drawClock(x, y);
        drawHands(x, y, currentTime);
        drawDigitalClock(x, y + RADIUS + 20, currentTime);

        delay(10); //takes time in milisecond
        page = 1-page; //page: 0->1 or 1->0
    }

    closegraph();
    return 0;
}

void drawClock(int x, int y)
{
    circle(x, y, RADIUS);
    circle(x, y, RADIUS + 1);

    for (int i = 0; i < 12; i++) { //clockwise variation of angle
        int innerX = x + (RADIUS - 10) * cos(M_PI / 6 * i);
        int innerY = y + (RADIUS - 10) * sin(M_PI / 6 * i);
        int outerX = x + RADIUS * cos(M_PI / 6 * i);
        int outerY = y + RADIUS * sin(M_PI / 6 * i);

        line(innerX, innerY, outerX, outerY);
    }
}

void drawHands(int x, int y, struct tm *time) 
{
    int hourX = x + (RADIUS - 30) * cos(M_PI / 6 * time->tm_hour - M_PI / 2);
    int hourY = y + (RADIUS - 30) * sin(M_PI / 6 * time->tm_hour - M_PI / 2);

    line(x, y, hourX, hourY);

    int minX = x + (RADIUS - 20) * cos(M_PI / 30 * time->tm_min - M_PI / 2);
    int minY = y + (RADIUS - 20) * sin(M_PI / 30 * time->tm_min - M_PI / 2);

    line(x, y, minX, minY);

    int secX = x + (RADIUS - 10) * cos(M_PI / 30 * time->tm_sec - M_PI / 2);
    int secY = y + (RADIUS - 10) * sin(M_PI / 30 * time->tm_sec - M_PI / 2);

    line(x, y, secX, secY);
}

void drawDigitalClock(int x, int y, struct tm *time)
{
    char buffer[9];
    sprintf(buffer,"%02d:%02d:%02d", time->tm_hour,time->tm_min,time->tm_sec);
    outtextxy(x-25,y+20,buffer);
}

#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <time.h>

#define pi 3.14
int color = 5, Xc = 200, Yc = 200;

void secminHand(float t, int length)
{
    int r = length;
    float angle = t * pi / 30 - pi / 2;
    setcolor(BLUE);
    if (length == 150)
	setcolor(RED);
    line(Xc, Yc, Xc + r * cos(angle), Yc + r * sin(angle));
}

void hrHand(float hr, float min)
{
    int r = 80;
    float angle = hr * pi / 6 - pi / 2 + min / 12 * pi / 30;
    setcolor(BLACK);
    line(Xc, Yc, Xc + r * cos(angle), Yc + r * sin(angle));
}

void clockLayout()
{
    int radius = 180;
    setfillstyle(SOLID_FILL, color);
    fillellipse(Xc, Yc, radius, radius);
    setfillstyle(SOLID_FILL, color + 1);
    fillellipse(Xc, Yc, radius - 20, radius - 20);
    outtextxy(Xc, Yc - (radius - 40), "12");
    outtextxy(Xc, Yc + (radius - 40), "6");
    outtextxy(Xc + (radius - 40), Yc, "3");
    outtextxy(Xc - (radius - 40), Yc, "9");
    outtextxy(Xc + radius / 3, Yc - 2 * radius / 3, "1");
    outtextxy(Xc + 2 * radius / 3, Yc - radius / 3, "2");
    outtextxy(Xc + 2 * radius / 3, Yc + radius / 3, "4");
    outtextxy(Xc + radius / 3, Yc + 2 * radius / 3, "5");
    outtextxy(Xc - radius / 3, Yc + 2 * radius / 3, "7");
    outtextxy(Xc - 2 * radius / 3, Yc + radius / 3, "8");
    outtextxy(Xc - radius / 3, Yc - 2 * radius / 3, "11");
    outtextxy(Xc - 2 * radius / 3, Yc - radius / 3, "10");
    putpixel(Xc, Yc, color);
}

int main()
{
    int gd = DETECT, gm;
    float sec, min, hr;
    time_t p = time(0);
    struct tm *t = localtime(&p);
    hr = t->tm_hour;
    min = t->tm_min;
    sec = t->tm_sec;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    do
    {
        if (sec == 60)
            sec = 0;
        if (min == 60)
            min = 0;
        if (hr > 12)
            hr -= 12;
        clockLayout();
        secminHand(sec, 150);
        secminHand(min, 110);
        hrHand(hr, min);
        sec++;
        min += 1 / 60.0;
        hr += 1 / 3600.0;
        delay(1000);
        if (kbhit())
            break;
        cleardevice();
    } while (1);
    getch();
    closegraph();
    return 0;
}

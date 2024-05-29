#include<iostream>
#include<graphics.h>
#include<cmath>
#define width 680
#define height 680

int initcolor(int color=15, int pattern=1, int border_color=15)
{
    setcolor(border_color);
    setfillstyle(pattern, color);
    return 1;
}

int moon(int x, int y, int radx, int rady=0, int sangle=0, int eangle=360)
{
    if(rady==0);
    rady=radx;
    initcolor();
    ellipse(x, y, sangle, eangle, radx, rady);
    floodfill(x, y, 15);

    int theta=45, rad;
    rad=radx/5;
    x=x+(40*cos(theta));
    y=y-(40*sin(theta));

    initcolor(7,3,7);
    ellipse(x, y, sangle, eangle, rad, rad);
    floodfill(x, y, 7);
    return 1;
}

int screen2(int sheet2, int source21, int source22, int thick=10)
{
    setfillstyle(1,5);
    setcolor(5);

    rectangle(0,sheet2-(thick/2), source21-2,sheet2+(thick/2));
    floodfill((source21-2)/2,sheet2, 5);
    rectangle(source21+2,sheet2-(thick/2), source22-2,sheet2+(thick/2));
    floodfill((source22-2+source21+2)/2,sheet2,5);
    rectangle(source22+2,sheet2-(thick/2), width,sheet2+(thick/2));
    floodfill((width+source22+2)/2,sheet2,5);

    setcolor(0);
    rectangle(0,sheet2-(thick/2), source21-2,sheet2+(thick/2));
    rectangle(source21+2,sheet2-(thick/2), source22-2,sheet2+(thick/2));
    rectangle(source22+2,sheet2-(thick/2), width,sheet2+(thick/2));
    return 1;
}


/*int main()
{
    int gd=DETECT, gm;
    initwindow(width, height);
    moon(width/2, height/2, 60);
    getch();
    return 0;
}

*/

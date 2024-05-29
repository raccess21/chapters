#include <graphics.h>

int main()
{
    int gd=DETECT, gm, width, height;
    width=height=400;
    initwindow(width, height);

    rectangle(150,150,300,300);

    for(int color=0; color<16; color++)
    {
    setfillstyle(1, color);
    floodfill(200, 200, 15);
    delay(200);
    }
    getch();
    return 0;
}

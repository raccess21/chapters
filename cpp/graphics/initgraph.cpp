#include <graphics.h>

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "C:/Program Files/CodeBlocks/MinGW/include/bgi");
    rectangle(10,10, 50,50);
    closegraph();
    getch();
    return 0;
}

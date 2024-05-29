#include <grpahics.h>

int main()
{
    int gd=DETECT, gm, i;
    initwindow(600, 600);

    for(i=0; i<5; i++)
    {
        ellipse();
        cleardevice();
    }

    getch();
    return 0;
}

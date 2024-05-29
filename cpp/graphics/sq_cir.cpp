#include<graphics.h>
#include<cmath>
#include<iostream>
using namespace std;
int main()
{
    int gd=DETECT, gm;
    int k, sangle=0, eangle=360;
    initwindow(680, 680);

    for(k=sangle; k<=eangle-5; k+=5)
    {
        ellipse(100,100, k, k+5, 50, 50);
        getch();
        //delay(5);
    }
    cleardevice();

    int xc=400, yc=400;
    double rad=200;
    int x1=20, y1=20, x2, y2;

    for(int j=0; j<10; j++)
    {for(int i=0; i<=360; i+=1)
    {
        unsigned int tmp1, tmp2;
        tmp1=(rad*(double)cosf(i%90));
        tmp2=(rad*(double)sinf(i%90));
        if(i>=0 && i<=90)
        {x2=xc+tmp1;
        y2=yc-tmp2;}
        if(i>90 && i<=180)
        {x2=xc-tmp1;
        y2=yc-tmp2;}
        if(i>180 && i<=270)
        {x2=xc-tmp1;
        y2=yc+tmp2;}
        if(i>270 && i<=360)
        {x2=xc+tmp1;
        y2=yc+tmp2;}
        ellipse(xc,yc, 0, i+5, rad, rad);
        rectangle(x1,y1, x2,y2);
        //getch();
        delay(100);
        cleardevice();
    }
    //cout<<"\n"<<j;
    getch();
    }

    getch();
    return 0;

}

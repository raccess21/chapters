#include<iostream>
#include<graphics.h>
#include<math.h>
#define width 480
#define height 480

using namespace std;

int main()
{
    char ch;
    int gd=DETECT, gm;
    int sheet2=height/3;
    int source21=width/3;
    int source22=2*(width/3);

//    initgraph(&gd, &gm, "C:/Users/Arun Kumar Das/Documents/WinBGIm-64-1.0.1/WinBGIm-64-1.0.1/libbgi/include/bgi");
    initwindow(height,width);

    /*for(int i=0; i<1000; i++)
    {
        int x=i;
        circle(x,200,50);
        if(x+50>1280)
        {
            circle((x%1280),200,50);
        }

        delay(1);
        cleardevice();
    }

    circle(360,640,40);
    setcolor(5);
    rectangle(5,20,1200,400);
    setfillstyle(3,15);
    setcolor(5);
    floodfill(1109,655,5);

    cout<<"\n"<<pow(2,3);
    cin>>ch;*/
  //  closegraph();
    return 0;
}


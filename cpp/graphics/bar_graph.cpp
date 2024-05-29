#include <graphics.h>
#include <iostream>
#define width 800
#define height 600
#define padding 50

int main()
{
    int bars=0, spaces, i;
    std::cout<<"\nEnter number of bars:";
    std::cin>>bars;
    spaces=bars+1;
    std::cin.ignore(1, '\n');
    char bar_name[bars][25];
    double bar_val[bars];

    for(i=0; i<bars; i++)
    {
        //cout<<"\nEnter name of bar "<<i+1<<":";
        //cin.getline(bar_name[i], 25);
        std::cout<<"\nEnter value of bar "<<i+1<<":";
        std::cin>>bar_val[i];
        std::cin.ignore(1, '\n');
    }

    double maxi=0;
    for(i=0; i<bars; i++)
    {
        if(maxi<bar_val[i])
            maxi=bar_val[i];
    }
    double available=(4*(height-(2*padding)))/5;
    double factorf=available/maxi;

    int num=2;
    int bart=((num*(width-2*padding))/((num*bars)+spaces));
    int spacet=bart/num;

    int gd=DETECT, gm;
    initwindow(width, height);
    line(padding, padding, padding, height-padding);
    line(padding, height-padding, width-padding, height-padding);

    int y2=height-padding;
    int x1, x2;
    x1=x2=padding+spacet;
    for(i=0; i<bars; i++)
    {
        x2+=bart;
        double y1f=(double)y2-(factorf*bar_val[i]);
        int y1=(int)y1f;
        rectangle(x1, y1, x2, y2);
        x1+=bart+spacet;
        x2+=spacet;
    }
//    char txt[]="yo";
//    char* t=&txt[0];

//    settextstyle(0, 0, 8);
  //  outtextxy(50, 50, t);    //const_cast<char*>(txt.str()c_str())
//    getimage(0,0, height+10,width+10, void *bitmap);
    getch();
    return 0;
}

#include "C:/rahul/CodeBlock/graphics/obj.cpp"
#define width 100
#define height 500
using namespace std;

int main()
{
    int gd=DETECT, gm;
    initwindow(width, height);
    int sheet1, source1, sheet2, source21, source22, sheet3;
    int i, j, band_space;
    int sangle, eangle;     //start and end angle for ellipse
    int sheet2_thick=10;
    sheet1=0;
    source1=width/2;
    sheet2=height/3;
    source21=width/3;
    source22=2*(width/3);
    sheet3=height;
    band_space=15;
    j=0;
    sangle=180;
    eangle=360;

    for(i=band_space; i<=sheet2-(sheet2_thick/2); i+=band_space)
    {
        setcolor(15);
        ellipse(source1, sheet1, sangle, eangle, i, i);
        delay(50);
        screen2(sheet2, source21, source22);
    }

    int maxr=sqrt(pow(source1,2)+pow((sheet2-(sheet2_thick/2)),2));
    int sec_sor_dist=sqrt(pow((source1-source21),2)+(pow(sheet2,2)));

    for(; i<=maxr; i+=band_space)
    {
        setcolor(15);
        ellipse(source1, sheet1, sangle, eangle, i, i);
        setcolor(5);
        rectangle(0,sheet2,width,sheet3);
        setfillstyle(1,0);
        floodfill(width/2,(sheet2+sheet3)/2,5);
        setcolor(0);
        rectangle(0,sheet2,width,sheet3);

        if(i>=sec_sor_dist)
        {
            for(int k=band_space; k<=j; k+=band_space)
            {
                setcolor(15);
                ellipse(source21, sheet2+(sheet2_thick/2), sangle, eangle, k, k);
                ellipse(source22, sheet2+(sheet2_thick/2), sangle, eangle, k, k);
            }
            screen2(sheet2, source21, source22);
            delay(50);
            j+=band_space;
        }
    }

    for(; j<=sheet3; j+=band_space)
    {
        setcolor(15);
        ellipse(source21, sheet2+(sheet2_thick/2), sangle, eangle, j, j);
        ellipse(source22, sheet2+(sheet2_thick/2), sangle, eangle, j, j);
        delay(50);
        screen2(sheet2, source21, source22);
    }
    screen2(sheet2, source21, source22);
    getch();

    return 0;
}

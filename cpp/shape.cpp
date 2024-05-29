/*int set_symbol(char sym)
{

}
*/
int rectangle(int x1, int y1, int x2, int y2, char sym='*')
{
    //cout<<"\nYO";
    int i;

    if(x2<x1)
    {
        i=x2;
        x2=x1;
        x1=i;
    }

    if(y2<y1)
    {
        i=y2;
        y2=y1;
        y1=i;
    }

    for(i=x1; i<=x2; i++)       //upper horizontal arm
    {
        gotoxy(i,y1);
        cout<<sym;
    }

    for(i=y1; i<=y2; i++)       //right vertical arm
    {
        gotoxy(x2,i);
        cout<<sym;
    }

    for(i=x1; i<=x2; i++)       //lower horizontal arm
    {
        gotoxy(i,y2);
        cout<<sym;
    }

    for(i=y1; i<=y2; i++)       //left vertical arm
    {
        gotoxy(x1,i);
        cout<<sym;
    }

    return 1;
}

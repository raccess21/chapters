#include "C:/rahul/ecom/myntra/myntraclass.cpp"
#include "C:/rahul/ecom/myntra/custom.cpp"

int main()
{
    char filepath1[]="C:/rahul/ecom/myntra/raw/2203salrdy.txt";
    char filepath2[]="C:/rahul/ecom/myntra/raw/2203revrdy.txt";
    //myntra_rto orderrto;
    myntra_sale_2203 ordersa;
    myntra_setl_2203 orderrev;
    int sale=0, match=0, rto=0;

    ifstream fin1, fin2;
    fin1.open(filepath1, ios::in);
    fin2.open(filepath2, ios::in);

    while(1)
    {
            ordersa.readraw(fin1);
            if(fin1.eof())
                break;
            cout<<"\n"<<++sale<<" . "<<ordersa.Sale_Order_Code;

            fin2.seekg(0);
            while(1)
            {
                orderrev.readraw(fin2);
                rto++;
                if(fin2.eof())
                    break;
                if(kmcompare(orderrev.order_release_id, ordersa.Sale_Order_Code))
                {
                    match++;
                    break;
                }
            }
            cout<<"    "<<orderrev.order_release_id;

            if(match==0)
                cout<<"  <<nmatch checked :";
            if(match==1)
                cout<<"  <<ymatch check @ :";
            cout<<rto;
            match=0;
            rto=0;
    }

    fin1.close();
    fin2.close();
    return 1;
}


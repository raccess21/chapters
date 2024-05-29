#include "C:/rahul/ecom/myntra/myntraclass.cpp"
#include "C:/rahul/ecom/myntra/custom.cpp"

int main()
{
    char filepath[101];
    ifstream fin1, fin2;
    ofstream fout;
    myntra order;
    myntra_sale_2203 ordersa;
    int sale=0;
    strcpy(filepath, "C:/rahul/2203outer.txt");
    fin1.open(filepath, ios::in);
    cout<<"\nOpened "<<filepath;
    strcpy(filepath, "C:/rahul/ecom/myntra/raw/2203salrdy.txt");
    fin2.open(filepath, ios::in);
    cout<<"\nOpened "<<filepath;

    strcpy(filepath, "C:/rahul/2203outer2.txt");
    fout.open(filepath, ios::out);
    cout<<"\nOpened "<<filepath;

    while(!fin1.eof() && !fin2.eof())
    {
        order.read_ashfash(fin1);
        ordersa.readraw(fin2);
        strcpy(order.Packing_Date, ordersa.Packing_Date);
        strcpy(order.order_created_date, ordersa.Order_Created_Date);
        cout<<"\n"<<++sale<<" . "<<order.Sale_Order_Code;
        order.csvout_ashfash(fout);
    }

    return 0;
}

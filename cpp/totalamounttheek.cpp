#include "C:/rahul/ecom/myntra/myntraclass.cpp"
#include "C:/rahul/ecom/myntra/custom.cpp"

int main()
{
    char filepath[101];
    ifstream fin1, fin2;
    ofstream fout;
    int sale=0;
    myntra_sale_2203 ordersa;
    myntra order;

    strcpy(filepath, "C:/rahul/ecom/myntra/raw/2203salrdy.txt");
    fin1.open(filepath, ios::in);
    strcpy(filepath, "C:/rahul/2203outer3.txt");
    fin2.open(filepath, ios::in);
    strcpy(filepath, "C:/rahul/2203outer4.txt");
    fout.open(filepath, ios::out);

    while(!fin1.eof())
    {
        ordersa.readraw(fin1);
        cout<<"\n"<<++sale<<". "<<ordersa.Sale_Order_Code;
        cout<<"  "<<ordersa.Total_Amount;
        order.read_ashfash(fin2);
        cout<<"  "<<order.Sale_Order_Code;
        cout<<"  "<<order.customer_amount;
        order.customer_amount=ordersa.Total_Amount;
        cout<<"  "<<order.customer_amount;
        order.csvout_ashfash(fout);
    }

    fin1.close();
    fin2.close();
    fout.close();

    return 0;
}

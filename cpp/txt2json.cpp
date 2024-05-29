#include "C:/rahul/ecom/myntra/myntraclass.cpp"

int main()
{
    ifstream fin1, fin2;
    ofstream fout;
    char text[100][500];
    int sal=0;
    char filepathin[]="C:/rahul/ecom/myntra/processed/2203outer12.txt";
    char filepathvar[]="C:/rahul/ecom/myntra/processed/2203outvar.txt";
    char filepathout[]="C:/rahul/ecom/myntra/processed/2203outjson.txt";

    fin1.open(filepathin, ios::in);
    fin2.open(filepathvar, ios::in);
    fout.open(filepathout, ios::out);

    int i=0;
    while(!fin2.eof())
    {
        fin2.getline(text[i], 150, ',');
        i++;
    }

    int var=i;

    fout<<"[";
    while(!fin1.eof())
    {
        i=0;
        myntra order;
        order.csvread(fin1);
        cout<<"\n"<<++sal<<". "<<order.Sale_Order_Code;
        fout<<"\n\t{";
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.Sale_Order_Code<<"\",";
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.SKU_Code<<"\",";
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.state_code<<"\",";
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.order_created_date<<"\",";
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.Packing_date<<"\",";
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.customer_amount<<"\",";
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.customer_pre_amount<<"\",";
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.customer_post_amount<<"\",";
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.status<<"\",";
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.statusc<<"\",";

        fout<<"\n\t\t"<<text[i++]<<":\""<<order.delivery_date<<"\",";       //delivery date
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.for_total_setl<<"\",";      //for setl amount
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.pre_for_setl_date<<"\",";
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.post_for_setl_date<<"\",";
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.for_pre_setl_amt<<"\",";
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.for_post_setl_amt<<"\",";
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.set_for_pre<<"\",";            //for setl status
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.set_for_post<<"\",";

        fout<<"\n\t\t"<<text[i++]<<":\""<<order.return_date<<"\",";
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.rev_total_setl<<"\",";      //return amount
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.pre_rev_setl_date<<"\",";
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.post_rev_setl_date<<"\",";
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.rev_pre_setl_amt<<"\",";
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.rev_post_setl_amt<<"\",";
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.set_rev_pre<<"\",";             //rev setl status
        fout<<"\n\t\t"<<text[i++]<<":\""<<order.set_rev_post<<"\"\n\t},";
    }
    fout<<"]";

    fin1.close();
    fin2.close();
    fout.close();
}

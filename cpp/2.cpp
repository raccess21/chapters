#include<iostream>
//#include<stdlib.h>
int main()
{
  //  system("cls");
    int i=1, sume,sumo;
    sume=sumo=0;

    std::cout<<"\nodd.";
    for(; i<20; i+=6)
    {
        std::cout<<"  "<<i;
        sumo+=i*i;
    }

    std::cout<<"\nenven ";
    for(i=2; i<20; i+=6)
    {
        std::cout<<"  "<<i;
        sume+=i*i;
    }
    
    std::cout<<"\nsume="<<sume;
    std::cout<<"\nsumo="<<sumo;
    std::cout<<"\ndifference="<<sumo-sume;
    return 0;
}
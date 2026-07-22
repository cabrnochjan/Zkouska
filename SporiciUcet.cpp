#include "SporiciUcet.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

SporiciUcet::SporiciUcet(string cisloUctu, double urokovaSazba):Ucet(cisloUctu)
{
    this -> urokovaSazba= urokovaSazba;
}
void SporiciUcet::vypisInfo()const
{
    Ucet::vypisInfo();
    cout<<" urokova sazba: "<<urokovaSazba<<endl;
}
void SporiciUcet::analyzujUcet()const
{
    int pocet = 0;
    double soucet = 0;
    for(int i = 0; i < historieTransakci.size();i++)
    {
        if(historieTransakci[i]>0)
        {
            soucet+=historieTransakci[i];
            pocet++;
        }
    }
    if(pocet==0){
        cout<<"Nedoslo k zadnemu vkladu. "<<endl;
    }
    else
    {
    cout<<"cislo uctu: "<<cisloUctu<<" pocet vkladu: "<<soucet/pocet<<endl;
    }
}

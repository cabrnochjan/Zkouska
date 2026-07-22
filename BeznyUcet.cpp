#include "BeznyUcet.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

BeznyUcet::BeznyUcet(string cisloUctu, double poplatek): Ucet(cisloUctu)
{
    this ->poplatek = poplatek;
}
void BeznyUcet::vypisInfo()const
{
    Ucet::vypisInfo();
    cout<<" vyse poplatku: "<<poplatek<<" Kc"<<endl;
}
void BeznyUcet::analyzujUcet()const
{
    int pocetVyberu = 0;
    for(int i = 0; i <historieTransakci.size(); i++)
    {
        if(historieTransakci[i]<0)
        {
            pocetVyberu++;
        }
    }
    cout<<" Pocet vyberu : "<<pocetVyberu<<endl;
}
bool BeznyUcet::operator==(const BeznyUcet& druhy)const
{
    return poplatek==druhy.poplatek;
}
void BeznyUcet::operator+=(double hodnota)
{
    historieTransakci.push_back(hodnota);
}
ostream& operator<<(ostream& os,const BeznyUcet& druhy)
{
    cout<<"Cislo uctu: "<<druhy.cisloUctu<<" pocet transakci: "<< druhy.historieTransakci.size()<<endl;

    return os;
}
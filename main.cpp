#include "SporiciUcet.h"
#include "BeznyUcet.h"
#include "Ucet.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void nejdelsiRadaVkladu(Ucet& nazevUctu)
{
    int aktualni = 0;
    int nejdelsi = 0;
    vector<double>& historie = nazevUctu.getHistorie();
    for(int i = 0; i < historie.size();i++)
    {
        if(historie[i]>0)
        {
            aktualni++;
            if(aktualni>nejdelsi)
            {
                nejdelsi=aktualni;
            }
        }
        else
        {
            aktualni = 0;
        }
    }
    cout<<"Nejdelsi rada v danem uctu: "<<nejdelsi<<endl;
}

void odstraneniMalychVyberu(Ucet& nazevUctu)
{
    vector<double>& historie = nazevUctu.getHistorie();
    for(int i = 0; i <historie.size();i++)
    {
        if(historie[i]<0&& historie[i]>-50)
        {
            historie.erase(historie.begin()+i);
            i--;
        }
    }
    for(int i = 0; i < historie.size(); i++)
    {
        cout<<historie[i]<<" | ";
    }
    cout<<endl;
}

int main()
{
    cout<<"Pocet uctu: "<<Ucet::getPocetUctu()<<endl;

    vector<Ucet*> ucty;

    BeznyUcet *u1 = new BeznyUcet("AB12", 50);
    BeznyUcet * u2 = new BeznyUcet("BC23", 100);
    BeznyUcet *u3 = new BeznyUcet("CD34", 50);
    SporiciUcet * s1 = new SporiciUcet("DE45", 3);

    ucty.push_back(u1);
    ucty.push_back(u2);
    ucty.push_back(u3);
    ucty.push_back(s1);


    vector<double> U1 = {500, 200, 150, -309, -29, 40, 20};
    vector<double> U2 = {143, 20, 15, -3059, -259, 420, -2, 320};
    vector<double> U3 = {12, -15, 50, 39, -29, 120};
    vector<double> S1 = {50, -200, -150, 309 ,920};

    u1 -> pridejTransakce(U1);
    u2 -> pridejTransakce(U2);
    u3 -> pridejTransakce(U3);
    s1 -> pridejTransakce(S1);
    
    cout<<"Pocet uctu: "<<Ucet::getPocetUctu()<<endl;

    for(int i = 0;i<ucty.size(); i++)
    {
        ucty[i]->vypisInfo();
    }

    cout<<"Pocet uctu: "<<Ucet::getPocetUctu()<<endl;

    for(int i = 0; i< ucty.size();i++)
    {
        delete ucty[i];
    }

    odstraneniMalychVyberu(*u1);

    nejdelsiRadaVkladu(*u1);
    
    if(*u1 == *u2)
    {
        cout<<"u1 a u2 jsou stejne\n";
    }
    else
    {
        cout<<"u1 a u2 nejsou stejne poplatky\n";
    }
    if(*u1 == *u3)
    {
        cout<<"u1 a u3 poplatky jsou stejne\n";
    }
    else
    {
        cout<<"u1 a u3 nejsou stejne poplatky\n";
    }

    *u3 += 500;
    u3 ->vypisInfo();

    cout<<"\n"<<*u2<<endl;

    cout<<"\nPocet uctu: "<<Ucet::getPocetUctu()<<endl;   

    return 0;
}
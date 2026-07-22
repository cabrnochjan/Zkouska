#include "Ucet.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int Ucet::pocetUctu = 0;

Ucet::Ucet(string cisloUctu)
{
    this->cisloUctu=cisloUctu;
    pocetUctu++;
}
Ucet::~Ucet()
{
    pocetUctu--;
}
int Ucet::getPocetUctu()
{
    return pocetUctu;
}
void Ucet::pridejTransakci(double hodnota)
{
    historieTransakci.push_back(hodnota);
}
void Ucet::pridejTransakce(const vector<double>& hodnoty)
{
    for(int i = 0; i < hodnoty.size(); i++)
    {
        historieTransakci.push_back(hodnoty[i]);
    }
}
vector<double>& Ucet::getHistorie()
{
    return historieTransakci;
}
void Ucet::vypisInfo()const
{
    cout<<"cislo uctu: "<<cisloUctu<< " pocet transakci: "<<historieTransakci.size();
}
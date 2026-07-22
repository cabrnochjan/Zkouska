#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Ucet
{
    private: 
        static int pocetUctu;
    protected: 
        string cisloUctu;
        vector<double> historieTransakci;
    public:
        Ucet(string cisloUctu);
        virtual ~Ucet();
        static int getPocetUctu();
        void pridejTransakci(double hodnota);
        void pridejTransakce(const vector<double>& hodnoty);
        vector<double>& getHistorie();
        virtual void analyzujUcet()const=0;
        virtual void vypisInfo()const;
    };
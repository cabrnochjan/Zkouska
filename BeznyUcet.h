#pragma once
#include "Ucet.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BeznyUcet : public Ucet
{
    private: 
        double poplatek;
    public:
        BeznyUcet(string cisloUctu, double poplatek);
        void vypisInfo()const;
        void analyzujUcet()const;

        bool operator==(const BeznyUcet& druhy)const;
        void operator+=(double hodnota);
        friend ostream& operator<<(ostream& os,const BeznyUcet& druhy);
};
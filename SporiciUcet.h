#pragma once
#include "Ucet.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class SporiciUcet : public Ucet
{
    private: 
        double urokovaSazba;
    public:
        SporiciUcet(string cisloUctu, double urokovaSazba);
        void vypisInfo()const override;
        void analyzujUcet()const override;
};
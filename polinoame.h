//
// Created by Bleo on 4/17/2019.
//

#ifndef TEMA_2_POO_POLINOAME_POLINOAME_H
#define TEMA_2_POO_POLINOAME_POLINOAME_H
#include <algorithm>
#include <iostream>
#include <fstream>
#include "Vector.h"
//#include "Vector.cpp"

using namespace std;

class Polinom : public Vector{
public:
    ///constructors
    Polinom (int n = 0);
    Polinom (int n,const double *v);
    Polinom (const Vector & v);
    Polinom (const Polinom & P);
    ///destructor
    ~Polinom();
    ///copy
    Polinom & operator = (const Polinom & P);
    ///read
    void read(istream & input);
    //friend istream & operator >> (istream & input,Polinom & P);
    ///write
    void write(ostream & output);
    //friend ostream & operator << (ostream & output,Polinom & P);

    bool operator == (const Polinom & P);
    bool operator != (const Polinom & P);
    bool operator < (const Polinom & P);
    long double value(double X);
    Polinom operator + (Polinom & P);
    Polinom operator - (Polinom & P);
    double & operator [] (int pos);
    friend class Solutie_Polinom;
};

class Solutie_Polinom{
    Polinom P;
    double x;
public:
    Solutie_Polinom();
    Solutie_Polinom(const double & px,Polinom pP);
    Solutie_Polinom(const Solutie_Polinom & S);
    ~Solutie_Polinom();
    friend istream & operator>>(istream & input, Solutie_Polinom & S);
    friend ostream & operator<<(ostream & ouput,const Solutie_Polinom & S);
    bool Verificare();
};

#endif //TEMA_2_POO_POLINOAME_POLINOAME_H

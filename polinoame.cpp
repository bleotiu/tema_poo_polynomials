
//
// Created by Bleo on 4/13/2019.
//
#pragma once
#include <algorithm>
#include <iostream>
#include <fstream>
#include "Vector.h"
//#include "Vector.cpp"
#include "polinoame.h"

using namespace std;
///constructors
Polinom :: Polinom (int n) : Vector(n){}
Polinom :: Polinom (int n,const double *v) : Vector (n,v){}
Polinom :: Polinom (const Vector & v) : Vector (v) {}
Polinom :: Polinom (const Polinom & P) : Vector(P) {}

///destructor
Polinom :: ~Polinom () {}

///copy
Polinom & Polinom :: operator = (const Polinom & P){
    (Vector &) (*this) = P;
    return (Polinom &)(*this);
}

///read & write
void Polinom :: read(istream & input){
    Vector :: read(input);
}
/*istream & operator >> (istream & input, Polinom & P){
    P.Polinom :: read(input);
    return input;
}*/
void Polinom :: write(ostream & output){
    if (length > 0)
        output << p[0];
    else
        output << 0;
    for (int i = 0; i < length; ++i)
        output << " + " << p[i] << "X^" << i;
    output << '\n';
}
/*ostream & operator >> (ostream & output, Polinom & P){
    P.Polinom :: write(output);
    return output;
}*/

bool Polinom :: operator == (const Polinom & P){
    return Vector :: operator== (P);
}

bool Polinom :: operator != (const Polinom & P){
    return !(*this == P);
}

bool Polinom :: operator < (const Polinom & P){
    if (length < P.length)
        return true;
    if (length == P.length){
        int i = length - 1;
        while (i > -1 && p[i] == P.p[i])
            --i;
        if (i > -1 && p[i] < P.p[i])
            return true;
    }
    return false;
}

long double Polinom :: value (double X){
    long double rezultat,factor = X;
    if (length < 1)
        return 0;
    rezultat = p[0];
    for (int i = 1; i < length; ++i){
        rezultat += p[i] * factor;
        factor *= X;
    }
    return rezultat;
}

Polinom Polinom :: operator + (Polinom & P){
    Polinom rezultat = (*this).Vector::operator+(P);
    return rezultat;
}

Polinom Polinom :: operator - (Polinom & P){
    Polinom rezultat = (*this).Vector::operator-(P);
    return rezultat;
}

double & Polinom :: operator [] (int pos){
    if (pos < length)
        return p[pos];
    return ZERO;
}

Solutie_Polinom ::Solutie_Polinom() :x(0), P() {}
Solutie_Polinom ::Solutie_Polinom(const double & px, Polinom pP) :x(px), P(pP) {}
Solutie_Polinom ::Solutie_Polinom(const Solutie_Polinom & S) :x(S.x), P(S.P) {}
Solutie_Polinom ::~Solutie_Polinom() {}
istream & operator>>(istream & input, Solutie_Polinom & S){
    input >> S.P >> S.x;
    return input;
}
ostream & operator<<(ostream & output,const Solutie_Polinom & S){
    output << S.P << '\n' << S.x << '\n';
    return output;
}
bool Solutie_Polinom :: Verificare() {
    if (P.value(x) == 0)
        return true;
    return false;
}


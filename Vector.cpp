//
// Created by Bleo on 4/17/2019.
//

#ifndef TEMA_2_POO_POLINOAME_VECTOR_H
#define TEMA_2_POO_POLINOAME_VECTOR_H

#pragma once
#include <algorithm>
#include <iostream>
#include <fstream>
#include "Vector.h"
using namespace std;


double absolut (double x){
    if (x < 0)
        return -x;
    return x;
}

///constructors
Vector::Vector (int n){
    capacity = n;
    length = n;
    if (n < 1)
        ++capacity;
    p = new double[capacity];
    for (int i = 0; i < capacity; ++i)
        p[i] = 0;
}

Vector::Vector (int n,const double *v){
    capacity = n;
    length = n;
    p = new double[n];
    for (int i = 0; i < length; ++i)
        p[i] = v[i];
}
Vector::Vector (const Vector& v){
    capacity = v.capacity;
    length = v.length;
    p = new double[capacity];
    for (int i = 0 ; i < v.length; ++i)
        p[i] = v.p[i];
}
///destructor
Vector::~Vector (){
    capacity = 1;
    length = 0;
    delete[] p;
}
///copy
Vector& Vector::operator = (const Vector&v){
    if (v.p == p)
        return *this;
    delete[]p;  ///eliberare memorie veche
    capacity = v.capacity;
    length = v.length;
    p = new double[capacity];
    for (int i = 0; i < length; ++i)
        p[i] = v.p[i];
    return *this;
}
double & Vector::operator [] (int pos){
    if (pos < capacity)
        return p[pos];
    //else
    //eroare
    return ZERO;
}

void Vector::push_back (const double & x){
    if(capacity - 1 > length){
        p[length] = x;
        ++length;
    }
    else{
        double *new_address = new double[2 * capacity];
        for (int i = 0; i < length; ++i)
            new_address[i] = p[i];
        new_address[length] = x;
        ++length;
        delete[] p;
        p = new_address;
    }
}
void Vector::pop_back(){
    if (length < 1)
        return;
    --length;
    p[length] = 0;
}
bool Vector::operator == (const Vector &v){
    if (length != v.length)
        return false;
    for (int i = 0; i < length; ++i)
        if (p[i] != v.p[i])
            return false;
    return true;
}
bool Vector::operator != (const Vector & v){
    return !(*this == v);
}
bool Vector::operator < (const Vector & v) const {
    if (length < v.length)
        return true;
    if (length == v.length){
        int i = 0;
        while (i < length && p[i] == v.p[i])
            ++i;
        if (i < length && p[i] < v.p[i])
            return true;
    }
    return false;
}
int Vector::GetSize (){
    return capacity;
}
int Vector::GetLength (){
    return length;
}
void Vector::SetSize (int n){
    delete[] p;
    length = capacity = n;
    p = new double [n];
    for (int i = 0; i < capacity; ++i)
        p[i] = 0;
}
double Vector::Sum (){
    double S = 0;
    for (int i = 0; i < length; ++i)
        S += p[i];
    return S;
}
double Vector::AbsSum (){
    double S = 0;
    for (int i = 0; i < length; ++i)
        S += absolut (p[i]);
    return S;
}
double Vector::Max (int &pos){
    if (length < 1){ ///maximul pe vector nul
        pos = -1;
        return 0;
    }
    double mx = p[0];
    pos = 0;
    for (int i = 1; i < length; ++i)
        if (mx < p[i]){
            mx = p[i];
            pos = i;
        }
    return mx;
}
void Vector::Sort (){
    if (length < 2) ///nu are ce sorta
        return;
    int i,j;
    for (i = 0; i < length; ++i)
        for (j = i + 1; j < length; ++j)
            if (p[i] > p[j])
                swap (p[i],p[j]);
}

///citire vector
void Vector::read (istream &input) {
    if(!length || AbsSum() > 0){ //vector neinitializat sau vector cu elemente in el
        // if(v.AbsSum() > 0)
        //   cout << v;
        int n;
        input >> n;
        capacity = n;
        length = n;
    }
    delete []p;
    p = new double[capacity];
    for (int i = 0; i < length; ++i)
        input >> p[i];
}

istream & operator>>(istream &input, Vector& v) {
    v.read (input);
    return input;
}

///afisare vector
void Vector::write (ostream &output) const {
    //output << "Vectorul are " << v.capacity << "elemente si este : " ;
    for (int i = 0; i < length; ++i)
        output << p[i] << ' ';
    output << '\n';
}

ostream& operator << (ostream &output,const Vector& v) {
    //output << "Vectorul are " << v.capacity << "elemente si este : " ;
    v.write(output);
    return output;
}

Vector Vector::operator + (Vector & v){
    int dimensiune = max(v.length, length);
    Vector rezultat(dimensiune);
    for (int i = 0; i < dimensiune; ++i)
        rezultat[i] = this->operator[](i) + v[i];
    return rezultat;
}
Vector Vector::operator - (Vector & v){
    int dimensiune = max(v.length, length);
    Vector rezultat(dimensiune);
    for (int i = 0; i < dimensiune; ++i)
        rezultat[i] = this->operator[](i) - v[i];
    return rezultat;
}
double Vector::operator * (const Vector & w){
    double scalar = 0;
    int dimensiune = min (length, w.length);
    for (int i = 0; i < dimensiune; ++i)
        scalar += p[i] * w.p[i];
    return scalar;
}
Vector Vector::operator * (double x){
    Vector rezultat(capacity);
    for (int i = 0; i < length; ++i)
        rezultat[i] = x * p[i];
    return rezultat;
}

///scalar * vector
Vector operator * (const double & x, const Vector & v){
    Vector rezultat (v.capacity);
    for (int i = 0; i < v.length; ++i)
        rezultat[i] = x * v.p[i];
    return rezultat;
}

#endif //TEMA_2_POO_POLINOAME_VECTOR_H

#pragma once
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

static double ZERO = 0;

class Vector {
protected:
    int capacity,length;
    double *p;
public:
    ///constructors
    Vector (int n = 0);
    Vector (int n,const double *v);
    Vector (const Vector& v);
    ///destructor
    ~Vector ();
    ///copy
    Vector& operator = (const Vector&v);
    double & operator [] (int pos);

    void push_back (const double & x);
    void pop_back();

    bool operator == (const Vector &v);
    bool operator != (const Vector & v);
    virtual bool operator < (const Vector & v) const;

    int GetSize ();
    int GetLength ();
    void SetSize (int n);

    double Sum ();
    double AbsSum ();
    double Max (int &pos);
    void Sort ();

    virtual void read (istream & input);
    virtual void write (ostream & output) const;
    friend istream& operator >> (istream &input, Vector& v);
    friend ostream& operator << (ostream &output, const Vector& v);

    Vector operator + (Vector & v);
    Vector operator - (Vector & v);
    virtual double operator * (const Vector & w);
    Vector operator * (double x);
    friend Vector operator * (const double & x, const Vector & v);
};
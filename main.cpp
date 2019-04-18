#include <iostream>
#include <fstream>
#include <algorithm>
#include "Vector.h"
//#include "Vector.cpp"
#include "polinoame.h"
//#include "polinoame.cpp"

using namespace std;
ifstream fin ("input");
int main() {
    Polinom a;
    Vector v;
    fin >> v;
    fin >> a;
    //cout << v;
    //cout << a;
    Polinom b(v),c(v);
    fin >> c;
   /* if (c < b)
        cout << "DA";
    else
        cout << "NU";*/
   //cout << b.value(1) << '\n';
   Polinom d = a - c;
   cout << d;
   Solutie_Polinom S(2,d);
   if (S.Verificare())
       cout << "DA";
   else
       cout << "NU";
   return 0;
}
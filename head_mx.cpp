//
// Created by petrk on 19.02.2021.
//
#include "head_mx.h"
#include <cmath>

 long rational::get_p() const{
    return p;
}
 unsigned long rational::get_q() const{
    return q;
}

void rational::easy() {
    unsigned long a = abs(p);
    unsigned long b = q;
    unsigned long t;
   while (a!=b){
       if (a>b)
           a-=b;
       else if (a<b)
           t = a;
           a = b;
           b = t;

   }
   p/=a;
   q/=a;
}

rational::operator double() const {
    double g = p;
    return g/q;
}
 rational operator+ ( rational a,  rational b) {
    rational k(a.get_p() * b.get_q() + a.get_q() * b.get_p(),a.get_q()*b.get_q());
    return k;
}
rational operator- ( rational a,  rational b){
    rational k(a.get_p() * b.get_q() - a.get_q() * b.get_p(),a.get_q()*b.get_q());
    return k;
}
rational operator* ( rational a,  rational b){
    rational k(a.get_p() * b.get_p() ,a.get_q()*b.get_q());
    return k;
}
rational operator/ ( rational a,  rational b){
    rational k(a.get_p() * b.get_q() ,a.get_q()*b.get_p());
    return k;
}

/*
template<typename T>
MATRIX<T> operator+(const MATRIX<T> A, const MATRIX<T> B){};
template<typename T>
MATRIX<T> operator-(const MATRIX<T> A, const MATRIX<T> B){};
template<typename T>
MATRIX<T> operator*(const MATRIX<T> A, const MATRIX<T> B){};
 */
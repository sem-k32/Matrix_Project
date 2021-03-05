//
// Created by petrk on 19.02.2021.
//
#include "head_mx.h"
#include <cmath>
#include <vector>
#include <iostream>

 long rational::get_p() const{
    return p;
}
 unsigned long rational::get_q() const{
    return q;
}

void rational::easy() {
    if (p==0){
        q = 1;
    }
    else {
        long c = abs(p);
        unsigned long b = q;
        unsigned long t;
        while (c != b) {
            if (c > b)
                c -= b;
            else if (c < b) {
                t = c;
                c = b;
                b = t;
            }

        }
        p /= c;
        q /= c;
    }
}

rational::operator double() const {
    double g = p;
    return g/q;
}

void rational::replace_p(long x) {
p = x;
}

void rational::replace_q(long x) {
q = x;
}

rational::rational(long a, unsigned long b): p(a), q(b) {}

rational::~rational() {

}

rational operator+ ( const rational& a,  const rational& b) {
    rational k(((a.get_p() * b.get_q()) + (a.get_q() * b.get_p())),a.get_q() * b.get_q());

    return k;
}
rational operator- ( const rational& a,  const rational& b){
    rational k(a.get_p() * b.get_q() - a.get_q() * b.get_p(),a.get_q()*b.get_q());

    return k;
}
rational operator* ( const rational& a,  const rational& b){
    rational k(a.get_p() * b.get_p() ,a.get_q()*b.get_q());

    return k;
}
rational operator/ ( const rational& a,  const rational& b){
    rational k(a.get_p() * b.get_q() ,a.get_q()*b.get_p());

    return k;
}

template<typename T>
void MATRIX<T>::vvod(){

    for (int i = 0; i < this->get_m(); i++){
        for(int j = 0; j < this->get_n(); j++){
            std::cin>>matrix[j][i];
        }
    }
}
template<typename T>
void MATRIX<T>::vivod(){

    for (int i = 0; i < this->get_m(); i++){
        for(int j = 0; j < this->get_n(); j++){
            std::cout<<matrix[j][i];
        }
    }
}
template<typename T>
T MATRIX<T>::get_element(unsigned int row, unsigned int column){
    return matrix[column][row];
}
template<typename T>
 MATRIX<T>::MATRIX(unsigned  int rows, unsigned int columns): m(rows),n(columns){
    matrix.resize(n);
    for (int i = 0; i < n; i++){
        matrix[i].resize(m);
    }
}
//TODO check this
template<typename T>
void MATRIX<T>::add_row(){
    m++;
    for (int i = 0; i < n; i++){
        matrix[i].resize(m);
    }
}
//TODO check this
template<typename T>
void MATRIX<T>::add_column(){
    n++;
    std::vector<T> a(m);
    matrix.push_back(a);
}
//TODO check this
template<typename T>
MATRIX<T> MATRIX<T>::transpose(){
    MATRIX B( this->get_n(), this->get_m() );
    for (int i = 0; i < this->get_n(); i++){
        for(int j = 0; j < this->get_m(); j++){
            B.matrix[j][i];
        }
    }
}
/*
template<typename T>
MATRIX<T> operator+(const MATRIX<T> A, const MATRIX<T> B){};
template<typename T>
MATRIX<T> operator-(const MATRIX<T> A, const MATRIX<T> B){};
template<typename T>
MATRIX<T> operator*(const MATRIX<T> A, const MATRIX<T> B){};
 */
#ifndef MATRIX_HEAD_MX_H
#define MATRIX_HEAD_MX_H
// класс рациональных чисел
class rational {
private:
    // числитель
    long p;
    // знаменатель
    unsigned long q;
public:
rational(long p, unsigned long q ){};
~rational(){}
// вывод числителя и знаменателя
 long get_p() const;
 unsigned long get_q() const;
// перевод в double
operator double() const;
// сокращение НОДа
void easy();

};


#endif //MATRIX_HEAD_MX_H

//
// Created by petrk on 14.02.2021.
//
#include <vector>
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
// операции с рациональными числами
//rational operator +( rational &a,  rational &b){};
//rational operator -( rational &a,  rational &b){};
//rational operator *( rational &a,  rational &b){};
//rational operator /( rational &a,  rational &b){};


template <typename T>
class MATRIX {
private:
    unsigned int n,m;
    // prepare for trouble
    // and make it double!
    std::vector < std::vector < T > > matrix ;

public:
    // добавить ввод из файла
    MATRIX();
    // добавить строку
    void add_row();
    // добавить столбец
    void add_column();
    // вывод размеров матрицы
    unsigned int get_n();
    unsigned int get_m();
    // склейка матриц
    MATRIX add_matrix(MATRIX A, MATRIX B);
    // транспонирование
    MATRIX transpose(MATRIX A);
    // элементарные операции с матрицами
    void multiply_row_by(T, unsigned  int row);
    void minus_multiplied_row(unsigned int multiplier, unsigned int row_mod, unsigned int row_orig);
    // алгоритм Гаусса
    MATRIX Gauss();
    // вычисление ранга матрицы
    unsigned int rank();
    // вывод фундаментальной системы решений
    MATRIX Fund_sol_syst();
    // решение СЛАУ
    MATRIX SLAE_sol(MATRIX A);
    // вычисление детерминанта
    T determinant();
    // нахождение обратной матрицы
    MATRIX reversed();
    // нахождение базисного минора
    MATRIX based_minor();
    // вывод матрицы
    void vivod();
    // сохранение в файл
    void vfail();
    // выгрузка из файла
    MATRIX izfaila();
};

// операции с матрицами
// добавить проверку размеров




#endif //MATRIX_HEAD_MX_H

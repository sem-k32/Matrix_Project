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
    //конструктор
rational(long a, unsigned long b );
    //деструктор
~rational();
// вывод числителя и знаменателя
 long get_p() const;
 unsigned long get_q() const;
    // замена числителя и знаменателя
    void replace_p(long x);
    void replace_q(long x);


// перевод в double
operator double() const;
// сокращение НОДа
void easy();
// конструктор копирования
//void copy (rational whom, rational to);




};
// операции с рациональными числами
rational operator +(const rational &a, const rational &b);
rational operator -(const rational &a, const rational &b);
rational operator *(const rational &a, const rational &b);
rational operator /(const rational &a, const rational &b);


template <typename T>
class MATRIX {
private:
    unsigned int n,m;
    // prepare for trouble
    // and make it double!
    std::vector < std::vector < T > > matrix ;

public:
    // доступ к элементу из матрицы по номеру строки
    T get_element(unsigned int row, unsigned int column);
    // ввод значений в матрицу, предполагается, что размеры известны
    void vvod();
    // вывод значений матрицы
    void vivod();
    // добавить ввод из файла
    MATRIX(unsigned  int rows, unsigned int columns);
    // добавить строку вниз
    void add_row();
    // добавить столбец вправо
    void add_column();
    // изменить строку

    // изменить столбец

    // вывод размеров матрицы
    unsigned int get_n();
    unsigned int get_m();
    // склейка матриц
    MATRIX add_matrix(MATRIX A, MATRIX B);
    // транспонирование
    MATRIX transpose();
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
    // сохранение в файл
    void vfail();
    // выгрузка из файла
    MATRIX izfaila();
};

// операции с матрицами
// добавить проверку размеров




#endif //MATRIX_HEAD_MX_H

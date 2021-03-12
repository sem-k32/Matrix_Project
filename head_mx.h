//
// Created by petrk on 14.02.2021.
//
#include <iostream>
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
    //конструктор без переменных
    rational(){p = 0; q = 1;}
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
// перегрузка ввода
   friend std::istream& operator>> (std::istream &in, rational &ratio){
       in >> ratio.p;
       in >> ratio.q;
        return in;

   }
   // перегрузка ввода
    friend std::ostream& operator<< (std::ostream &out, const rational &ratio)
    {
        if (ratio.get_q()!= 1)
            out << ratio.get_p() <<'/'<< ratio.get_q() ;
        else
            out <<ratio.get_p();

        return out;
    }

};
// операции с рациональными числами
rational operator +(const rational &a, const rational &b);
rational operator -(const rational &a, const rational &b);
rational operator *(const rational &a, const rational &b);
rational operator /(const rational &a, const rational &b);




template <typename T>
class MATRIX {

public:
    MATRIX(unsigned  int rows, unsigned int columns): m(rows),n(columns){
        matrix.resize(n);
        for (int i = 0; i < n; i++){
            matrix[i].resize(m);
        }
    }
    // доступ к элементу из матрицы по номеру строки
    T get_element(unsigned int row, unsigned int column){
        return matrix[column][row];
    }
    // ввод значений в матрицу, предполагается, что размеры известны
    void vvod(){

        for (int i = 0; i < this->get_m(); i++){
            for(int j = 0; j < this->get_n(); j++){
                std::cin>>matrix[j][i];
            }
        }
    }
    // вывод значений матрицы
    void vivod(){

        for (int i = 0; i < this->get_m(); i++){
            for(int j = 0; j < this->get_n(); j++){
                std::cout<<matrix[j][i]<<' ';
            }
            std::cout<<'\n';
        }
    }
    // добавить ввод из файла

    // добавить строку вниз
    void add_row(){
        m++;
        for (int i = 0; i < n; i++){
            matrix[i].resize(m);
        }
    }
    // добавить столбец вправо
    void add_column(){
        n++;
        std::vector<T> a(m);
        matrix.push_back(a);
    }
    // изменить строку
    void change_row(unsigned int row){
        for (int i = 0; i < get_n(); i++){
            std::cin>>matrix[i][row];
        }

    }
    // изменить столбец
    void change_column(unsigned int column){
        for (int i = 0; i < get_m(); i++){
            std::cin>>matrix[column][i];
        }

    }

    // запрос размеров матрицы
    unsigned int get_n(){
        return n;
    }
    unsigned int get_m(){
        return m;
    }
    // склейка матриц
    MATRIX add_matrix(MATRIX A, MATRIX B);
    // транспонирование
    MATRIX transpose(){
        MATRIX B( this->get_n(), this->get_m() );
        for (int i = 0; i < this->get_n(); i++){
            for(int j = 0; j < this->get_m(); j++){
                B.matrix[j][i] = matrix[i][j];
            }
        }
        return B;
    }
    // элементарные операции с матрицами
    // умножение строки на число
    void multiply_row_by(T multiplier, unsigned  int row){
        for (int i = 0; i<get_n();i++){
            matrix[i][row]= matrix[i][row]*multiplier;
        }

    }
    // вычитание строки умноженной на число
    void minus_multiplied_row(T multiplier, unsigned int row_mod, unsigned int row_orig){
        for (int i = 0; i<get_n();i++){
            matrix[i][row_mod] = matrix[i][row_mod] - multiplier*matrix[i][row_orig];
        }

    }
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

private:
    unsigned int n,m;
    // prepare for trouble
    // and make it double!
    std::vector < std::vector < T > > matrix ;

};

// операции с матрицами
// добавить проверку размеров




#endif //MATRIX_HEAD_MX_H

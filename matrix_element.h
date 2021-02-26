#ifndef MATRIX_ELEMENT_H
#define MATRIX_ELEMENT_H

#include <QtWidgets>
#include "matel_inputnumber.h"

class Matrix_Element : public QWidget
{
    Q_OBJECT
public:
    explicit Matrix_Element(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent* me) override;
    void paintEvent(QPaintEvent* ke) override;
    void keyPressEvent(QKeyEvent* ke) override;

private:
    double value;

    QRgb back_colour;

signals:

};

#endif // MATRIX_ELEMENT_H

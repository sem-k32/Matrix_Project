#ifndef MATEL_INPUTNUMBER_H
#define MATEL_INPUTNUMBER_H

#include <QDialog>

class MatEl_InputNumber : public QDialog
{
    Q_OBJECT

public:
    MatEl_InputNumber(QWidget *parent = nullptr);
    ~MatEl_InputNumber();
};
#endif // MATEL_INPUTNUMBER_H

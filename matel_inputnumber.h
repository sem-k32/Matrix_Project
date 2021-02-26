#ifndef MATEL_INPUTNUMBER_H
#define MATEL_INPUTNUMBER_H

#include <QDialog>
#include <QLineEdit>
#include <QKeyEvent>
#include <QDoubleValidator>
#include <QVBoxLayout>

class MatEl_InputNumber : public QDialog
{
    Q_OBJECT

public:
    MatEl_InputNumber(QWidget *parent = nullptr);

    QString getText() const;


protected:
    void keyPressEvent(QKeyEvent* ke) override;

private:
    QLineEdit* input_field;

signals:
    void theEnd();
    void cancel();

};
#endif // MATEL_INPUTNUMBER_H

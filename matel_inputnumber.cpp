#include "matel_inputnumber.h"

MatEl_InputNumber::MatEl_InputNumber(QWidget *parent)
    : QDialog(parent)
{
    setWindowFlags(Qt::SplashScreen);

    input_field = new QLineEdit();
    input_field->setPlaceholderText("Введите вещественное число");
    input_field->setMaxLength(30);

    QDoubleValidator* val = new QDoubleValidator(0,10,10);
    input_field->setValidator(val);

    input_field->resize(40,10);

    connect(this,&MatEl_InputNumber::cancel,&QDialog::reject);
    connect(this,&MatEl_InputNumber::theEnd,&MatEl_InputNumber::accept);

    QPoint leftBot = parent->pos();
    leftBot.rx() += parent->width() * 0.80;
    leftBot.ry() += parent->height() * 0.20;
    QSize wgSize = input_field->size();
    setGeometry(QRect(leftBot,wgSize));
    //input_field->setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::Maximum));

    QVBoxLayout* lay = new QVBoxLayout;
    lay->addWidget(input_field);

    setLayout(lay);
}

void MatEl_InputNumber::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key() == Qt::Key_Shift)
        emit theEnd();
    else if(ke->key() == Qt::Key_Escape)
        emit cancel();
}

QString MatEl_InputNumber::getText() const
{
    return input_field->text();
}


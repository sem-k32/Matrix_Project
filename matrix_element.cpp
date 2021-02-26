#include "matrix_element.h"

Matrix_Element::Matrix_Element(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(Qt::ToolTip);
    this->resize(100,50);

    int r = QRandomGenerator::global()->bounded(0,255);
    int g = QRandomGenerator::global()->bounded(0,255);
    int b = QRandomGenerator::global()->bounded(0,255);

    back_colour = qRgb(r,g,b);

    value = 0;

    repaint();
}

void Matrix_Element::mousePressEvent(QMouseEvent *me)
{
    MatEl_InputNumber* field = new MatEl_InputNumber(this);

    if(field->exec() == QDialog::Accepted)
    {
        QString val = field->getText();
        if(val.contains(","))
            val.replace(",",".");

        value = val.toDouble();
        repaint();
    }

    delete field;
}

void Matrix_Element::paintEvent(QPaintEvent *ke)
{
    QPalette pal = this->palette();
    pal.setColor(QPalette::Window,back_colour);
    this->setPalette(pal);

    QPainter pt(this);

    QPoint firstP = this->rect().bottomLeft();
    firstP.rx() += this->width() * 0.2;
    firstP.ry() -= this->height() * 0.2;

    QPoint secP = this->rect().bottomRight();
    secP.rx() -= this->width() * 0.2;
    secP.ry() -= this->height() * 0.2;

    pt.setPen(QPen(Qt::black,2));

    pt.drawLine(firstP,secP);

    pt.setFont(QFont("Times",10));

    QPoint startTextPoint = this->rect().center();
    startTextPoint.rx() -= this->width()*0.3;
    startTextPoint.ry() += this->height()*0.25;

    QString strToDraw = fontMetrics().elidedText(QString::number(value),
                                    Qt::ElideRight,this->width()*0.5);
    //QString strToDraw = QString::number(value);


    pt.drawText(startTextPoint,strToDraw);
}

void Matrix_Element::keyPressEvent(QKeyEvent *ke)
{
    switch (ke->key()) {
    case Qt::Key_Escape:
        this->close();
        break;
    default:
        break;
    }
}

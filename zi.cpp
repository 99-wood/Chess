#include "zi.h"

QString Zi::TransformName()
{
    QString ans = "://image/";
    switch (contry) {
    case black:
        ans += "hei";
        break;
    case red:
        ans += "hong";
        break;
    }
    switch (armType) {
    case shuai:
        ans += "shuai";
        break;
    case jv:
        ans += "jv";
        break;
    case ma:
        ans += "ma";
        break;
    case pao:
        ans += "pao";
        break;
    case shi:
        ans += "shi";
        break;
    case xiang:
        ans += "xiang";
        break;
    case zu:
        ans += "zu";
        break;
    }
    ans += ".svg";      // "://image/heijiang.svg"
    return ans;
}

void Zi::mouseReleaseEvent(QMouseEvent *event)
{
    if(!isSelected)emit Selected(this);
    else emit UnSelected(this);
}

Zi::Zi(QWidget *parent) : QWidget(parent)
{

}

Zi::Zi(QWidget *parent, const Contry &contry, const ArmType &armType, const int &x, const int &y)
    : QWidget(parent), contry(contry), armType(armType), x(x), y(y)
{
    Move(x, y);
    setAutoFillBackground(true);
    QPalette tmp = this -> palette();
    tmp.setBrush(QPalette::Background, QBrush(QPixmap(TransformName()).scaled(
                                                  this -> size(),
                                                  Qt::IgnoreAspectRatio,
                                                  Qt::SmoothTransformation)));
    setPalette(tmp);
    connect(this, &Zi::Selected, this, [=](){
        isSelected = true;
        kuang = new QWidget(this);
        kuang -> setAutoFillBackground(true);
        kuang -> setGeometry(0, 0, chessSize, chessSize);
        QPalette tmp = kuang -> palette();
        tmp.setBrush(QPalette::Background, QBrush(QPixmap("://image/kuang.svg").scaled(
                                                      kuang -> size(),
                                                      Qt::IgnoreAspectRatio,
                                                      Qt::SmoothTransformation)));
        kuang -> setPalette(tmp);
        kuang -> show();
    });
    connect(this, &Zi::UnSelected, this, &Zi::CancelSelected);
}

bool Zi::GetAlive()
{
    return alive;
}

int Zi::Getx()
{
    return (this -> pos().x() + chessSize / 2 + 40) / 80;
}

int Zi::Gety()
{
    return (this -> pos().y() + chessSize / 2 - 40) / 80;
}

Contry Zi::GetCountry()
{
    return contry;
}

ArmType Zi::GetArmType()
{
    return armType;
}

void Zi::Move(const int &x, const int &y)
{
    setGeometry(x * chessSize - 40 - chessSize / 2, y * chessSize + 40 - chessSize / 2, chessSize, chessSize);
}

void Zi::BeDead()
{
    alive = false;
    close();
}

void Zi::CancelSelected()
{
    delete kuang;
    kuang = nullptr;
    isSelected = false;
}



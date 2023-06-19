#ifndef ZI_H
#define ZI_H

#include <QWidget>
#include <QString>
#include <QDebug>
#include <QPushButton>
#include <QMouseEvent>
#include <QPoint>

enum ArmType{shuai, jv, ma, pao, shi, xiang, zu};
enum Contry {black, red};
class Zi : public QWidget
{
    Q_OBJECT
    Contry contry;      //阵营
    ArmType armType;    //兵种
    int x, y;
    bool isSelected = false, alive = true, enableSelect = true;
    const int chessSize = 80;
    QWidget *kuang = nullptr;
    QString TransformName();
protected:
//    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
public:
    explicit Zi(QWidget *parent = nullptr);
    explicit Zi(QWidget *parent = nullptr, const Contry &contry = red,
                const ArmType &armType = shuai, const int &x = 0, const int &y = 0);
    Contry GetCountry();
    ArmType GetArmType();
    bool GetAlive();
    int Getx();
    int Gety();
    void setEnableSelect(bool flag);

signals:
    void Selected(Zi *id);
    void UnSelected(Zi *id);
    void Die(Zi *id);
public slots:
    void Move(const int &x, const int &y);
    void BeDead();
    void BeAlive();
    void CancelSelected();
};

#endif // ZI_H

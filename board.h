#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPalette>
#include <QBrush>
#include <QPushButton>
#include <QMessageBox>
#include <QVector>
#include <QDebug>
#include <QMessageBox>
#include "zi.h"
#include "legalpoint.h"

namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();

private:
    Ui::Board *ui;
//    const int chessSize = 40;
    const int posx[10] = {0, 40, 120, 200, 280, 360, 440, 520, 600, 680},
        posy[11] = {0, 120, 200, 280, 360, 440, 520, 600, 680, 760, 840};
    QVector<Zi*> zi;
    QVector<LegalPoint*> legalPoint;
    Zi *selectedZi = nullptr;
    Zi* GetZi(int x, int y);
    bool IfLegalMove(Zi* zi, int x, int y);

public slots:
    void SelectZi(Zi* zi);
    void UnSelectZi(Zi* zi);
    void MoveZi(LegalPoint* id);
};

#endif // BOARD_H

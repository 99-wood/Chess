#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui -> buttonStart -> move((this -> width() - ui -> buttonStart -> width()) * 1 / 2,
                              (this -> height() - ui -> buttonStart -> height()) * 1 / 4);

    ui -> buttonLast -> move((this -> width() - ui -> buttonLast -> width()) * 1 / 2,
                              (this -> height() - ui -> buttonLast -> height()) * 3 / 4);
    connect(ui -> buttonStart, &QPushButton::clicked, this, [=](){
        Board *newPage = new Board(nullptr);
        newPage -> setAttribute(Qt::WA_DeleteOnClose);
        newPage -> show();
    });
    connect(ui -> buttonReproduce, &QPushButton::clicked, this, [=](){
        Reproduce *newPage = new Reproduce(nullptr);
        newPage -> setAttribute(Qt::WA_DeleteOnClose);
        if(newPage -> IfSuccessBuild())newPage -> show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap("://image/play_chess_fixed_2.png").scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}


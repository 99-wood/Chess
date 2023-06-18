#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> setWindowTitle("开始");
    this -> setFixedSize(600, 400);
    ui -> buttonStart -> move((this -> width() - ui -> buttonStart -> width()) * 1 / 2,
                              (this -> height() - ui -> buttonStart -> height()) * 1 / 4);

    ui -> buttonLast -> move((this -> width() - ui -> buttonLast -> width()) * 1 / 2,
                              (this -> height() - ui -> buttonLast -> height()) * 3 / 4);
    connect(ui -> buttonStart, &QPushButton::clicked, this, [=](){
        QWidget *newPage = new Board(nullptr);
        newPage -> setAttribute(Qt::WA_DeleteOnClose);
        newPage -> show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


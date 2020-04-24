#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Kill.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Kill::kill(ui->lineEdit->text().toInt());
    ui->label->setText("Укажите время в минутах и нажмите кнопку\nКиллер в деле");
}

#include "mainwindow.h"
#include "Kill.h"
#include "ui_mainwindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->reset->setDisabled(true);
  ui->label->setText("Укажите время в минутах и нажмите кнопку");
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_start_clicked() {
  Kill::kill(ui->lineEdit->text().toInt());
  if (!reset) {
    ui->label->setText("Киллер в деле");
  }
  ui->lineEdit->setDisabled(true);
  ui->start->setDisabled(true);
  ui->reset->setDisabled(false);
}

void MainWindow::on_reset_clicked() {
  ui->lineEdit->setDisabled(false);
  ui->start->setDisabled(false);
  ui->label->setText("Укажите новое значение");
  reset = true;
}

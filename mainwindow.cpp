#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QMainWindow>
#include <QSysInfo>
#include <QMessageBox>

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



void MainWindow::on_addPushButton_clicked()
{
    QString text = ui->lineEdit->text();

    if (!text.isEmpty()){
        ui->listWidget->addItem(text);
        ui->lineEdit->clear();

    }
}


void MainWindow::on_deleteButton_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    if(item)
    {
        delete ui->listWidget->takeItem(ui->listWidget->row(item));
    }
}


void MainWindow::on_clearButton_clicked()
{
    ui->listWidget->clear();
}


void MainWindow::on_InfoButton_clicked()
{

    QListWidgetItem *item = ui->listWidget->currentItem();

    if(item)

    {
    QString text = item->text();
    text = text.toUpper();
    item->setText(text);
    }
    else{
        QMessageBox::critical(this, "Eror", "Eror не вибрано поле.", QMessageBox::Ok);
    }
}


void MainWindow::on_lowerButton_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    if(item)
    {
    QString text = item->text();
    text = text.toLower();
    item->setText(text);
    }
    else
    {
        QMessageBox::critical(this, "Eror", "Не вибрано поле.", QMessageBox::Ok);
    }
}


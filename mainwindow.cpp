#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QEventLoop>


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


void MainWindow::on_Run_clicked()
{
    if (equide == 1)
    {
            system("wmic process where name=\"ShaderCompileWorker.exe\" CALL setpriority 32768");
            ui->RunBoost->setText("On");

    }

}

void MainWindow::on_Stop_clicked()
{
    system("wmic process where name=\"ShaderCompileWorker.exe\" CALL setpriority 32");
    ui->RunBoost->setText("Off");
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    equide = ui->horizontalSlider->value();
}

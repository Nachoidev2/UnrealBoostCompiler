#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QEventLoop>
#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <stdio.h>
#include <process.h>

using namespace std;

DWORD FindProcessId(const std::wstring& processName);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Actulizar()));
    running = true;

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Actualizar()
{

/*    if ( FindProcessId(L"firefox.exe") )
    {
        running = true;
    }
    else
    {
        running = false;
    }
*/
}


void MainWindow::on_Run_clicked()
{
    if (running == true)
    {
        if (equide == 0)
        {
                system("wmic process where name=\"ShaderCompileWorker.exe\" CALL setpriority 32");
                ui->RunBoost->setText("On");

        }
        if (equide == 1)
        {
                system("wmic process where name=\"ShaderCompileWorker.exe\" CALL setpriority 32768");
                ui->RunBoost->setText("On");

        }
        if (equide == 2)
        {
                system("wmic process where name=\"ShaderCompileWorker.exe\" CALL setpriority 128");
                ui->RunBoost->setText("On");

        }
    }



}

void MainWindow::on_Stop_clicked()
{
    system("wmic process where name=\"ShaderCompileWorker.exe\" CALL setpriority 16384");
    ui->RunBoost->setText("Off");
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    equide = ui->horizontalSlider->value();
}



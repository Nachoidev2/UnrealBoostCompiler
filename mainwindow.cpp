#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QEventLoop>
#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <stdio.h>
#include <process.h>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <string>


using namespace std;

DWORD FindProcessId(const std::wstring& processName);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Actualizar()));
    time.setHMS(0,1,0);
    timer->start(1000);
    system ("start /min %cd%/Verificador.vbs");
}


MainWindow::~MainWindow()
{
    delete ui;
}

// Evento de actualizacion
void MainWindow::Actualizar()
{

    CheckRunUnrealCompiler();
    CheckProcess();
    EventAutoRun();

}

void MainWindow::CheckProcess()
{
    QString fileName("./equide.txt");
    QFile file(fileName);
    if(QFileInfo::exists(fileName))
    {
        running = true;
    }
    else
    {
        running = false;
    }
}

// Comprueba si se esta ejecutando el compilador de Unreal
void MainWindow::CheckRunUnrealCompiler()
{

    if ( running == true )
    {
        ui->RunUnrealCompiler->setText("On");
    }
    else
    {
        ui->RunUnrealCompiler->setText("Off");
    }

}

// Boton de iniciar Boost
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
                ui->RunUnrealCompiler->setText("On");

        }
        if (equide == 2)
        {
                system("wmic process where name=\"ShaderCompileWorker.exe\" CALL setpriority 128");
                ui->RunBoost->setText("On");

        }
    }
}

// Boton de parar
void MainWindow::on_Stop_clicked()
{
    system("wmic process where name=\"ShaderCompileWorker.exe\" CALL setpriority 16384");
    ui->RunBoost->setText("Off");
}

// Slider que cambiar el perfil
void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    equide = ui->horizontalSlider->value();
}

// AutoRun
void MainWindow::on_checkBox_toggled(bool checked)
{
    if (checked == true)
    {
        AutoRun = true;
    }
    else
    {
        AutoRun = false;
    }
}

void MainWindow::EventAutoRun()
{
    if (AutoRun == true)
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
                    ui->RunUnrealCompiler->setText("On");

            }
            if (equide == 2)
            {
                    system("wmic process where name=\"ShaderCompileWorker.exe\" CALL setpriority 128");
                    ui->RunBoost->setText("On");

            }
        }
    }
}

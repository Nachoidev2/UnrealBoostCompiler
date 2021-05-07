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
    system ("start /min Verificador.vbs");
    time.setHMS(0,1,0);
    timer->start(1000);
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
    EventAutoStop();

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
    if (BoostOn == true)
    {
        ui->RunBoost->setText("On");
    }
    else
    {
        ui->RunBoost->setText("Off");
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
                system("wmic process where name=\"UnrealLightmass.exe\" CALL setpriority 32");
                BoostOn = true;

        }
        if (equide == 1)
        {
                system("wmic process where name=\"ShaderCompileWorker.exe\" CALL setpriority 32768");
                system("wmic process where name=\"UnrealLightmass.exe\" CALL setpriority 32768");
                BoostOn = true;

        }
        if (equide == 2)
        {
                system("wmic process where name=\"ShaderCompileWorker.exe\" CALL setpriority 128");
                system("wmic process where name=\"UnrealLightmass.exe\" CALL setpriority 128");
                BoostOn = true;

        }
    }
    else
    {
        system ("start /min MensajeError.vbs");
    }
}

// Boton de parar
void MainWindow::on_Stop_clicked()
{
    system("wmic process where name=\"ShaderCompileWorker.exe\" CALL setpriority 16384");
    BoostOn = false;
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
            if (BoostOn == false)
            {
                if (equide == 0)
                {
                        system("wmic process where name=\"ShaderCompileWorker.exe\" CALL setpriority 32");
                        system("wmic process where name=\"UnrealLightmass.exe\" CALL setpriority 32");
                        BoostOn = true;

                }
                if (equide == 1)
                {
                        system("wmic process where name=\"ShaderCompileWorker.exe\" CALL setpriority 32768");
                        system("wmic process where name=\"UnrealLightmass.exe\" CALL setpriority 32768");
                        BoostOn = true;

                }
                if (equide == 2)
                {
                        system("wmic process where name=\"ShaderCompileWorker.exe\" CALL setpriority 128");
                        system("wmic process where name=\"UnrealLightmass.exe\" CALL setpriority 128");
                        BoostOn = true;

                }
            }

        }
    }
}

void MainWindow::EventAutoStop()
{
    if (running == false)
    {
        if (BoostOn == true)
        {
            system("wmic process where name=\"ShaderCompileWorker.exe\" CALL setpriority 16384");
            BoostOn = false;
        }
    }
}


void MainWindow::MensajeError()
{

}

void MainWindow::on_Instagram_clicked()
{
    system ("start /min https://www.instagram.com/nachoide.v2.0.dll/");
}

void MainWindow::on_Twitter_clicked()
{
    system ("start /min https://twitter.com/NachoideV2");
}

void MainWindow::on_pushButton_2_clicked()
{
    system ("start /min https://www.linkedin.com/in/ignacio-peralta-768396174/");
}

void MainWindow::on_pushButton_3_clicked()
{
    system ("start /min https://nachoidev2.github.io/");
}


void MainWindow::on_Github_clicked()
{
   system ("start /min https://github.com/NachoideV2");
}

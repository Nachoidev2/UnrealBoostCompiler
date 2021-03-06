#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QProcess>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <tchar.h>
#include<Windows.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int equide=1;
    bool running=false;
    bool AutoRun=false;
    bool BoostOn=false;
    bool Shaders=false;
    bool Light=false;
    QTimer *timer=new QTimer();
    QTime time;

public slots:


private slots:
    void on_Run_clicked();

    void on_Stop_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void Actualizar();

    void CheckRunUnrealCompiler();

    void CheckProcess();

    void EventAutoRun();

    void EventAutoStop();

    void MensajeError();

    void on_checkBox_toggled(bool checked);

    void on_Instagram_clicked();

    void on_Twitter_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


    void on_Github_clicked();

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H


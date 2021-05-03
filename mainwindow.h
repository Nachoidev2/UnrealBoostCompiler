#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Run_clicked();

    void on_Stop_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_checkBox_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    int equide= 1;
    bool running= false;
    void UpdateStatus();

};
#endif // MAINWINDOW_H

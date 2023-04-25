
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPalette>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void upTemperature();
    void downTemperature();
    void downHumid();
    void upHumid();
    void upCo2();
    void downCo2();
    void goLogout();
    void changeWaterColor();
    void changeWindColor();
    void changeSunColor();
    void changeCloudColor();
};

#endif // MAINWINDOW_H

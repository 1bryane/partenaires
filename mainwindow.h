#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "partenaires.h"
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


    void on_addpart_clicked();

    void on_supp_clicked();

private:
    Ui::MainWindow *ui;
    partenaires p;
};
#endif // MAINWINDOW_H

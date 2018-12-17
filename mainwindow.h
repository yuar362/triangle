#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Vector3D.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //calculate
    void on_countPB_clicked();    
private:
    Ui::MainWindow *ui;
    Vector3D triangle_point1;
    Vector3D triangle_point2;
    Vector3D triangle_point3;

    Vector3D segment_point1;
    Vector3D segment_point2;
};

#endif // MAINWINDOW_H

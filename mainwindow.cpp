#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Triangle.h"

#include <QDoubleValidator>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //validators
    QDoubleValidator *dv = new QDoubleValidator;
    ui->triangle_point1_z->setValidator(dv);
    ui->triangle_point1_y->setValidator(dv);
    ui->triangle_point1_x->setValidator(dv);

    ui->triangle_point2_z->setValidator(dv);
    ui->triangle_point2_y->setValidator(dv);
    ui->triangle_point2_x->setValidator(dv);

    ui->triangle_point3_z->setValidator(dv);
    ui->triangle_point3_y->setValidator(dv);
    ui->triangle_point3_x->setValidator(dv);

    ui->segment_point1_x->setValidator(dv);
    ui->segment_point1_y->setValidator(dv);
    ui->segment_point1_z->setValidator(dv);

    ui->segment_point2_x->setValidator(dv);
    ui->segment_point2_y->setValidator(dv);
    ui->segment_point2_z->setValidator(dv);

}

MainWindow::~MainWindow()
{
    delete ui;    
}


void MainWindow::on_countPB_clicked()
{
    triangle_point1[0] = ui->triangle_point1_x->text().toDouble();
    triangle_point1[1] = ui->triangle_point1_y->text().toDouble();
    triangle_point1[2] = ui->triangle_point1_z->text().toDouble();

    triangle_point2[0] = ui->triangle_point2_x->text().toDouble();
    triangle_point2[1] = ui->triangle_point2_y->text().toDouble();
    triangle_point2[2] = ui->triangle_point2_z->text().toDouble();

    triangle_point3[0] = ui->triangle_point3_x->text().toDouble();
    triangle_point3[1] = ui->triangle_point3_y->text().toDouble();
    triangle_point3[2] = ui->triangle_point3_z->text().toDouble();

    if((triangle_point2 - triangle_point1).cross(triangle_point3 - triangle_point1) == Vector3D())
    {
        ui->lineEdit->setText(QString::fromLocal8Bit("Точки треугольника лежат на одной прямой"));
        return;
    }

    segment_point1[0] = ui->segment_point1_x->text().toDouble();
    segment_point1[1] = ui->segment_point1_y->text().toDouble();
    segment_point1[2] = ui->segment_point1_z->text().toDouble();

    segment_point2[0] = ui->segment_point2_x->text().toDouble();
    segment_point2[1] = ui->segment_point2_y->text().toDouble();
    segment_point2[2] = ui->segment_point2_z->text().toDouble();


    if(segment_point2 - segment_point1 == Vector3D())
    {
        ui->lineEdit->setText(QString::fromLocal8Bit("Отрезок нулевой длины"));
        return;
    }

    Triangle triangle(triangle_point1, triangle_point2, triangle_point3);
    Vector3D intersection_point;
    QString result;
    if(triangle.getIntersection(segment_point1, segment_point2, intersection_point))
    {
        result = QString::fromLocal8Bit("Точка пересечения X = ") + QString::number(intersection_point[0]) + " Y = " +
                QString::number(intersection_point[1]) + " Z = " + QString::number(intersection_point[2]);
    }
    else
    {
        result = QString::fromLocal8Bit("Отрезок и треугольник не пересекаются");
    }
    ui->lineEdit->setText(result);
}

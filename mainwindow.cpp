#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QtNumeric>

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

void MainWindow::on_coloring_prob_slider_sliderMoved(int position)
{
    ui->coloring_prob->setText(QString::number(
        static_cast<double>(position) / 1000.0));
}


void MainWindow::on_coloring_prob_slider_valueChanged(int value)
{
    ui->coloring_prob->setText(QString::number(
        static_cast<double>(value) / 1000.0));
}


void MainWindow::on_coloring_prob_editingFinished()
{
    double prob = ui->coloring_prob->text().toDouble();
    if (prob < 0.0 || prob > 1.0) {
        prob = 0.0;
    }

    int val = qRound(prob * 1000.0);
    prob = static_cast<double>(val) / 1000.0;

    ui->coloring_prob_slider->setValue(val);
    ui->coloring_prob->setText(QString::number(prob));
}


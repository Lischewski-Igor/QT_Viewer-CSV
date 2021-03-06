#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newdialog.h" //Das wurde eingefügt
#include <QStandardItemModel> //Das wurde eingefügt
#include <QFileDialog> //Das wurde eingefügt
#include <QTextStream> //Das wurde eingefügt
#include <QFile> //Das wurde eingefügt

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mModel = new QStandardItemModel(this); //Das wurde eingeführt
    ui->tableView->setModel(mModel); //Das wurde eingeführt
    setCentralWidget(ui->tableView); //Das wurde eingeführt
    setWindowTitle("CSV-Viewer"); //Das wurde eingeführt
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNeu_triggered() //Das wurde eingeführt
{
    NewDialog d(this);
    if (d.exec() == QDialog::Rejected){
        return;
    }
    const int rowCount = d.getRowCount();
    const int colCount = d.getColCount();
    mModel->setRowCount(rowCount);
    mModel->setColumnCount(colCount);
}

void MainWindow::on_actionOpen_triggered() //Das wurde eingeführt
{
    auto filename = QFileDialog::getOpenFileName(this, "Open", QDir::rootPath(), "CSV File (*.csv)");
    if (filename.isEmpty()){
        return;
    }
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }
    QTextStream xin(&file);
    int ix = 0;
    while (!xin.atEnd()){
        mModel->setRowCount(ix);
        auto line = xin.readLine();
        auto values = line.split(",");
        const int colCount = values.size();
        mModel->setColumnCount(colCount);
        for (int jx = 0; jx < colCount; ++jx){
            setValueAt (ix, jx, values.at(jx));
        }
        ++ix;
    }
    file.close();
}

void MainWindow::on_actionSave_triggered() //Das wurde eingeführt
{
    auto filename = QFileDialog::getSaveFileName(this, "Save", QDir::rootPath(), "CSV File (*.csv)");
    if (filename.isEmpty()){
        return;
    }
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        return;
    }
    QTextStream xout(&file);
    const int rowCount = mModel->rowCount();
    const int colCount = mModel->columnCount();
    for (int ix = 0; ix < rowCount; ++ ix){
        xout << getValueAt(ix, 0);
        for (int jx = 1; jx < colCount; ++jx){
            xout << ", " << getValueAt (ix, jx);
        }
        xout << "\n";
    }
    file.flush();
    file.close();
}

void MainWindow::on_actionExit_triggered() //Das wurde eingeführt
{
    close();
}

void MainWindow::setValueAt (int ix, int jx, const QString &value) //Das wurde eingefügt
{
    if (!mModel->item(ix, jx)){
        mModel->setItem(ix, jx, new QStandardItem(value));
        } else {
            mModel->item(ix, jx)->setText(value);
        }
}

QString MainWindow::getValueAt(int ix, int jx) //Das wurde eingeführt
{
    if (!mModel->item(ix, jx)){
        return "";
    }
    return mModel->item(ix, jx)->text();
}

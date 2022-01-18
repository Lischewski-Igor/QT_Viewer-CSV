#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QStandardItemModel; //Das wurde eingefügt

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNeu_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionExit_triggered();

private:
    void setValueAt (int ix, int jx, const QString &value); //Das wurde eingefügt
    QString getValueAt(int ix, int jx); //Das wurde eingefügt
    Ui::MainWindow *ui;
    QStandardItemModel *mModel; //Das wurde eingefügt
};
#endif // MAINWINDOW_H

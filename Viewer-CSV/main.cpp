#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion"); //Das wurde eingefügt
    MainWindow w;
    w.show();
    return a.exec();
}

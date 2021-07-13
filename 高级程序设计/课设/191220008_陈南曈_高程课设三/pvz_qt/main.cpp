#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));
    MainWindow w;
    w.show();
    return a.exec();
}

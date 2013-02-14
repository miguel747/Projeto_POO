#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller *controller = new Controller();
    MainWindow w(controller);
    controller->star();
    
    return a.exec();
}

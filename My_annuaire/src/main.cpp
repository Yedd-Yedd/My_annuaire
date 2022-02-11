#include "headers/mainwindow.h"
#include <QApplication>
#include "headers/contact.h"
#include "headers/adress.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

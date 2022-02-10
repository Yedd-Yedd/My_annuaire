#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/contact.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Contact *c = new Contact(1,"jeanne","aurelien",'m');
    qDebug()<< QString::fromStdString(c->toString());
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

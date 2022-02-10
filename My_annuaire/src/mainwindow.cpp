#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/contact.h"
#include "headers/adress.h"
#include "headers/cprofessionnels.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Contact *c = new Contact(1,"jeanne","aurelien",'h');
    qDebug()<< QString::fromStdString(c->toString());

    Adress *a = new Adress(3,"place truc","14400","Bayeux");
    qDebug()<< QString::fromStdString(a->toString());

    qDebug()<<"----------------------Pro---------------------";
    CProfessionnels *pro=new CProfessionnels("entr","entre@mail.fr",a,1,"jeanne","aurelien",'h');
    qDebug()<< QString::fromStdString(pro->toString());
}

MainWindow::~MainWindow()
{
    delete ui;
}

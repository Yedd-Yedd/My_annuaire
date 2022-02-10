#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/contact.h"
#include "headers/adress.h"
#include "headers/cprive.h"
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
    
    CPrive *b = new CPrive(a, "22/01/4199", 1, "Ted", "Tedd", 'h');

}


MainWindow::~MainWindow()
{
    delete ui;
}

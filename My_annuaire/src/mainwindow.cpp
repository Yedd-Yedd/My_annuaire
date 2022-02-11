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

    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:\\Users\\Yed\\My_annuaire\\My_annuaire\\BDD\\dbContacts.db");

    connect(ui->chkPrive,SIGNAL(stateChanged(int)),this,SLOT(on_checked_changed(int)));
    connect(ui->chkPro,SIGNAL(stateChanged(int)),this,SLOT(on_checked_changed(int)));

    this->mydb = QSqlDatabase::addDatabase("QSQLITE");
    this->mydb.setDatabaseName("C:\\Users\\audit\\OneDrive\\Documents\\Formation C++\\QT\\Projet\\My_annuaire\\My_annuaire\\BDD\\dbContacts.db");

    if(this->mydb.open()){
        qDebug() << "DB ouverts";

        QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("SELECT idContact, nom, prenom, entreprise FROM contacts");

        ui->listContact->setModel(model);
        ui->listContact->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

         this->mydb.close();
    }
    else{
        qDebug() << "Err ouverture";
    }

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

void MainWindow::on_checked_changed(int status)
{
    ui->listContact->reset();
    QSqlQueryModel *model= new QSqlQueryModel();

    if(ui->chkPrive->isChecked() and ui->chkPro->isChecked()){
        if(this->mydb.open()){
            model->setQuery("SELECT idContact, nom, prenom, entreprise FROM contacts");
        }
    }
    else if(ui->chkPrive->isChecked()){
        if(this->mydb.open()){
            model->setQuery("SELECT idContact, nom, prenom, entreprise FROM contacts WHERE entreprise IS NULL");
        }
    }
    else if(ui->chkPro->isChecked()){
        if(this->mydb.open()){
            model->setQuery("SELECT idContact, nom, prenom, entreprise FROM contacts WHERE entreprise IS NOT NULL");
        }
    }
    ui->listContact->setModel(model);
    ui->listContact->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    this->mydb.close();
}

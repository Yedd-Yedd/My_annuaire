#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/contact.h"
#include "headers/adress.h"
#include "headers/cprive.h"
#include "headers/cprofessionnels.h"
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");

    connect(ui->chkPrive,SIGNAL(stateChanged(int)),this,SLOT(on_checked_changed(int)));
    connect(ui->chkPro,SIGNAL(stateChanged(int)),this,SLOT(on_checked_changed(int)));

    this->mydb = QSqlDatabase::addDatabase("QSQLITE");

    this->mydb.setDatabaseName("C:\\Users\\audit\\OneDrive\\Documents\\Formation C++\\QT\\Projet\\My_annuaire\\My_annuaire\\BDD\\dbContacts.db");
    //this->mydb.setDatabaseName("C:\\Users\\Yed\\My_annuaire\\My_annuaire\\BDD\\dbContacts.db");

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

    if(this->mydb.open()){
        model->setQuery(this->setQueryget());
        ui->listContact->setModel(model);
        ui->listContact->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }

    this->mydb.close();
    //delete model;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QString req=this->setQueryget();
    QSqlQuery query(this->mydb);


    ui->listContact->reset();
    QSqlQueryModel *model= new QSqlQueryModel();

    if(ui->chkPrive->isChecked() and ui->chkPro->isChecked()){
        req+=" WHERE nom LIKE :nom";
    }
    else{
        req+=" AND nom LIKE :nom";
    }
    if(this->mydb.open()){
        query.prepare(req);
        query.bindValue(":nom",arg1+"%");

        query.exec();
        query.next();

        model->setQuery(query);
        ui->listContact->setModel(model);
        ui->listContact->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

QString MainWindow::setQueryget()
{
    QString query;
    if(ui->chkPrive->isChecked() and ui->chkPro->isChecked()){
        query="SELECT idContact, nom, prenom, entreprise FROM contacts";

    }
    else if(ui->chkPrive->isChecked()){
        query="SELECT idContact, nom, prenom FROM contacts WHERE entreprise IS NULL";
    }
    else if(ui->chkPro->isChecked()){
        query="SELECT idContact, nom, prenom, entreprise FROM contacts WHERE entreprise IS NOT NULL";
    }
    return query;
}

void MainWindow::on_listContact_doubleClicked(const QModelIndex &index)
{
    QString id = index.siblingAtColumn(0).data().toString();
    QSqlQuery my_query(this->mydb);
    QString infos = "";
    if (this->mydb.open()){
        my_query.prepare("Select * FROM contacts WHERE idContact= :id");
        my_query.bindValue(":id", id);
        my_query.exec();
        my_query.next();
        infos += "id = ";
        infos += my_query.value("idContact").toString();
        infos += "\nPrenom = ";
        infos += my_query.value("Prenom").toString();
        infos += "\nNom = ";
        infos += my_query.value("Nom").toString();
        infos += "\nSexe = ";
        infos += my_query.value("Sexe").toString();
        if (my_query.value("Entreprise").toString() != ""){
            infos += "\nEntreprise = ";
            infos += my_query.value("Entreprise").toString();
        }
        infos += "\nAdresse = ";
        infos += my_query.value("rue").toString();
        if (my_query.value("Complement").toString() != ""){
            infos += " ";
            infos += my_query.value("Complement").toString();
        }
        infos += " ";
        infos += my_query.value("cp").toString();
        infos += " ";
        infos += my_query.value("Ville").toString();
        if (my_query.value("mail").toString() != ""){
            infos += "\nMail = ";
            infos += my_query.value("mail").toString();
        }
        if (my_query.value("dtNaissance").toString() != ""){
            infos += "\ndate naissance = ";
            infos += my_query.value("dtNaissance").toString();
        }
        qDebug() <<infos;
    }
    ui->label->setText(infos);
    this->mydb.close();
    qDebug() << id;
}

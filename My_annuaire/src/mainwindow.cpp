#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");

    connect(ui->chkPrive,SIGNAL(stateChanged(int)),this,SLOT(on_checked_changed(int)));
    connect(ui->chkPro,SIGNAL(stateChanged(int)),this,SLOT(on_checked_changed(int)));

    this->mydb = QSqlDatabase::addDatabase("QSQLITE");

    //this->mydb.setDatabaseName("C:\\Users\\audit\\OneDrive\\Documents\\Formation C++\\QT\\Projet\\My_annuaire\\My_annuaire\\BDD\\dbContacts.db");
    this->mydb.setDatabaseName("../My_annuaire/BDD/dbContacts.db");

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

    Contact *c = new Contact(1,"jeanne","aurelien",'m');
    qDebug()<< QString::fromStdString(c->toString());

    Adress *a = new Adress(3,"place truc","14400","Bayeux");
    qDebug()<< QString::fromStdString(a->toString());

    qDebug()<<"----------------------Pro---------------------";
    CProfessionnels *pro=new CProfessionnels("entr","entre@mail.fr",a,1,"jeanne","aurelien",'m');
    qDebug()<< QString::fromStdString(pro->toString());
    
    CPrive *b = new CPrive(a, "22/01/4199", 1, "Ted", "Tedd", 'm');

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

void MainWindow::on_leChercheNom_textChanged(const QString &arg1)
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
    string infos = "";
    if (this->mydb.open()){

        my_query.prepare("Select * FROM contacts WHERE idContact= :id");
        my_query.bindValue(":id", id);
        my_query.exec();
        my_query.next();

        QString lib = my_query.value("rue").toString();
        QString comp = my_query.value("Complement").toString();
        QString cp = my_query.value("cp").toString();
        QString city = my_query.value("Ville").toString();
        QString prenom = my_query.value("Prenom").toString();
        QString nom = my_query.value("Nom").toString();
        QString mail = my_query.value("mail").toString();
        QString nomE = my_query.value("Entreprise").toString();

        QString my_id = my_query.value("idContact").toString();
        QString tmp_sexe = my_query.value("Sexe").toString();
        QString date = my_query.value("dtNaissance").toString();

        string num = lib.toStdString();
        num = num.substr(0, num.find(","));

        int i=0;
        if (num != "")
         i = stoi(num);
        char sexe = tmp_sexe.at(0).toLatin1();

        Adress *addr = new Adress
                (i, lib.toStdString(), cp.toStdString(), city.toStdString(), comp.toStdString());
        if (nomE != "" && date == ""){
            CProfessionnels *cont = new CProfessionnels
                    (nomE.toStdString(), mail.toStdString(),
                     addr, my_id.toInt(), nom.toStdString(),
                     prenom.toStdString(), sexe);
            infos = cont->toString();
        }
        else if (nomE == "" && date != ""){
            CPrive *cont = new CPrive
                    (addr, date.toStdString(), my_id.toInt(), nom.toStdString(),
                     prenom.toStdString(), sexe);
            infos = cont->toString();
        }
        qDebug() << "infos ="<< QString::fromStdString(infos);
    }

    ui->label->setText(QString::fromStdString(infos));
    this->mydb.close();
}


void MainWindow::on_btnSupprimer_clicked()
{
    QString rowidx = ui->listContact->selectionModel()->currentIndex().data(0).toString();
    QString t=ui->listContact->selectionModel()->currentIndex().siblingAtColumn(0).data().toString();

    QSqlQuery my_query(this->mydb);
    if (this->mydb.open()){
        QString id = my_query.value("idContact").toString();
        my_query.prepare("DELETE FROM contacts WHERE idContact= :t");
        my_query.bindValue(":t", t);
        my_query.exec();
        my_query.next();
        this->mydb.close();
    }
    ui->listContact->reset();
        if(this->mydb.open()){
            qDebug() << "DB ouverts";
            QSqlQueryModel *model= new QSqlQueryModel();
            model->setQuery("SELECT idContact, nom, prenom, entreprise FROM contacts");
            ui->listContact->setModel(model);
            ui->listContact->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            this->mydb.close();
        }
}

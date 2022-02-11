#include "headers/ajout_contact.h"
#include "ui_ajout_contact.h"
#include "headers/mainwindow.h"

ajout_contact::ajout_contact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajout_contact)
{
    ui->setupUi(this);

    ui->w_pro->setVisible(false);
    MainWindow *t=dynamic_cast<MainWindow*>(parent);
    this->mydb=t->getbdd();
}

ajout_contact::~ajout_contact()
{
    delete ui;
    mydb.close();
}

void ajout_contact::on_rbPrive_clicked(bool checked)
{
    if(checked){
        ui->w_prive->setVisible(true);
        ui->w_pro->setVisible(false);
    }
}


void ajout_contact::on_rbPro_clicked(bool checked)
{
    if(checked){
        ui->w_prive->setVisible(false);
        ui->w_pro->setVisible(true);
    }
}


void ajout_contact::on_pushButton_clicked()
{
    string nom = ui->leNom->text().toStdString();
    string prenom = ui->lePrenom->text().toStdString();
    char genre = ui->leGenre->text().at(0).toLatin1();

    int numRue=ui->leNum->text().toInt();
    string rue=ui->leRue->text().toStdString();
    string comp=ui->leCom->text().toStdString();
    string cp=ui->leCP->text().toStdString();
    string ville=ui->leVille->text().toStdString();

    Adress *addr=new Adress(numRue,rue,cp,ville,comp);

    if(ui->rbPrive->isChecked()){
        try{
            string dateNaissance=ui->dateNaissance->text().toStdString();

            CPrive *contactP = new CPrive(addr,dateNaissance,0,nom,prenom,genre);

            QSqlQuery query(this->mydb);

            if(this->mydb.open()){
                QString req="INSERT INTO CONTACTS(nom,prenom,sexe,rue,complement,cp,ville,dtNaissance)"
                            "VALUES(:nom,:prenom,:sexe,:rue,:complement,:cp,:ville,:dateNaissance)";
                query.prepare(req);
                query.bindValue(":nom",QString::fromStdString(contactP->getNom()));
                query.bindValue(":prenom",QString::fromStdString(contactP->getPrenom()));
                query.bindValue(":sexe",QChar(contactP->getGenre()));
                QString num_rue=QString::number(contactP->getAddr()->getAddr_num())+","+QString::fromStdString(contactP->getAddr()->getLibel());
                query.bindValue(":rue",num_rue);
                query.bindValue(":complement",QString::fromStdString(contactP->getAddr()->getComp()));
                query.bindValue(":cp",QString::fromStdString(contactP->getAddr()->getCp()));
                query.bindValue(":ville",QString::fromStdString(contactP->getAddr()->getVille()));
                query.bindValue(":dateNaissance",QString::fromStdString(contactP->getDate_naissance()));

                qDebug()<<query.exec();
                qDebug()<<query.lastError().text();
                this->mydb.close();
                delete contactP;
            }
        }
        catch(char const* error){
            QMessageBox msgbox;
            msgbox.setInformativeText("Erreur : "+QString::fromUtf8(error));
            msgbox.setText("Erreur");
            msgbox.setStandardButtons(QMessageBox::Close);
            msgbox.setIcon(QMessageBox::Critical);
            msgbox.exec();
        }

    }
    if(ui->rbPro->isChecked()){
        try{
            string nomE = ui->leNemE->text().toStdString();
            string mail = ui->leMail->text().toStdString();

            CProfessionnels *contactPro = new CProfessionnels(nomE,mail,addr,0,nom,prenom,genre);

            qDebug() << QString::fromStdString(contactPro->toString());
            QSqlQuery query(this->mydb);
            if(this->mydb.open()){
                QString req="INSERT INTO CONTACTS(nom,prenom,sexe,entreprise,rue,complement,cp,ville,mail)"
                            "VALUES(:nom,:prenom,:sexe,:entreprise,:rue,:complement,:cp,:ville,:mail)";
                query.prepare(req);
                query.bindValue(":nom",QString::fromStdString(contactPro->getNom()));
                query.bindValue(":prenom",QString::fromStdString(contactPro->getPrenom()));
                query.bindValue(":sexe",QChar(contactPro->getGenre()));
                query.bindValue(":entreprise",QString::fromStdString(contactPro->getNomE()));
                QString num_rue=QString::number(contactPro->getAddr()->getAddr_num())+","+QString::fromStdString(contactPro->getAddr()->getLibel());
                query.bindValue(":rue",num_rue);
                query.bindValue(":complement",QString::fromStdString(contactPro->getAddr()->getComp()));
                query.bindValue(":cp",QString::fromStdString(contactPro->getAddr()->getCp()));
                query.bindValue(":ville",QString::fromStdString(contactPro->getAddr()->getVille()));
                query.bindValue(":mail",QString::fromStdString(contactPro->getMail()));

                query.exec();

                this->mydb.close();
                delete contactPro;
            }
        }
        catch(char const* error){
            QMessageBox msgbox;
            msgbox.setInformativeText("Erreur : "+QString::fromUtf8(error));
            msgbox.setText("Erreur");
            msgbox.setStandardButtons(QMessageBox::Close);
            msgbox.setIcon(QMessageBox::Critical);
            msgbox.exec();
        }

    }
    //delete addr;
}


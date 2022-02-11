#ifndef AJOUT_CONTACT_H
#define AJOUT_CONTACT_H

#endif // AJOUT_CONTACT_H
#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>



namespace Ui {
class Ajout_contact;
}

class Ajout_contact : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ajout_contact(QWidget *parent = nullptr);
    ~Ajout_contact();



private:
    Ui::Ajout_contact *ui;
    QSqlDatabase mydb;
};

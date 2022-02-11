#ifndef AJOUT_CONTACT_H
#define AJOUT_CONTACT_H

#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

#include "cprive.h"
#include "adress.h"
#include "cprofessionnels.h"

namespace Ui {
class ajout_contact;
}

class ajout_contact : public QDialog
{
    Q_OBJECT

public:
    explicit ajout_contact(QWidget *parent = nullptr);
    ~ajout_contact();

private slots:
    void on_rbPrive_clicked(bool checked);

    void on_rbPro_clicked(bool checked);

    void on_pushButton_clicked();

private:
    QSqlDatabase mydb;
    Ui::ajout_contact *ui;
};

#endif // AJOUT_CONTACT_H

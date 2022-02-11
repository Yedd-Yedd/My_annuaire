#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <iostream>
#include <string>
#include "headers/contact.h"
#include "headers/adress.h"
#include "headers/cprive.h"
#include "headers/cprofessionnels.h"
#include "headers/ajout_contact.h"


using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QSqlDatabase getbdd();
    ~MainWindow();

    string toString();


private slots:
    void on_checked_changed(int status);

    void on_listContact_doubleClicked(const QModelIndex &index);

    void on_leChercheNom_textChanged(const QString &arg1);

    void on_btnAjouter_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;

    QString setQueryget();

    //ajout_contact fenetre_ajout;
};

#endif // MAINWINDOW_H

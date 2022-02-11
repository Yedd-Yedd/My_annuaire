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

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    string toString();


private slots:
    void on_checked_changed(int status);

    void on_listContact_doubleClicked(const QModelIndex &index);

    void on_leChercheNom_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;

    QString setQueryget();
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include "headers/ajout_contact.h"



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

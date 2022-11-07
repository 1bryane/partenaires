#include "mainwindow.h"

#include "partenaires.h"
#include<QMessageBox>
#include"connection.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableau->setModel(p.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_addpart_clicked()
{
    int id=ui->edid->text().toInt();
    QString nomentr=ui->edentremprise->text();
    QString nom=ui->ednom->text();
    QString prenom=ui->edprenom->text();
    QString service=ui->edservice->text();
    QString email=ui->edemail->text();
        int numeros=ui->ednumeros->text().toInt();
        partenaires p (id,nomentr,nom,prenom,service,email,numeros);
        bool test=p.ajouter();
        QMessageBox msgbox;
        if(test)
        {   msgbox.setText("ajout avec succes");


           ui->tableau->setModel(p.afficher());

        }
        else
        {msgbox.setText("echec d'ajout ");
            msgbox.exec();
        }

}


void MainWindow::on_supp_clicked()
{
    partenaires p;
    p.setid(ui->supid->text().toInt());
    bool test=p.supprimer(p.getid());
QMessageBox msgbox;
    if(test)
    {
        msgbox.setText("sup avc succe");
       ui->tableau->setModel(p.afficher());

    }
    else
      msgbox.setText("echec de supp");
    msgbox.exec();

}


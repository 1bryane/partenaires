#include "partenaires.h"


partenaires::partenaires(int id,QString nomentr,QString nom,QString prenom,QString service,QString email,int numeros)
{
    this->id=id;
     this->nomentr=nomentr;
    this->nom=nom;
    this->prenom=prenom;
   this->service=service;
    this->email=email;
    this->numeros=numeros;
}

bool partenaires::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id);
    QString resn = QString::number(numeros);
    query.prepare("INSERT INTO PARTENAIRE(ID,NOMENTREPRISE,NOM,PRENOM,SERVICE,EMAIL,NUMEROS)"
                  "VALUES (:ID,:NOMENTREPRISE,:NOM,:PRENOM,:SERVICE,:EMAIL,:NUMEROS)");
    query.bindValue(0,res);
    query.bindValue(1,nomentr);
    query.bindValue(2,nom);
    query.bindValue(3,prenom);
    query.bindValue(4,service);
    query.bindValue(5,email);
    query.bindValue(6,resn);

    return  query.exec();
}
 QSqlQueryModel * partenaires::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("SELECT* FROM PARTENAIRE");
model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom d'entreprise"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("Nom"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("Prenom"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("Service"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("Email"));
model->setHeaderData(6, Qt::Horizontal,QObject::tr("Numero"));
return model;
 }

bool partenaires::supprimer(int id)
{
QSqlQuery query;
query.prepare("delete from partenaire where id=:id");
query.bindValue(0,id);
 return query.exec();
}


#include "parking.h"
#include <QSystemTrayIcon>
parking::parking()
{

}

parking::parking(int a,int b,int c,QString d)
{
    id_p=a;
    nbr_place=b;
    nom=d;
    id_m=c;
}

bool parking::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id_p);
    QString res1 = QString::number(id_m);
    QString res2 = QString::number(nbr_place);

    query.prepare("INSERT INTO parking(id_p,nbr_place_total,nom,id_m)""VALUES (:id_p,:nbr_place,:nom,:id_m)");
    query.bindValue(":id_p",res);
    query.bindValue(":nbr_place",res2);
    query.bindValue(":nom",nom);
    query.bindValue(":id_m",res1);


    return query.exec();
}


QSqlQueryModel * parking::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM parking");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_p"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("capacite"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("id magasin"));

    return model;
}


bool parking::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("DELETE FROM parking WHERE id_p = :id");
    query.bindValue(":id",res);
    return query.exec();
}

bool parking::modifier(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    QString res1 = QString::number(nbr_place);
    QString res2 = QString::number(id_m);
    query.prepare("UPDATE parking SET nom=:nom,id_m=:id_m,nbr_place_total=:nbr_place WHERE id_p=:id");
    query.bindValue(":id",res);
    query.bindValue(":nbr_place",res1);
    query.bindValue(":id_m",res2);
    query.bindValue(":nom",nom);


    return query.exec();

}


QSqlQueryModel *parking::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM parking " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_p"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("capacite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("id magasin"));

    return model;
}




QSqlQueryModel * parking::tri_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM parking ORDER BY ID_p ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_p"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("capacite"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("id magasin"));
    return model;
}

QSqlQueryModel * parking::tri_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM parking ORDER BY nom ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_p"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("capacite"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("id magasin"));
    return model;
}
QSqlQueryModel * parking::tri_cap()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM parking ORDER BY nbr_place_total ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_p"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("capacite"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("id magasin"));
    return model;
}


void parking::notification_ajoutparking()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des parkings ","Nouvau parking ajoutée ",QSystemTrayIcon::Information,15000);
}
void parking::notification_modifparking()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des parkings "," parking modifiee ",QSystemTrayIcon::Information,15000);
}

void parking::notification_suppparking()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des parkings "," parking supprimee ",QSystemTrayIcon::Information,15000);
}

void parking::notification_pdf()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des parkings ","pdf generee ",QSystemTrayIcon::Information,15000);
}




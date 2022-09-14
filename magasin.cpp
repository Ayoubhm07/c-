#include "magasin.h"
#include <QSystemTrayIcon>

magasin::magasin()
{

}
magasin::magasin(int a,int b,QString c,QString d)
{
    id_m=a;
    surface=b;
    nom=c;
    adresse=d;
}

bool magasin::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id_m);
    QString res1 = QString::number(surface);

    query.prepare("INSERT INTO magasin(id_m,surface,nom,adresse)""VALUES (:id_m,:surface,:nom,:adresse)");
    query.bindValue(":id_m",res);
    query.bindValue(":surface",res1);
    query.bindValue(":nom",nom);
    query.bindValue(":adresse",adresse);


    return query.exec();
}


QSqlQueryModel * magasin::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM magasin");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_m"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("surface"));

    return model;
}


bool magasin::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("DELETE FROM magasin WHERE id_m = :id");
    query.bindValue(":id",res);
    return query.exec();
}

bool magasin::modifier(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    QString res1 = QString::number(surface);
    query.prepare("UPDATE magasin SET nom=:nom,adresse=:adresse,surface=:surface WHERE id_m=:id");
    query.bindValue(":id",res);
    query.bindValue(":surface",res1);
    query.bindValue(":nom",nom);
    query.bindValue(":adresse",adresse);

    return query.exec();

}


QSqlQueryModel *magasin::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM magasin " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_m"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresses"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("surface"));

    return model;
}


QSqlQueryModel * magasin::tri_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM magasin ORDER BY ID_m ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("surface"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    return model;
}

QSqlQueryModel * magasin::tri_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM magasin ORDER BY nom ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("surface"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    return model;
}
QSqlQueryModel * magasin::tri_sur()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM magasin ORDER BY surface ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("surface"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    return model;
}


void magasin::notification_ajoutmagasin()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des magasins ","Nouvau magasin ajoutée ",QSystemTrayIcon::Information,15000);
}
void magasin::notification_modifmagasin()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des magasins "," magasin modifiee ",QSystemTrayIcon::Information,15000);
}

void magasin::notification_suppmagasin()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des magasins "," magasin supprimee ",QSystemTrayIcon::Information,15000);
}

void magasin::notification_pdf()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des magasins ","pdf generee ",QSystemTrayIcon::Information,15000);
}




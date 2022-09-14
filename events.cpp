#include "events.h"
#include <QSystemTrayIcon>

events::events()
{

}

events::events(int a, int b, QString c, QString e, QDate f )
{
    id=a;
    nbV=b;
    nom=c;
    d=f;
    sponsor=e;
}
QSqlQueryModel * events::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM events");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_e"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nb_visiteurs"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_e"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("sponsors"));

    return model;
}
bool events::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id);
    QString res1 = QString::number(nbV);
   // QDateTime timestamp=QDateTime::currentDateTime();
    //timestamp.addDays(1);
    query.prepare("INSERT INTO events(id_e,nb_visiteurs,nom,spnsors)""VALUES (:id,:nbV,:nom,:sponsor)");
    query.bindValue(":id",res);
    query.bindValue(":nbV",res1);
    query.bindValue(":nom",nom);
    query.bindValue(":sponsor",sponsor);
   // query.bindValue(":datetime",timestamp);

    return query.exec();
}
bool events::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("DELETE FROM events WHERE id_e = :id");
    query.bindValue(":id",res);
    return query.exec();
}
bool events::modifier(int id_ev)
{
    QSqlQuery query;
    QString res = QString::number(id_ev);
    QString res1 = QString::number(nbV);

    query.prepare("UPDATE events SET nb_visiteurs=:nbV,nom=:nom,sponsors=:sponsor WHERE id_e=:id_ev");
    query.bindValue(":id_ev",res);
    query.bindValue(":nbV",res1);
    query.bindValue(":nom",nom);
    query.bindValue(":sponsor",sponsor);

    return query.exec();

}



QSqlQueryModel * events::tri_nbV()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM events ORDER BY nbV ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbV"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("quan"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_f"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_s"));

    return model;
}

QSqlQueryModel * events::tri_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM events ORDER BY ID_produit ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbV"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("quan"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_f"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_s"));

    return model;
}



QSqlQueryModel * events::tri_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM events ORDER BY nom ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbV"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("quan"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_f"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_s"));

    return model;
}



QSqlQueryModel *events::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM events " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbV"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quan"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_f"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_s"));

    return model;
}

void events::notification_ajoutProduit()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des events ","Nouvau produit ajoutée ",QSystemTrayIcon::Information,15000);
}


void events::notification_suppProduit()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des events ","Produit supprime ",QSystemTrayIcon::Information,15000);
}

void events::notification_modifProduit()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des events ","Produit modifie ",QSystemTrayIcon::Information,15000);
}


void events::notification_pdf()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des events ","pdf generee ",QSystemTrayIcon::Information,15000);
}

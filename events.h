#ifndef EVENTS_H
#define EVENTS_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class events
{
public:
    events();
    events(int, int , QString, QString , QDate);
           //Getters
           int get_id(){return id;}
           int get_nbV(){return nbV;}
           QString get_nom(){return nom;}
           QString get_sponsor(){return sponsor;}

           //Setters
           void set_id(int a){id=a;}
           void set_nbV(int a){nbV=a;}
           void set_nom(QString b){nom=b;}
           void set_date(QDate a){d=a;}
           void set_spon(QString f){sponsor=f;}


          //other functions
           QSqlQueryModel * afficher();
           bool ajouter();
           bool supprimer(int);
           bool modifier(int);
           QSqlQueryModel *tri_nbV();
           QSqlQueryModel *tri_id();
           QSqlQueryModel *tri_nom();
           QSqlQueryModel *displayClause(QString cls);
           void notification_ajoutProduit();
           void notification_suppProduit();
           void notification_modifProduit();
           void notification_pdf();


    private:
        int id;
        int nbV;
        QString nom;
        QString sponsor;
        QDate d;
        int id_s;
};

#endif // EVENTS_H

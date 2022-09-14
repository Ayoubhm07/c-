#ifndef PARKING_H
#define PARKING_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <magasin.h>

class parking
{
public:
    parking();
    parking(int,int,int,QString);
    int get_id(){return id_p;}
    int get_espae(){return nbr_place;}
    QString get_nom(){return nom;}
    int get_idM(){return id_m;}

    //Setters
    void set_id(int a){id_p=a;}
    void set_mag(int a){id_m=a;}
    void set_nom(QString b){nom=b;}
    void set_cap(int f){nbr_place=f;}


   //other functions
    QSqlQueryModel * afficher();
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel *tri_cap();
    QSqlQueryModel *tri_id();
    QSqlQueryModel *tri_nom();
    QSqlQueryModel *displayClause(QString cls);
    void notification_ajoutparking();
    void notification_suppparking();
    void notification_modifparking();
    void notification_pdf();
    QVector<double> statistiques();
    void makePlot();




private:
 int id_p;
 int nbr_place;
 QString nom;
 int id_m;

};

#endif // PARKING_H

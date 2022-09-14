#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QIntValidator>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include <QVector>
#include <QPainter>
#include <QPdfWriter>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include <QVector>
//#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_e_ajouter_clicked()
{
        ptmp.set_id(ui->lineEdit_id_e->text().toInt());
        ptmp.set_sur(ui->lineEdit_spon_e->text().toInt());
        ptmp.set_nom(ui->lineEdit_nom_e->text());
        ptmp.set_adr(ui->lineEdit_nbv_e->text());

        bool test=ptmp.ajouter();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("ajouté avec succes.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ptmp.notification_ajoutmagasin();


    }
        else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("error.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_m->setModel(ptmp.afficher());


}



void MainWindow::on_pushButton_a_m_clicked()
{
    ui->tableView_m->setModel(ptmp.afficher());
}


void MainWindow::on_pushButton_del_m_clicked()
{
    int id_del;
            id_del=ui->tableView_m->model()->data(ui->tableView_m->model()->index(ui->tableView_m->currentIndex().row(),0)).toInt();
            bool test=ptmp.supprimer(id_del);
            if(test)
            {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("supprimé avec succes.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                ptmp.notification_suppmagasin();

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("error.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_m->setModel(ptmp.afficher());
}


void MainWindow::on_pushButton_g_m_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_g_p_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_m_m_clicked()
{
    int id_up;
    id_up=ui->tableView_m->model()->data(ui->tableView_m->model()->index(ui->tableView_m->currentIndex().row(),0)).toInt();
    ptmp.set_sur(ui->lineEdit_spon_e->text().toInt());
    ptmp.set_nom(ui->lineEdit_nom_e->text());
    ptmp.set_adr(ui->lineEdit_nbv_e->text());

    bool test=ptmp.modifier(id_up);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("modifie avec succes.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ptmp.notification_modifmagasin();

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("error.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tableView_m->setModel(ptmp.afficher());
}


void MainWindow::on_lineEdit_sea_id_textChanged()
{
    if(ui->lineEdit_sea_id->text()!="")
        {
            QString a=ui->lineEdit_sea_id->text();
            ui->tableView_m->setModel(ptmp.displayClause("WHERE (id_m LIKE '%"+a+"%') "));
        }
        else
            ui->tableView_m->setModel(ptmp.afficher());
}


void MainWindow::on_lineEdit_sea_nom_textChanged()
{
    if(ui->lineEdit_sea_nom->text()!="")
        {
            QString a=ui->lineEdit_sea_nom->text();
            ui->tableView_m->setModel(ptmp.displayClause("WHERE (nom LIKE '%"+a+"%') "));
        }
        else
            ui->tableView_m->setModel(ptmp.afficher());
}


void MainWindow::on_lineEdit_sea_sur_textChanged()
{
    if(ui->lineEdit_sea_sur->text()!="")
        {
            QString a=ui->lineEdit_sea_sur->text();
            ui->tableView_m->setModel(ptmp.displayClause("WHERE (surface LIKE '%"+a+"%') "));
        }
        else
            ui->tableView_m->setModel(ptmp.afficher());
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->tableView_m->setModel(ptmp.tri_id());
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->tableView_m->setModel(ptmp.tri_nom());
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->tableView_m->setModel(ptmp.tri_sur());
}


void MainWindow::on_pushButton_m_pdf_clicked()
{
    QPdfWriter pdf("E:/qtprojects/untitled1/Pdfmagasin.pdf");
        QPainter painter(&pdf);
        int i = 4000;
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(3300,1200,"Liste Des Magasins");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        // painter.drawText(1100,2000,afficheDC);
        painter.drawRect(1500,200,7300,2600);
        //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(1300,3300,"ID_M");
        painter.drawText(2600,3300,"NOM");
        painter.drawText(3900,3300,"ADRESSE");
        painter.drawText(5200,3300,"SURFACE");




        QSqlQuery query;
        query.prepare("select * from MAGASIN");
        query.exec();
        while (query.next())
        {
            painter.drawText(1300,i,query.value(0).toString());
            painter.drawText(2600,i,query.value(1).toString());
            painter.drawText(3900,i,query.value(2).toString());
            painter.drawText(5200,i,query.value(3).toString());



            i = i +500;
        }
        ptmp.notification_pdf();
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile("E:/qtprojects/untitled1/Pdfmagasin.pdf"));

            painter.end();
        }
        if (reponse == QMessageBox::No)
        {
            painter.end();
        }
}

QVector<double> MainWindow::statistiques()
{
    QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    q.prepare("SELECT surface FROM magasin WHERE surface<=400");
    q.exec();
    while (q.next())
    {
        stat[0]++;

    }
    q.prepare("SELECT surface FROM magasin WHERE 400<surface and surface<=700");
    q.exec();
    while (q.next())
    {
        stat[1]++;

    }
    q.prepare("SELECT surface FROM magasin WHERE 700<surface and surface<=1000");
    q.exec();
    while (q.next())
    {
        stat[2]++;

    }
    q.prepare("SELECT surface FROM magasin WHERE 1000<surface and surface<=1500");
    q.exec();
    while (q.next())
    {
        stat[3]++;

    }
    q.prepare("SELECT surface FROM magasin WHERE 1500<surface ");
    q.exec();
    while (q.next())
    {
        stat[4]++;

    }
    return stat;
}

void MainWindow::makePlot()
{
    // prepare data:
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customplot->xAxis, ui->customplot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, MainWindow::statistiques());////fonction statistiques
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customplot->replot();

    // move bars above graphs and grid below bars:
    ui->customplot->addLayer("abovemain", ui->customplot->layer("main"), QCustomPlot::limAbove);
    ui->customplot->addLayer("belowmain", ui->customplot->layer("main"), QCustomPlot::limBelow);
    ui->customplot->xAxis->grid()->setLayer("belowmain");
    ui->customplot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6<<7;//////
    QVector<QString> labels;
    labels<<"0-400"<<"400-700"<<"700-1000"<<"1000-1500"<<"1500+";////////
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customplot->xAxis->setTicker(textTicker);
    ui->customplot->xAxis->setSubTicks(false);
    ui->customplot->xAxis->setTickLength(0,4);
    ui->customplot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customplot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customplot->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customplot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customplot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customplot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customplot->xAxis->setTickLabelColor(Qt::white);
    ui->customplot->yAxis->setTickLabelColor(Qt::white);
    ui->customplot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customplot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customplot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customplot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customplot->xAxis->grid()->setSubGridVisible(true);
    ui->customplot->yAxis->grid()->setSubGridVisible(true);
    ui->customplot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customplot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customplot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customplot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(00, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customplot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));//
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customplot->axisRect()->setBackground(axisRectGradient);

    ui->customplot->rescaleAxes();
    ui->customplot->xAxis->setRange(0, 7);
    ui->customplot->yAxis->setRange(0, 10);


}

void MainWindow::on_pushButton_m_stat_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->customplot->clearPlottables();
    MainWindow::makePlot();
    MainWindow::makePlot();
    ind=1;
}





void MainWindow::on_pushButton_p_a_clicked()
{
    ptmp1.set_id(ui->lineEdit_p_id->text().toInt());
    ptmp1.set_nom(ui->lineEdit_p_nom->text());
    ptmp1.set_cap(ui->lineEdit_p_nbrp->text().toInt());
    ptmp1.set_mag(ui->lineEdit_p_idM->text().toInt());

    bool test=ptmp1.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("ajouté avec succes.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ptmp1.notification_ajoutparking();


}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("error.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tableView_p->setModel(ptmp1.afficher());
}


void MainWindow::on_pushButton_p_supp_clicked()
{
    int id_del;
            id_del=ui->tableView_p->model()->data(ui->tableView_p->model()->index(ui->tableView_p->currentIndex().row(),0)).toInt();
            bool test=ptmp1.supprimer(id_del);
            if(test)
            {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("supprimé avec succes.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                ptmp1.notification_suppparking();

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("error.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_p->setModel(ptmp1.afficher());
}


void MainWindow::on_pushButton_p_aff_clicked()
{
    ui->tableView_p->setModel(ptmp1.afficher());
}


void MainWindow::on_pushButton_p_del_clicked()
{
    int id_up;
    id_up=ui->tableView_p->model()->data(ui->tableView_p->model()->index(ui->tableView_p->currentIndex().row(),0)).toInt();
    ptmp1.set_nom(ui->lineEdit_p_nom->text());
    ptmp1.set_cap(ui->lineEdit_p_nbrp->text().toInt());
    ptmp1.set_mag(ui->lineEdit_p_idM->text().toInt());

    bool test=ptmp1.modifier(id_up);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("modifie avec succes.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ptmp1.notification_modifparking();

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("error.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tableView_p->setModel(ptmp1.afficher());
}


void MainWindow::on_lineEdit_p_sea_id_textChanged()
{
    if(ui->lineEdit_p_sea_id->text()!="")
        {
            QString a=ui->lineEdit_p_sea_id->text();
            ui->tableView_p->setModel(ptmp1.displayClause("WHERE (id_p LIKE '%"+a+"%') "));
        }
        else
            ui->tableView_p->setModel(ptmp1.afficher());
}


void MainWindow::on_lineEdit__p_sea_nom_textChanged()
{
    if(ui->lineEdit__p_sea_nom->text()!="")
        {
            QString a=ui->lineEdit__p_sea_nom->text();
            ui->tableView_p->setModel(ptmp1.displayClause("WHERE (nom LIKE '%"+a+"%') "));
        }
        else
            ui->tableView_p->setModel(ptmp1.afficher());
}


void MainWindow::on_lineEdit_p_sea_cap_textChanged()
{
    if(ui->lineEdit_p_sea_cap->text()!="")
        {
            QString a=ui->lineEdit_p_sea_cap->text();
            ui->tableView_p->setModel(ptmp1.displayClause("WHERE (nbr_place_total LIKE '%"+a+"%') "));
        }
        else
            ui->tableView_p->setModel(ptmp1.afficher());
}



void MainWindow::on_pushButton_p_triID_clicked()
{
    ui->tableView_p->setModel(ptmp1.tri_id());
}


void MainWindow::on_pushButton_p_trinom_clicked()
{
    ui->tableView_p->setModel(ptmp1.tri_nom());
}


void MainWindow::on_pushButton_p_tricp_clicked()
{
    ui->tableView_p->setModel(ptmp1.tri_cap());
}


void MainWindow::on_pushButton_p_genp_clicked()
{
    QPdfWriter pdf("E:/qtprojects/untitled1/Pdfparking.pdf");
        QPainter painter(&pdf);
        int i = 4000;
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(3300,1200,"Liste Des Parking");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        // painter.drawText(1100,2000,afficheDC);
        painter.drawRect(1500,200,7300,2600);
        //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(1300,3300,"ID_P");
        painter.drawText(2600,3300,"NOM");
        painter.drawText(3900,3300,"CAPACITE");
        painter.drawText(5200,3300,"ID MAGASIN");
        painter.drawText(5500,3300,"NOM MAGASIN");




        QSqlQuery query;
        query.prepare("select * from parking");
        query.exec();
        while (query.next())
        {
            painter.drawText(1300,i,query.value(0).toString());
            painter.drawText(2600,i,query.value(1).toString());
            painter.drawText(3900,i,query.value(2).toString());
            painter.drawText(5200,i,query.value(3).toString());




            i = i +500;
        }

        ptmp1.notification_pdf();
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile("E:/qtprojects/untitled1/Pdfparking.pdf"));

            painter.end();
        }
        if (reponse == QMessageBox::No)
        {
            painter.end();
        }
}
QVector<double> MainWindow::statistiquesP()
{
    QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    q.prepare("SELECT nbr_place_total FROM parking WHERE nbr_place_total<=100");
    q.exec();
    while (q.next())
    {
        stat[0]++;

    }
    q.prepare("SELECT nbr_place_total FROM parking WHERE 100<nbr_place_total and nbr_place_total<=300");
    q.exec();
    while (q.next())
    {
        stat[1]++;

    }
    q.prepare("SELECT nbr_place_total FROM parking WHERE 300<nbr_place_total and nbr_place_total<=500");
    q.exec();
    while (q.next())
    {
        stat[2]++;

    }
    q.prepare("SELECT nbr_place_total FROM parking WHERE 500<nbr_place_total and nbr_place_total<=800");
    q.exec();
    while (q.next())
    {
        stat[3]++;

    }
    q.prepare("SELECT nbr_place_total FROM parking WHERE 800<nbr_place_total ");
    q.exec();
    while (q.next())
    {
        stat[4]++;

    }
    return stat;
}

void MainWindow::makePlotP()
{
    // prepare data:
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customplot->xAxis, ui->customplot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, MainWindow::statistiquesP());////fonction statistiques
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customplot->replot();

    // move bars above graphs and grid below bars:
    ui->customplot->addLayer("abovemain", ui->customplot->layer("main"), QCustomPlot::limAbove);
    ui->customplot->addLayer("belowmain", ui->customplot->layer("main"), QCustomPlot::limBelow);
    ui->customplot->xAxis->grid()->setLayer("belowmain");
    ui->customplot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6<<7;//////
    QVector<QString> labels;
    labels<<"0-100"<<"100-300"<<"300-500"<<"500-800"<<"800+";////////
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customplot->xAxis->setTicker(textTicker);
    ui->customplot->xAxis->setSubTicks(false);
    ui->customplot->xAxis->setTickLength(0,4);
    ui->customplot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customplot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customplot->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customplot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customplot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customplot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customplot->xAxis->setTickLabelColor(Qt::white);
    ui->customplot->yAxis->setTickLabelColor(Qt::white);
    ui->customplot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customplot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customplot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customplot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customplot->xAxis->grid()->setSubGridVisible(true);
    ui->customplot->yAxis->grid()->setSubGridVisible(true);
    ui->customplot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customplot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customplot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customplot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(00, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customplot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));//
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customplot->axisRect()->setBackground(axisRectGradient);

    ui->customplot->rescaleAxes();
    ui->customplot->xAxis->setRange(0, 7);
    ui->customplot->yAxis->setRange(0, 10);


}


void MainWindow::on_statP_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->customplot->clearPlottables();
    MainWindow::makePlotP();
    MainWindow::makePlotP();
    ind=2;
}


void MainWindow::on_pushButton_s_m_clicked()
{
    ui->stackedWidget->setCurrentIndex(ind);

}





void MainWindow::on_tableView_m_doubleClicked()
{
   int id=ui->tableView_m->model()->data(ui->tableView_m->model()->index(ui->tableView_m->currentIndex().row(),0)).toInt();
   QString res = QString::number(id);
   ui->lineEdit_id_e->setText(res);
    QString nom;
    nom=ui->tableView_m->model()->data(ui->tableView_m->model()->index(ui->tableView_m->currentIndex().row(),1)).toString();
   ui->lineEdit_nom_e->setText(nom);
   QString adr;
  adr=ui->tableView_m->model()->data(ui->tableView_m->model()->index(ui->tableView_m->currentIndex().row(),2)).toString();
  ui->lineEdit_nbv_e->setText(adr);
  int urf=ui->tableView_m->model()->data(ui->tableView_m->model()->index(ui->tableView_m->currentIndex().row(),3)).toInt();
  QString urfa = QString::number(urf);
  ui->lineEdit_spon_e->setText(urfa);
}


void MainWindow::on_tableView_p_doubleClicked()
{
    int id=ui->tableView_p->model()->data(ui->tableView_p->model()->index(ui->tableView_p->currentIndex().row(),0)).toInt();
    QString res = QString::number(id);
    ui->lineEdit_p_id->setText(res);
     QString nom;
     nom=ui->tableView_p->model()->data(ui->tableView_p->model()->index(ui->tableView_p->currentIndex().row(),1)).toString();
    ui->lineEdit_p_nom->setText(nom);
    int cap=ui->tableView_p->model()->data(ui->tableView_p->model()->index(ui->tableView_p->currentIndex().row(),0)).toInt();
    QString res2 = QString::number(cap);
    ui->lineEdit_p_nbrp->setText(res);
   int idm=ui->tableView_p->model()->data(ui->tableView_p->model()->index(ui->tableView_p->currentIndex().row(),3)).toInt();
   QString idma = QString::number(idm);
   ui->lineEdit_p_idM->setText(idma);
}


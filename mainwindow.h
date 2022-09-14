#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "magasin.h"
#include "parking.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QVector>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_e_ajouter_clicked();

    void on_pushButton_a_m_clicked();

    void on_pushButton_del_m_clicked();

    void on_pushButton_g_m_clicked();

    void on_pushButton_g_p_clicked();

    void on_pushButton_clicked();

    void on_pushButton_m_m_clicked();

    void on_lineEdit_sea_id_textChanged();

    void on_lineEdit_sea_nom_textChanged();

    void on_lineEdit_sea_sur_textChanged();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_m_pdf_clicked();
    QVector<double> statistiques();
    void makePlot();

    void on_pushButton_m_stat_clicked();


    void on_pushButton_p_a_clicked();

    void on_pushButton_p_supp_clicked();

    void on_pushButton_p_aff_clicked();

    void on_pushButton_p_del_clicked();

    void on_lineEdit_p_sea_id_textChanged();

    void on_lineEdit__p_sea_nom_textChanged();

    void on_lineEdit_p_sea_cap_textChanged();

    void on_pushButton_p_triID_clicked();

    void on_pushButton_p_trinom_clicked();

    void on_pushButton_p_tricp_clicked();

    void on_pushButton_p_genp_clicked();
    QVector<double> statistiquesP();
    void makePlotP();

    void on_statP_clicked();

    void on_pushButton_s_m_clicked();



    void on_tableView_m_doubleClicked();

    void on_tableView_p_doubleClicked();

private:
    Ui::MainWindow *ui;

    magasin ptmp;
    parking ptmp1;
public:
    int ind;
};
#endif // MAINWINDOW_H

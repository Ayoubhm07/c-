#include "mainwindow.h"
#include <QMessageBox>
#include "connection.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connection c;
        bool test=c.createconnect();
        QFile file("E:/qtprojects/untitled1/style.qss");
                   file.open(QFile::ReadOnly);

                   QString styleSheet { QLatin1String(file.readAll()) };

                   //setup stylesheet
                   a.setStyleSheet(styleSheet);
       MainWindow w;
        if(test)
        {w.show();
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("connection successful.\n"
                                    "Click close to continue."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("connection failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



        return a.exec();
    }

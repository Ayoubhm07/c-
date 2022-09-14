#include "connection.h"

connection::connection()
{

}

bool connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("data_base");
db.setUserName("ash");//inserer nom de l'utilisateur
db.setPassword("ash");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

#include "database.h"


DataBase::DataBase()
{

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.sqlite");
    db.open();

    QSqlQuery query;
    query.exec("create table person "
              "(id integer primary key, "
              "firstname varchar(20), "
              "lastname varchar(30), "
              "age integer)");


}

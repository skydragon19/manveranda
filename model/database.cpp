#include "database.h"

extern struct settings set;

database::database()
{
}

void database::mysql_connect(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(set.host);
    db.setDatabaseName(set.name);
    db.setUserName(set.user);
    db.setPassword(set.pass);

    if (db.open()){
        qDebug() << "MySql Connect!";
    }
    else{
        qDebug() << "Err()";
    }

    set.sql = db;
}

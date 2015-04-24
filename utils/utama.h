#ifndef UTAMA_H
#define UTAMA_H

#include <QDebug>
#include <QString>
#include <QSettings>

#include <QSqlDatabase>
#include <QSqlQuery>

#include <QDateTime>

struct settings{
    QString host;
    QString name;
    QString user;
    QString pass;

    QSqlDatabase sql;
};

struct xmls{
    QString startUTC;
    QString endUTC;
    QString access_id;
    QString password;
    int id_ship[99];
};

#endif // UTAMA_H

#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include <QDateTime>

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QXmlStreamReader>
#include <QSqlQuery>

#include <utils/utama.h>
#include <model/util_skyw.h>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);
    QXmlStreamReader xml;

    void request_selected_mobile_id(int index);
    void request_all_mobile_id();
    
public slots:

private slots:
    void getResponSkyW();
    void replyFinished(QNetworkReply* reply);

private:
    util_skyw skyw;

    QString modem_id;
    QString access_id;
    QString password;
    QString gateway;

    QString urls;

    int SIN;
    int MIN;
    int indexs;

    void get_ship_info(QSqlQuery q, int id_ship);
};

#endif // TIMER_H

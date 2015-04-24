#include "worker.h"

extern struct settings set;
extern struct xmls xmll;

Worker::Worker(QObject *parent) : QObject(parent){
}

void Worker::request_selected_mobile_id(int index){
    QSqlQuery q(set.sql);

    indexs = index;
    this->get_ship_info(q, xmll.id_ship[index]);
    this->getResponSkyW();
}

void Worker::request_all_mobile_id(){

}

void Worker::getResponSkyW(){
    urls.sprintf("%sget_return_messages.xml/?access_id=%s&password=%s&start_utc=%s&end_utc=%s&mobile_id=%s", \
                 gateway.toLocal8Bit().data(), access_id.toLocal8Bit().data(), password.toLocal8Bit().data(),
                 xmll.startUTC.toLocal8Bit().data(), xmll.endUTC.toLocal8Bit().data(), modem_id.toLocal8Bit().data());
#if 1
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply *)));

    QNetworkRequest request;

    QUrl url =  QUrl::fromEncoded(urls.toLocal8Bit().data());
    request.setUrl(url);
    manager->get(request);
#endif
}

void Worker::replyFinished(QNetworkReply* reply){
    QString readAll=reply->readAll();
    skyw.parse_xml(readAll, set.sql, xmll.id_ship[indexs], SIN, MIN);
}

void Worker::get_ship_info(QSqlQuery q, int id_ship){
    QString query;
    query.sprintf("select modem_id, access_id, password, SIN, MIN, gateway from ship where id_ship = %d", id_ship);

    q.prepare(query);
    if (!q.exec()){
        qDebug() << "Err()";
    }
    else{
        while(q.next()){
            modem_id = q.value(0).toString();
            access_id = q.value(1).toString();
            password = q.value(2).toString();
            SIN = q.value(3).toInt();
            MIN = q.value(4).toInt();
            gateway = q.value(5).toString();
        }
    }
}

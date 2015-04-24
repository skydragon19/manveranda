#include "mainwindow.h"
#include "ui_mainwindow.h"

extern struct settings set;
struct xmls xmll;

#define dua_minggu    1209600

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    st.read_setting();
    db.mysql_connect();

    this->set_ui();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_ui(){
    this->ui->host->setText(set.host);
    this->ui->dbname->setText(set.name);
    this->ui->user->setText(set.user);
    this->ui->pass->setText(set.pass);

    this->ui->pass->setEchoMode(QLineEdit::Password);

    endTime = QDateTime::currentDateTime();

    uint timestamp = endTime.toTime_t();
    const QDateTime start = QDateTime::fromTime_t(timestamp - dua_minggu);
    startTime = start;

    this->ui->startsUTC->setDateTime(startTime);
    this->ui->endUTC->setDateTime(endTime);

    /* Combo Box Mobile ID */
    QSqlQuery q(set.sql);
    int cnt_ship = 0;

    q.prepare("select count(id_ship) from ship");
    if(!q.exec()){
        qDebug() << "Err()";
    }
    else{
        while(q.next()){
            sum_ship = q.value(0).toInt();
        }
    }

    q.prepare("select name, id_ship from ship");
    if (!q.exec()){
        qDebug() << "Err()";
    }
    else{
        while(q.next()){
            this->ui->mobile_id->addItem(q.value(0).toString());
            xmll.id_ship[cnt_ship] = q.value(1).toInt();
            cnt_ship++;
        }
        this->ui->mobile_id->addItem("== All Mobile ID ==");
    }
}

void MainWindow::on_startsUTC_dateTimeChanged(const QDateTime &dateTime)
{
    this->ui->startsUTC->setToolTip("UTC : "+dateTime.toUTC().toString("yyyy-MM-dd hh:mm:00"));
}

void MainWindow::on_endUTC_dateTimeChanged(const QDateTime &dateTime)
{
    this->ui->endUTC->setToolTip("UTC : "+dateTime.toUTC().toString("yyyy-MM-dd hh:mm:00"));
}

void MainWindow::on_pushButton_clicked()
{
    xmll.startUTC = this->ui->startsUTC->dateTime().toUTC().toString("yyyy-MM-dd hh:mm:00");
    xmll.endUTC = this->ui->endUTC->dateTime().toUTC().toString("yyyy-MM-dd hh:mm:00");

    if (this->ui->mobile_id->currentIndex() != sum_ship){
        worker.request_selected_mobile_id(this->ui->mobile_id->currentIndex());
    }
    else{
        worker.request_all_mobile_id();
    }
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <model/setting.h>
#include <model/database.h>
#include <controller/worker.h>
#include <utils/utama.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startsUTC_dateTimeChanged(const QDateTime &dateTime);
    void on_endUTC_dateTimeChanged(const QDateTime &dateTime);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    Worker worker;
    setting st;
    database db;

    QSqlDatabase *sql;

    QDateTime startTime;
    QDateTime endTime;

    int sum_ship;

    void set_ui();
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "profile.h"
#include "admin.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sendData(QString str);

public slots:
    void recieveData(QString str);

    void recieveData2(QString str);

private slots:
    void on_log_in_clicked();

    void on_sign_up_clicked();

    void on_admin_clicked();

private:
    Profile *profile;
    Admin *admin;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

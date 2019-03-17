#ifndef PROFILE_H
#define PROFILE_H

#include <QMainWindow>
#include <QtSql>
#include <QStringList>
#include "redact.h"
#include "voldoc.h"

namespace Ui {
class Profile;
}

class Profile : public QMainWindow
{
    Q_OBJECT

public:
    explicit Profile(QWidget *parent = nullptr);
    ~Profile();

signals:
    void sendData(QString str);

public slots:
    void recieveData(QString str);

    void recieveData2(QString str);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Profile *ui;
};

#endif // PROFILE_H

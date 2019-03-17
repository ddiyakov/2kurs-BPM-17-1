#include "mainwindow.h"
#include "profile.h"
#include "ui_profile.h"

Profile::Profile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Profile)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/admin/Desktop/qt/project1/users.db");

    if (!db.open()) {
        ui->statusbar->showMessage("Can't load database.");
    }
}

Profile::~Profile()
{
    delete ui;
}

void Profile::recieveData(QString str) {
    ui->login->setText(str);

    QSqlQuery query;
    query.prepare("SELECT first_n, second_n, third_n, age, city, numbVK "
                  "FROM users_data WHERE login = :login");
    query.bindValue(":login", str);
    query.exec();

    if (query.next()){
        ui->first_n->setText(query.value(0).toString());
        ui->second_n->setText(query.value(1).toString());
        ui->third_n->setText(query.value(2).toString());
        ui->age->setText(query.value(3).toString());
        ui->city->setText(query.value(4).toString());
        ui->numbVK->setText(query.value(5).toString());
    } else {
        ui->statusbar->showMessage("Что-то пошло не так...");
    }
}

void Profile::recieveData2(QString str) {
    QStringList qsl = str.split(',');

    QSqlQuery query;

    if (qsl.at(0) != ui->first_n->text()) {
        query.prepare("UPDATE users_data "
                      "SET first_n = :first_n WHERE login = :login");
        query.bindValue(":login", ui->login->text());
        query.bindValue(":first_n", qsl.at(0));
        query.exec();
        ui->first_n->setText(qsl.at(0));
    }

    if (qsl.at(1) != ui->first_n->text()) {
        query.prepare("UPDATE users_data "
                    "SET second_n = :second_n WHERE login = :login");
        query.bindValue(":login", ui->login->text());
        query.bindValue(":second_n", qsl.at(1));
        query.exec();
        ui->second_n->setText(qsl.at(1));
    }

    if (qsl.at(2) != ui->first_n->text()) {
        query.prepare("UPDATE users_data "
                    "SET third_n = :third_n WHERE login = :login");
        query.bindValue(":login", ui->login->text());
        query.bindValue(":third_n", qsl.at(2));
        query.exec();
        ui->third_n->setText(qsl.at(2));
    }

    if (qsl.at(3) != ui->age->text()) {
        query.prepare("UPDATE users_data "
                      "SET age = :age WHERE login = :login");
        query.bindValue(":login", ui->login->text());
        query.bindValue(":age", qsl.at(3));
        query.exec();
        ui->age->setText(qsl.at(3));
    }

    if (qsl.at(4) != ui->city->text()) {
        query.prepare("UPDATE users_data "
                      "SET city = :city WHERE login = :login");
        query.bindValue(":login", ui->login->text());
        query.bindValue(":city", qsl.at(4));
        query.exec();
        ui->city->setText(qsl.at(4));
    }
}

void Profile::on_pushButton_clicked()
{
    Redact *redact = new Redact(this);
    QString str = ui->first_n->text() + "," + ui->second_n->text() + "," + ui->third_n->text() + "," + ui->age->text() + "," + ui->city->text();
    QObject::connect(this , SIGNAL(sendData(QString)), redact, SLOT(recieveData(QString)));
    QObject::connect(redact , SIGNAL(sendData(QString)), this, SLOT(recieveData2(QString)));
    emit sendData(str);
    redact->exec();
}

void Profile::on_pushButton_2_clicked()
{
    auto w = new MainWindow;
    w->setAttribute( Qt::WA_DeleteOnClose );
    w->show();
    deleteLater();
}

void Profile::on_pushButton_3_clicked()
{
    Voldoc *voldoc = new Voldoc(this);
    QObject::connect(this , SIGNAL(sendData(QString)), voldoc, SLOT(recieveData(QString)));
    QObject::connect(voldoc , SIGNAL(sendData(QString)), this, SLOT(recieveData3(QString)));
    emit sendData(ui->numbVK->text());
    voldoc->exec();
}

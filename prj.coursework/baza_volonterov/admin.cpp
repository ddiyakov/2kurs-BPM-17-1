#include "mainwindow.h"
#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_2_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM users_data WHERE login = :login");
    query.bindValue(":login", ui->lineEdit_2->text());
    query.exec();
    if (query.next()) {
        query.prepare("UPDATE users_data "
                      "SET status = :status WHERE login = :login");
        query.bindValue(":login", ui->lineEdit_2->text());

        if (!ui->radioButton->isChecked() && !ui->radioButton_2->isChecked()){
            QMessageBox::warning(this, "Ошибка", "Вы не отметили нужный статус.");
            query.clear();
        } else {
            if(ui->radioButton->isChecked()) {
                query.bindValue(":status", "Волонтер");
            } else if (ui->radioButton_2->isChecked()) {
                query.bindValue(":status", "Администратор");
            }
            query.exec();
            QMessageBox::information(this, "Успешно", "Вы успешно изменили статус.");
        }
    } else {
        QMessageBox::warning(this, "Ошибка", "Такого логина не существует.");
    }
}

void Admin::on_pushButton_clicked()
{
    if (ui->lineEdit->text() != "" && ui->lineEdit_3->text() != ""
            && ui->lineEdit_4->text() != "" && ui->dateEdit->text() != "") {
        QSqlQuery query;
        query.prepare("SELECT * FROM users_data WHERE numbVK = :numbVK");
        query.bindValue(":numbVK", ui->lineEdit_4->text());
        query.exec();
        if (query.next()) {
            query.clear();
            query.prepare("INSERT INTO baza_aktiv (name, date, lvl, numbVK) "
                          "VALUES (:name, :date, :lvl, :numbVK)");
            query.bindValue(":name", ui->lineEdit->text());
            query.bindValue(":date", ui->dateEdit->text());
            query.bindValue(":lvl", ui->lineEdit_3->text());
            query.bindValue(":numbVK", ui->lineEdit_4->text());
            query.exec();
            QMessageBox::information(this, "Успешно", "Данные успешно добавлены.");
        } else {
            QMessageBox::warning(this, "Ошибка", "Волонтера с таким ID не существует.");
        }
    } else {
        QMessageBox::warning(this, "Ошибка", "Не все данные введены");
    }
}

void Admin::on_pushButton_3_clicked()
{
    auto w = new MainWindow;
    w->setAttribute( Qt::WA_DeleteOnClose );
    w->show();
    deleteLater();
}

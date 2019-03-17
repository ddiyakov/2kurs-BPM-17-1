#include "adlog.h"
#include "ui_adlog.h"

Adlog::Adlog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adlog)
{
    ui->setupUi(this);
}

Adlog::~Adlog()
{
    delete ui;
}

void Adlog::on_pushButton_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE login = :login");
    query.bindValue(":login", ui->lineEdit->text());
    query.exec();

    if (query.next()) {
        if (query.value(0).toString() == ui->lineEdit_2->text()) {
            query.prepare("SELECT status FROM users_data WHERE login = :login");
            query.bindValue(":login", ui->lineEdit->text());
            query.exec();
            if (query.next()) {
                if (query.value(0).toString() == "Администратор") {
                    emit sendData("All is OK");
                    close();
                    QMessageBox::information(this, "Все верно!", "Вы успешно авторизовались!");
                } else {
                    QMessageBox::warning(this, "Неверно", "Вы не администратор.");
                }
            }
        } else {
            QMessageBox::warning(this, "Неверно", "Неправильный пароль.");
        }
    } else {
        QMessageBox::warning(this, "Неверно", "Такого логина не существует.");
    }
}

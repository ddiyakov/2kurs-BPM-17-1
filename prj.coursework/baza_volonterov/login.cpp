#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE login = :login");
    query.bindValue(":login", ui->lineEdit->text());
    query.exec();

    if (query.next()) {
        if (query.value(0).toString() == ui->lineEdit_2->text()) {
            emit sendData(ui->lineEdit->text());
            close();
            QMessageBox::information(this, "Все верно!", "Вы успешно авторизовались!");

        } else {
            QMessageBox::warning(this, "Неверно", "Неправильный пароль.");
        }
    } else {
        QMessageBox::warning(this, "Неверно", "Такого логина не существует.");
    }
}

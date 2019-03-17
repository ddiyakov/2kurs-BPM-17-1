#include "signup.h"
#include "ui_signup.h"

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_pushButton_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE login = :login");
    query.bindValue(":login", ui->lineEdit_4->text());
    query.exec();

    if (!query.next()) {                                                                      //проверка существования логина
        if (ui->lineEdit_5->text() == ui->lineEdit_6->text()) {                               //проверка совпадения паролей
            if (ui->lineEdit->text() != "" && ui->lineEdit_2->text() != ""
                    && ui->lineEdit_4->text() != "" && ui->lineEdit_5->text() != "") {        //проверка введения всех данных, кроме отчества
                query.prepare("INSERT INTO users (login, password)"                           //добавление логина и пароля в базу
                                              "VALUES (:login, :password);");
                query.bindValue(":login", ui->lineEdit_4->text());
                query.bindValue(":password", ui->lineEdit_5->text());
                query.exec();

                query.prepare("INSERT INTO users_data (login, first_n, second_n, third_n)"    //добавление данных в базу
                                              "VALUES (:login, :first_n, :second_n, :third_n);");
                query.bindValue(":login", ui->lineEdit_4->text());
                query.bindValue(":first_n", ui->lineEdit->text());
                query.bindValue(":second_n", ui->lineEdit_2->text());
                query.bindValue(":third_n", ui->lineEdit_3->text());
                query.exec();

                QMessageBox::information(this, "Ура!", "Вы успешно зарегистрировались!");
                close();
            } else {
                QMessageBox::warning(this, "Неверно", "Вы ввели не все данные.");
            }
        } else {
            QMessageBox::warning(this, "Неверно", "Пароли не совпадают.");
        }
    } else {
        QMessageBox::warning(this, "Неверно", "Такой логин уже существует.");
    }
}

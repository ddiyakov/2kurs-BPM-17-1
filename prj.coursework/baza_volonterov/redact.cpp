#include "redact.h"
#include "ui_redact.h"
#include <QMessageBox>

Redact::Redact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Redact)
{
    ui->setupUi(this);
}

Redact::~Redact()
{
    delete ui;
}

void Redact::recieveData(QString str) {
    QStringList qsl = str.split(',');
    ui->lineEdit->setText(qsl.at(0));
    ui->lineEdit_2->setText(qsl.at(1));
    ui->lineEdit_3->setText(qsl.at(2));
    ui->lineEdit_4->setText(qsl.at(3));
    ui->lineEdit_5->setText(qsl.at(4));
}

void Redact::on_pushButton_2_clicked()
{
    close();
}

void Redact::on_pushButton_clicked()
{
    emit sendData(ui->lineEdit->text() + ',' +
            ui->lineEdit_2->text() + ',' +
            ui->lineEdit_3->text() + ',' +
            ui->lineEdit_4->text() + ',' +
            ui->lineEdit_5->text());
    QMessageBox::information(this, "Успешно", "Данные успешно сохранены.");
}

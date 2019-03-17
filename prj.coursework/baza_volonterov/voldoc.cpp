#include "voldoc.h"
#include "ui_voldoc.h"

Voldoc::Voldoc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Voldoc)
{
    ui->setupUi(this);
}

Voldoc::~Voldoc()
{
    delete ui;
}

void Voldoc::recieveData(QString str) {
    ui->label_2->setText(str);

    QSqlQuery query;
    query.prepare("SELECT COUNT(numbVK) "
                  "FROM baza_aktiv WHERE numbVK = :numbVK");
    query.bindValue(":numbVK", str);
    query.exec();
    query.next();
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(query.value(0).toInt());
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Название мероприятия" << "Дата мероприятия" << "Уровень мероприятия");

    query.prepare("SELECT name, date, lvl "
                  "FROM baza_aktiv WHERE numbVK = :numbVK");
    query.bindValue(":numbVK", str);
    query.exec();

    for(int i = 0; i < ui->tableWidget->rowCount(); i++) {
        query.next();
        for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
            QTableWidgetItem *itm = new QTableWidgetItem(query.value(j).toString());

            ui->tableWidget->setItem(i, j, itm);
        }
    }
}

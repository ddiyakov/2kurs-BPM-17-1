#ifndef ADLOG_H
#define ADLOG_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>

namespace Ui {
class Adlog;
}

class Adlog : public QDialog
{
    Q_OBJECT

public:
    explicit Adlog(QWidget *parent = nullptr);
    ~Adlog();

signals:
    void sendData(QString str);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Adlog *ui;
};

#endif // ADLOG_H

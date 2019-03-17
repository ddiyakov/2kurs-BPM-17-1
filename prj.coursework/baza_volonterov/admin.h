#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSql>

namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H

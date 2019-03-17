#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

signals:
    void sendData(QString str);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H

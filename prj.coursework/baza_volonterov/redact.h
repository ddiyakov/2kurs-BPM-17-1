#ifndef REDACT_H
#define REDACT_H

#include <QDialog>

namespace Ui {
class Redact;
}

class Redact : public QDialog
{
    Q_OBJECT

public:
    explicit Redact(QWidget *parent = nullptr);
    ~Redact();

signals:
    void sendData(QString str);

public slots:
    void recieveData(QString str);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Redact *ui;
};

#endif // REDACT_H

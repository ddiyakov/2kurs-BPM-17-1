#ifndef VOLDOC_H
#define VOLDOC_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Voldoc;
}

class Voldoc : public QDialog
{
    Q_OBJECT

public:
    explicit Voldoc(QWidget *parent = nullptr);
    ~Voldoc();

public slots:
    void recieveData(QString str);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Voldoc *ui;
};

#endif // VOLDOC_H

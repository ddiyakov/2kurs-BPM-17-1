#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "signup.h"
#include "adlog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/admin/Desktop/qt/project1/users.db");

    if (!db.open()) {
        ui->statusBar->showMessage("Can't load database.");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_log_in_clicked()
{
    Login *login = new Login(this);
    QObject::connect(login, SIGNAL(sendData(QString)), this, SLOT(recieveData(QString)));
    login->exec();
}

void MainWindow::on_sign_up_clicked()
{
    SignUp *signup = new SignUp(this);
    signup->exec();
}

void MainWindow::recieveData(QString str) {
    profile = new Profile;
    profile->setAttribute( Qt::WA_DeleteOnClose );
    profile->show();
    QObject::connect(this , SIGNAL(sendData(QString)), profile, SLOT(recieveData(QString)));
    emit sendData(str);
    deleteLater();
    hide();
}

void MainWindow::on_admin_clicked()
{
    Adlog *adlog = new Adlog(this);
    QObject::connect(adlog, SIGNAL(sendData(QString)), this, SLOT(recieveData2(QString)));
    adlog->exec();
}

void MainWindow::recieveData2(QString str) {
    admin = new Admin;
    admin->setAttribute( Qt::WA_DeleteOnClose );
    admin->show();
    deleteLater();
    hide();
}

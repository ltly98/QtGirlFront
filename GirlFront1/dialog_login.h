#ifndef DIALOG_LOGIN_H
#define DIALOG_LOGIN_H

#include <QDialog>
#include<QCloseEvent>
#include<QString>
#include<QMessageBox>
#include <QtSql/QSqlQuery>
#include"dialog_sign.h"

extern int login_user;
extern int login_root;

namespace Ui {
class Dialog_login;
}

class Dialog_login : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_login(QWidget *parent = nullptr);

    ~Dialog_login();

protected:
    void closeEvent(QCloseEvent *event);//重写关闭函数，防止关闭主窗体

signals:
    void sendDataInfo_login(QString,int);   //用来传递数据的信号

    void send_loginstatus(int);//传送登录状态

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog_login *ui;
    Dialog_sign *sign;
    int loginstatus;
};

#endif // DIALOG_LOGIN_H

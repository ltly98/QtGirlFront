#ifndef DIALOG_EQUIP_H
#define DIALOG_EQUIP_H

#include <QDialog>
#include<QCloseEvent>
#include <QtSql/QSqlQuery>
#include<QString>
#include<QMessageBox>

#include"dialog_add_equip.h"
#include"dialog_login.h"

namespace Ui {
class Dialog_equip;
}

class Dialog_equip : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_equip(QWidget *parent = nullptr);

    ~Dialog_equip();

    void ShowInformation(QSqlQuery query);

protected:
    void closeEvent(QCloseEvent *event);//重写关闭函数，防止关闭主窗体

signals:
    void sendDataInfo_equip(QString,int);   //用来传递数据的信号

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void receive_add_delete();

private:
    Ui::Dialog_equip *ui;

    QSqlQuery query;

    Dialog_add_equip *addequip;
};

#endif // DIALOG_EQUIP_H

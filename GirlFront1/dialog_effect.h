#ifndef DIALOG_EFFECT_H
#define DIALOG_EFFECT_H

#include <QDialog>
#include<QCloseEvent>
#include <QtSql/QSqlQuery>
#include<QString>
#include<QMessageBox>

#include"dialog_add_effect.h"
#include"dialog_login.h"

namespace Ui {
class Dialog_effect;
}

class Dialog_effect : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_effect(QWidget *parent = nullptr);
    ~Dialog_effect();
     void ShowInformation(QSqlQuery query);
protected:
    void closeEvent(QCloseEvent *event);//重写关闭函数，防止关闭主窗体
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void receive_add_delete();

signals:
    void sendDataInfo_effect(QString,int);   //用来传递数据的信号
private:
    Ui::Dialog_effect *ui;
    QSqlQuery query;
    Dialog_add_effect *addeffect;
};

#endif // DIALOG_EFFECT_H

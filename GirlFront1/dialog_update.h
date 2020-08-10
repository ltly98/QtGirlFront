#ifndef DIALOG_UPDATE_H
#define DIALOG_UPDATE_H

#include <QDialog>
#include<QCloseEvent>
#include <QtSql/QSqlQuery>
#include<QString>
#include<QMessageBox>

namespace Ui {
class Dialog_update;
}

class Dialog_update : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_update(QWidget *parent = nullptr);

    ~Dialog_update();

    void update_one(QString dbase,QString data,QString base,int d);
protected:
    void closeEvent(QCloseEvent *event);//重写关闭函数，防止关闭主窗体
private slots:

    void on_pushButton_No_clicked();

    void on_pushButton_Name_clicked();

    void on_pushButton_Type_clicked();

    void on_pushButton_Rare_clicked();

    void on_pushButton_No_Attack_clicked();

    void on_pushButton_No_Hit_clicked();

    void on_pushButton_No_Speed_clicked();

    void on_pushButton_No_Avoid_clicked();

    void on_pushButton_No_Life_clicked();

    void on_pushButton_No_Armor_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

signals:
    void sendDataInfo_update(QString,int);   //用来传递数据的信号

    void send_tableview_update(QString);//成功执行则发送信号至主窗体tableview
private:
    Ui::Dialog_update *ui;
};

#endif // DIALOG_UPDATE_H

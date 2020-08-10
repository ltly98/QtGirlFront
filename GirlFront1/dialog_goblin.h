#ifndef DIALOG_GOBLIN_H
#define DIALOG_GOBLIN_H

#include <QDialog>
#include<QCloseEvent>
#include <QtSql/QSqlQuery>
#include<QString>
#include<QMessageBox>
#include<QPalette>

#include"dialog_add_goblin.h"
#include"dialog_login.h"

namespace Ui {
class Dialog_goblin;
}

class Dialog_goblin : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_goblin(QWidget *parent = nullptr);

    ~Dialog_goblin();

    void ShowInformation(QSqlQuery query);
protected:

    void closeEvent(QCloseEvent *event);//重写关闭函数，防止关闭主窗体


signals:
    void sendDataInfo_goblin(QString,int);   //用来传递数据的信号

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void receive_add_delete();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Dialog_goblin *ui;

    QSqlQuery query;

    Dialog_add_goblin *addgoblin;
};

#endif // DIALOG_GOBLIN_H

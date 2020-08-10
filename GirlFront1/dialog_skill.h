#ifndef DIALOG_SKILL_H
#define DIALOG_SKILL_H

#include <QDialog>
#include<QCloseEvent>
#include <QtSql/QSqlQuery>
#include<QString>
#include<QMessageBox>
#include<QPalette>

#include"dialog_login.h"
#include"dialog_add_skill.h"

namespace Ui {
class Dialog_skill;
}

class Dialog_skill : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_skill(QWidget *parent = nullptr);

    ~Dialog_skill();

    void ShowInformation(QSqlQuery query);
protected:
    void closeEvent(QCloseEvent *event);//重写关闭函数，防止关闭主窗体

signals:
    void sendDataInfo_skill(QString,int);   //用来传递数据的信号
private slots:
    void on_pushButton_pre_clicked();

    void on_pushButton_nex_clicked();

    void on_pushButton_ini_clicked();

    void on_pushButton_select_clicked();

    void on_pushButton_mai_clicked();

    void receive_add_delete();
private:
    Ui::Dialog_skill *ui;
    QSqlQuery query;
    Dialog_add_skill *addskill;
};

#endif // DIALOG_SKILL_H

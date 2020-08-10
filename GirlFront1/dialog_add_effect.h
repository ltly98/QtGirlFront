#ifndef DIALOG_ADD_EFFECT_H
#define DIALOG_ADD_EFFECT_H

#include <QDialog>
#include<QCloseEvent>
#include <QtSql/QSqlQuery>
#include<QString>
#include<QMessageBox>

namespace Ui {
class Dialog_add_effect;
}

class Dialog_add_effect : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_add_effect(QWidget *parent = nullptr);
    ~Dialog_add_effect();
protected:
    void closeEvent(QCloseEvent *event);//重写关闭函数，防止关闭主窗体
signals:
    void send_effect();   //用来传递数据的信号
private slots:
    void on_pushButton_Save_clicked();

    void on_pushButton_Save_2_clicked();

    void on_pushButton_Save_3_clicked();

    void on_pushButton_Save_4_clicked();

    void on_pushButton_Save_5_clicked();

private:
    Ui::Dialog_add_effect *ui;
    QString selectno;
};

#endif // DIALOG_ADD_EFFECT_H

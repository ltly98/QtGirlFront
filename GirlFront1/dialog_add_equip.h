#ifndef DIALOG_ADD_EQUIP_H
#define DIALOG_ADD_EQUIP_H

#include <QDialog>
#include<QCloseEvent>
#include <QtSql/QSqlQuery>
#include<QString>
#include<QMessageBox>

namespace Ui {
class Dialog_add_equip;
}

class Dialog_add_equip : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_add_equip(QWidget *parent = nullptr);

    ~Dialog_add_equip();

protected:
    void closeEvent(QCloseEvent *event);//重写关闭函数，防止关闭主窗体

private slots:

    void on_pushButton_Save_clicked();

    void on_pushButton_Clear_clicked();


    void on_pushButton_Delete_clicked();

    void on_pushButton_Clear_2_clicked();

    void on_pushButton_Save_2_clicked();

signals:
    void send_equip();   //用来传递数据的信号
private:
    Ui::Dialog_add_equip *ui;
    QString selectname;
};

#endif // DIALOG_ADD_EQUIP_H

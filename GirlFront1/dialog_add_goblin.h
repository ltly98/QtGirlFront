#ifndef DIALOG_ADD_GOBLIN_H
#define DIALOG_ADD_GOBLIN_H

#include <QDialog>
#include<QCloseEvent>
#include <QtSql/QSqlQuery>
#include<QString>
#include<QMessageBox>

namespace Ui {
class Dialog_add_goblin;
}

class Dialog_add_goblin : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_add_goblin(QWidget *parent = nullptr);
    ~Dialog_add_goblin();
protected:
    void closeEvent(QCloseEvent *event);//重写关闭函数，防止关闭主窗体
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

signals:
    void send_goblin();   //用来传递数据的信号
private:
    Ui::Dialog_add_goblin *ui;
    QString selectno;
};

#endif // DIALOG_ADD_GOBLIN_H

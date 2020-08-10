#ifndef DIALOG_ADD_SKILL_H
#define DIALOG_ADD_SKILL_H

#include <QDialog>
#include<QCloseEvent>
#include <QtSql/QSqlQuery>
#include<QString>
#include<QMessageBox>

namespace Ui {
class Dialog_add_skill;
}

class Dialog_add_skill : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_add_skill(QWidget *parent = nullptr);
    ~Dialog_add_skill();
protected:
    void closeEvent(QCloseEvent *event);//重写关闭函数，防止关闭主窗体
signals:
    void send_skill();   //用来传递数据的信号

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_clear_2_clicked();

    void on_pushButton_save_2_clicked();

private:
    Ui::Dialog_add_skill *ui;
    QString selectno;
};

#endif // DIALOG_ADD_SKILL_H

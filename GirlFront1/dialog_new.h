#ifndef DIALOG_NEW_H
#define DIALOG_NEW_H

#include <QDialog>
#include<QCloseEvent>
#include <QtSql/QSqlQuery>
#include<QString>
#include<QMessageBox>

namespace Ui {
class Dialog_new;
}

class Dialog_new : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_new(QWidget *parent = nullptr);
    ~Dialog_new();
protected:
    void closeEvent(QCloseEvent *event);//重写关闭函数，防止关闭主窗体
private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void sendDataInfo_new(QString,int);   //用来传递数据的信号

    void send_tableview_new(QString);//成功执行则发送信号至主窗体tableview
private:
    Ui::Dialog_new *ui;
};

#endif // DIALOG_NEW_H

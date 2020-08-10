#ifndef DIALOG_SELECT_H
#define DIALOG_SELECT_H

#include <QDialog>
#include<QCloseEvent>
#include <QtSql/QSqlQuery>
#include<QString>
#include<QMessageBox>

namespace Ui {
class Dialog_select;
}

class Dialog_select : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_select(QWidget *parent = nullptr);
    ~Dialog_select();
protected:
    void closeEvent(QCloseEvent *event);//重写关闭函数，防止关闭主窗体
signals:
    void sendDataInfo_select(QString,int);   //用来传递数据的信号

    void send_tableview_select(QString);//成功执行则发送信号至主窗体tableview
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_select *ui;
};

#endif // DIALOG_SELECT_H

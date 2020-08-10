#ifndef DIALOG_COMMAND_H
#define DIALOG_COMMAND_H

#include <QDialog>
#include<QCloseEvent>
#include <QtSql/QSqlQuery>
#include<QString>
#include<QMessageBox>

namespace Ui {
class Dialog_command;
}

class Dialog_command : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_command(QWidget *parent = nullptr);
    ~Dialog_command();
protected:
    void closeEvent(QCloseEvent *event);//重写关闭函数，防止关闭主窗体
private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void sendDataInfo_command(QString,int);   //用来传递数据的信号

    void send_tableview_command(QString);//成功执行则发送信号至主窗体tableview
private:
    Ui::Dialog_command *ui;
};

#endif // DIALOG_COMMAND_H

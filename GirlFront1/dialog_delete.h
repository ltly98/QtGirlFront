#ifndef DIALOG_DELETE_H
#define DIALOG_DELETE_H

#include <QDialog>
#include<QCloseEvent>
#include <QtSql/QSqlQuery>
#include<QString>
#include<QMessageBox>

namespace Ui {
class Dialog_delete;
}

class Dialog_delete : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_delete(QWidget *parent = nullptr);
    ~Dialog_delete();
protected:
    void closeEvent(QCloseEvent *event);//重写关闭函数，防止关闭主窗体
private slots:

    void on_pushButton_clicked();

signals:
    void sendDataInfo_delete(QString,int);   //用来传递数据的信号

    void send_tableview_delete(QString);//成功执行则发送信号至主窗体tableview
private:
    Ui::Dialog_delete *ui;
};

#endif // DIALOG_DELETE_H

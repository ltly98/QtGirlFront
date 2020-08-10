#ifndef DIALOG_ABOUT_H
#define DIALOG_ABOUT_H

#include <QDialog>
#include<QCloseEvent>
#include<QString>

namespace Ui {
class Dialog_about;
}

class Dialog_about : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_about(QWidget *parent = nullptr);
    ~Dialog_about();
protected:
    void closeEvent(QCloseEvent *event);//重写关闭函数，防止关闭主窗体
signals:
    void sendDataInfo_about(QString,int);   //用来传递数据的信号
private:
    Ui::Dialog_about *ui;
};

#endif // DIALOG_ABOUT_H

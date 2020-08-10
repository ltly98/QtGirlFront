#ifndef DIALOG_SIGN_H
#define DIALOG_SIGN_H

#include <QDialog>
#include<QCloseEvent>
#include<QString>
#include<QMessageBox>
#include <QtSql/QSqlQuery>


namespace Ui {
class Dialog_sign;
}

class Dialog_sign : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_sign(QWidget *parent = nullptr);

    ~Dialog_sign();
protected:
    void closeEvent(QCloseEvent *event);//重写关闭函数，防止关闭主窗体

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_sign *ui;
};

#endif // DIALOG_SIGN_H

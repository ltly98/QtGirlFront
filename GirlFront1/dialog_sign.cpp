#include "dialog_sign.h"
#include "ui_dialog_sign.h"

Dialog_sign::Dialog_sign(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_sign)
{
    ui->setupUi(this);
    //设置tab键顺序
    QWidget::setTabOrder(ui->lineEdit,ui->lineEdit_2);
    QWidget::setTabOrder(ui->lineEdit_2,ui->lineEdit_3);
    QWidget::setTabOrder(ui->lineEdit_3,ui->pushButton);
}

Dialog_sign::~Dialog_sign()
{
    delete ui;
}

void Dialog_sign::closeEvent(QCloseEvent *event)
{
     event->ignore();
     reject();
}

void Dialog_sign::on_pushButton_clicked()
{
    QString user=ui->lineEdit->text();
    QString pass=ui->lineEdit_2->text();
    QString pass_c=ui->lineEdit_3->text();
    if(user.isEmpty()||pass.isEmpty()||pass_c.isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：信息未填完整"));
    }
    else if(user.length()>30||pass.length()>30)
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：长度过长"));
    }
    else if(pass!=pass_c)
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：密码不一致"));
    }
    else
    {
        QSqlQuery query;
        int index=0;
        query.exec("select * from account");
        while(query.next())
        {
            if(user==query.value(0))
            {
                index=1;
                break;
            }
        }
        if(index==0)
        {
            query.prepare("insert into account values(:gun1,:gun2)");
            query.bindValue(":gun1",user);
            query.bindValue(":gun2",pass);
            if(query.exec())
            {
                QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：注册成功"));
            }
            else {
                QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：注册失败"));
            }
        }
        else
        {
            QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：账户已存在"));
        }

    }
}

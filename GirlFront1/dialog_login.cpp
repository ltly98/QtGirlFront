#include "dialog_login.h"
#include "ui_dialog_login.h"

int login_user=0;
int login_root=0;

Dialog_login::Dialog_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_login)
{
    ui->setupUi(this);
    loginstatus=0;

    //设置tab键顺序
    QWidget::setTabOrder(ui->lineEdit,ui->lineEdit_2);
    QWidget::setTabOrder(ui->lineEdit_2,ui->pushButton);
    QWidget::setTabOrder(ui->pushButton,ui->pushButton_2);
}

Dialog_login::~Dialog_login()
{
    delete ui;
}

void Dialog_login::closeEvent(QCloseEvent *event)
{
     event->ignore();
     reject();
     emit sendDataInfo_login(QString::fromLocal8Bit("提示：关闭登录功能"),1);

}
void Dialog_login::on_pushButton_clicked()
{
    QString user=ui->lineEdit->text();
    QString pass=ui->lineEdit_2->text();
    if(user.isEmpty()||pass.isEmpty())
    {
        emit sendDataInfo_login(QString::fromLocal8Bit("提示：账户或不能为空"),0);
    }
    else
    {
        QSqlQuery query;
        query.exec("select * from account");
        while(query.next())
        {
            if(user==query.value(0)&&pass==query.value(1))
            {
                loginstatus=1;
            }
            if(user=="root")
            {
                loginstatus=2;
            }
        }
        if(loginstatus==1)
        {
            emit send_loginstatus(1);
            emit sendDataInfo_login(QString::fromLocal8Bit("提示：普通用户登录成功"),1);
            this->close();
        }
        else if(loginstatus==2)
        {
            emit send_loginstatus(2);
            emit sendDataInfo_login(QString::fromLocal8Bit("提示：开发者登录成功"),1);
            this->close();
        }
        else
        {
            emit sendDataInfo_login(QString::fromLocal8Bit("提示：登录失败"),0);
        }
    }
}

void Dialog_login::on_pushButton_2_clicked()
{
    sign=new Dialog_sign(this);
    sign->setWindowTitle(QString::fromLocal8Bit("注册信息"));
    sign->setFixedSize(sign->width(),sign->height());//禁止拉伸
    sign->show();
    emit sendDataInfo_login(QString::fromLocal8Bit("提示：打开注册功能"),1);
}

#include "dialog_command.h"
#include "ui_dialog_command.h"

Dialog_command::Dialog_command(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_command)
{
    ui->setupUi(this);

    //tab顺序
    QWidget::setTabOrder(ui->textEdit,ui->pushButton);
    QWidget::setTabOrder(ui->pushButton,ui->pushButton_2);
}

Dialog_command::~Dialog_command()
{
    delete ui;
}

void Dialog_command::closeEvent(QCloseEvent *event)
{
    event->ignore();
    reject();
    emit sendDataInfo_command(QString::fromLocal8Bit("提示：关闭命令信息功能"),1);
}

void Dialog_command::on_pushButton_clicked()
{
    QString command;
    QSqlQuery query;//执行数据库语句用
    if(ui->textEdit->toPlainText().isEmpty())
    {
        emit sendDataInfo_command(QString::fromLocal8Bit("提示:命令为空"),0);
    }
    else
    {
        if(QMessageBox::question(this,
                                    QString::fromLocal8Bit("提示"),
                                    QString::fromLocal8Bit("是否执行"),
                                    QMessageBox::Yes,
                                    QMessageBox::No)==QMessageBox::Yes)
        {
            command=ui->textEdit->toPlainText();
            if(query.exec(command))
            {
                emit sendDataInfo_command(QString::fromLocal8Bit("提示：执行成功,请手动刷新"),1);
            }
            else
            {
                emit sendDataInfo_command(QString::fromLocal8Bit("提示:执行失败"),0);
            }
        }
        else {
            emit sendDataInfo_command(QString::fromLocal8Bit("提示:取消执行命令"),0);
        }
    }
}

void Dialog_command::on_pushButton_2_clicked()
{
    ui->textEdit->setText("");
    emit sendDataInfo_command(QString::fromLocal8Bit("提示：清空命令"),1);
}

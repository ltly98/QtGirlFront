#include "dialog_delete.h"
#include "ui_dialog_delete.h"

Dialog_delete::Dialog_delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_delete)
{
    ui->setupUi(this);

    //tab顺序
    QWidget::setTabOrder(ui->lineEdit_1,ui->pushButton);
}

Dialog_delete::~Dialog_delete()
{
    delete ui;
}

void Dialog_delete::closeEvent(QCloseEvent *event)
{
     event->ignore();
     reject();
     emit sendDataInfo_delete(QString::fromLocal8Bit("提示：关闭删除信息功能"),1);

}

void Dialog_delete::on_pushButton_clicked()
{
    QString gun_no=ui->lineEdit_1->text();
    if(gun_no.isEmpty())
    {
        emit sendDataInfo_delete(QString::fromLocal8Bit("提示：内容为空"),0);
    }
    else {
        if(QMessageBox::question(this,
                                    QString::fromLocal8Bit("提示"),
                                    QString::fromLocal8Bit("是否删除"),
                                    QMessageBox::Yes,
                                    QMessageBox::No)==QMessageBox::Yes)
        {
            QSqlQuery query;
            query.exec("select * from gun");
            int index=0;
            while(query.next())
            {
                if(gun_no==query.value(0))
                {
                    index=1;
                    break;
                }
            }
            if(index==1)
            {
                query.prepare("delete from gun where gunNo=:gun");
                query.bindValue(":gun",gun_no);
                if(query.exec())
                {
                    emit sendDataInfo_delete(QString::fromLocal8Bit("提示:删除成功"),1);
                    emit send_tableview_delete("select * from gun");
                }
                else {
                    emit sendDataInfo_delete(QString::fromLocal8Bit("提示:删除失败"),0);
                }
            }
            else {
                emit sendDataInfo_delete(QString::fromLocal8Bit("提示:删除目标不存在"),0);
            }

        }
        else {
            emit sendDataInfo_delete(QString::fromLocal8Bit("提示:已取消删除"),0);
        }

    }
}

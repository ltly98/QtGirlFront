#include "dialog_select.h"
#include "ui_dialog_select.h"

Dialog_select::Dialog_select(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_select)
{
    ui->setupUi(this);
}

Dialog_select::~Dialog_select()
{
    delete ui;
}

void Dialog_select::closeEvent(QCloseEvent *event)
{
     event->ignore();
     reject();
     emit sendDataInfo_select(QString::fromLocal8Bit("提示：关闭查找信息功能"),1);

}
void Dialog_select::on_pushButton_clicked()
{
    QString gun_no=ui->lineEdit_1->text();
    if(gun_no.isEmpty())
    {
        emit sendDataInfo_select(QString::fromLocal8Bit("提示：内容为空"),0);
    }
    else {
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
                emit send_tableview_select("select * from gun where gunNo="+gun_no);
                emit sendDataInfo_select(QString::fromLocal8Bit("提示:查找成功"),1);
            }
            else {
                emit sendDataInfo_select(QString::fromLocal8Bit("提示:查找目标不存在"),0);
            }

    }
}

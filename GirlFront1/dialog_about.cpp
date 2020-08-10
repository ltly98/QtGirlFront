#include "dialog_about.h"
#include "ui_dialog_about.h"

Dialog_about::Dialog_about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_about)
{
    ui->setupUi(this);
}

Dialog_about::~Dialog_about()
{
    delete ui;
}

void Dialog_about::closeEvent(QCloseEvent *event)
{
     event->ignore();
     reject();
     emit sendDataInfo_about(QString::fromLocal8Bit("提示：关闭相关信息"),1);

}

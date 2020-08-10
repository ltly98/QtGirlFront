#include "dialog_effect.h"
#include "ui_dialog_effect.h"

Dialog_effect::Dialog_effect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_effect)
{
    ui->setupUi(this);
    ui->lineEdit_select->setPlaceholderText(QString::fromLocal8Bit("编号"));

    query.exec("select * from array");
    if(query.next())
    {
        ShowInformation(query);
    }
}

void Dialog_effect::receive_add_delete()
{
    query.exec("select * from array");
    query.next();
    ShowInformation(query);
}

Dialog_effect::~Dialog_effect()
{
    delete ui;
}

void Dialog_effect::closeEvent(QCloseEvent *event)
{
    event->ignore();
    reject();
    emit sendDataInfo_effect(QString::fromLocal8Bit("提示：关闭影响表"),1);
}

void Dialog_effect::ShowInformation(QSqlQuery query)
{
    QString arrNo=query.value(0).toString();
    QString arrName=query.value(1).toString();
    QString arrType=query.value(2).toString();
    QString arrL1=query.value(3).toString();
    QString arrL2=query.value(4).toString();
    QString arrL3=query.value(5).toString();
    QString arrL4=query.value(6).toString();
    QString arrL5=query.value(7).toString();
    QString arrL6=query.value(8).toString();
    QString arrL7=query.value(9).toString();
    QString arrL8=query.value(10).toString();
    QString arrL9=query.value(11).toString();
    QString arrEffect=query.value(12).toString();
    ui->label_No->setText(arrNo);
    ui->label_Name->setText(arrName);
    ui->label_Type->setText(arrType);
    ui->label_L1->setText(arrL1);
    ui->label_L2->setText(arrL2);
    ui->label_L3->setText(arrL3);
    ui->label_L4->setText(arrL4);
    ui->label_L5->setText(arrL5);
    ui->label_L6->setText(arrL6);
    ui->label_L7->setText(arrL7);
    ui->label_L8->setText(arrL8);
    ui->label_L9->setText(arrL9);
    ui->label_Effect->setText(arrEffect);
}

void Dialog_effect::on_pushButton_clicked()
{
    if(query.previous())
    {
        ShowInformation(query);
    }
    else
        {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：已到第一条"));
    }
}

void Dialog_effect::on_pushButton_2_clicked()
{
    if(query.next())
    {
        ShowInformation(query);
    }
    else {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：已到最后一条"));
    }
}

void Dialog_effect::on_pushButton_3_clicked()
{
    query.exec("select * from array");
    query.next();
    ShowInformation(query);
    QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：初始化成功"));
}

void Dialog_effect::on_pushButton_4_clicked()
{
    QString select_data=ui->lineEdit_select->text();
    query.exec("select *from array");
    int index=0;
    while(query.next())
    {
        if(select_data==query.value(0))
        {
            index=1;
            break;
        }
    }
    if(index==1)
    {
        query.prepare("select * from array where gunNo=:arr1");
        query.bindValue(":arr1",select_data);
        if(query.exec())
        {
            query.next();
            ShowInformation(query);
            QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：查找成功"));
        }
        else
        {
            QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：查找失败"));
        }
    }
    else {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：不存在"));
    }
}

void Dialog_effect::on_pushButton_5_clicked()
{
    if(login_root==1||login_user==1)
    {
        addeffect=new Dialog_add_effect(this);
        addeffect->setWindowTitle(QString::fromLocal8Bit("添加/删除/修改影响信息"));
        addeffect->setFixedSize(addeffect->width(),addeffect->height());//禁止拉伸
        connect(addeffect, SIGNAL(send_effect()), this, SLOT(receive_add_delete()));
        addeffect->show();
    }
    else
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：没有权限"));
    }
}

#include "dialog_equip.h"
#include "ui_dialog_equip.h"

Dialog_equip::Dialog_equip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_equip)
{
    ui->setupUi(this);
    ui->lineEdit_sel->setPlaceholderText(QString::fromLocal8Bit("格式：%名称/适用关键字%"));

    //tab顺序
    QWidget::setTabOrder(ui->lineEdit_sel,ui->pushButton_3);
    QWidget::setTabOrder(ui->pushButton_3,ui->pushButton_6);
    QWidget::setTabOrder(ui->pushButton_6,ui->pushButton_5);
    QWidget::setTabOrder(ui->pushButton_5,ui->pushButton);
    QWidget::setTabOrder(ui->pushButton,ui->pushButton_2);
    QWidget::setTabOrder(ui->pushButton_2,ui->pushButton_4);

    query.exec("select * from equip");
    if(query.next())
    {
        ShowInformation(query);
    }

}

Dialog_equip::~Dialog_equip()
{
    delete ui;
}

void Dialog_equip::closeEvent(QCloseEvent *event)
{
    event->ignore();
    reject();
    emit sendDataInfo_equip(QString::fromLocal8Bit("提示：关闭装备表"),1);
}

void Dialog_equip::receive_add_delete()
{
    query.exec("select * from equip");
    query.next();
    ShowInformation(query);
}

void Dialog_equip::ShowInformation(QSqlQuery query)
{
    QString equName=query.value(0).toString();
    QString equRare=query.value(1).toString();
    QString equPart=query.value(2).toString();
    QString equFit=query.value(3).toString();
    QString equGet=query.value(4).toString();
    QString equAddition=query.value(5).toString();
    ui->label_Name->setText(equName);
    ui->label_Rare->setText(equRare);
    ui->label_Part->setText(equPart);
    ui->label_Fit->setText(equFit);
    ui->label_Get->setText(equGet);
    ui->label_Addition->setText(equAddition);
}

void Dialog_equip::on_pushButton_clicked()
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

void Dialog_equip::on_pushButton_2_clicked()
{
    if(query.next())
    {
        ShowInformation(query);
    }
    else {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：已到最后一条"));
    }
}

void Dialog_equip::on_pushButton_3_clicked()
{
    QString equSelect=ui->lineEdit_sel->text();
    query.prepare("select * from equip where equName like :equ1");
    query.bindValue(":equ1",equSelect);
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

void Dialog_equip::on_pushButton_4_clicked()
{
    query.exec("select * from equip");
    query.next();
    ShowInformation(query);
    QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：初始化成功"));
}

void Dialog_equip::on_pushButton_6_clicked()
{
    QString equSelect=ui->lineEdit_sel->text();
    query.prepare("select * from equip where equFit like :equ1");
    query.bindValue(":equ1",equSelect);
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



void Dialog_equip::on_pushButton_5_clicked()
{
    if(login_root==1||login_user==1)
    {
        addequip=new Dialog_add_equip(this);
        addequip->setWindowTitle(QString::fromLocal8Bit("添加/删除/修改装备信息"));
        addequip->setFixedSize(addequip->width(),addequip->height());//禁止拉伸
        connect(addequip, SIGNAL(send_equip()), this, SLOT(receive_add_delete()));
        addequip->show();
    }
    else
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：没有权限"));
    }
}

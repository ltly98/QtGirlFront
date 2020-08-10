#include "dialog_skill.h"
#include "ui_dialog_skill.h"

Dialog_skill::Dialog_skill(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_skill)
{
    ui->setupUi(this);

    //提示
    ui->lineEdit_select->setPlaceholderText(QString::fromLocal8Bit("编号"));

    //设置textedit透明
    QPalette pl=ui->textEdit_skill->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    ui->textEdit_skill->setPalette(pl);

    query.exec("select * from skill");
    if(query.next())
    {
        ShowInformation(query);
    }
}

Dialog_skill::~Dialog_skill()
{
    delete ui;
}

void Dialog_skill::receive_add_delete()
{
    query.exec("select * from skill");
    query.next();
    ShowInformation(query);
}

void Dialog_skill::ShowInformation(QSqlQuery query)
{
    QString sk_no=query.value(0).toString();
    QString sk_name=query.value(1).toString();
    QString sk_skill=query.value(2).toString();
    ui->label_No->setText(sk_no);
    ui->label_Name->setText(sk_name);
    ui->textEdit_skill->setText(sk_skill);
}

void Dialog_skill::closeEvent(QCloseEvent *event)
{
    event->ignore();
    reject();
    emit sendDataInfo_skill(QString::fromLocal8Bit("提示：关闭技能表"),1);
}

void Dialog_skill::on_pushButton_pre_clicked()
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

void Dialog_skill::on_pushButton_nex_clicked()
{
    if(query.next())
    {
        ShowInformation(query);
    }
    else {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：已到最后一条"));
    }
}

void Dialog_skill::on_pushButton_ini_clicked()
{
    query.exec("select * from skill");
    query.next();
    ShowInformation(query);
    QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：初始化成功"));
}

void Dialog_skill::on_pushButton_select_clicked()
{
    QString select_data=ui->lineEdit_select->text();
    query.exec("select *from skill");
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
        query.prepare("select * from skill where skNo=:sk1");
        query.bindValue(":sk1",select_data);
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

void Dialog_skill::on_pushButton_mai_clicked()
{
    if(login_root==1||login_user==1)
    {
        addskill=new Dialog_add_skill(this);
        addskill->setWindowTitle(QString::fromLocal8Bit("添加/删除/修改技能信息"));
        addskill->setFixedSize(addskill->width(),addskill->height());//禁止拉伸
        connect(addskill, SIGNAL(send_skill()), this, SLOT(receive_add_delete()));
        addskill->show();
    }
    else
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：没有权限"));
    }
}

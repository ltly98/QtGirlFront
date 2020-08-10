#include "dialog_goblin.h"
#include "ui_dialog_goblin.h"

Dialog_goblin::Dialog_goblin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_goblin)
{
    ui->setupUi(this);

    //tab顺序
    QWidget::setTabOrder(ui->pushButton_2,ui->pushButton);
    QWidget::setTabOrder(ui->pushButton,ui->pushButton_3);
    QWidget::setTabOrder(ui->pushButton_3,ui->lineEdit_select);
    QWidget::setTabOrder(ui->lineEdit_select,ui->pushButton_4);
    QWidget::setTabOrder(ui->pushButton_4,ui->pushButton_5);

    ui->lineEdit_select->setPlaceholderText(QString::fromLocal8Bit("此处输入编号"));

    //设置textedit透明
    QPalette pl=ui->textEdit->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    ui->textEdit->setPalette(pl);

    //初始化query
    query.exec("select * from goblin");
    query.next();
    ShowInformation(query);
}

void Dialog_goblin::receive_add_delete()
{
    query.exec("select * from goblin");
    query.next();
    ShowInformation(query);
}

Dialog_goblin::~Dialog_goblin()
{
    delete ui;
}

void Dialog_goblin::ShowInformation(QSqlQuery query)
{
    QString gob_no=query.value(0).toString();
    QString gob_name=query.value(1).toString();
    QString gob_type=query.value(2).toString();
    QString gob_attack=query.value(3).toString();
    QString gob_strike=query.value(4).toString();
    QString gob_hit=query.value(5).toString();
    QString gob_avoid=query.value(6).toString();
    QString gob_armor=query.value(7).toString();
    QString gob_get=query.value(8).toString();
    QString gob_skill=query.value(9).toString();
    ui->label_No->setText(gob_no);
    ui->label_Name->setText(gob_name);
    ui->label_Type->setText(gob_type);
    ui->label_Attack->setText(gob_attack);
    ui->label_Strike->setText(gob_strike);
    ui->label_Hit->setText(gob_hit);
    ui->label_Avoid->setText(gob_avoid);
    ui->label_Armor->setText(gob_armor);
    ui->label_Get->setText(gob_get);
    ui->textEdit->setText(gob_skill);
}

void Dialog_goblin::closeEvent(QCloseEvent *event)
{
    event->ignore();
    reject();
    emit sendDataInfo_goblin(QString::fromLocal8Bit("提示：关闭妖精表"),1);
}
void Dialog_goblin::on_pushButton_clicked()
{
    if(query.next())
    {
        ShowInformation(query);
    }
    else {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：已到最后一条"));
    }

}

void Dialog_goblin::on_pushButton_2_clicked()
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

void Dialog_goblin::on_pushButton_3_clicked()
{
    if(login_root==1||login_user==1)
    {
        addgoblin=new Dialog_add_goblin(this);
        addgoblin->setWindowTitle(QString::fromLocal8Bit("添加/删除/修改妖精信息"));
        addgoblin->setFixedSize(addgoblin->width(),addgoblin->height());//禁止拉伸
        connect(addgoblin, SIGNAL(send_goblin()), this, SLOT(receive_add_delete()));
        addgoblin->show();
    }
    else
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：没有权限"));
    }


}

void Dialog_goblin::on_pushButton_4_clicked()
{
    QString select_data=ui->lineEdit_select->text();
    query.exec("select *from goblin");
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
        query.prepare("select * from goblin where gobNo=:gob1");
        query.bindValue(":gob1",select_data);
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

void Dialog_goblin::on_pushButton_5_clicked()
{
    query.exec("select * from goblin");
    query.next();
    ShowInformation(query);
    QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：初始化成功"));
}

#include "dialog_add_equip.h"
#include "ui_dialog_add_equip.h"

Dialog_add_equip::Dialog_add_equip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_add_equip)
{
    ui->setupUi(this);
}

Dialog_add_equip::~Dialog_add_equip()
{
    delete ui;
}

void Dialog_add_equip::closeEvent(QCloseEvent *event)
{
     event->ignore();
     reject();
}

void Dialog_add_equip::on_pushButton_Save_clicked()
{
    QString equ_name=ui->lineEdit_Name->text();
    QString equ_rare=ui->lineEdit_Rare->text();
    QString equ_part=ui->lineEdit_Part->text();
    QString equ_fit=ui->lineEdit_Fit->text();
    QString equ_get=ui->lineEdit_Get->text();
    QString equ_addition=ui->lineEdit_Addition->text();

    QSqlQuery query;
    query.exec("select * from equip");
    int index=0;
    while(query.next())
    {
        if(equ_name==query.value(0))
        {
            index=1;
            break;
        }
    }

    if(equ_name.isEmpty()||equ_rare.isEmpty()
            ||equ_fit.isEmpty()||equ_get.isEmpty()||
            equ_part.isEmpty()||equ_addition.isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：信息不完整"));
    }
    else if(index==0)
    {
        if(QMessageBox::question(this,
                                    QString::fromLocal8Bit("提示"),
                                    QString::fromLocal8Bit("是否添加"),
                                    QMessageBox::Yes,
                                    QMessageBox::No)==QMessageBox::Yes)
        {
            query.prepare("insert into equip values(:equ1,:equ2,:equ3,:equ4,:equ5,:equ6)");
            query.bindValue(":equ1",equ_name);
            query.bindValue(":equ2",equ_rare);
            query.bindValue(":equ3",equ_part);
            query.bindValue(":equ4",equ_fit);
            query.bindValue(":equ5",equ_get);
            query.bindValue(":equ6",equ_addition);
            if(query.exec())
            {
                emit send_equip();
                QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：添加成功"));
            }
            else
            {
                QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：添加失败"));
            }
        }
        else {
            QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：取消保存"));
        }
    }
    else {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：装备信息已存在"));
    }

}

void Dialog_add_equip::on_pushButton_Clear_clicked()
{
    ui->lineEdit_Name->setText("");
    ui->lineEdit_Rare->setText("");
    ui->lineEdit_Part->setText("");
    ui->lineEdit_Fit->setText("");
    ui->lineEdit_Get->setText("");
    ui->lineEdit_Addition->setText("");
    ui->lineEdit_Select->setText("");
}


void Dialog_add_equip::on_pushButton_Delete_clicked()
{
    QString equ_name=ui->lineEdit_Select->text();
    if(equ_name.isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：请填写名称"));
    }
    else
        {
        if(QMessageBox::question(this,
                                    QString::fromLocal8Bit("提示"),
                                    QString::fromLocal8Bit("是否删除"),
                                    QMessageBox::Yes,
                                    QMessageBox::No)==QMessageBox::Yes)
        {
            QSqlQuery query;
            int index=0;
            query.exec("select * from equip");
            while(query.next())
            {
                if(equ_name==query.value(0))
                {
                    index=1;
                    break;
                }
            }
            if(index==1)
            {
                query.prepare("delete from equip where equName=:equ1");
                query.bindValue(":equ1",equ_name);
                if(query.exec())
                {
                    emit send_equip();
                    QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：删除成功"));
                }
                else {
                    QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：删除失败"));
                }
            }
            else {
                QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：目标不存在"));
            }

        }
        else
        {
            QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：已取消删除"));
        }
    }
}

void Dialog_add_equip::on_pushButton_Clear_2_clicked()
{
    QString equ_name=ui->lineEdit_Name->text();
    QSqlQuery query;
    if(equ_name.isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：请填写编号"));
    }
    else
    {
        int index=0;
        query.exec("select * from equip");
        while(query.next())
        {
            if(equ_name==query.value(0))
            {
                index=1;
                break;
            }
        }
        if(index==1)
        {
            query.prepare("select * from equip where equName=:equ1");
            query.bindValue(":equ1",equ_name);
            if(query.exec())
            {
                query.next();
                selectname=query.value(0).toString();
                QString equ_name=query.value(0).toString();
                QString equ_rare=query.value(1).toString();
                QString equ_part=query.value(2).toString();
                QString equ_fit=query.value(3).toString();
                QString equ_get=query.value(4).toString();
                QString equ_addition=query.value(5).toString();
                ui->lineEdit_Name->setText(equ_name);
                ui->lineEdit_Rare->setText(equ_rare);
                ui->lineEdit_Part->setText(equ_part);
                ui->lineEdit_Fit->setText(equ_fit);
                ui->lineEdit_Get->setText(equ_get);
                ui->lineEdit_Addition->setText(equ_addition);
                QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：获取成功"));
            }
            else
            {
                QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：执行失败"));
            }
        }
        else {
            QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：目标不存在"));
        }
    }
}

void Dialog_add_equip::on_pushButton_Save_2_clicked()
{
    QString equ_name=ui->lineEdit_Name->text();
    QString equ_rare=ui->lineEdit_Rare->text();
    QString equ_part=ui->lineEdit_Part->text();
    QString equ_fit=ui->lineEdit_Fit->text();
    QString equ_get=ui->lineEdit_Get->text();
    QString equ_addition=ui->lineEdit_Addition->text();

    QSqlQuery query;
    query.exec("select * from equip");
    int index=0;
    int index1=0;
    while(query.next())
    {
        if(selectname==query.value(0))
        {
            index=1;
        }
        if(equ_name==query.value(0)&&equ_name!=selectname)
        {
            index1=1;
        }
    }

    if(equ_name.isEmpty()||equ_rare.isEmpty()
            ||equ_fit.isEmpty()||equ_get.isEmpty()||
            equ_part.isEmpty()||equ_addition.isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：信息不完整"));
    }
    else if(index==1&&index1==0)
    {
        if(QMessageBox::question(this,
                                    QString::fromLocal8Bit("提示"),
                                    QString::fromLocal8Bit("是否修改"),
                                    QMessageBox::Yes,
                                    QMessageBox::No)==QMessageBox::Yes)
        {
            query.prepare("update equip set equName=:equ1,equRare=:equ2,equPart=:equ3,equFit=:equ4,equGet=:equ5,equAddition=:equ6 where equName=:equ7");
            query.bindValue(":equ1",equ_name);
            query.bindValue(":equ2",equ_rare);
            query.bindValue(":equ3",equ_part);
            query.bindValue(":equ4",equ_fit);
            query.bindValue(":equ5",equ_get);
            query.bindValue(":equ6",equ_addition);
            query.bindValue(":equ7",selectname);
            if(query.exec())
            {
                emit send_equip();
                QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：修改成功"));
            }
            else
            {
                QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：修改失败"));
            }
        }
        else {
            QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：取消修改"));
        }
    }
    else {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：\n修改目标不存在\n或修改后编号与已有重复"));
    }
}

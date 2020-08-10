#include "dialog_add_effect.h"
#include "ui_dialog_add_effect.h"

Dialog_add_effect::Dialog_add_effect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_add_effect)
{
    ui->setupUi(this);

    ui->lineEdit_Delete->setPlaceholderText(QString::fromLocal8Bit("编号"));
}

Dialog_add_effect::~Dialog_add_effect()
{
    delete ui;
}

void Dialog_add_effect::closeEvent(QCloseEvent *event)
{
     event->ignore();
     reject();
}

void Dialog_add_effect::on_pushButton_Save_clicked()
{
   QString arr_no=ui->lineEdit_No->text();
   QString arr_name=ui->lineEdit_Name->text();
   QString arr_type=ui->lineEdit_Type->text();
   QString arr_l1=ui->lineEdit_L1->text();
   QString arr_l2=ui->lineEdit_L2->text();
   QString arr_l3=ui->lineEdit_L3->text();
   QString arr_l4=ui->lineEdit_L4->text();
   QString arr_l5=ui->lineEdit_L5->text();
   QString arr_l6=ui->lineEdit_L6->text();
   QString arr_l7=ui->lineEdit_L7->text();
   QString arr_l8=ui->lineEdit_L8->text();
   QString arr_l9=ui->lineEdit_L9->text();
   QString arr_effect=ui->lineEdit_Effect->text();

    QSqlQuery query;
    query.exec("select * from array");
    int index=0;
    while(query.next())
    {
        if(arr_no==query.value(0))
        {
            index=1;
            break;
        }
    }

    if(arr_no.isEmpty()||arr_name.isEmpty()||arr_type.isEmpty()||arr_l1.isEmpty()
            ||arr_l2.isEmpty()||arr_l3.isEmpty()||arr_l4.isEmpty()||arr_l5.isEmpty()||
            arr_l6.isEmpty()||arr_l7.isEmpty()||arr_l8.isEmpty()||arr_l9.isEmpty()||arr_effect.isEmpty())
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
            query.prepare("insert into array values(:arr1,:arr2,:arr3,:arr4,:arr5,:arr6,:arr7,:arr8,:arr9,:arr10,:arr11,:arr12,:arr13)");
            query.bindValue(":arr1",arr_no);
            query.bindValue(":arr2",arr_name);
            query.bindValue(":arr3",arr_type);
            query.bindValue(":arr4",arr_l1);
            query.bindValue(":arr5",arr_l2);
            query.bindValue(":arr6",arr_l3);
            query.bindValue(":arr7",arr_l4);
            query.bindValue(":arr8",arr_l5);
            query.bindValue(":arr9",arr_l6);
            query.bindValue(":arr10",arr_l7);
            query.bindValue(":arr11",arr_l8);
            query.bindValue(":arr12",arr_l9);
            query.bindValue(":arr13",arr_effect);
            if(query.exec())
            {
                emit send_effect();
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

void Dialog_add_effect::on_pushButton_Save_2_clicked()
{
    ui->lineEdit_No->setText("");
    ui->lineEdit_Name->setText("");
    ui->lineEdit_Type->setText("");
    ui->lineEdit_L1->setText("");
    ui->lineEdit_L2->setText("");
    ui->lineEdit_L3->setText("");
    ui->lineEdit_L4->setText("");
    ui->lineEdit_L5->setText("");
    ui->lineEdit_L6->setText("");
    ui->lineEdit_L7->setText("");
    ui->lineEdit_L8->setText("");
    ui->lineEdit_L9->setText("");
    ui->lineEdit_Effect->setText("");
}

void Dialog_add_effect::on_pushButton_Save_3_clicked()
{
    QString data_no=ui->lineEdit_Delete->text();
    if(data_no.isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：请填写编号"));
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
            query.exec("select * from array");
            while(query.next())
            {
                if(data_no==query.value(0))
                {
                    index=1;
                    break;
                }
            }
            if(index==1)
            {
                query.prepare("delete from array where gunNo=:arr1");
                query.bindValue(":arr1",data_no);
                if(query.exec())
                {
                    emit send_effect();
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

void Dialog_add_effect::on_pushButton_Save_4_clicked()
{
    QString arr_no=ui->lineEdit_No->text();
    QSqlQuery query;
    if(arr_no.isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：请填写编号"));
    }
    else
    {
        int index=0;
        query.exec("select * from array");
        while(query.next())
        {
            if(arr_no==query.value(0))
            {
                index=1;
                break;
            }
        }
        if(index==1)
        {
            query.prepare("select * from array where gunNo=:arr1");
            query.bindValue(":arr1",arr_no);
            if(query.exec())
            {
                query.next();
                selectno=query.value(0).toString();
                QString arr_no=query.value(0).toString();
                QString arr_name=query.value(1).toString();
                QString arr_type=query.value(2).toString();
                QString arr_l1=query.value(3).toString();
                QString arr_l2=query.value(4).toString();
                QString arr_l3=query.value(5).toString();
                QString arr_l4=query.value(6).toString();
                QString arr_l5=query.value(7).toString();
                QString arr_l6=query.value(8).toString();
                QString arr_l7=query.value(9).toString();
                QString arr_l8=query.value(10).toString();
                QString arr_l9=query.value(11).toString();
                QString arr_effect=query.value(12).toString();
                ui->lineEdit_No->setText(arr_no);
                ui->lineEdit_Name->setText(arr_name);
                ui->lineEdit_Type->setText(arr_type);
                ui->lineEdit_L1->setText(arr_l1);
                ui->lineEdit_L2->setText(arr_l2);
                ui->lineEdit_L3->setText(arr_l3);
                ui->lineEdit_L4->setText(arr_l4);
                ui->lineEdit_L5->setText(arr_l5);
                ui->lineEdit_L6->setText(arr_l6);
                ui->lineEdit_L7->setText(arr_l7);
                ui->lineEdit_L8->setText(arr_l8);
                ui->lineEdit_L9->setText(arr_l9);
                ui->lineEdit_Effect->setText(arr_effect);
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

void Dialog_add_effect::on_pushButton_Save_5_clicked()
{
    QString arr_no=ui->lineEdit_No->text();
    QString arr_name=ui->lineEdit_Name->text();
    QString arr_type=ui->lineEdit_Type->text();
    QString arr_l1=ui->lineEdit_L1->text();
    QString arr_l2=ui->lineEdit_L2->text();
    QString arr_l3=ui->lineEdit_L3->text();
    QString arr_l4=ui->lineEdit_L4->text();
    QString arr_l5=ui->lineEdit_L5->text();
    QString arr_l6=ui->lineEdit_L6->text();
    QString arr_l7=ui->lineEdit_L7->text();
    QString arr_l8=ui->lineEdit_L8->text();
    QString arr_l9=ui->lineEdit_L9->text();
    QString arr_effect=ui->lineEdit_Effect->text();

    QSqlQuery query;
    query.exec("select * from array");
    int index=0;
    int index1=0;
    while(query.next())
    {
        if(selectno==query.value(0))
        {
            index=1;
        }
        if(arr_no==query.value(0)&&arr_no!=selectno)
        {
            index1=1;
        }
    }

    if(arr_no.isEmpty()||arr_name.isEmpty()||arr_type.isEmpty()||arr_l1.isEmpty()
            ||arr_l2.isEmpty()||arr_l3.isEmpty()||arr_l4.isEmpty()||arr_l5.isEmpty()||
            arr_l6.isEmpty()||arr_l7.isEmpty()||arr_l8.isEmpty()||arr_l9.isEmpty()||arr_effect.isEmpty())
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
            query.prepare("update array set gunNo=:arr1,gunName=:arr2,gunType=:arr3,gunL1=:arr4,gunL2=:arr5,gunL3=:arr6,"
                          "gunL4=:arr7,gunL5=:arr8,gunL6=:arr9,gunL7=:arr10,gunL8=:arr11,gunL9=:arr12,gunEffect=:arr13 "
                          "where gunNo=:arr14");
            query.bindValue(":arr1",arr_no);
            query.bindValue(":arr2",arr_name);
            query.bindValue(":arr3",arr_type);
            query.bindValue(":arr4",arr_l1);
            query.bindValue(":arr5",arr_l2);
            query.bindValue(":arr6",arr_l3);
            query.bindValue(":arr7",arr_l4);
            query.bindValue(":arr8",arr_l5);
            query.bindValue(":arr9",arr_l6);
            query.bindValue(":arr10",arr_l7);
            query.bindValue(":arr11",arr_l8);
            query.bindValue(":arr12",arr_l9);
            query.bindValue(":arr13",arr_effect);
            query.bindValue(":arr14",selectno);
            if(query.exec())
            {
                emit send_effect();
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

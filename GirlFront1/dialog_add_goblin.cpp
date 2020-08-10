#include "dialog_add_goblin.h"
#include "ui_dialog_add_goblin.h"

Dialog_add_goblin::Dialog_add_goblin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_add_goblin)
{
    ui->setupUi(this);

    //tab顺序
    QWidget::setTabOrder(ui->lineEdit_No,ui->lineEdit_Name);
    QWidget::setTabOrder(ui->lineEdit_Name,ui->lineEdit_Type);
    QWidget::setTabOrder(ui->lineEdit_Type,ui->lineEdit_Get);
    QWidget::setTabOrder(ui->lineEdit_Get,ui->lineEdit_Attack);
    QWidget::setTabOrder(ui->lineEdit_Attack,ui->lineEdit_Strike);
    QWidget::setTabOrder(ui->lineEdit_Strike,ui->lineEdit_Hit);
    QWidget::setTabOrder(ui->lineEdit_Hit,ui->lineEdit_Avoid);
    QWidget::setTabOrder(ui->lineEdit_Avoid,ui->lineEdit_Armor);
    QWidget::setTabOrder(ui->lineEdit_Armor,ui->textEdit_Skill);
    QWidget::setTabOrder(ui->textEdit_Skill,ui->pushButton);
    QWidget::setTabOrder(ui->pushButton,ui->pushButton_2);
    QWidget::setTabOrder(ui->pushButton_2,ui->lineEdit_Delete1);
    QWidget::setTabOrder(ui->lineEdit_Delete1,ui->pushButton_3);
}

Dialog_add_goblin::~Dialog_add_goblin()
{
    delete ui;
}

void Dialog_add_goblin::closeEvent(QCloseEvent *event)
{
     event->ignore();
     reject();
}

void Dialog_add_goblin::on_pushButton_2_clicked()//清空
{
    ui->lineEdit_No->setText("");
    ui->lineEdit_Name->setText("");
    ui->lineEdit_Type->setText("");
    ui->lineEdit_Attack->setText("");
    ui->lineEdit_Strike->setText("");
    ui->lineEdit_Hit->setText("");
    ui->lineEdit_Avoid->setText("");
    ui->lineEdit_Armor->setText("");
    ui->lineEdit_Get->setText("");
    ui->textEdit_Skill->setText("");
}

void Dialog_add_goblin::on_pushButton_clicked()
{
    QString dataNo=ui->lineEdit_No->text();
    QString dataName=ui->lineEdit_Name->text();
    QString dataType=ui->lineEdit_Type->text();
    QString dataAttack=ui->lineEdit_Attack->text();
    QString dataStrike=ui->lineEdit_Strike->text();
    QString dataHit=ui->lineEdit_Hit->text();
    QString dataAvoid=ui->lineEdit_Avoid->text();
    QString dataArmor=ui->lineEdit_Armor->text();
    QString dataGet=ui->lineEdit_Get->text();
    QString dataSkill=ui->textEdit_Skill->toPlainText();

    QSqlQuery query;
    query.exec("select * from goblin");
    int index=0;
    while(query.next())
    {
        if(dataNo==query.value(0))
        {
            index=1;
            break;
        }
    }
    if(dataNo.isEmpty()||dataName.isEmpty()||dataType.isEmpty()
            ||dataAttack.isEmpty()||dataStrike.isEmpty()||dataHit.isEmpty()
            ||dataAvoid.isEmpty()||dataArmor.isEmpty()||dataGet.isEmpty()||dataSkill.isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：信息不完整"));
    }
    else {
        if(QMessageBox::question(this,
                                    QString::fromLocal8Bit("提示"),
                                    QString::fromLocal8Bit("是否添加"),
                                    QMessageBox::Yes,
                                    QMessageBox::No)==QMessageBox::Yes)
        {
            if(index==0)
            {
                query.prepare("insert into goblin values(:gob1,:gob2,:gob3,:gob4,:gob5,:gob6,:gob7,:gob8,:gob9,:gob10)");
                query.bindValue(":gob1",dataNo);
                query.bindValue(":gob2",dataName);
                query.bindValue(":gob3",dataType);
                query.bindValue(":gob4",dataAttack);
                query.bindValue(":gob5",dataStrike);
                query.bindValue(":gob6",dataHit);
                query.bindValue(":gob7",dataAvoid);
                query.bindValue(":gob8",dataArmor);
                query.bindValue(":gob9",dataGet);
                query.bindValue(":gob10",dataSkill);
                if(query.exec())
                {
                    emit send_goblin();
                    QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：添加成功"));
                }
                else
                {
                    QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：添加失败"));
                }
            }
            else {
                QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：添加信息编号已存在"));
            }
        }
        else {
            QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：已取消添加"));
        }
    }
}



void Dialog_add_goblin::on_pushButton_3_clicked()
{
    QString data_no=ui->lineEdit_Delete1->text();
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
            query.exec("select * from goblin");
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
                query.prepare("delete from goblin where gobNo=:gob1");
                query.bindValue(":gob1",data_no);
                if(query.exec())
                {
                    emit send_goblin();
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

void Dialog_add_goblin::on_pushButton_5_clicked()//获取
{
    QString dataNo=ui->lineEdit_No->text();
    QSqlQuery query;
    if(dataNo.isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：请填写编号"));
    }
    else
    {
        int index=0;
        query.exec("select * from goblin");
        while(query.next())
        {
            if(dataNo==query.value(0))
            {
                index=1;
                break;
            }
        }
        if(index==1)
        {
            query.prepare("select * from goblin where gobNo=:gob1");
            query.bindValue(":gob1",dataNo);
            if(query.exec())
            {
                query.next();
                selectno=query.value(0).toString();
                QString dataNo=query.value(0).toString();
                QString dataName=query.value(1).toString();
                QString dataType=query.value(2).toString();
                QString dataAttack=query.value(3).toString();
                QString dataStrike=query.value(4).toString();
                QString dataHit=query.value(5).toString();
                QString dataAvoid=query.value(6).toString();
                QString dataArmor=query.value(7).toString();
                QString dataGet=query.value(8).toString();
                QString dataSkill=query.value(8).toString();

                ui->lineEdit_No->setText(dataNo);
                ui->lineEdit_Name->setText(dataName);
                ui->lineEdit_Type->setText(dataType);
                ui->lineEdit_Attack->setText(dataAttack);
                ui->lineEdit_Strike->setText(dataStrike);
                ui->lineEdit_Hit->setText(dataHit);
                ui->lineEdit_Avoid->setText(dataAvoid);
                ui->lineEdit_Armor->setText(dataArmor);
                ui->lineEdit_Get->setText(dataGet);
                ui->textEdit_Skill->setText(dataSkill);

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

void Dialog_add_goblin::on_pushButton_4_clicked()//修改
{
    QString dataNo=ui->lineEdit_No->text();
    QString dataName=ui->lineEdit_Name->text();
    QString dataType=ui->lineEdit_Type->text();
    QString dataAttack=ui->lineEdit_Attack->text();
    QString dataStrike=ui->lineEdit_Strike->text();
    QString dataHit=ui->lineEdit_Hit->text();
    QString dataAvoid=ui->lineEdit_Avoid->text();
    QString dataArmor=ui->lineEdit_Armor->text();
    QString dataGet=ui->lineEdit_Get->text();
    QString dataSkill=ui->textEdit_Skill->toPlainText();

    QSqlQuery query;
    query.exec("select * from goblin");
    int index=0;
    int index1=0;
    while(query.next())
    {
        if(selectno==query.value(0))
        {
            index=1;
        }
        if(dataNo==query.value(0)&&dataNo!=selectno)
        {
            index1=1;
        }
    }
    if(dataNo.isEmpty()||dataName.isEmpty()||dataType.isEmpty()
            ||dataAttack.isEmpty()||dataStrike.isEmpty()||dataHit.isEmpty()
            ||dataAvoid.isEmpty()||dataArmor.isEmpty()||dataGet.isEmpty()||dataSkill.isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：信息不完整"));
    }
    else {
        if(QMessageBox::question(this,
                                    QString::fromLocal8Bit("提示"),
                                    QString::fromLocal8Bit("是否修改"),
                                    QMessageBox::Yes,
                                    QMessageBox::No)==QMessageBox::Yes)
        {
            if(index==1&&index1==0)
            {
                query.prepare("update goblin set gobNo=:gob1,gobName=:gob2,gobType=:gob3,gobAttack=:gob4,"
                              "gobStrike=:gob5,gobHit=:gob6,gobAvoid=:gob7,gobArmor=:gob8,"
                              "gobGet=:gob9,gobSkill=:gob10 where gobNo=:gob11");
                query.bindValue(":gob1",dataNo);
                query.bindValue(":gob2",dataName);
                query.bindValue(":gob3",dataType);
                query.bindValue(":gob4",dataAttack);
                query.bindValue(":gob5",dataStrike);
                query.bindValue(":gob6",dataHit);
                query.bindValue(":gob7",dataAvoid);
                query.bindValue(":gob8",dataArmor);
                query.bindValue(":gob9",dataGet);
                query.bindValue(":gob10",dataSkill);
                query.bindValue(":gob11",selectno);
                if(query.exec())
                {
                    emit send_goblin();
                    QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：修改成功"));
                }
                else
                {
                    QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：修改失败"));
                }
            }
            else {
                QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：\n修改目标不存在\n或修改后编号与已有重复"));
            }
        }
        else {
            QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：已取消修改"));
        }
    }
}

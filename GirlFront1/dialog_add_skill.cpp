#include "dialog_add_skill.h"
#include "ui_dialog_add_skill.h"

Dialog_add_skill::Dialog_add_skill(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_add_skill)
{
    ui->setupUi(this);

    ui->lineEdit_delete->setPlaceholderText(QString::fromLocal8Bit("编号"));
}

Dialog_add_skill::~Dialog_add_skill()
{
    delete ui;
}

void Dialog_add_skill::closeEvent(QCloseEvent *event)
{
     event->ignore();
     reject();
}

void Dialog_add_skill::on_pushButton_save_clicked()
{
    QString sk_no=ui->lineEdit_No->text();
    QString sk_name=ui->lineEdit_Name->text();
    QString sk_skill=ui->textEdit_skill->toPlainText();

    QSqlQuery query;
    query.exec("select * from skill");
    int index=0;
    while(query.next())
    {
        if(sk_no==query.value(0))
        {
            index=1;
            break;
        }
    }

    if(sk_no.isEmpty()||sk_name.isEmpty()||sk_skill.isEmpty())
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
            query.prepare("insert into skill values(:sk1,:sk2,:sk3)");
            query.bindValue(":sk1",sk_no);
            query.bindValue(":sk2",sk_name);
            query.bindValue(":sk3",sk_skill);
            if(query.exec())
            {
                emit send_skill();
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

void Dialog_add_skill::on_pushButton_clear_clicked()
{
    ui->lineEdit_No->setText("");
    ui->lineEdit_Name->setText("");
    ui->textEdit_skill->setText("");
}

void Dialog_add_skill::on_pushButton_delete_clicked()
{
    QString sk_no=ui->lineEdit_delete->text();
    if(sk_no.isEmpty())
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
            query.exec("select * from skill");
            while(query.next())
            {
                if(sk_no==query.value(0))
                {
                    index=1;
                    break;
                }
            }
            if(index==1)
            {
                query.prepare("delete from skill where skNo=:sk1");
                query.bindValue(":sk1",sk_no);
                if(query.exec())
                {
                    emit send_skill();
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

void Dialog_add_skill::on_pushButton_clear_2_clicked()
{
    QString sk_no=ui->lineEdit_No->text();
    QSqlQuery query;
    if(sk_no.isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("提示：请填写编号"));
    }
    else
    {
        int index=0;
        query.exec("select * from skill");
        while(query.next())
        {
            if(sk_no==query.value(0))
            {
                index=1;
                break;
            }
        }
        if(index==1)
        {
            query.prepare("select * from skill where skNo=:sk1");
            query.bindValue(":sk1",sk_no);
            if(query.exec())
            {
                query.next();
                selectno=query.value(0).toString();
                QString sk_no=query.value(0).toString();
                QString sk_name=query.value(1).toString();
                QString sk_skill=query.value(2).toString();

                ui->lineEdit_No->setText(sk_no);
                ui->lineEdit_Name->setText(sk_name);
                ui->textEdit_skill->setText(sk_skill);

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

void Dialog_add_skill::on_pushButton_save_2_clicked()
{
    QString sk_no=ui->lineEdit_No->text();
    QString sk_name=ui->lineEdit_Name->text();
    QString sk_skill=ui->textEdit_skill->toPlainText();

    QSqlQuery query;
    query.exec("select * from skill");
    int index=0;
    int index1=0;
    while(query.next())
    {
        if(selectno==query.value(0))
        {
            index=1;
        }
        if(sk_no==query.value(0)&&sk_no!=selectno)
        {
            index1=1;
        }
    }

    if(sk_no.isEmpty()||sk_name.isEmpty()||sk_skill.isEmpty())
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
            query.prepare("update skill set skNo=:sk1,skName=:sk2,skSkill=:sk3 where skNo=:sk4");
            query.bindValue(":sk1",sk_no);
            query.bindValue(":sk2",sk_name);
            query.bindValue(":sk3",sk_skill);
            query.bindValue(":sk4",selectno);
            if(query.exec())
            {
                emit send_skill();
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

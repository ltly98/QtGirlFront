#include "dialog_update.h"
#include "ui_dialog_update.h"

Dialog_update::Dialog_update(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_update)
{
    ui->setupUi(this);

    //设置tab键顺序
    QWidget::setTabOrder(ui->lineEdit_No,ui->lineEdit_Name);
    QWidget::setTabOrder(ui->lineEdit_Name,ui->lineEdit_Type);
    QWidget::setTabOrder(ui->lineEdit_Type,ui->lineEdit_Rare);
    QWidget::setTabOrder(ui->lineEdit_Rare,ui->lineEdit_Attack);
    QWidget::setTabOrder(ui->lineEdit_Attack,ui->lineEdit_Hit);
    QWidget::setTabOrder(ui->lineEdit_Hit,ui->lineEdit_Speed);
    QWidget::setTabOrder(ui->lineEdit_Speed,ui->lineEdit_Avoid);
    QWidget::setTabOrder(ui->lineEdit_Avoid,ui->lineEdit_Life);
    QWidget::setTabOrder(ui->lineEdit_Life,ui->lineEdit_Armor);
}

Dialog_update::~Dialog_update()
{
    delete ui;
}

void Dialog_update::closeEvent(QCloseEvent *event)
{
     event->ignore();
     reject();
     emit sendDataInfo_update(QString::fromLocal8Bit("提示：关闭修改信息功能"),1);

}

void Dialog_update::update_one(QString dbase,QString data, QString base,int d)
{
    if(data.isEmpty())
    {
        emit sendDataInfo_update(QString::fromLocal8Bit("提示：内容不完整"),0);
    }
    else {
        if(d==1)
        {
            if(QMessageBox::question(this,
                                        QString::fromLocal8Bit("提示"),
                                        QString::fromLocal8Bit("是否修改"),
                                        QMessageBox::Yes,
                                        QMessageBox::No)==QMessageBox::Yes)
            {
                QSqlQuery query;
                QString da=QString("update gun set \"%1\"=\"%2\" where gunNo=\"%3\"").arg(dbase,data,base);
                if(query.exec(da))
                {
                    emit sendDataInfo_update(QString::fromLocal8Bit("提示：修改成功"),1);
                    emit send_tableview_update("select * from gun");
                }
                else {
                   emit sendDataInfo_update(QString::fromLocal8Bit("提示：修改失败"),0);
                }
            }
            else
            {
                emit sendDataInfo_update(QString::fromLocal8Bit("提示：取消修改"),0);
            }

        }
        else {
            if(QMessageBox::question(this,
                                        QString::fromLocal8Bit("提示"),
                                        QString::fromLocal8Bit("是否修改"),
                                        QMessageBox::Yes,
                                        QMessageBox::No)==QMessageBox::Yes)
            {
                QSqlQuery query;
                query.prepare("update gun set "+dbase+"=:gun1 where gunNo=:gun2");
                query.bindValue(":gun1",data.toInt());
                 query.bindValue(":gun2",base);
                if(query.exec())
                {
                    emit sendDataInfo_update(QString::fromLocal8Bit("提示：修改成功"),1);
                    emit send_tableview_update("select * from gun");
                }
                else {
                   emit sendDataInfo_update(QString::fromLocal8Bit("提示：修改失败"),0);
                }
            }
            else
            {
                emit sendDataInfo_update(QString::fromLocal8Bit("提示：取消修改"),0);
            }

        }

    }
}

void Dialog_update::on_pushButton_No_clicked()
{
    QString gun_no=ui->lineEdit_No->text();
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
    if(index==0)
    {
        QString gun_selectno=ui->lineEdit_SelectNo->text();
        update_one("gunNo",gun_no,gun_selectno,1);
    }
    else {
        emit sendDataInfo_update(QString::fromLocal8Bit("提示：修改编号已存在"),0);
    }

}

void Dialog_update::on_pushButton_Name_clicked()
{
    QString gun_name=ui->lineEdit_Name->text();
    QString gun_selectno=ui->lineEdit_SelectNo->text();
    update_one("gunName",gun_name,gun_selectno,1);
}

void Dialog_update::on_pushButton_Type_clicked()
{
    QString gun_type=ui->lineEdit_Type->text();
    QString gun_selectno=ui->lineEdit_SelectNo->text();
    update_one("gunType",gun_type,gun_selectno,1);
}

void Dialog_update::on_pushButton_Rare_clicked()
{
    QString gun_rare=ui->lineEdit_Rare->text();
    QString gun_selectno=ui->lineEdit_SelectNo->text();
    update_one("gunRare",gun_rare,gun_selectno,1);
}

void Dialog_update::on_pushButton_No_Attack_clicked()
{
    QString gun_attack=ui->lineEdit_Attack->text();
    QString gun_selectno=ui->lineEdit_SelectNo->text();
    update_one("gunAttack",gun_attack,gun_selectno,0);
}

void Dialog_update::on_pushButton_No_Hit_clicked()
{
    QString gun_hit=ui->lineEdit_Hit->text();
    QString gun_selectno=ui->lineEdit_SelectNo->text();
    update_one("gunHit",gun_hit,gun_selectno,0);
}

void Dialog_update::on_pushButton_No_Speed_clicked()
{
    QString gun_speed=ui->lineEdit_Speed->text();
    QString gun_selectno=ui->lineEdit_SelectNo->text();
    update_one("gunSpeed",gun_speed,gun_selectno,0);
}

void Dialog_update::on_pushButton_No_Avoid_clicked()
{
    QString gun_avoid=ui->lineEdit_Avoid->text();
    QString gun_selectno=ui->lineEdit_SelectNo->text();
    update_one("gunAvoid",gun_avoid,gun_selectno,0);
}

void Dialog_update::on_pushButton_No_Life_clicked()
{
    QString gun_life=ui->lineEdit_Life->text();
    QString gun_selectno=ui->lineEdit_SelectNo->text();
    update_one("gunLife",gun_life,gun_selectno,0);
}

void Dialog_update::on_pushButton_No_Armor_clicked()
{
    QString gun_armor=ui->lineEdit_Armor->text();
    QString gun_selectno=ui->lineEdit_SelectNo->text();
    update_one("gunArmor",gun_armor,gun_selectno,0);
}

void Dialog_update::on_pushButton_clicked()
{
    QString gun_selectno=ui->lineEdit_SelectNo->text();
    QString gun_no=ui->lineEdit_No->text();
    QString gun_name=ui->lineEdit_Name->text();
     QString gun_type=ui->lineEdit_Type->text();
     QString gun_rare=ui->lineEdit_Rare->text();
     QString gun_attack=ui->lineEdit_Attack->text();
      QString gun_hit=ui->lineEdit_Hit->text();
      QString gun_speed=ui->lineEdit_Speed->text();
      QString gun_avoid=ui->lineEdit_Avoid->text();
      QString gun_life=ui->lineEdit_Life->text();
      QString gun_armor=ui->lineEdit_Armor->text();
      if(gun_selectno.isEmpty())
      {
          emit sendDataInfo_update(QString::fromLocal8Bit("提示：缺少依据编号"),0);
      }
      else if(gun_no.isEmpty()||gun_hit.isEmpty()||gun_life.isEmpty()
              ||gun_name.isEmpty()||gun_rare.isEmpty()||gun_type.isEmpty()
              ||gun_avoid.isEmpty()||gun_speed.isEmpty()||gun_attack.isEmpty()||gun_armor.isEmpty())
      {
          emit sendDataInfo_update(QString::fromLocal8Bit("提示：内容不完整"),0);
      }
      else
      {
          if(QMessageBox::question(this,
                                      QString::fromLocal8Bit("提示"),
                                      QString::fromLocal8Bit("是否修改"),
                                      QMessageBox::Yes,
                                      QMessageBox::No)==QMessageBox::Yes)
          {
              QSqlQuery query;
              query.exec("select *from gun");
              int index=0;
              while(query.next())
              {
                  if(gun_selectno!=gun_no&&gun_no==query.value(0))
                  {
                      index=1;
                      break;
                  }
              }
              if(index==0)
              {
                  query.prepare("update gun set gunNo=:gun1,gunName=:gun2,gunType=:gun3,"
                                "gunRare=:gun4,gunAttack=:gun5,gunHit=:gun6,gunAvoid=:gun7,"
                                "gunSpeed=:gun8,gunLife=:gun9,gunArmor=:gun10 where gunNo=:gun11");
                  query.bindValue(":gun1",gun_no);
                  query.bindValue(":gun2",gun_name);
                  query.bindValue(":gun3",gun_type);
                  query.bindValue(":gun4",gun_rare);
                  query.bindValue(":gun5",gun_attack.toInt());
                  query.bindValue(":gun6",gun_hit.toInt());
                  query.bindValue(":gun7",gun_avoid.toInt());
                  query.bindValue(":gun8",gun_speed.toInt());
                  query.bindValue(":gun9",gun_life.toInt());
                  query.bindValue(":gun10",gun_armor.toInt());
                  query.bindValue(":gun11",gun_selectno);
                  if(query.exec())
                  {
                      emit sendDataInfo_update(QString::fromLocal8Bit("提示：修改成功"),1);
                      emit send_tableview_update("select * from gun");
                  }
                  else {
                     emit sendDataInfo_update(QString::fromLocal8Bit("提示：修改失败"),0);
                  }
              }
              else {
                  emit sendDataInfo_update(QString::fromLocal8Bit("提示：修改编号已存在"),0);
              }

          }
          else {
              emit sendDataInfo_update(QString::fromLocal8Bit("提示：取消修改"),0);
          }

      }
}

void Dialog_update::on_pushButton_2_clicked()
{
    ui->lineEdit_No->setText("");
    ui->lineEdit_Name->setText("");
    ui->lineEdit_Type->setText("");
    ui->lineEdit_Rare->setText("");
    ui->lineEdit_Attack->setText("");
    ui->lineEdit_Hit->setText("");
    ui->lineEdit_Speed->setText("");
    ui->lineEdit_Avoid->setText("");
    ui->lineEdit_Life->setText("");
    ui->lineEdit_Armor->setText("");
    ui->lineEdit_SelectNo->setText("");
    emit sendDataInfo_update(QString::fromLocal8Bit("提示：清空内容"),1);
}

void Dialog_update::on_pushButton_3_clicked()
{
    QString gun_selectno=ui->lineEdit_SelectNo->text();
     QString gun_attack=ui->lineEdit_Attack->text();
      QString gun_hit=ui->lineEdit_Hit->text();
      QString gun_speed=ui->lineEdit_Speed->text();
      QString gun_avoid=ui->lineEdit_Avoid->text();
      QString gun_life=ui->lineEdit_Life->text();
      QString gun_armor=ui->lineEdit_Armor->text();
      if(gun_selectno.isEmpty())
      {
          emit sendDataInfo_update(QString::fromLocal8Bit("提示：缺少依据编号"),0);
      }
      else if(gun_hit.isEmpty()||gun_life.isEmpty()
              ||gun_avoid.isEmpty()||gun_speed.isEmpty()||gun_attack.isEmpty()||gun_armor.isEmpty())
      {
          emit sendDataInfo_update(QString::fromLocal8Bit("提示：内容不完整"),0);
      }
      else
      {
          if(QMessageBox::question(this,
                                      QString::fromLocal8Bit("提示"),
                                      QString::fromLocal8Bit("是否修改"),
                                      QMessageBox::Yes,
                                      QMessageBox::No)==QMessageBox::Yes)
          {
              QSqlQuery query;
              query.prepare("update gun set gunAttack=:gun1,gunHit=:gun2,gunAvoid=:gun3,"
                            "gunSpeed=:gun4,gunLife=:gun5,gunArmor=:gun6 where gunNo=:gun7");
              query.bindValue(":gun1",gun_attack.toInt());
              query.bindValue(":gun2",gun_hit.toInt());
              query.bindValue(":gun3",gun_avoid.toInt());
              query.bindValue(":gun4",gun_speed.toInt());
              query.bindValue(":gun5",gun_life.toInt());
              query.bindValue(":gun6",gun_armor.toInt());
              query.bindValue(":gun7",gun_selectno);
              if(query.exec())
              {
                  emit sendDataInfo_update(QString::fromLocal8Bit("提示：修改成功"),1);
                  emit send_tableview_update("select * from gun");
              }
              else {
                 emit sendDataInfo_update(QString::fromLocal8Bit("提示：修改失败"),0);
              }
          }
          else {
              emit sendDataInfo_update(QString::fromLocal8Bit("提示：取消修改"),0);
          }

      }
}


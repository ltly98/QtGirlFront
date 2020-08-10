#include "dialog_new.h"
#include "ui_dialog_new.h"

Dialog_new::Dialog_new(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_new)
{
    ui->setupUi(this);
    QMessageBox::information(this,QString::fromLocal8Bit("新建注意"),QString::fromLocal8Bit("特典枪编号前加T\n稀有度填T"));

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
    QWidget::setTabOrder(ui->lineEdit_Armor,ui->pushButton);
    QWidget::setTabOrder(ui->pushButton,ui->pushButton_2);
}

Dialog_new::~Dialog_new()
{
    delete ui;
}

void Dialog_new::closeEvent(QCloseEvent *event)
{
     event->ignore();
     reject();
     emit sendDataInfo_new(QString::fromLocal8Bit("提示：关闭新建信息功能"),1);
}

void Dialog_new::on_pushButton_clicked()
{
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
    if(gun_no.isEmpty()||gun_hit.isEmpty()||gun_life.isEmpty()
            ||gun_name.isEmpty()||gun_rare.isEmpty()||gun_type.isEmpty()
            ||gun_avoid.isEmpty()||gun_speed.isEmpty()||gun_attack.isEmpty()||gun_armor.isEmpty())
    {
        emit sendDataInfo_new(QString::fromLocal8Bit("提示：内容不完整"),0);
    }
    else
    {
        if(QMessageBox::question(this,
                                    QString::fromLocal8Bit("提示"),
                                    QString::fromLocal8Bit("是否新建"),
                                    QMessageBox::Yes,
                                    QMessageBox::No)==QMessageBox::Yes)
        {
            QSqlQuery query;//执行数据库语句用
            query.exec("select * from gun");
            int index=0;
            while (query.next()) {
                if(gun_no==query.value(0))
                {
                    index=1;
                    break;
                }
            }
            if(index==0)
            {
                query.prepare("insert into gun values(:gun1,:gun2,:gun3,:gun4,:gun5,:gun6,:gun7,:gun8,:gun9,:gun10)");
                query.bindValue(":gun1",gun_no);
                query.bindValue(":gun2",gun_name);
                query.bindValue(":gun3",gun_type);
                query.bindValue(":gun4",gun_rare);
                query.bindValue(":gun5",gun_attack.toInt());
                query.bindValue(":gun6",gun_hit.toInt());
                query.bindValue(":gun7",gun_speed.toInt());
                query.bindValue(":gun8",gun_avoid.toInt());
                query.bindValue(":gun9",gun_life.toInt());
                query.bindValue(":gun10",gun_armor.toInt());
                if(query.exec())
                {
                    emit sendDataInfo_new(QString::fromLocal8Bit("提示：添加成功"),1);
                    emit send_tableview_new("select * from gun");
                }
                else {
                    emit sendDataInfo_new(QString::fromLocal8Bit("提示：添加失败"),0);
                }
            }
            else {
                emit sendDataInfo_new(QString::fromLocal8Bit("提示：已存在该编号枪"),0);
            }

        }
        else
        {
            emit sendDataInfo_new(QString::fromLocal8Bit("提示：已取消新建"),0);
        }

    }

}

void Dialog_new::on_pushButton_2_clicked()
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
    emit sendDataInfo_new(QString::fromLocal8Bit("提示：清空内容"),1);
}

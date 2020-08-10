#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include<QStandardItemModel>
#include<QApplication>



#include"dialog_delete.h"
#include"dialog_new.h"
#include"dialog_update.h"
#include"dialog_command.h"
#include"dialog_login.h"
#include"dialog_goblin.h"
#include"dialog_equip.h"
#include"dialog_effect.h"
#include"dialog_skill.h"
#include"dialog_about.h"
#include"dialog_select.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void ShowTableView(QStandardItemModel *model);

    void ShowOrderTable(QString data);

private slots:
    void receiveDataInfo(QString data,int num);   //接收传递过来的数据的槽

    void receive_showtable(QString);//变动显示表

    void logstatus(int data);//接收登录状态

    void on_actionNew_triggered();

    void on_actionUpdate_triggered();

    void on_actionDelete_triggered();

    void on_actionDB_command_triggered();

    void on_actionExit_triggered();

    //AR

    void on_actionAR_Attack_triggered();

    void on_actionAR_Hit_triggered();

    void on_actionAR_Speed_triggered();

    void on_actionAR_Avoid_triggered();

    void on_actionAR_Life_triggered();

    void on_actionAR_All_triggered();

    //RF

    void on_actionRF_All_triggered();

    void on_actionRF_Attack_triggered();

    void on_actionRF_Hit_triggered();

    void on_actionRF_Avoid_triggered();

    void on_actionRF_Speed_triggered();

    void on_actionRF_Life_triggered();

    //HG

    void on_actionHG_All_triggered();

    void on_actionHG_Attack_triggered();

    void on_actionHG_Hit_triggered();

    void on_actionHG_Speed_triggered();

    void on_actionHG_Avoid_triggered();

    void on_actionHG_Life_triggered();

    //SG

    void on_actionSG_All_triggered();

    void on_actionSG_Attack_triggered();

    void on_actionSG_Hit_triggered();

    void on_actionSG_Speed_triggered();

    void on_actionSG_Avoid_triggered();

    void on_actionSG_Life_triggered();

    void on_actionSG_Armor_triggered();

    //MG

    void on_actionMG_All_triggered();

    void on_actionMG_Attack_triggered();

    void on_actionMG_Hit_triggered();

    void on_actionMG_Speed_triggered();

    void on_actionMG_Avoid_triggered();

    void on_actionMG_Life_triggered();

    //SMG

    void on_actionSMG_All_triggered();

    void on_actionSMG_Attack_triggered();

    void on_actionSMG_Hit_triggered();

    void on_actionSMG_Speed_triggered();

    void on_actionSMG_Avoid_triggered();

    void on_actionSMG_Life_triggered();

    void on_actionlogin_triggered();

    void on_actionlogout_triggered();

    void on_actionStatus_triggered();

    void on_actionGoblin_triggered();

    void on_actionEquip_triggered();

    void on_actionArray_triggered();

    void on_actionSkill_triggered();

    void on_actionAbout_triggered();

    void on_actionSelect_triggered();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QSqlDatabase db_gril;//数据库
    int row;//统计行数


    Dialog_new *newinfo;
    Dialog_delete *deleteinfo;
    Dialog_update *updateinfo;
    Dialog_select *selectinfo;
    Dialog_command *commandinfo;

    Dialog_login *administator;

    Dialog_goblin *goblininfo;

    Dialog_equip *equipinfo;

    Dialog_effect *effectinfo;

    Dialog_skill *skillinfo;

    Dialog_about *aboutinfo;

};

#endif // MAINWINDOW_H

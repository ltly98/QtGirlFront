#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText(QString::fromLocal8Bit("登录状态：未登录"));

    ui->textEdit->setTextColor(Qt::green);//设置初始字体颜色

    ui->menuMenu->setTitle(QString::fromLocal8Bit("基本菜单"));

    ui->actionAbout->setText(QString::fromLocal8Bit("关于.."));
    ui->actionExit->setText(QString::fromLocal8Bit("退出"));

    ui->menuSelect->setTitle(QString::fromLocal8Bit("属性排序"));

    ui->menuOther->setTitle(QString::fromLocal8Bit("其他表"));
    ui->actionGoblin->setText(QString::fromLocal8Bit("妖精表"));
    ui->actionEquip->setText(QString::fromLocal8Bit("装备表"));
    ui->actionArray->setText(QString::fromLocal8Bit("影响表"));
    ui->actionSkill->setText(QString::fromLocal8Bit("技能表"));


    ui->menuAR->setTitle(QString::fromLocal8Bit("AR"));
    ui->actionAR_All->setText(QString::fromLocal8Bit("全部AR"));
    ui->actionAR_Attack->setText(QString::fromLocal8Bit("降序攻击排序"));
    ui->actionAR_Hit->setText(QString::fromLocal8Bit("降序命中排序"));
    ui->actionAR_Speed->setText(QString::fromLocal8Bit("降序射速排序"));
    ui->actionAR_Avoid->setText(QString::fromLocal8Bit("降序回避排序"));
    ui->actionAR_Life->setText(QString::fromLocal8Bit("降序生命排序"));

    ui->menuRF->setTitle(QString::fromLocal8Bit("RF"));
    ui->actionRF_All->setText(QString::fromLocal8Bit("全部RF"));
    ui->actionRF_Attack->setText(QString::fromLocal8Bit("降序攻击排序"));
    ui->actionRF_Hit->setText(QString::fromLocal8Bit("降序命中排序"));
    ui->actionRF_Speed->setText(QString::fromLocal8Bit("降序射速排序"));
    ui->actionRF_Avoid->setText(QString::fromLocal8Bit("降序回避排序"));
    ui->actionRF_Life->setText(QString::fromLocal8Bit("降序生命排序"));

    ui->menuHG->setTitle(QString::fromLocal8Bit("HG"));
    ui->actionHG_All->setText(QString::fromLocal8Bit("全部HG"));
    ui->actionHG_Attack->setText(QString::fromLocal8Bit("降序攻击排序"));
    ui->actionHG_Hit->setText(QString::fromLocal8Bit("降序命中排序"));
    ui->actionHG_Speed->setText(QString::fromLocal8Bit("降序射速排序"));
    ui->actionHG_Avoid->setText(QString::fromLocal8Bit("降序回避排序"));
    ui->actionHG_Life->setText(QString::fromLocal8Bit("降序生命排序"));

    ui->menuMG->setTitle(QString::fromLocal8Bit("MG"));
    ui->actionMG_All->setText(QString::fromLocal8Bit("全部MG"));
    ui->actionMG_Attack->setText(QString::fromLocal8Bit("降序攻击排序"));
    ui->actionMG_Hit->setText(QString::fromLocal8Bit("降序命中排序"));
    ui->actionMG_Speed->setText(QString::fromLocal8Bit("降序射速排序"));
    ui->actionMG_Avoid->setText(QString::fromLocal8Bit("降序回避排序"));
    ui->actionMG_Life->setText(QString::fromLocal8Bit("降序生命排序"));

    ui->menuSMG->setTitle(QString::fromLocal8Bit("SMG"));
    ui->actionSMG_All->setText(QString::fromLocal8Bit("全部SMG"));
    ui->actionSMG_Attack->setText(QString::fromLocal8Bit("降序攻击排序"));
    ui->actionSMG_Hit->setText(QString::fromLocal8Bit("降序命中排序"));
    ui->actionSMG_Speed->setText(QString::fromLocal8Bit("降序射速排序"));
    ui->actionSMG_Avoid->setText(QString::fromLocal8Bit("降序回避排序"));
    ui->actionSMG_Life->setText(QString::fromLocal8Bit("降序生命排序"));

    ui->menuSG->setTitle(QString::fromLocal8Bit("SG"));
    ui->actionSG_All->setText(QString::fromLocal8Bit("全部SG"));
    ui->actionSG_Attack->setText(QString::fromLocal8Bit("降序攻击排序"));
    ui->actionSG_Hit->setText(QString::fromLocal8Bit("降序命中排序"));
    ui->actionSG_Speed->setText(QString::fromLocal8Bit("降序射速排序"));
    ui->actionSG_Avoid->setText(QString::fromLocal8Bit("降序回避排序"));
    ui->actionSG_Life->setText(QString::fromLocal8Bit("降序生命排序"));
    ui->actionSG_Armor->setText(QString::fromLocal8Bit("降序护甲排序"));

    ui->actionStatus->setText(QString::fromLocal8Bit("初始化表"));

    ui->menuAdministrator->setTitle(QString::fromLocal8Bit("管理表"));
    ui->actionlogin->setText(QString::fromLocal8Bit("登录"));
    ui->actionNew->setText(QString::fromLocal8Bit("新建信息(权限)"));
    ui->actionUpdate->setText(QString::fromLocal8Bit("修改信息(权限)"));
    ui->actionDelete->setText(QString::fromLocal8Bit("删除信息(权限)"));
    ui->actionSelect->setText(QString::fromLocal8Bit("查找信息"));
    ui->actionlogout->setText(QString::fromLocal8Bit("注销"));

    ui->menuMaintain->setTitle(QString::fromLocal8Bit("重要维护"));
    ui->actionDB_command->setText(QString::fromLocal8Bit("数据库命令(root权限)"));

    //创建数据库，并检查
    db_gril=QSqlDatabase::addDatabase("QSQLITE");
    db_gril.setDatabaseName("GirlFront.db3");//设置数据库名称
    if(db_gril.open())
    {
        ui->textEdit->append(QString::fromLocal8Bit("提示：打开数据库成功"));
    }
    else {
        ui->textEdit->setTextColor(Qt::red);
        ui->textEdit->append(QString::fromLocal8Bit("提示：打开数据库失败"));
        ui->textEdit->setTextColor(Qt::green);
    }

    //tableview设置

    model = new QStandardItemModel();
    model->setColumnCount(10);
    model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("图鉴编号"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("名称"));
    model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("类型"));
    model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("稀有度"));
    model->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("伤害"));
    model->setHeaderData(5,Qt::Horizontal,QString::fromLocal8Bit("命中"));
    model->setHeaderData(6,Qt::Horizontal,QString::fromLocal8Bit("射速"));
    model->setHeaderData(7,Qt::Horizontal,QString::fromLocal8Bit("回避"));
    model->setHeaderData(8,Qt::Horizontal,QString::fromLocal8Bit("生命"));
    model->setHeaderData(9,Qt::Horizontal,QString::fromLocal8Bit("护甲"));

    ui->tableView->setModel(model);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止双击编辑，不提供此操作功能

    ShowTableView(model);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}

void MainWindow::ShowTableView(QStandardItemModel *model)
{
    QSqlQuery query;//执行数据库语句用
    query.exec("select * from gun");
    int t=0;
    while(query.next())
    {
        model->setItem(t,0,new QStandardItem(query.value(0).toString()));
        model->setItem(t,1,new QStandardItem(query.value(1).toString()));
        model->setItem(t,2,new QStandardItem(query.value(2).toString()));
        model->setItem(t,3,new QStandardItem(query.value(3).toString()));
        model->setItem(t,4,new QStandardItem(query.value(4).toString()));
        model->setItem(t,5,new QStandardItem(query.value(5).toString()));
        model->setItem(t,6,new QStandardItem(query.value(6).toString()));
        model->setItem(t,7,new QStandardItem(query.value(7).toString()));
        model->setItem(t,8,new QStandardItem(query.value(8).toString()));
        model->setItem(t,9,new QStandardItem(query.value(9).toString()));
        for(int k=0;k<10;k++)
        {
            model->item(t,k)->setTextAlignment(Qt::AlignCenter);
        }
        t++;
    }
    row=model->rowCount();
    ui->textEdit->append(QString::fromLocal8Bit("提示：显示表成功"));
}

void MainWindow::ShowOrderTable(QString data)
{
    QSqlQuery query;//执行数据库语句用
    query.exec(data);
    int t=0;
    while(query.next())
    {
        model->setItem(t,0,new QStandardItem(query.value(0).toString()));
        model->setItem(t,1,new QStandardItem(query.value(1).toString()));
        model->setItem(t,2,new QStandardItem(query.value(2).toString()));
        model->setItem(t,3,new QStandardItem(query.value(3).toString()));
        model->setItem(t,4,new QStandardItem(query.value(4).toString()));
        model->setItem(t,5,new QStandardItem(query.value(5).toString()));
        model->setItem(t,6,new QStandardItem(query.value(6).toString()));
        model->setItem(t,7,new QStandardItem(query.value(7).toString()));
        model->setItem(t,8,new QStandardItem(query.value(8).toString()));
        model->setItem(t,9,new QStandardItem(query.value(9).toString()));
        for(int k=0;k<10;k++)
        {
            model->item(t,k)->setTextAlignment(Qt::AlignCenter);
        }
        t++;
    }
    for(int i=t-1;i<row;i++)
    {
        model->removeRow(t);
    }
    ui->textEdit->append(QString::fromLocal8Bit("提示：排序查找成功"));
}

void MainWindow::receiveDataInfo(QString data,int num)//接收传递过来的数据的槽
{
    if(num==1)
    {
        ui->textEdit->append(data);
    }
    else {
         ui->textEdit->setTextColor(Qt::red);
         ui->textEdit->append(data);
         ui->textEdit->setTextColor(Qt::green);
    }
}

void MainWindow::receive_showtable(QString data)
{

    QSqlQuery query;//执行数据库语句用
    query.exec(data);
    int t=0;
    while(query.next())
    {
        model->setItem(t,0,new QStandardItem(query.value(0).toString()));
        model->setItem(t,1,new QStandardItem(query.value(1).toString()));
        model->setItem(t,2,new QStandardItem(query.value(2).toString()));
        model->setItem(t,3,new QStandardItem(query.value(3).toString()));
        model->setItem(t,4,new QStandardItem(query.value(4).toString()));
        model->setItem(t,5,new QStandardItem(query.value(5).toString()));
        model->setItem(t,6,new QStandardItem(query.value(6).toString()));
        model->setItem(t,7,new QStandardItem(query.value(7).toString()));
        model->setItem(t,8,new QStandardItem(query.value(8).toString()));
        model->setItem(t,9,new QStandardItem(query.value(9).toString()));
        for(int k=0;k<10;k++)
        {
            model->item(t,k)->setTextAlignment(Qt::AlignCenter);
        }
        t++;
    }
    for(int i=t-1;i<row;i++)
    {
        model->removeRow(t);
    }
    ui->textEdit->append(QString::fromLocal8Bit("提示：显示表成功"));
}

void MainWindow::logstatus(int data)
{
    if(data==1)
    {
        login_user=1;
        ui->label->setText(QString::fromLocal8Bit("登录状态：用户登录"));
    }
    else {
        login_user=1;
        login_root=1;
        ui->label->setText(QString::fromLocal8Bit("登录状态：开发者登录"));
    }
}

void MainWindow::on_actionNew_triggered()
{
    if(login_user==1)
    {
        newinfo=new Dialog_new(this);
        newinfo->setWindowTitle(QString::fromLocal8Bit("新建信息"));
        newinfo->setFixedSize(newinfo->width(),newinfo->height());//禁止拉伸
        connect(newinfo, SIGNAL(sendDataInfo_new(QString,int)), this, SLOT(receiveDataInfo(QString,int)));
        connect(newinfo, SIGNAL(send_tableview_new(QString)), this, SLOT(receive_showtable(QString)));
        newinfo->show();
        ui->textEdit->append(QString::fromLocal8Bit("提示：打开新建信息功能"));

    }
    else {
        ui->textEdit->setTextColor(Qt::red);
        ui->textEdit->append(QString::fromLocal8Bit("提示：没有权限"));
        ui->textEdit->setTextColor(Qt::green);
    }
}

void MainWindow::on_actionUpdate_triggered()
{
    if(login_user==1)
    {
        updateinfo=new Dialog_update(this);
        updateinfo->setWindowTitle(QString::fromLocal8Bit("修改信息"));
        updateinfo->setFixedSize(updateinfo->width(),updateinfo->height());//禁止拉伸
        connect(updateinfo, SIGNAL(sendDataInfo_update(QString,int)), this, SLOT(receiveDataInfo(QString,int)));
        connect(updateinfo, SIGNAL(send_tableview_update(QString)), this, SLOT(receive_showtable(QString)));
        updateinfo->show();
        ui->textEdit->append(QString::fromLocal8Bit("提示：打开修改信息功能"));

    }
    else {
        ui->textEdit->setTextColor(Qt::red);
        ui->textEdit->append(QString::fromLocal8Bit("提示：没有权限"));
        ui->textEdit->setTextColor(Qt::green);
    }

}

void MainWindow::on_actionDelete_triggered()
{
    if(login_user==1)
    {
        deleteinfo=new Dialog_delete(this);
        deleteinfo->setWindowTitle(QString::fromLocal8Bit("删除信息"));
        deleteinfo->setFixedSize(deleteinfo->width(),deleteinfo->height());//禁止拉伸
        connect(deleteinfo, SIGNAL(sendDataInfo_delete(QString,int)), this, SLOT(receiveDataInfo(QString,int)));
        connect(deleteinfo, SIGNAL(send_tableview_delete(QString)), this, SLOT(receive_showtable(QString)));
        deleteinfo->show();
        ui->textEdit->append(QString::fromLocal8Bit("提示：打开删除信息功能"));

    }
    else {
        ui->textEdit->setTextColor(Qt::red);
        ui->textEdit->append(QString::fromLocal8Bit("提示：没有权限"));
        ui->textEdit->setTextColor(Qt::green);
    }

}

void MainWindow::on_actionDB_command_triggered()
{
    if(login_root==1)
    {
        commandinfo=new Dialog_command(this);
        commandinfo->setWindowTitle(QString::fromLocal8Bit("数据库命令"));
        commandinfo->setFixedSize(commandinfo->width(),commandinfo->height());//No stretching
        connect(commandinfo, SIGNAL(sendDataInfo_command(QString,int)), this, SLOT(receiveDataInfo(QString,int)));
        commandinfo->show();
        ui->textEdit->append(QString::fromLocal8Bit("打开数据库命令功能..."));
    }
    else {
        ui->textEdit->setTextColor(Qt::red);
        ui->textEdit->append(QString::fromLocal8Bit("提示：需要root权限"));
        ui->textEdit->setTextColor(Qt::green);
    }
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_actionAR_Attack_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"AR\" order by gunAttack DESC");
}

void MainWindow::on_actionAR_Hit_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"AR\" order by gunHit DESC");
}

void MainWindow::on_actionAR_Speed_triggered()
{
     ShowOrderTable("select *from gun where gunType=\"AR\" order by gunSpeed DESC");
}

void MainWindow::on_actionAR_Avoid_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"AR\" order by gunAvoid DESC");
}

void MainWindow::on_actionAR_Life_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"AR\" order by gunLife DESC");
}

void MainWindow::on_actionAR_All_triggered()
{

    ShowOrderTable("select *from gun where gunType=\"AR\" ");
}

void MainWindow::on_actionRF_All_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"RF\"");
}

void MainWindow::on_actionRF_Attack_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"RF\" order by gunAttack DESC");
}

void MainWindow::on_actionRF_Hit_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"RF\" order by gunHit DESC");
}

void MainWindow::on_actionRF_Avoid_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"RF\" order by gunAvoid DESC");
}

void MainWindow::on_actionRF_Speed_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"RF\" order by gunSpeed DESC");
}

void MainWindow::on_actionRF_Life_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"RF\" order by gunLife DESC");
}

void MainWindow::on_actionHG_All_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"HG\"");
}

void MainWindow::on_actionHG_Attack_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"HG\" order by gunAttack DESC");
}

void MainWindow::on_actionHG_Hit_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"HG\" order by gunHit DESC");
}

void MainWindow::on_actionHG_Speed_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"HG\" order by gunSpeed DESC");
}

void MainWindow::on_actionHG_Avoid_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"HG\" order by gunAvoid DESC");
}

void MainWindow::on_actionHG_Life_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"HG\" order by gunLife DESC");
}

void MainWindow::on_actionSG_All_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"SG\"");
}

void MainWindow::on_actionSG_Attack_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"SG\" order by gunAttack DESC");
}

void MainWindow::on_actionSG_Hit_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"SG\" order by gunHit DESC");
}

void MainWindow::on_actionSG_Speed_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"SG\" order by gunSpeed DESC");
}

void MainWindow::on_actionSG_Avoid_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"SG\" order by gunAvoid DESC");
}

void MainWindow::on_actionSG_Life_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"SG\" order by gunLife DESC");
}

void MainWindow::on_actionSG_Armor_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"SG\" order by gunArmor DESC");
}

void MainWindow::on_actionMG_All_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"MG\"");
}

void MainWindow::on_actionMG_Attack_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"MG\" order by gunAttack DESC");
}

void MainWindow::on_actionMG_Hit_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"MG\" order by gunHit DESC");
}

void MainWindow::on_actionMG_Speed_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"MG\" order by gunSpeed DESC");
}

void MainWindow::on_actionMG_Avoid_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"MG\" order by gunAvoid DESC");
}

void MainWindow::on_actionMG_Life_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"MG\" order by gunLife DESC");
}

void MainWindow::on_actionSMG_All_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"SMG\"");
}

void MainWindow::on_actionSMG_Attack_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"SMG\" order by gunAttack DESC");
}

void MainWindow::on_actionSMG_Hit_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"SMG\" order by gunHit DESC");
}

void MainWindow::on_actionSMG_Speed_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"SMG\" order by gunSpeed DESC");
}

void MainWindow::on_actionSMG_Avoid_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"SMG\" order by gunAvoid DESC");
}

void MainWindow::on_actionSMG_Life_triggered()
{
    ShowOrderTable("select *from gun where gunType=\"SMG\" order by gunLife DESC");
}

void MainWindow::on_actionlogin_triggered()
{
    if(login_user==1||login_root==1)
    {
        ui->textEdit->setTextColor(Qt::red);
        ui->textEdit->append(QString::fromLocal8Bit("已登录"));
        ui->textEdit->setTextColor(Qt::green);
    }
    else{
            administator=new Dialog_login(this);
            administator->setWindowTitle(QString::fromLocal8Bit("登录"));
            administator->setFixedSize(administator->width(),administator->height());//禁止拉伸
            connect(administator, SIGNAL(sendDataInfo_login(QString,int)), this, SLOT(receiveDataInfo(QString,int)));
            connect(administator, SIGNAL(send_loginstatus(int)), this, SLOT(logstatus(int)));
            administator->show();
            ui->textEdit->append(QString::fromLocal8Bit("提示：打开登录功能"));
    }
}

void MainWindow::on_actionlogout_triggered()
{
    if(login_root!=0||login_user!=0)
    {
        login_root=0;
        login_user=0;
        ui->label->setText(QString::fromLocal8Bit("登录状态：未登录"));
    }
    else {
        ui->textEdit->setTextColor(Qt::red);
        ui->textEdit->append(QString::fromLocal8Bit("提示：注销失败，未登录"));
        ui->textEdit->setTextColor(Qt::green);
    }
}

void MainWindow::on_actionStatus_triggered()
{
    ShowTableView(model);
    ui->textEdit->append(QString::fromLocal8Bit("提示：初始化表成功"));
}

void MainWindow::on_actionGoblin_triggered()
{
    goblininfo=new Dialog_goblin(this);
    goblininfo->setWindowTitle(QString::fromLocal8Bit("妖精表"));
    goblininfo->setFixedSize(goblininfo->width(),goblininfo->height());//禁止拉伸
    connect(goblininfo, SIGNAL(sendDataInfo_goblin(QString,int)), this, SLOT(receiveDataInfo(QString,int)));
    goblininfo->show();
    ui->textEdit->append(QString::fromLocal8Bit("提示：打开妖精表"));
}

void MainWindow::on_actionEquip_triggered()
{
    equipinfo=new Dialog_equip(this);
    equipinfo->setWindowTitle(QString::fromLocal8Bit("装备表"));
    equipinfo->setFixedSize(equipinfo->width(),equipinfo->height());//禁止拉伸
    connect(equipinfo, SIGNAL(sendDataInfo_equip(QString,int)), this, SLOT(receiveDataInfo(QString,int)));
    equipinfo->show();
    ui->textEdit->append(QString::fromLocal8Bit("提示：打开装备表"));
}

void MainWindow::on_actionArray_triggered()
{
    effectinfo=new Dialog_effect(this);
    effectinfo->setWindowTitle(QString::fromLocal8Bit("影响表"));
    effectinfo->setFixedSize(effectinfo->width(),effectinfo->height());//禁止拉伸
    connect(effectinfo, SIGNAL(sendDataInfo_effect(QString,int)), this, SLOT(receiveDataInfo(QString,int)));
    effectinfo->show();
    ui->textEdit->append(QString::fromLocal8Bit("提示：打开影响表"));
}

void MainWindow::on_actionSkill_triggered()
{
    skillinfo=new Dialog_skill(this);
    skillinfo->setWindowTitle(QString::fromLocal8Bit("技能表"));
    skillinfo->setFixedSize(skillinfo->width(),skillinfo->height());//禁止拉伸
    connect(skillinfo, SIGNAL(sendDataInfo_skill(QString,int)), this, SLOT(receiveDataInfo(QString,int)));
    skillinfo->show();
    ui->textEdit->append(QString::fromLocal8Bit("提示：打开技能表"));
}

void MainWindow::on_actionAbout_triggered()
{
    aboutinfo=new Dialog_about(this);
    aboutinfo->setWindowTitle(QString::fromLocal8Bit("关于"));
    aboutinfo->setFixedSize(aboutinfo->width(),aboutinfo->height());//禁止拉伸
    connect(aboutinfo, SIGNAL(sendDataInfo_about(QString,int)), this, SLOT(receiveDataInfo(QString,int)));
    aboutinfo->show();
    ui->textEdit->append(QString::fromLocal8Bit("提示：打开相关信息"));
}

void MainWindow::on_actionSelect_triggered()
{
    selectinfo=new Dialog_select(this);
    selectinfo->setWindowTitle(QString::fromLocal8Bit("查找信息"));
    selectinfo->setFixedSize(selectinfo->width(),selectinfo->height());//禁止拉伸
    connect(selectinfo, SIGNAL(sendDataInfo_select(QString,int)), this, SLOT(receiveDataInfo(QString,int)));
    connect(selectinfo, SIGNAL(send_tableview_select(QString)), this, SLOT(receive_showtable(QString)));
    selectinfo->show();
    ui->textEdit->append(QString::fromLocal8Bit("提示：打开查找信息功能"));
}

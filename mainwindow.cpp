#pragma execution_character_set("utf-8")

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QItemSelectionModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //禁用最大化按钮
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    //禁用窗口拉伸
    setFixedSize(this->width(), this->height());
    InitMessageFind();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitMessageFind()
{
   QStandardItemModel* model = new QStandardItemModel(ui->log_message_find);

   model->setHorizontalHeaderLabels(QStringList()<<QString::fromUtf8("日志查看器"));

   //一级第一个节点
   QStandardItem* item_first = new QStandardItem(QIcon(QString::fromUtf8("F:\\treetest\\res_treeItemIcon\\folder.png")),QString::fromUtf8("系统日志"));

   model->appendRow(item_first);

   //第一个节点内容
   QStandardItem* itemProject = new QStandardItem(QIcon(QString::fromUtf8("F:\\treetest\\res_treeItemIcon\\folder.png")),QString::fromUtf8("SysEvent日志"));
   item_first->appendRow(itemProject);

   QStandardItem* itemProject1 = new QStandardItem(QIcon(QString::fromUtf8("F:\\treetest\\res_treeItemIcon\\folder.png")),QString::fromUtf8("SecEvent日志"));
   item_first->appendRow(itemProject1);

   QStandardItem* itemProject2 = new QStandardItem(QIcon(QString::fromUtf8("F:\\treetest\\res_treeItemIcon\\folder.png")),QString::fromUtf8("AppEvent日志"));
   item_first->appendRow(itemProject2);


   //第二个节点
   QStandardItem* item_second = new QStandardItem(QIcon(QString::fromUtf8("F:\\treetest\\res_treeItemIcon\\folder.png")),QString::fromUtf8("保存的日志"));
   model->appendRow(item_second);

   QStandardItem* item2_1 = new QStandardItem(QIcon(QString::fromUtf8("F:\\treetest\\res_treeItemIcon\\folder.png")),QString::fromUtf8("System"));
   item_second->appendRow(item2_1);

   QStandardItem* item2_2 = new QStandardItem(QIcon(QString::fromUtf8("F:\\treetest\\res_treeItemIcon\\folder.png")),QString::fromUtf8("Security"));
   item_second->appendRow(item2_2);

   QStandardItem* item2_3 = new QStandardItem(QIcon(QString::fromUtf8("F:\\treetest\\res_treeItemIcon\\folder.png")),QString::fromUtf8("Application"));
   item_second->appendRow(item2_3);

    //第三个节点
   QStandardItem* item_three = new QStandardItem(QIcon(QString::fromUtf8("F:\\treetest\\res_treeItemIcon\\folder.png")),QString::fromUtf8("主机性能"));
   model->appendRow(item_three);

   QStandardItem* item3_1 = new QStandardItem(QIcon(QString::fromUtf8("F:\\treetest\\res_treeItemIcon\\folder.png")),QString::fromUtf8("主机性能信息"));
   item_three->appendRow(item3_1);

   ui->log_message_find->setModel(model);

}

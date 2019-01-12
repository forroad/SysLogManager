#pragma execution_character_set("utf-8")

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QItemSelection>
#include <QMessageBox>

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
    InitLogList();
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

   ui->log_message_find->setEditTriggers(QAbstractItemView::NoEditTriggers);

   connect(ui->log_message_find->selectionModel(),&QItemSelectionModel::selectionChanged,this,&MainWindow::slotSelectionChanged);
}

void MainWindow::InitLogList(){
    //初始化标题
    ui->log_list->setHorizontalHeaderLabels(QStringList()<<QString::fromUtf8("级别")<<QString::fromUtf8("日期和时间")
                                            <<QString::fromUtf8("来源")<<QString::fromUtf8("事件ID")<<QString::fromUtf8("任务类型"));
}

//QTreeView选中事件处理
void MainWindow::slotSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected){
    QItemSelectionModel *selections = ui->log_message_find->selectionModel();
       QModelIndexList indexes = selections->selectedIndexes();    //得到所有选中的index
       foreach(QModelIndex index, indexes)
       {

           QString data = index.data().toString();
           if(data.compare(QString("系统日志"))){
               QMessageBox::information(this,"tip",index.data().toString());
           }else if(data.compare(QString("系统日志"))){
               QMessageBox::information(this,"tip",index.data().toString());
           }else if(data.compare(QString("SysEvent日志"))){
                QMessageBox::information(this,"tip",index.data().toString());
           }else if(data.compare(QString("SecEvent日志"))){
                QMessageBox::information(this,"tip",index.data().toString());
           }else if(data.compare(QString("SecEvent日志"))){
                QMessageBox::information(this,"tip",index.data().toString());
           }else if(data.compare(QString("保存的日志"))){
                QMessageBox::information(this,"tip",index.data().toString());
           }else if(data.compare(QString("System"))){
                QMessageBox::information(this,"tip",index.data().toString());
           }else if(data.compare(QString("Security"))){
                QMessageBox::information(this,"tip",index.data().toString());
           }else if(data.compare(QString("Application"))){
                QMessageBox::information(this,"tip",index.data().toString());
           }else if(data.compare(QString("主机性能"))){
                QMessageBox::information(this,"tip",index.data().toString());
           }else if(data.compare(QString("主机性能"))){
                QMessageBox::information(this,"tip",index.data().toString());
           }
       }
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>
#include<QFileDialog>
#include<QMessageBox>//提示对话框
#include<QColorDialog>//颜色对话框
#include<QFontDialog>//字体对话框
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect( ui->actionOPEN,&QAction::triggered,this,[=]()
    {
////        QDialog *dlg=new QDialog(this);
////        QString name=QFileDialog::getOpenFileName(this,"打开文件","D://","Image(*.jpg*.png)");
////          dlg->show();
///                exec();
//          //析构问题
//          //设置对话框的属性
//          dlg->setAttribute(Qt::WA_DeleteOnClose);
       if(QMessageBox::Ok== QMessageBox:: warning(this,"error","xitongwenhcuo", QMessageBox:: Ok| QMessageBox::Cancel,QMessageBox::Cancel))
       {
          QDialog *dlg=new QDialog(this);
             dlg->exec();
        }//critical 错误提示  information信息    question  问题   对话框一样图标不一样
        bool  OK;
        QColor color=QColorDialog::getColor();//选择颜色
        qDebug()<<color.blue()<<color.red()<<color.green();
        QFont font =QFontDialog::getFont(&OK,QFont("华文彩云"),this,"我的字体设置");
        qDebug()<<font.family()<<font.italic()<<font.pointSize()<<font.bold();//字体类型   是否倾斜   字体的高度  是否加粗

   });
}

MainWindow::~MainWindow()
{
    delete ui;
}

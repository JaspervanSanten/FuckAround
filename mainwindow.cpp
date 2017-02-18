#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "pipethread.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Tab 1
    ui->Value_widget1->setNext(ui->Value_widget2);
    ui->Value_widget2->setNext(ui->Value_widget3);
    ui->Value_widget3->setNext(ui->Value_widget4);
    ui->Value_widget4->setNext(ui->Value_widget1);

    // Tab 2
    m_Model1.setStringList(m_StringList1);
    m_Model2.setStringList(m_StringList2);
    m_Model3.setStringList(m_StringList3);
    m_Model4.setStringList(m_StringList4);

    ui->listView_1->setModel(&m_Model1);
    ui->listView_2->setModel(&m_Model2);
    ui->listView_3->setModel(&m_Model3);
    ui->listView_4->setModel(&m_Model4);

    m_PipeThread1 = new PipeThread( this );
    m_PipeThread2 = new PipeThread( this );
    m_PipeThread3 = new PipeThread( this );
    m_PipeThread4 = new PipeThread( this );

    m_PipeThread1->setInput(&m_Model1);
    m_PipeThread2->setInput(&m_Model2);
    m_PipeThread3->setInput(&m_Model3);
    m_PipeThread4->setInput(&m_Model4);

    m_PipeThread1->setOutput(&m_Model2);
    m_PipeThread2->setOutput(&m_Model3);
    m_PipeThread3->setOutput(&m_Model4);
    m_PipeThread4->setOutput(&m_Model1);

    m_PipeThread1->setInputMutex(&m_ModelMutex1);
    m_PipeThread2->setInputMutex(&m_ModelMutex2);
    m_PipeThread3->setInputMutex(&m_ModelMutex3);
    m_PipeThread4->setInputMutex(&m_ModelMutex4);

    m_PipeThread1->setOutputMutex(&m_ModelMutex2);
    m_PipeThread2->setOutputMutex(&m_ModelMutex3);
    m_PipeThread3->setOutputMutex(&m_ModelMutex4);
    m_PipeThread4->setOutputMutex(&m_ModelMutex1);

//    m_Model1.insertColumn( append("a"));
    int rowNum = m_Model1.rowCount();m_Model1.insertRow(m_Model1.rowCount());QModelIndex mi = m_Model1.index(rowNum);m_Model1.setData(mi, QString("a"));
    rowNum = m_Model1.rowCount();   m_Model1.insertRow(m_Model1.rowCount());    mi = m_Model1.index(rowNum);    m_Model1.setData(mi, QString("b"));
    rowNum = m_Model1.rowCount();   m_Model1.insertRow(m_Model1.rowCount());    mi = m_Model1.index(rowNum);    m_Model1.setData(mi, QString("c"));
    rowNum = m_Model1.rowCount();   m_Model1.insertRow(m_Model1.rowCount());    mi = m_Model1.index(rowNum);    m_Model1.setData(mi, QString("d"));
    rowNum = m_Model1.rowCount();   m_Model1.insertRow(m_Model1.rowCount());    mi = m_Model1.index(rowNum);    m_Model1.setData(mi, QString("e"));
    rowNum = m_Model1.rowCount();   m_Model1.insertRow(m_Model1.rowCount());    mi = m_Model1.index(rowNum);    m_Model1.setData(mi, QString("f"));

    rowNum = m_Model2.rowCount();   m_Model2.insertRow(m_Model2.rowCount());    mi = m_Model2.index(rowNum);    m_Model2.setData(mi, QString("g"));
    rowNum = m_Model2.rowCount();   m_Model2.insertRow(m_Model2.rowCount());    mi = m_Model2.index(rowNum);    m_Model2.setData(mi, QString("h"));
    rowNum = m_Model2.rowCount();   m_Model2.insertRow(m_Model2.rowCount());    mi = m_Model2.index(rowNum);    m_Model2.setData(mi, QString("i"));
    rowNum = m_Model2.rowCount();   m_Model2.insertRow(m_Model2.rowCount());    mi = m_Model2.index(rowNum);    m_Model2.setData(mi, QString("j"));
    rowNum = m_Model2.rowCount();   m_Model2.insertRow(m_Model2.rowCount());    mi = m_Model2.index(rowNum);    m_Model2.setData(mi, QString("k"));
    rowNum = m_Model2.rowCount();   m_Model2.insertRow(m_Model2.rowCount());    mi = m_Model2.index(rowNum);    m_Model2.setData(mi, QString("l"));
    rowNum = m_Model2.rowCount();   m_Model2.insertRow(m_Model2.rowCount());    mi = m_Model2.index(rowNum);    m_Model2.setData(mi, QString("m"));

    rowNum = m_Model3.rowCount();   m_Model3.insertRow(m_Model3.rowCount());    mi = m_Model3.index(rowNum);    m_Model3.setData(mi, QString("n"));
    rowNum = m_Model3.rowCount();   m_Model3.insertRow(m_Model3.rowCount());    mi = m_Model3.index(rowNum);    m_Model3.setData(mi, QString("o"));
    rowNum = m_Model3.rowCount();   m_Model3.insertRow(m_Model3.rowCount());    mi = m_Model3.index(rowNum);    m_Model3.setData(mi, QString("p"));
    rowNum = m_Model3.rowCount();   m_Model3.insertRow(m_Model3.rowCount());    mi = m_Model3.index(rowNum);    m_Model3.setData(mi, QString("q"));
    rowNum = m_Model3.rowCount();   m_Model3.insertRow(m_Model3.rowCount());    mi = m_Model3.index(rowNum);    m_Model3.setData(mi, QString("r"));
    rowNum = m_Model3.rowCount();   m_Model3.insertRow(m_Model3.rowCount());    mi = m_Model3.index(rowNum);    m_Model3.setData(mi, QString("s"));
    rowNum = m_Model3.rowCount();   m_Model3.insertRow(m_Model3.rowCount());    mi = m_Model3.index(rowNum);    m_Model3.setData(mi, QString("t"));
    rowNum = m_Model3.rowCount();   m_Model3.insertRow(m_Model3.rowCount());    mi = m_Model3.index(rowNum);    m_Model3.setData(mi, QString("u"));
    rowNum = m_Model3.rowCount();   m_Model3.insertRow(m_Model3.rowCount());    mi = m_Model3.index(rowNum);    m_Model3.setData(mi, QString("v"));
    rowNum = m_Model3.rowCount();   m_Model3.insertRow(m_Model3.rowCount());    mi = m_Model3.index(rowNum);    m_Model3.setData(mi, QString("w"));
    rowNum = m_Model3.rowCount();   m_Model3.insertRow(m_Model3.rowCount());    mi = m_Model3.index(rowNum);    m_Model3.setData(mi, QString("x"));
    rowNum = m_Model3.rowCount();   m_Model3.insertRow(m_Model3.rowCount());    mi = m_Model3.index(rowNum);    m_Model3.setData(mi, QString("y"));
    rowNum = m_Model3.rowCount();   m_Model3.insertRow(m_Model3.rowCount());    mi = m_Model3.index(rowNum);    m_Model3.setData(mi, QString("z"));

    rowNum = m_Model4.rowCount();   m_Model4.insertRow(m_Model4.rowCount());    mi = m_Model4.index(rowNum);    m_Model4.setData(mi, QString("1"));
    rowNum = m_Model4.rowCount();   m_Model4.insertRow(m_Model4.rowCount());    mi = m_Model4.index(rowNum);    m_Model4.setData(mi, QString("2"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_m_Tab1_Start_pushButton_clicked()
{
    ui->Value_widget1->start();
    ui->Value_widget2->start();
    ui->Value_widget3->start();
    ui->Value_widget4->start();
}

void MainWindow::on_m_Tab2_Start_pushButton_clicked()
{
    m_PipeThread1->start();
    m_PipeThread2->start();
    m_PipeThread3->start();
    m_PipeThread4->start();
}

void MainWindow::closeEvent(QCloseEvent *)
{
    m_PipeThread1->quit();
    m_PipeThread2->quit();
    m_PipeThread3->quit();
    m_PipeThread4->quit();
}

void MainWindow::on_m_Tab1_Stop_pushButton_clicked()
{
    ui->Value_widget1->stop();
    ui->Value_widget2->stop();
    ui->Value_widget3->stop();
    ui->Value_widget4->stop();
}

void MainWindow::on_m_Tab2_Stop_pushButton_clicked()
{
    m_PipeThread1->quit();
    m_PipeThread2->quit();
    m_PipeThread3->quit();
    m_PipeThread4->quit();
}

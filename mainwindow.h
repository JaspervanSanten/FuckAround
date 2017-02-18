#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMutex>
#include <QStringListModel>

namespace Ui {
class MainWindow;
}

class PipeThread;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_m_Tab1_Start_pushButton_clicked();

    void on_m_Tab2_Start_pushButton_clicked();

    void on_m_Tab1_Stop_pushButton_clicked();

    void on_m_Tab2_Stop_pushButton_clicked();

protected:
    void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow *ui;

    QStringListModel m_Model1;
    QStringListModel m_Model2;
    QStringListModel m_Model3;
    QStringListModel m_Model4;

    QStringList m_StringList1;
    QStringList m_StringList2;
    QStringList m_StringList3;
    QStringList m_StringList4;

    QMutex m_ModelMutex1;
    QMutex m_ModelMutex2;
    QMutex m_ModelMutex3;
    QMutex m_ModelMutex4;

    PipeThread* m_PipeThread1;
    PipeThread* m_PipeThread2;
    PipeThread* m_PipeThread3;
    PipeThread* m_PipeThread4;
};

#endif // MAINWINDOW_H

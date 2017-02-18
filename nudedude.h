#ifndef NUDEDUDE_H
#define NUDEDUDE_H

#include <QtNetwork>
#include <QWidget>

namespace Ui {
class NudeDude;
}

class NudeDude : public QWidget
{
    Q_OBJECT

public:
    explicit NudeDude(QWidget *parent = 0);
    ~NudeDude();

//    Receiver(QWidget *parent = 0);

private slots:
    void on_Broadcast_pushButton_clicked();
    void on_actionSendBroadcast_triggered();
    void processPendingDatagrams();

    void on_lineEdit_InPort_textChanged(const QString &arg1);
    void on_lineEdit_OutPort_textChanged(const QString &arg1);

private:
    Ui::NudeDude *ui;

    QUdpSocket *Caller_udpSocket;
    QUdpSocket *Listener_udpSocket;
    QTimer *timer;
    int messageNo;

    int iInPortNumber_m;
    int iOutPortNumber_m;
};

#endif // NUDEDUDE_H

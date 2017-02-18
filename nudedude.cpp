

#include "nudedude.h"
#include "ui_nudedudeForm.h"

NudeDude::NudeDude(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NudeDude)
{
    ui->setupUi(this);
//    connect(ui->Broadcast_pushButton,SIGNAL((c)))

    timer = new QTimer(this);

    Caller_udpSocket = new QUdpSocket(this);
    Listener_udpSocket = new QUdpSocket(this);

    messageNo = 1;

    iInPortNumber_m = 45454;
    iOutPortNumber_m = 45454;

    Listener_udpSocket->bind( iInPortNumber_m, QUdpSocket::ShareAddress );
    connect( Listener_udpSocket, SIGNAL(readyRead()),
            this, SLOT(processPendingDatagrams()));
}

NudeDude::~NudeDude()
{
    delete ui;
}

void NudeDude::on_Broadcast_pushButton_clicked()
{

}

void NudeDude::on_actionSendBroadcast_triggered()
{
    ui->Eavesdrop_textEdit->append(tr("Broadcast [%1]").arg(messageNo));

    QByteArray datagram = "Broadcast message " + QByteArray::number(messageNo);
    Caller_udpSocket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, iOutPortNumber_m);
    ++messageNo;
}

void NudeDude::processPendingDatagrams()
{
    while (Listener_udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(Listener_udpSocket->pendingDatagramSize());
        Listener_udpSocket->readDatagram(datagram.data(), datagram.size());
        ui->Eavesdrop_textEdit->append(tr("Received datagram: \"%1\"")
                             .arg(datagram.data()));
    }
}



void NudeDude::on_lineEdit_InPort_textChanged(const QString &arg1)
{
    iInPortNumber_m = arg1.toInt();
}

void NudeDude::on_lineEdit_OutPort_textChanged(const QString &arg1)
{
    iOutPortNumber_m = arg1.toInt();
}

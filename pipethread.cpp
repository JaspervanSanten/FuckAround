#include "pipethread.h"

#include <QTime>

PipeThread::PipeThread(QObject *parent)
    : QThread(parent)
{

}

void PipeThread::run() //Q_DECL_OVERRIDE
{
    setIsWorking( true );
//        qint64 readLines = 0;
//        qint64 writtenLines = 0;
    if ( !Input() || !Output() || !InputMutex() || !OutputMutex() )
        return;

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    while(IsWorking()) {
        if (InputMutex()->tryLock( ((float)qrand())*10.0/RAND_MAX ) ){
            if (OutputMutex()->tryLock( ((float)qrand())*10.0/RAND_MAX ) ){
                int linesToRead = 1;
                if (Input()->stringList().count()>linesToRead){
                    for (int i = 0; i < linesToRead; ++i) {
                        QModelIndex inMi = Input()->index(0);
                        QString takenString = Input()->data(inMi,Qt::DisplayRole).toString( );
                        Input()->removeRow(0);
                        int outputRow = Output()->rowCount();
                        Output()->insertRow(outputRow);
                        QModelIndex mi = Output()->index(outputRow);    Output()->setData(mi, takenString );
                        qDebug() << QString("Transferred: [%1]").arg(takenString);
                    }
                }
                OutputMutex()->unlock();
            }
            InputMutex()->unlock();
        }

        msleep( ((float)qrand())*100.0/RAND_MAX );

    }
}

void PipeThread::quit()
{
    setIsWorking( false );
    terminate();
    wait(1000);
}


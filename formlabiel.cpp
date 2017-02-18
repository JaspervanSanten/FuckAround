#include "formlabiel.h"
#include "ui_formlabiel.h"

#include <QThread>
#include <QDebug>
#include <QtMath>

FormLabiel::FormLabiel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormLabiel)
{
    ui->setupUi(this);

    connect(this, SIGNAL(ValueChanged(float)), this, SLOT(updateValue(float)) );

    setValue( 23 );

    setTimer(new QTimer());
    Timer()->setInterval(1000);
    Timer()->setSingleShot(true);
    connect(m_Timer, SIGNAL(timeout()), this, SLOT(share()) );

}

FormLabiel::~FormLabiel()
{
    delete ui;
}

void FormLabiel::addToValue(float v)
{
    setValue( m_Value + v );
}

void FormLabiel::start()
{
    setIsWorking(true);
    share();
}

void FormLabiel::share()
{
    float part = ((float)qrand())/RAND_MAX;
    float interval = ((float)qrand())*10.0/RAND_MAX;
    qDebug() << QString("FormLabiel::share(): %1, %2").arg(part).arg(interval);
    if (part<Value()){
        if (Next()){
            setValue(Value()-part);
            Next()->addToValue(part);
            qDebug() << QString("==> FormLabiel::share()");
        }
    }
    if (IsWorking())
        Timer()->start(interval);
}

void FormLabiel::stop()
{
    setIsWorking(false);
}

void FormLabiel::updateValue(float v)
{
    ui->m_label->setText( QLocale::system().toString(v,'f',2) );
}

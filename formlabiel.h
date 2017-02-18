#ifndef FORMLABIEL_H
#define FORMLABIEL_H

#include <QProcess>
#include <QWidget>
#include <QTimer>

namespace Ui {
class FormLabiel;
}

class FormLabiel : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(float Value READ Value WRITE setValue NOTIFY ValueChanged)
    Q_PROPERTY(FormLabiel* Next READ Next WRITE setNext NOTIFY NextChanged)
    Q_PROPERTY(FormLabiel* Previous READ Previous WRITE setPrevious NOTIFY PreviousChanged)
    Q_PROPERTY(QThread* Thread READ Thread WRITE setThread NOTIFY ThreadChanged)
    Q_PROPERTY(QTimer* Timer READ Timer WRITE setTimer NOTIFY TimerChanged)
    Q_PROPERTY(bool IsWorking READ IsWorking WRITE setIsWorking NOTIFY IsWorkingChanged)

public:
    explicit FormLabiel(QWidget *parent = 0);
    ~FormLabiel();

    float Value() const
    {
        return m_Value;
    }

    FormLabiel* Next() const
    {
        return m_Next;
    }

    FormLabiel* Previous() const
    {
        return m_Previous;
    }

    QThread* Thread() const
    {
        return m_Thread;
    }

    QTimer* Timer() const
    {
        return m_Timer;
    }

    bool IsWorking() const
    {
        return m_IsWorking;
    }

public slots:
    void setValue(float Value)
    {
        if (m_Value == Value)
            return;

        m_Value = Value;
        emit ValueChanged(Value);
    }
    void addToValue(float v);

    void setNext(FormLabiel* Next)
    {
        if (m_Next == Next)
            return;

        m_Next = Next;
        emit NextChanged(Next);
    }

    void setPrevious(FormLabiel* Previous)
    {
        if (m_Previous == Previous)
            return;

        m_Previous = Previous;
        emit PreviousChanged(Previous);
    }

    void setThread(QThread* Thread)
    {
        if (m_Thread == Thread)
            return;

        m_Thread = Thread;
        emit ThreadChanged(Thread);
    }

    void setTimer(QTimer* Timer)
    {
        if (m_Timer == Timer)
            return;

        m_Timer = Timer;
        emit TimerChanged(Timer);
    }

    void start();
    void stop();

    void setIsWorking(bool IsWorking)
    {
        if (m_IsWorking == IsWorking)
            return;

        m_IsWorking = IsWorking;
        emit IsWorkingChanged(IsWorking);
    }

private slots:
    void updateValue(float v );

    void share();

signals:
    void ValueChanged(float Value);

    void NextChanged(FormLabiel* Next);

    void PreviousChanged(FormLabiel* Previous);

    void ThreadChanged(QThread* Thread);

    void TooMuch();

    void TimerChanged(QTimer* Timer);

    void IsWorkingChanged(bool IsWorking);

private:
    Ui::FormLabiel *ui;


    float m_Value;
    FormLabiel* m_Next;
    FormLabiel* m_Previous;
    QThread* m_Thread;
    QTimer* m_Timer;
    bool m_IsWorking;
};

#endif // FORMLABIEL_H

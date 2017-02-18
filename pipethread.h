#ifndef PIPETHREAD_H
#define PIPETHREAD_H

#include <QDebug>

#include <QObject>
#include <QThread>

#include <QListView>
#include <QMutex>
//#include <QAbstractListModel>
#include <QStringListModel>

class PipeThread : public QThread
{    
    Q_OBJECT
    Q_PROPERTY(QStringListModel* Input READ Input WRITE setInput NOTIFY InputChanged)
    Q_PROPERTY(QStringListModel* Output READ Output WRITE setOutput NOTIFY OutputChanged)
    Q_PROPERTY(QMutex* InputMutex READ InputMutex WRITE setInputMutex NOTIFY InputMutexChanged)
    Q_PROPERTY(QMutex* OutputMutex READ OutputMutex WRITE setOutputMutex NOTIFY OutputMutexChanged)
    Q_PROPERTY(bool IsWorking READ IsWorking WRITE setIsWorking NOTIFY IsWorkingChanged)


public:
    PipeThread(QObject *parent = NULL);

    virtual void run() Q_DECL_OVERRIDE;

    QStringListModel* Input() const
    {
        return m_Input;
    }

    QStringListModel* Output() const
    {
        return m_Output;
    }

    QMutex* InputMutex() const
    {
        return m_InputMutex;
    }

    QMutex* OutputMutex() const
    {
        return m_OutputMutex;
    }

    bool IsWorking() const
    {
        return m_IsWorking;
    }

public slots:
    void setInput(QStringListModel* Input)
    {
        if (m_Input == Input)
            return;

        m_Input = Input;
        emit InputChanged(Input);
    }

    void setOutput(QStringListModel* Output)
    {
        if (m_Output == Output)
            return;

        m_Output = Output;
        emit OutputChanged(Output);
    }

    void setInputMutex(QMutex* InputMutex)
    {
        if (m_InputMutex == InputMutex)
            return;

        m_InputMutex = InputMutex;
        emit InputMutexChanged(InputMutex);
    }

    void setOutputMutex(QMutex* OutputMutex)
    {
        if (m_OutputMutex == OutputMutex)
            return;

        m_OutputMutex = OutputMutex;
        emit OutputMutexChanged(OutputMutex);
    }

    void quit();


    void setIsWorking(bool IsWorking)
    {
        if (m_IsWorking == IsWorking)
            return;

        m_IsWorking = IsWorking;
        emit IsWorkingChanged(IsWorking);
    }

signals:
    void stringConsumed(const QString &text);
    void InputChanged(QStringListModel* Input);
    void OutputChanged(QStringListModel* Output);

    void InputMutexChanged(QMutex* InputMutex);

    void OutputMutexChanged(QMutex* OutputMutex);

    void IsWorkingChanged(bool IsWorking);

private:
    QStringListModel* m_Input;
    QStringListModel* m_Output;

    QMutex* m_InputMutex;
    QMutex* m_OutputMutex;

    bool m_IsWorking;
};

#endif // PIPETHREAD_H

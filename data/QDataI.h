#pragma once

#include "QDataDevicesI.h"

#include <QAudioFormat>

class QDataI : public QObject
{
    Q_OBJECT

public:
    Q_PROPERTY(int delaySamples READ delaySamples WRITE setDelaySamples NOTIFY delaySamplesChanged)
    Q_PROPERTY(int delayMS READ delayMS WRITE setDelayMS NOTIFY delayMSChanged)

    Q_PROPERTY(QAudioFormat selectedFormat READ selectedFormat NOTIFY selectedFormatChanged)

    Q_PROPERTY(QDataDevicesI* input READ input NOTIFY inputChanged)
    Q_PROPERTY(QDataDevicesI* output READ output NOTIFY outputChanged)

public:
    QDataI(QObject* inParent = nullptr);

    virtual int delaySamples() const = 0;
    virtual int delayMS() const = 0;

    virtual QAudioFormat selectedFormat() const = 0;

    virtual QDataDevicesI* input() const = 0;
    virtual QDataDevicesI* output() const = 0;

public slots:
    virtual void setDelaySamples(int inDelay) = 0;
    virtual void setDelayMS(int inDelay) = 0;

signals:
    void delaySamplesChanged(int);
    void delayMSChanged(int);
    void selectedFormatChanged(QAudioFormat);
    void inputChanged(QDataDevicesI*);
    void outputChanged(QDataDevicesI*);

};

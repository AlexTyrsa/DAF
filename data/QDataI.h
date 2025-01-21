#pragma once

#include "QDataDevicesI.h"

class QDataI : public QObject
{
    Q_OBJECT

public:
    Q_PROPERTY(int delaySamples READ delaySamples WRITE setDelaySamples NOTIFY delayChanged)
    Q_PROPERTY(int delayMS READ delayMS WRITE setDelayMS NOTIFY delayChanged)

    Q_PROPERTY(int delaySamplesMAX READ delaySamplesMAX CONSTANT)
    Q_PROPERTY(int delayMSMAX READ delayMSMAX CONSTANT)


    Q_PROPERTY(QDataDevicesI* input READ input NOTIFY inputChanged)
    Q_PROPERTY(QDataDevicesI* output READ output NOTIFY outputChanged)

public:
    QDataI(QObject* inParent = nullptr);

    virtual int delaySamples() const = 0;
    virtual int delayMS() const = 0;

    virtual int delaySamplesMAX() const = 0;
    virtual int delayMSMAX() const = 0;

    virtual QDataDevicesI* input() const = 0;
    virtual QDataDevicesI* output() const = 0;

public slots:
    virtual void setDelaySamples(int inDelay) = 0;
    virtual void setDelayMS(int inDelay) = 0;

signals:
    void delayChanged(int);
    void inputChanged(QDataDevicesI*);
    void outputChanged(QDataDevicesI*);

};

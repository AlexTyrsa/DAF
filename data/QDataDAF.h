#pragma once

#include "QDataI.h"

#include "../sample_processor/QSampleProcessor.h"

class QDataDAF : public QDataI
{
    Q_OBJECT

public:
    QDataDAF(QObject* inParent = nullptr);

public:
    int delaySamples() const override;
    int delayMS() const override;

    QDataDevicesI* input() const override;
    QDataDevicesI* output() const override;

public slots:
    void setDelaySamples(int inDelay) override;
    void setDelayMS(int inDelay) override;

private:
    int               mDelaySamples;
    QSampleProcessor* mIODevice;
    QDataDevicesI*    mInputs;
    QDataDevicesI*    mOutputs;

};

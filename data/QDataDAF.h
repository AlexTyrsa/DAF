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

    int delaySamplesMAX() const override;
    int delayMSMAX() const override;

    bool pause() const override;

    QDataDevicesI* input() const override;
    QDataDevicesI* output() const override;

public slots:
    void setDelaySamples(int inDelay) override;
    void setDelayMS(int inDelay) override;
    void setPause(bool inPause) override;

private:
    QSampleProcessor* mIODevice;
    QDataDevicesI*    mInputs;
    QDataDevicesI*    mOutputs;

};

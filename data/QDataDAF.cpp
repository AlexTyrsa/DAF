#include "QDataDAF.h"

#include "QDataDevicesDAF.h"

QDataDAF::QDataDAF(QObject *inParent) : QDataI(inParent)
{
    mIODevice = new QSampleProcessor(sizeof(int16_t), this);
    mIODevice->open(QIODevice::ReadWrite);

    mInputs   = new QDataDevicesDAF(mIODevice, this);
    mOutputs  = new QDataDevicesDAF(mIODevice, this);

    QAudioFormat selectedFormat;

    selectedFormat.setSampleRate(48000);
    selectedFormat.setSampleFormat(QAudioFormat::Int16);
    selectedFormat.setChannelCount(1);

    mInputs->setSelectedFormat(selectedFormat);
    mOutputs->setSelectedFormat(selectedFormat);

    connect(mIODevice, SIGNAL(delaySamplesChanged(int)), this, SIGNAL(delayChanged(int)));
    connect(mIODevice, SIGNAL(pauseChanged(bool)), this, SIGNAL(pauseChanged(bool)));
}

int QDataDAF::delaySamples() const
{
    return mIODevice->delaySamples();
}

int QDataDAF::delayMS() const
{
    return input()->selectedFormat().durationForFrames(delaySamples()) / 1000;
}

int QDataDAF::delaySamplesMAX() const
{
    return input()->selectedFormat().sampleRate() * 2;
}

int QDataDAF::delayMSMAX() const
{
    return input()->selectedFormat().durationForFrames(delaySamplesMAX()) / 1000;
}

bool QDataDAF::pause() const
{
    return mIODevice->pause();
}

QDataDevicesI *QDataDAF::input() const
{
    return mInputs;
}

QDataDevicesI *QDataDAF::output() const
{
    return mOutputs;
}

void QDataDAF::setDelaySamples(int inDelay)
{
    mIODevice->setDelaySamples(inDelay);
}

void QDataDAF::setDelayMS(int inDelay)
{
    int delaySamples = input()->selectedFormat().framesForDuration(inDelay * 1000) / input()->selectedFormat().channelCount();

    setDelaySamples(delaySamples);
}

void QDataDAF::setPause(bool inPause)
{
    mIODevice->setPause(inPause);
}

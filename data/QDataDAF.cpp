#include "QDataDAF.h"

#include "QDataDevicesDAF.h"

#include <QBuffer>

QDataDAF::QDataDAF(QObject *inParent) : QDataI(inParent), mDelaySamples(0)
{
    mIODevice = new QBuffer(this);
    mIODevice->open(QIODevice::ReadWrite);
    mInputs   = new QDataDevicesDAF(mIODevice, this);
    mOutputs  = new QDataDevicesDAF(mIODevice, this);

    QAudioFormat selectedFormat;

    selectedFormat.setSampleRate(48000);
    selectedFormat.setSampleFormat(QAudioFormat::Int16);
    selectedFormat.setChannelCount(1);

    mInputs->setSelectedFormat(selectedFormat);

    selectedFormat.setChannelCount(2);

    mOutputs->setSelectedFormat(selectedFormat);
}

int QDataDAF::delaySamples() const
{
    return mDelaySamples;
}

int QDataDAF::delayMS() const
{
    return input()->selectedFormat().durationForFrames(delaySamples()) / 1000;
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
    if(inDelay != delaySamples())
    {
        mDelaySamples = inDelay;

        emit delayChanged();
    }
}

void QDataDAF::setDelayMS(int inDelay)
{
    int delaySamples = input()->selectedFormat().framesForDuration(inDelay * 1000) / input()->selectedFormat().channelCount();

    setDelaySamples(delaySamples);
}

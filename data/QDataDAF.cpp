#include "QDataDAF.h"

#include "QDataDevicesDAF.h"

#include <QBuffer>

QDataDAF::QDataDAF(QObject *inParent) : QDataI(inParent), mDelaySamples(0)
{
    mIODevice = new QBuffer(this);
    mInputs   = new QDataDevicesDAF(mIODevice, this);
    mOutputs  = new QDataDevicesDAF(mIODevice, this);
}

int QDataDAF::delaySamples() const
{
    return mDelaySamples;
}

int QDataDAF::delayMS() const
{
    return selectedFormat().durationForFrames(delaySamples()) / 1000;
}

QAudioFormat QDataDAF::selectedFormat() const
{
    return mSelectedFormat;
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
    int delaySamples = selectedFormat().framesForDuration(inDelay * 1000);

    setDelaySamples(delaySamples);
}

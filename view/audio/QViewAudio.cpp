#include "QViewAudio.h"

QViewAudio::QViewAudio(QObject *inParent) : QViewDevicesI(inParent)
{
    QObject::connect(this, SIGNAL(dataChanged(QDataDevicesI*)), this, SLOT(onDataChanged(QDataDevicesI*)));
}

void QViewAudio::onDataChanged(QDataDevicesI *inData)
{
    QObject::connect(inData, SIGNAL(selectedDeviceChanged(QAudioDevice)), this, SLOT(onSelectedDeviceChanged(QAudioDevice)));
    QObject::connect(inData, SIGNAL(selectedFormatChanged(QAudioFormat)), this, SLOT(onSelectedFormatChanged(QAudioFormat)));

    emit audioDataChanged();
}

void QViewAudio::onSelectedDeviceChanged(QAudioDevice inDevice)
{
    Q_UNUSED(inDevice)

    emit audioDataChanged();
}

void QViewAudio::onSelectedFormatChanged(QAudioFormat inFormat)
{
    Q_UNUSED(inFormat)

    emit audioDataChanged();
}

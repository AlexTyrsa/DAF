#include "QViewRecorder.h"

QViewRecorder::QViewRecorder(QObject *inParent) : QViewAudio(inParent)
{
    QObject::connect(this, SIGNAL(audioDataChanged()), this, SLOT(onAudioDataChanged()));
}

void QViewRecorder::onAudioDataChanged()
{
    QDataDevicesI* dev_data = data();

    mAudio.reset();

    if(dev_data)
    {
        QAudioFormat format = dev_data->selectedFormat();
        QAudioDevice info   = dev_data->selectedDevice();

        if(!format.isValid())
            qWarning() << "QViewRecorder::onAudioDataChanged, destroing QAudioSource due to QAudioFormat is invalid!";
        else if(info.isNull())
            qWarning() << "QViewRecorder::onAudioDataChanged, destroing QAudioSource due to QAudioDevice is empty!";
        else if (!info.isFormatSupported(format))
            qWarning() << "QViewRecorder::onAudioDataChanged, destroing QAudioSource due to selected format not supported!";
        else
        {
            mAudio.reset(new QAudioSource(info, format));
            mAudio->start(dev_data->io());
        }
    }else
        qInfo() << "QViewRecorder::onAudioDataChanged, destroing QAudioSource due to no data";
}

#include "QViewPlayer.h"

QViewPlayer::QViewPlayer(QObject *inParent) : QViewAudio(inParent)
{
    QObject::connect(this, SIGNAL(audioDataChanged()), this, SLOT(onAudioDataChanged()));
}

void QViewPlayer::onAudioDataChanged()
{
    QDataDevicesI* dev_data = data();

    mAudio.reset();

    if(dev_data)
    {
        QAudioFormat format;
        QAudioDevice info;

        if(format.isValid())
            qWarning() << "QViewPlayer::onAudioDataChanged, destroing QAudioSink due to QAudioFormat is invalid!";
        else if(info.isNull())
            qWarning() << "QViewPlayer::onAudioDataChanged, destroing QAudioSink due to QAudioDevice is empty!";
        else if (!info.isFormatSupported(format))
            qWarning() << "QViewPlayer::onAudioDataChanged, destroing QAudioSink due to selected format not supported!";
        else
        {
            mAudio.reset(new QAudioSink(info, format));
            mAudio->start(dev_data->io());
        }
    }else
        qInfo() << "QViewPlayer::onAudioDataChanged, destroing QAudioSink due to no data";
}

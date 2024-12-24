#pragma once

#include "QViewAudio.h"

#include <QScopedPointer>
#include <QAudioSink>

class QViewPlayer: public QViewAudio
{
    Q_OBJECT

public:
    QViewPlayer(QObject* inParent = nullptr);

private slots:
    void onAudioDataChanged();

private:
    QScopedPointer<QAudioSink> mAudio;

};

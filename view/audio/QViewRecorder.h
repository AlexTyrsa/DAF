#pragma once

#include "QViewAudio.h"

#include <QScopedPointer>
#include <QAudioSource>

class QViewRecorder: public QViewAudio
{
    Q_OBJECT

public:
    QViewRecorder(QObject* inParent);

private slots:
    void onAudioDataChanged();

private:
    QScopedPointer<QAudioSource> mAudio;

};

#pragma once

#include "QViewAudio.h"

#include <QScopedPointer>
#include <QAudioSource>

class QViewRecorder: public QViewAudio
{
    Q_OBJECT

public:
    QViewRecorder(QObject* inParent = nullptr);

private slots:
    void onAudioDataChanged();

private:
    QScopedPointer<QAudioSource> mAudio;

};

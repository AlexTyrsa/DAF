#pragma once

#include "../QViewDevicesI.h"

class QViewAudio: public QViewDevicesI
{
    Q_OBJECT

public:
    QViewAudio(QObject* inParent);

signals:
    void audioDataChanged();

private slots:
    void onDataChanged(QDataDevicesI* inData);
    void onSelectedDeviceChanged(QAudioDevice inDevice);
    void onSelectedFormatChanged(QAudioFormat inFormat);

};

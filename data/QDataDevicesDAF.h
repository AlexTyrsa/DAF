#pragma once

#include "QDataDevicesI.h"

class QDataDevicesDAF : public QDataDevicesI
{
    Q_OBJECT

public:
    QDataDevicesDAF(QIODevice* inIODevice, QObject* inParent = nullptr);

    QAudioDevice selectedDevice() const override;
    Q_INVOKABLE void setSelectedDevice(const QByteArray& inId) override;

    QAudioDevice defaultDevice() const override;

    QAudioFormat selectedFormat() const override;
    void setSelectedFormat(const QAudioFormat& inFormat) override;

    const QList<QAudioDevice>& devices() const override;
    void setDevices(const QList<QAudioDevice>& inDevices) override;

    QIODevice* io() const override;

private:
    QList<QAudioDevice> mDevices;
    QByteArray mSelectedDeviceId;
    QIODevice* mIODevice;

    QAudioFormat mSelectedFormat;

};

#include "QDataDevicesDAF.h"

#include <algorithm>

QDataDevicesDAF::QDataDevicesDAF(QIODevice* inIODevice, QObject *inParent) : QDataDevicesI(inParent), mIODevice(inIODevice)
{

}

QAudioDevice QDataDevicesDAF::selectedDevice() const
{
    QList<QAudioDevice>::const_iterator res = std::find_if(mDevices.cbegin(), mDevices.cend(), [this](QAudioDevice device)->bool
    {
        return device.id() == mSelectedDeviceId;
    });

    if(res != mDevices.cend())
        return *res;
    else
        return QAudioDevice();
}

void QDataDevicesDAF::setSelectedDevice(const QByteArray &inId)
{
    if(inId != mSelectedDeviceId)
    {
        mSelectedDeviceId = inId;

        emit selectedDeviceChanged(selectedDevice());
    }
}

QAudioDevice QDataDevicesDAF::defaultDevice() const
{
    QList<QAudioDevice>::const_iterator res = std::find_if(mDevices.cbegin(), mDevices.cend(), [](QAudioDevice device)->bool
    {
        return device.isDefault();
    });

    if(res != mDevices.cend())
        return *res;
    else
        return QAudioDevice();
}

const QList<QAudioDevice> &QDataDevicesDAF::devices() const
{
    return mDevices;
}

void QDataDevicesDAF::setDevices(const QList<QAudioDevice> &inDevices)
{
    mDevices = inDevices;

    emit devicesChanged();
    emit defaultDeviceChanged(defaultDevice());
    emit selectedDeviceChanged(selectedDevice());
}

QIODevice *QDataDevicesDAF::io() const
{
    return mIODevice;
}

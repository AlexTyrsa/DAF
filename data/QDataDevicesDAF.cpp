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

QAudioFormat QDataDevicesDAF::selectedFormat() const
{
    return mSelectedFormat;
}

void QDataDevicesDAF::setSelectedFormat(const QAudioFormat &inFormat)
{
    if(inFormat != mSelectedFormat)
    {
        mSelectedFormat = inFormat;

        emit selectedFormatChanged(mSelectedFormat);
    }
}

const QList<QAudioDevice> &QDataDevicesDAF::devices() const
{
    return mDevices;
}

void QDataDevicesDAF::setDevices(const QList<QAudioDevice> &inDevices)
{
    QAudioDevice oldDefDevice = defaultDevice();

    mDevices = inDevices;
    emit devicesChanged();

    QAudioDevice defDevice = defaultDevice();
    if(oldDefDevice != defDevice)
        emit defaultDeviceChanged(defDevice);

    QAudioDevice selDevice = selectedDevice();
    if(selDevice.isNull())
    {
        if(!defDevice.isNull())
            mSelectedDeviceId = defDevice.id();
        else if(!inDevices.empty())
            mSelectedDeviceId = inDevices[0].id();
        else
            mSelectedDeviceId.clear();

        emit selectedDeviceChanged(selectedDevice());
    }
}

QIODevice *QDataDevicesDAF::io() const
{
    return mIODevice;
}

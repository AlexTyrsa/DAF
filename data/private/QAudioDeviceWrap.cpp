#include "QAudioDeviceWrap.h"

#include <QtDebug>

#include <QQmlEngine>


QAudioDeviceWrap::QAudioDeviceWrap(QAudioDevice inDevice, QObject *inParent) : QObject(inParent), mDevice(inDevice)
{
    QQmlEngine::setObjectOwnership(this, QQmlEngine::JavaScriptOwnership);
}

QByteArray QAudioDeviceWrap::id() const
{
    return mDevice.id();
}

QString QAudioDeviceWrap::description() const
{
    return mDevice.description();
}

bool QAudioDeviceWrap::isDefault() const
{
    return mDevice.isDefault();
}

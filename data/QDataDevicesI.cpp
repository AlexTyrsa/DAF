#include "QDataDevicesI.h"

QDataDevicesI::QDataDevicesI(QObject *inParent)
{

}

QQmlListProperty<QAudioDeviceWrap> QDataDevicesI::devicesList()
{
    return QQmlListProperty<QAudioDeviceWrap>(this, this, &QDataDevicesI::itemsCount, &QDataDevicesI::itemAt);
}

qsizetype QDataDevicesI::itemsCount(QQmlListProperty<QAudioDeviceWrap> *inProperty)
{
    return reinterpret_cast<QDataDevicesI*>(inProperty->data)->devices().size();
}

QAudioDeviceWrap* QDataDevicesI::itemAt(QQmlListProperty<QAudioDeviceWrap> *inProperty, qsizetype inIndex)
{
    QDataDevicesI* _this = reinterpret_cast<QDataDevicesI*>(inProperty->data);

    if(inIndex >= 0 && inIndex < _this->devices().size())
        return new QAudioDeviceWrap(_this->devices()[inIndex]);
    else
        return nullptr;
}

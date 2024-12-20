#include "QDataDevicesI.h"

QDataDevicesI::QDataDevicesI(QObject *inParent)
{

}

QQmlListProperty<const QAudioDevice> QDataDevicesI::devicesList()
{
    return QQmlListProperty<const QAudioDevice>(this, this, &QDataDevicesI::itemsCount, &QDataDevicesI::itemAt);
}

qsizetype QDataDevicesI::itemsCount(QQmlListProperty<const QAudioDevice> *inProperty)
{
    return reinterpret_cast<QDataDevicesI*>(inProperty->data)->devices().size();
}

const QAudioDevice* QDataDevicesI::itemAt(QQmlListProperty<const QAudioDevice> *inProperty, qsizetype inIndex)
{
    QDataDevicesI* _this = reinterpret_cast<QDataDevicesI*>(inProperty->data);

    if(inIndex >= 0 && inIndex < _this->devices().size())
        return &(_this->devices()[inIndex]);
    else
        return nullptr;
}

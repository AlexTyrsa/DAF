#include "QViewDevicesI.h"

QViewDevicesI::QViewDevicesI(QObject *inParent) : QObject(inParent), mData(nullptr)
{

}

QDataDevicesI *QViewDevicesI::data() const
{
    return mData;
}

void QViewDevicesI::setData(QDataDevicesI *inData)
{
    if(inData != data())
    {
        mData = inData;

        emit dataChanged(data());
    }
}

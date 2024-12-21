#include "QViewI.h"

QViewI::QViewI(QObject *inParent) : QObject(inParent), mData(nullptr)
{

}

QDataI *QViewI::data() const
{
    return mData;
}

void QViewI::setData(QDataI *inData)
{
    if(inData != data())
    {
        mData = inData;

        emit dataChanged(data());
    }
}

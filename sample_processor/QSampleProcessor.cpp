#include "QSampleProcessor.h"

#include <QDebug>

QSampleProcessor::QSampleProcessor(QObject *inParent) : QIODevice(inParent), buffer(1024, 0)
{

}

qint64 QSampleProcessor::bytesAvailable() const
{
    return buffer.size() + QIODevice::bytesAvailable();
}

qint64 QSampleProcessor::readData(char *inData, qint64 inMaxLen)
{
    memcpy(inData, buffer.data(), 1024);

    return 1024;
}

qint64 QSampleProcessor::writeData(const char *inData, qint64 inLen)
{
    memcpy(buffer.data(), inData, 1024);

    return 1024;
}

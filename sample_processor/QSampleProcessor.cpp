#include "QSampleProcessor.h"

QSampleProcessor::QSampleProcessor(QObject *inParent) : QIODevice(inParent)
{

}

qint64 QSampleProcessor::bytesAvailable() const
{
    return 0;
}

qint64 QSampleProcessor::readData(char *inData, qint64 inMaxLen)
{
    return 0;
}

qint64 QSampleProcessor::writeData(const char *inData, qint64 inLen)
{
    return 0;
}

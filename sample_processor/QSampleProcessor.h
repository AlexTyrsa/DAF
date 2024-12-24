#pragma once

#include <QIODevice>

#include <QByteArray>

class QSampleProcessor : public QIODevice
{
    Q_OBJECT

public:
    QSampleProcessor(QObject* inParent = nullptr);

    qint64 bytesAvailable() const override;

protected:
    qint64 readData(char *inData, qint64 inMaxLen) override;
    qint64 writeData(const char *inData, qint64 inLen) override;

private:
    QByteArray buffer;

};

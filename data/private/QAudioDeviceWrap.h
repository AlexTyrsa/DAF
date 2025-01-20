#pragma once

#include <QObject>
#include <QAudioDevice>

class QAudioDeviceWrap : public QObject
{
    Q_OBJECT

public:
    Q_PROPERTY(QByteArray id READ id CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(bool isDefault READ isDefault CONSTANT)

public:
    QAudioDeviceWrap(QAudioDevice inDevice, QObject* inParent = nullptr);

    QByteArray id() const;
    QString description() const;
    bool isDefault() const;

private:
    QAudioDevice mDevice;

};

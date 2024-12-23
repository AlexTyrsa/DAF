#pragma once

#include <QObject>
#include <QAudioDevice>
#include <QAudioFormat>
#include <QQmlListProperty>
#include <QList>
#include <QIODevice>

class QDataDevicesI: public QObject
{
    Q_OBJECT

public:
    Q_PROPERTY(QQmlListProperty<const QAudioDevice> devices READ devicesList NOTIFY devicesChanged)

    Q_PROPERTY(QAudioDevice selectedDevice READ selectedDevice NOTIFY selectedDeviceChanged)
    Q_PROPERTY(QAudioDevice defaultDevice READ defaultDevice NOTIFY defaultDeviceChanged)

    Q_PROPERTY(QAudioFormat selectedFormat READ selectedFormat WRITE setSelectedFormat NOTIFY selectedFormatChanged)

public:
    QDataDevicesI(QObject* inParent = nullptr);

    virtual QAudioDevice selectedDevice() const = 0;
    virtual Q_INVOKABLE void setSelectedDevice(const QByteArray& inId) = 0;

    virtual QAudioDevice defaultDevice() const = 0;

    virtual QAudioFormat selectedFormat() const = 0;
    virtual void setSelectedFormat(const QAudioFormat& inFormat) = 0;

    virtual const QList<QAudioDevice>& devices() const = 0;
    virtual void setDevices(const QList<QAudioDevice>& inDevices) = 0;

    virtual QIODevice* io() const = 0;

signals:
    void selectedDeviceChanged(QAudioDevice);
    void defaultDeviceChanged(QAudioDevice);
    void selectedFormatChanged(QAudioFormat);
    void devicesChanged();

public:
    QQmlListProperty<const QAudioDevice> devicesList();

private:
    static qsizetype itemsCount(QQmlListProperty<const QAudioDevice>* inProperty);
    static const QAudioDevice *itemAt(QQmlListProperty<const QAudioDevice>* inProperty, qsizetype inIndex);

};

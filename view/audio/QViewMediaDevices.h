#pragma once

#include "../QViewI.h"

#include <QMediaDevices>

class QViewMediaDevices : public QViewI
{
    Q_OBJECT

public:
    QViewMediaDevices(QObject* inParent = nullptr);

private slots:
    void onDataChanged(QDataI* data);
    void onInputChanged(QDataDevicesI* inInput);
    void onOutputChanged(QDataDevicesI* inOutput);
    void onInputChanged();
    void onOutputChanged();

private:
    QMediaDevices mDevices;

};

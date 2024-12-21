#pragma once

#include "../data/QDataDevicesI.h"

class QViewDevicesI : public QObject
{
    Q_OBJECT

public:
    Q_PROPERTY(QDataDevicesI* data READ data WRITE setData NOTIFY dataChanged)

public:
    QViewDevicesI(QObject* inParent = nullptr);

    QDataDevicesI* data() const;

public slots:
    void setData(QDataDevicesI* inData);

signals:
    void dataChanged(QDataDevicesI*);

private:
    QDataDevicesI* mData;

};

#pragma once

#include "../data/QDataI.h"

class QViewI : public QObject
{
    Q_OBJECT

public:
    Q_PROPERTY(QDataI* data READ data WRITE setData NOTIFY dataChanged)

public:
    QViewI(QObject* inParent = nullptr);

    QDataI* data() const;

public slots:
    void setData(QDataI* inData);

signals:
    void dataChanged(QDataI*);

private:
    QDataI* mData;

};

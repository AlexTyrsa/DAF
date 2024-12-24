#include "QViewMediaDevices.h"

QViewMediaDevices::QViewMediaDevices(QObject *inParent) : QViewI(inParent)
{
    QObject::connect(this, SIGNAL(dataChanged(QDataI*)), this, SLOT(onDataChanged(QDataI*)));
    QObject::connect(&mDevices, SIGNAL(audioInputsChanged()), this, SLOT(onInputChanged()));
    QObject::connect(&mDevices, SIGNAL(audioOutputsChanged()), this, SLOT(onOutputChanged()));
}

void QViewMediaDevices::onDataChanged(QDataI *data)
{
    QObject::connect(data, SIGNAL(inputChanged(QDataDevicesI*)), this, SLOT(onInputChanged(QDataDevicesI*)));
    QObject::connect(data, SIGNAL(outputChanged(QDataDevicesI*)), this, SLOT(onOutputChanged(QDataDevicesI*)));

    onInputChanged();
    onOutputChanged();
}

void QViewMediaDevices::onInputChanged(QDataDevicesI *inInput)
{
    onInputChanged();
}

void QViewMediaDevices::onOutputChanged(QDataDevicesI *inOutput)
{
    onOutputChanged();
}

void QViewMediaDevices::onInputChanged()
{
    if(data())
    {
        QDataDevicesI* input = data()->input();

        if(input)
            input->setDevices(mDevices.audioInputs());
    }
}

void QViewMediaDevices::onOutputChanged()
{
    if(data())
    {
        QDataDevicesI* output = data()->output();

        if(output)
            output->setDevices(mDevices.audioOutputs());
    }
}

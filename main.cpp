#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "data/QDataDAF.h"

#include "view/audio/QViewMediaDevices.h"
#include "view/audio/QViewPlayer.h"
#include "view/audio/QViewRecorder.h"

#include <QScopedPointer>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QScopedPointer<QDataDAF> data(new QDataDAF());

    QScopedPointer<QViewMediaDevices> viewMediaDevices(new QViewMediaDevices());
    viewMediaDevices->setData(data.get());

    QScopedPointer<QViewRecorder> viewRecord(new QViewRecorder());
    viewRecord->setData(data->input());

    QScopedPointer<QViewPlayer> viewPlayer(new QViewPlayer());
    viewPlayer->setData(data->output());

    data->setDelayMS(1000);

    qmlRegisterUncreatableType<QDataI>("QDAFLib", 1, 0, "QDataI", "interface");
    qmlRegisterUncreatableType<QDataDevicesI>("QDAFLib", 1, 0, "QDataDevicesI", "interface");
    qmlRegisterSingletonInstance("QDAFLib", 1, 0, "DAFData", data.get());

    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/DAF/main.qml"));

    return app.exec();
}

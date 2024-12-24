#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "view/QViewI.h"
#include "view/QViewDevicesI.h"

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

    qmlRegisterUncreatableType<QViewI>("QDAFLib", 1, 0, "QViewI", "interface");
    qmlRegisterUncreatableType<QViewDevicesI>("QDAFLib", 1, 0, "QViewDevicesI", "interface");

    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/DAF/main.qml"));

    return app.exec();
}

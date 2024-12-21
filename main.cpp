#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "view/QViewI.h"
#include "view/QViewDevicesI.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterUncreatableType<QViewI>("QDAFLib", 1, 0, "QViewI", "interface");
    qmlRegisterUncreatableType<QViewDevicesI>("QDAFLib", 1, 0, "QViewDevicesI", "interface");

    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/DAF/main.qml"));

    return app.exec();
}

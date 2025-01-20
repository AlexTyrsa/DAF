import QtQuick
import QDAFLib 1.0
import "./view/qml"

Window
{
    width: 500
    height: 200
    visible: true
    title: qsTr("DAF")

    QCViewMain
    {
        viewData: DAFData

        anchors.fill: parent
        anchors.margins: 15
    }
}

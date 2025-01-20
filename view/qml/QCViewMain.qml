import QtQuick
import QDAFLib 1.0
import QtQuick.Layouts
import "./.."
import ".."

QCViewItem
{
    id: root

    RowLayout
    {
        anchors.fill: parent

        spacing: 5

        QCViewDevices
        {
            Layout.fillHeight: true
            Layout.fillWidth: true

            caption: qsTr("Inputs:")
            viewData: root.viewData.input
        }

        QCViewDevices
        {
            Layout.fillHeight: true
            Layout.fillWidth: true

            caption: qsTr("Outputs:")
            viewData: root.viewData.output
        }
    }
}

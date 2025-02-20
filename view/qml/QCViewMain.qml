import QtQuick
import QDAFLib 1.0
import QtQuick.Layouts
import QtQuick.Controls
import "./.."
import ".."

QCViewItem
{
    id: root

    ColumnLayout
    {
        anchors.fill: parent

        RowLayout
        {
            Layout.fillHeight: true
            Layout.fillWidth: true

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

        Item
        {
            Layout.fillHeight: true
            Layout.fillWidth: true

            RowLayout
            {
                anchors.fill: parent

                spacing: 15

                Item
                {
                    Layout.fillHeight: true

                    width: 50

                    Text
                    {
                        anchors.fill: parent

                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter

                        text: viewData.delayMS + qsTr(" ms")
                    }
                }

                Item
                {
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    RoundButton
                    {
                        anchors.centerIn: parent

                        width: 20
                        height: 20

                        text: viewData.pause ? "\u25b6" : "\u23f8"
                        onClicked:
                        {
                            viewData.pause = !viewData.pause;
                        }
                    }
                }

                Slider
                {
                    id: sliderDelay

                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignRight

                    from: 0
                    to: viewData.delayMSMAX
                }
            }
        }
    }

    onViewDataChanged:
    {
        sliderDelay.value = viewData.delayMS;
    }

    Connections
    {
        target: sliderDelay

        function onValueChanged()
        {
            viewData.delayMS = sliderDelay.value;
        }
    }

    Connections
    {
        target: viewData

        function onDelayChanged()
        {
            sliderDelay.value = viewData.delayMS;
        }
    }

}

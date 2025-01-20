import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QDAFLib 1.0
import "./.."

QCViewDevicesItem
{
    id: root

    property string caption: ""

    ColumnLayout
    {
        anchors.left: parent.left
        anchors.right: parent.right

        spacing: 5

        Text
        {
            Layout.fillWidth: true
            text: caption
        }

        ComboBox
        {
            Layout.fillWidth: true
            model:
            {
                var stringList = [];

                if(viewData)
                {
                    for (var i = 0; i < viewData.devices.length; i++)
                    {
                        var device = viewData.devices[i];
                        var str = device.description;

                        if(device.isDefault)
                            str += qsTr(" (default)");

                        stringList.push(str);
                    }
                }

                return stringList;
            }

            onCurrentIndexChanged:
            {
                viewData.setSelectedDevice(viewData.devices[currentIndex].id);
            }
        }
    }
}

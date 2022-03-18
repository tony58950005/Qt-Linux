import QtQuick 2.11
import QtQuick.Controls 2.4

Page {
    width: 1024
    height: 600

    header: Label {
        text: qsTr("Page 2")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        text: qsTr("You are on Page 2.")
        anchors.centerIn: parent
    }
}

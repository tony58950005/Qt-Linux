import QtQuick 2.11
import QtQuick.Controls 2.4
import com.company.openotherapp 1.0
Page1FormForm {
    Openotherapp{
        id:openOtherApp
    }
    Page {
        width: 600
        height: 400

//        header: Label {
//            text: qsTr("Loongson Desk 1")
//            font.pixelSize: Qt.application.font.pixelSize * 2
//            padding: 10
//        }

        Grid {
            anchors.verticalCenterOffset: 0
            anchors.horizontalCenterOffset: 0
            columns: 3
            rows: 3
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            Rectangle {
                id: rect1
                color: "red"
                width: 50
                height: 50
            }
            Rectangle {
                id: rect2
                color: "red"
                width: 50
                height: 50
            }
            Rectangle {
                id: rect3
                color: "red"
                width: 50
                height: 50
            }
            Rectangle {
                id: rect4
                color: "green"
                width: 50
                height: 50
            }
            Rectangle {
                id: rect5
                color: "green"
                width: 50
                height: 50
            }
            Rectangle {
                id: rect6
                color: "green"
                width: 50
                height: 50
            }
            Rectangle {
                id: rect7
                color: "blue"
                width: 50
                height: 50
            }
            Rectangle {
                id: rect8
                color: "blue"
                width: 50
                height: 50
            }

            Image {
                id:img9
                width: 50
                height: 50
                source: "qrc:/qtlogo.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: openOtherApp.openClock()

                }
            }

        }
    }

}

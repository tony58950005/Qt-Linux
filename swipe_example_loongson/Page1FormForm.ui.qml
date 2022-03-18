import QtQuick 2.11
import QtQuick.Controls 2.4

Page {
    width: 1024
    height: 600

    header: Label {
        text: qsTr("Loongson Desk 1")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }
    Image {
        width: 1024
        height: 600
        rotation: 0
        source: "qrc:/background/UbuntuStyle3.jpg"


//        header: Label {
//            text: qsTr("Loongson Desk 1")
//            font.pixelSize: Qt.application.font.pixelSize * 2
//            padding: 10
//        }

        Text{
            id:nowTimes
            font.pixelSize: 50
            font.bold: true
            anchors.top: parent.top
            anchors.topMargin: 30
            anchors.left: parent.left
            anchors.leftMargin: 390
            color: "white"
            width: parent.width
            anchors.fill: parent
            height: parent.height

        }




        Grid {

            anchors.verticalCenterOffset: 0
            anchors.horizontalCenterOffset: 0
            flow:Grid.LeftToRight

            columns: 4
            rows: 2
            spacing: 50
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            y:10
            z:1
            Image {
                id:img1
                width: 100
                height: 100
                source: "qrc:/icon/1.png"

            }
            Image {
                id:img2
                width: 100
                height: 100
                source: "qrc:/icon/2.png"



            }
            Image {
                id:img3
                width: 100
                height: 100
                source: "qrc:/icon/3.png"

            }
            Image {
                id:img4
                width: 100
                height: 100
                source: "qrc:/icon/4.png"

            }
            Image {
                id:img5
                width: 100
                height: 100
                source: "qrc:/icon/5.png"

            }
            Image {
                id:img6
                width: 100
                height: 100
                source: "qrc:/icon/6.png"

            }
            Image {
                id:img7
                width: 100
                height: 100
                source: "qrc:/icon/7.png"

            }
            Image {
                id:img8
                width: 100
                height: 100
                source: "qrc:/icon/8.png"

            }



        }
    }

}

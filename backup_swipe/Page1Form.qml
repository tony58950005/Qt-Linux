import QtQuick 2.11
import QtQuick.Controls 2.4
import com.company.openotherapp 1.0

Page1FormForm {
    id:page1
    Openotherapp{
        id:openOtherApp
    }
    header: Label {
        text: {
                qsTr("TOPEET Loongson Desktop 1")
        }

        //padding: 3

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
//            anchors.left: parent.left
//            anchors.leftMargin: 390
            color: "white"
            width: parent.width
            //anchors.fill: parent
//            height: parent.height

        }

        Timer{

            function getCurDate(){
                var d = new Date();
                var year = d.getFullYear();
                var month = add_zero(d.getMonth()+1);
                var days = add_zero(d.getDate());
                var hours = add_zero(d.getHours());
                var minutes = add_zero(d.getMinutes());
                var seconds = add_zero(d.getSeconds());
                var ndate = year+"/"+month+"/"+days+"\n"+"  "+hours+":"+minutes+":"+seconds;
                return ndate;
            }

            function add_zero(temp){
                if(temp<10)
                    return "0"+temp;
                else
                    return temp;
            }
            id:nowTimer;
            interval:1000;running:true;repeat:true;
            onTriggered:{
                nowTimes.text = getCurDate()//let time to be shown as text
                showFullScreen()
            }
        }

        Grid {

            anchors.verticalCenterOffset: 0
            anchors.horizontalCenterOffset: 0
            flow:Grid.LeftToRight

            columns: 4
            rows: 2
            spacing: 80
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            y:10
            z:1
            Image {
                id:img1
                width: 100
                height: 100
                source: "qrc:/icon/1.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        openOtherApp.openCalendar()
                    }

                }
            }
            Image {
                id:img2
                width: 100
                height: 100
                source: "qrc:/icon/2.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: openOtherApp.openClock()

                }


            }
            Image {
                id:img3
                width: 100
                height: 100
                source: "qrc:/icon/3.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: openOtherApp.openSerial()

                }
            }
            Image {
                id:img4
                width: 100
                height: 100
                source: "qrc:/icon/4.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: openOtherApp.openRs485()

                }
            }
            Image {
                id:img5
                width: 100
                height: 100
                source: "qrc:/icon/5.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: openOtherApp.openCan()

                }
            }
            Image {
                id:img6
                width: 100
                height: 100
                source: "qrc:/icon/6.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: openOtherApp.openLed()

                }
            }
            Image {
                id:img7
                width: 100
                height: 100
                source: "qrc:/icon/7.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: openOtherApp.openTemperature()

                }
            }
            Image {
                id:img8
                width: 100
                height: 100
                source: "qrc:/icon/8.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: openOtherApp.openWeather()

                }
            }



        }
    }

}

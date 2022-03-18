import QtQuick 2.11
import QtQuick.Controls 2.4
import com.company.openotherapp 1.0
Page2FormForm {
    id:page2
    Openotherapp{
        id:openOtherApp
    }
    header: Label {
        id:headerpart
        text: {
                qsTr("TOPEET Loongson Desktop 2")
        }

        //padding: 3

    }

    Image {
        width: 1024
        height: 600
        rotation: 0
        source: "qrc:/background/UbuntuStyle4.jpg"

        Text{
            id:nowTimes2
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
            id:nowTimer2;
            interval:1000;running:true;repeat:true;
            onTriggered:{
                nowTimes2.text = getCurDate()//let time to be shown as text
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
                source: "qrc:/icon/9.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        openOtherApp.openBuzzer()
                    }

                }
            }
            Image {
                id:img2
                width: 100
                height: 100
                source: "qrc:/icon/10.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: openOtherApp.openBearmonitor()

                }


            }
            Image {
                id:img3
                width: 100
                height: 100
                source: "qrc:/icon/11.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: openOtherApp.openMediaplayer()

                }
            }
            Image {
                id:img4
                width: 100
                height: 100
                source: "qrc:/icon/12.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: openOtherApp.openGps()

                }
            }
            Image {
                id:img5
                width: 100
                height: 100
                source: "qrc:/icon/13.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: openOtherApp.openPictureviewer()

                }
            }
            Image {
                id:img6
                width: 100
                height: 100
                source: "qrc:/icon/14.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: openOtherApp.openFileview()

                }
            }
            Image {
                id:img7
                width: 100
                height: 100
                source: "qrc:/icon/15.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: openOtherApp.openTetris()

                }
            }
            Image {
                id:img8
                width: 100
                height: 100
                source: "qrc:/icon/16.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: openOtherApp.openWuziqi()

                }
            }



        }
    }

}

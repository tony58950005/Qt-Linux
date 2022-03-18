import QtQuick 2.11
import QtQuick.Controls 2.4
import com.company.openotherapp 1.0

Page3FormForm {

    id:page3
    Openotherapp{
        id:openOtherApp
    }
    header: Label {
        text: {
                qsTr("TOPEET Loongson Desktop 3")
        }

        //padding: 3

    }

    Image {
        width: 1024
        height: 600
        rotation: 0
        source: "qrc:/background/UbuntuStyle3.jpg"

        Text{
            id:nowTimes3
            font.pixelSize: 50
            font.bold: true
            anchors.top: parent.top
            anchors.topMargin: 30
            visible: true

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
            id:nowTimer3;
            interval:1000;running:true;repeat:true;
            onTriggered:{
                nowTimes3.text = getCurDate()//let time to be shown as text
                showFullScreen()
            }
        }
    }
    Text {
        id: name_topeet
        text: qsTr("北京迅为电子有限公司\n")
        anchors.top: parent.top
        anchors.topMargin: 190
        font.family: "Helvetica"
        font.pointSize: 40
        color:"white"
        font.bold: true
    }

    Text {
        id: details_topeet
        text: qsTr("销售客服 ：010-58957586\n全国服务热线：010-85270716丨010-85270708\n公司地址: 北京市海淀区永翔北路9号中国航发大厦三层")
        anchors.top: name_topeet.bottom;anchors.topMargin: 0
        font.family: "Helvetica"
        font.pointSize: 30
        color:"white"
        font.bold: false
    }

}

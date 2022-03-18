import QtQuick 2.11
import QtQuick.Controls 2.4

ApplicationWindow {
    visible: true
    width: 1024
    height: 600

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
            //nowTimes.text = getCurDate()//let time to be shown as text
            showFullScreen()
        }
    }


    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex
        visible: true

        Page1Form {

        }

        Page2Form {
        }
        Page3Form {
        }
    }

    footer: TabBar {
        id: tabBar
        visible: true
        currentIndex: swipeView.currentIndex
        contentHeight:20

        TabButton {
            text: qsTr("•")
            font.bold: true
            font.pixelSize: 30
        }
        TabButton {
            text: qsTr("••")
            font.bold: true
            font.pixelSize: 30
        }
        TabButton {
            text: qsTr("•••")
            font.bold: true
            font.pixelSize: 30
        }

    }


}


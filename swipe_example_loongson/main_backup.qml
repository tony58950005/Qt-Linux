import QtQuick 2.11
import QtQuick.Controls 2.4

import com.company.openotherapp 1.0


ApplicationWindow {
    id:appWin
    visible: true
    width: 1024
    height: 600
    Openotherapp{
        id:openOtherApp
    }



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
        id:nowTimer;
        interval:1000;running:true;repeat:true;
        onTriggered:{
            update()

        }
    }




    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex
        visible: true
        interactive: true




//        function moveCenter(center){
//            swipeView.x=center.x-width/2
//            swipeView.y=center.y-height/2
//        }
//        ParallelAnimation{
//            id:goToxAnimation
//            NumberAnimation {
//                target: swipeView
//                properties: "x"
//                //from:0.1
//                to:appWin.width-swipeView.width
//                duration: 500
//                easing.type: Easing.OutBounce
//            }
//        }
//        function goBackAnimation(){
//            goToxAnimation.start()
//        }


        Timer
        {
            running: true
            repeat:false
            interval: 100
            triggeredOnStart: true
            onTriggered: {
                swipeOnce()
                swipeOnce()
            }
            function swipeOnce(){
                var nextIndex = (swipeView.currentIndex+1) % swipeView.count
                console.log("NEXT:"+nextIndex)
                swipeView.setCurrentIndex(nextIndex)
            }

        }



        Page1Form {

        }

        Page2Form {

        }
        Page3Form {

        }


    }

    footer: TabBar {
        id: tabBar
        visible: false
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



    PageIndicator {
        id: pageIndicator
        interactive: true
        count: swipeView.count
        currentIndex: swipeView.currentIndex

        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        delegate: Rectangle{
            implicitWidth: 15
            implicitHeight: 15

            radius: width
            color:"white"

            opacity: index===pageIndicator.currentIndex ? 0.95:pressed?0.7:0.45
            Behavior on opacity {
                OpacityAnimator{duration: 100}
            }
        }

    }


}


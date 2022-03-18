import QtQuick 2.11
import QtQuick.Controls 2.4
import com.company.openotherapp 1.0
Page2FormForm {
    property int clickNum: 0
    id:page2
    Openotherapp{
        id:openOtherApp
    }
    header: Label {
        id:headerpart
        text: {
            qsTr("TOPEET Loongson Desktop 1")
        }

        //padding: 3

    }

    Image {
        width: 1024
        height: 600
        rotation: 0
        source: "qrc:/background/UbuntuStyle4.jpg"
        MouseArea{

            width:parent.width
            height:parent.height
            preventStealing: true
            property real velocity:0.0
            property int xStart:0
            property int xPrev:0
            property bool tracing:false
            onPressed: {
                xStart = mouse.x
                xPrev = mouse.x
                velocity = 0
                tracing = true
    //            console.log(" pressed "+xStart)
    //            console.log(" pressed "+xPrev)
            }

            onPositionChanged: {
                if( !tracing) return
                var currVel = (mouse.x-xPrev)
                velocity = (velocity + currVel)/2.0
                xPrev = mouse.x
                if(velocity > 0.1 && mouse.x > parent.width*0.02){
                    tracing = false
                    //console.log("sipw to right")

                }
            }
            onReleased: {
                tracing:false
                console.log("velocity:"+velocity)
                if(velocity>=0.5){
                    console.log("swipe to left")
                    currentIndex: swipeView.decrementCurrentIndex()
                }else if(velocity<=-0.5 ){
                    console.log("swipe to right")
                    currentIndex: swipeView.incrementCurrentIndex()
                }
            }
        }

        Text{
            id:nowTimes2
            font.pixelSize: 60
            font.bold: true
            anchors.top: parent.top
            anchors.topMargin: 40
//            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Gill Sans "
            color: "white"

        }
        Timer{
            id:clickTimer
            interval:200
            onTriggered: {
                clickNum =0
                clickTimer.stop()
                console.log("clicked, clicked, clicked")
            }

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
            }
        }



        Grid {

            anchors.verticalCenterOffset: 50
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
                scale: m1.containsMouse ? 1.2:1

                WorkerScript{
                    id:thread1
                    source: "handler.js"
                    onMessage: {
                        openOtherApp.openBuzzer()
                        busyIndicator1.running = messageObject.run;

                    }
                }

                MouseArea{
                    id:m1
                    anchors.fill: parent
                    anchors.margins: 20
                    hoverEnabled: true
                    pressAndHoldInterval: 200
                    propagateComposedEvents: false
//                    onPressAndHold: {
//                        console.log("drag")
//                        mouse.accepted = false
//                    }
                    onClicked: {
                            busyIndicator1.running = true
                            thread1.sendMessage({run : true});
                    }
                    onReleased: {
                        console.log("openBuzzer")
                        mouse.accepted = false
                    }

                    BusyIndicator{
                        id:busyIndicator1
                        anchors.centerIn: parent
                        implicitHeight: 50
                        implicitWidth: 50
                        opacity: running? 1.0 : 1.0
                        //contentItem: QmlBusyIndicator{}
                        running:false
                    }


                }
            }
            Image {
                id:img2
                width: 100
                height: 100
                source: "qrc:/icon/10.png"
                scale: m2.containsMouse ? 1.2:1

                WorkerScript{
                    id:thread2
                    source: "handler.js"
                    onMessage: {
                        openOtherApp.openBearmonitor()
                        busyIndicator2.running = messageObject.run;

                    }
                }

                MouseArea{
                    id:m2
                    anchors.fill: parent
                    anchors.margins: 20
                    hoverEnabled: true
                    pressAndHoldInterval: 200
                    propagateComposedEvents: false

                    onClicked: {
                            busyIndicator2.running = true
                            thread2.sendMessage({run : true});
                    }
                    onReleased: {
                        console.log("openBearermonitor")
                        mouse.accepted = false
                    }

                    BusyIndicator{
                        id:busyIndicator2
                        anchors.centerIn: parent
                        implicitHeight: 50
                        implicitWidth: 50
                        opacity: running? 1.0 : 1.0
                        //contentItem: QmlBusyIndicator{}
                        running:false
                    }
                }


            }
            Image {
                id:img3
                width: 100
                height: 100
                source: "qrc:/icon/11.png"
                scale: m3.containsMouse ? 1.2:1

                WorkerScript{
                    id:thread3
                    source: "handler.js"
                    onMessage: {
                        openOtherApp.openMediaplayer()
                        busyIndicator3.running = messageObject.run;

                    }
                }

                MouseArea{
                    id:m3
                    anchors.fill: parent
                    anchors.margins: 20
                    hoverEnabled: true
                    pressAndHoldInterval: 200
                    propagateComposedEvents: false

                    onClicked: {
                            busyIndicator3.running = true
                            thread3.sendMessage({run : true});
                    }
                    onReleased: {
                        console.log("openMediaplayer")
                        mouse.accepted = false
                    }

                    BusyIndicator{
                        id:busyIndicator3
                        anchors.centerIn: parent
                        implicitHeight: 50
                        implicitWidth: 50
                        opacity: running? 1.0 : 1.0
                        //contentItem: QmlBusyIndicator{}
                        running:false
                    }
                }
            }
            Image {
                id:img4
                width: 100
                height: 100
                source: "qrc:/icon/12.png"
                scale: m4.containsMouse ? 1.2:1

                WorkerScript{
                    id:thread4
                    source: "handler.js"
                    onMessage: {
                        openOtherApp.openGps()
                        busyIndicator4.running = messageObject.run;

                    }
                }

                MouseArea{
                    id:m4
                    anchors.fill: parent
                    anchors.margins: 20
                    hoverEnabled: true
                    pressAndHoldInterval: 200
                    propagateComposedEvents: false

                    onClicked: {
                            busyIndicator4.running = true
                            thread4.sendMessage({run : true});
                    }
                    onReleased: {
                        console.log("openGPS")
                        mouse.accepted = false
                    }

                    BusyIndicator{
                        id:busyIndicator4
                        anchors.centerIn: parent
                        implicitHeight: 50
                        implicitWidth: 50
                        opacity: running? 1.0 : 1.0
                        //contentItem: QmlBusyIndicator{}
                        running:false
                    }
                }
            }
            Image {
                id:img5
                width: 100
                height: 100
                source: "qrc:/icon/13.png"
                scale: m5.containsMouse ? 1.2:1

                WorkerScript{
                    id:thread5
                    source: "handler.js"
                    onMessage: {
                        openOtherApp.openPictureviewer()
                        busyIndicator5.running = messageObject.run;

                    }
                }

                MouseArea{
                    id:m5
                    anchors.fill: parent
                    anchors.margins: 20
                    hoverEnabled: true
                    pressAndHoldInterval: 200
                    propagateComposedEvents: false

                    onClicked: {
                            busyIndicator5.running = true
                            thread5.sendMessage({run : true});
                    }
                    onReleased: {
                        console.log("openPictureviewer")
                        mouse.accepted = false
                    }

                    BusyIndicator{
                        id:busyIndicator5
                        anchors.centerIn: parent
                        implicitHeight: 50
                        implicitWidth: 50
                        opacity: running? 1.0 : 1.0
                        //contentItem: QmlBusyIndicator{}
                        running:false
                    }
                }
            }
            Image {
                id:img6
                width: 100
                height: 100
                source: "qrc:/icon/14.png"
                scale: m6.containsMouse ? 1.2:1

                WorkerScript{
                    id:thread6
                    source: "handler.js"
                    onMessage: {
                        openOtherApp.openFileview()
                        busyIndicator6.running = messageObject.run;

                    }
                }


                MouseArea{
                    id:m6
                    anchors.fill: parent
                    anchors.margins: 20
                    hoverEnabled: true
                    pressAndHoldInterval: 200
                    propagateComposedEvents: false

                    onClicked: {
                            busyIndicator6.running = true
                            thread6.sendMessage({run : true});
                    }
                    onReleased: {
                        console.log("openFileviewer")
                        mouse.accepted = false
                    }
                    BusyIndicator{
                        id:busyIndicator6
                        anchors.centerIn: parent
                        implicitHeight: 50
                        implicitWidth: 50
                        opacity: running? 1.0 : 1.0
                        //contentItem: QmlBusyIndicator{}
                        running:false
                    }
                }
            }
            Image {
                id:img7
                width: 100
                height: 100
                source: "qrc:/icon/15.png"
                scale: m7.containsMouse ? 1.2:1

                WorkerScript{
                    id:thread7
                    source: "handler.js"
                    onMessage: {
                        openOtherApp.openTetris()
                        busyIndicator7.running = messageObject.run;

                    }
                }

                MouseArea{
                    id:m7
                    anchors.fill: parent
                    anchors.margins: 20
                    hoverEnabled: true
                    pressAndHoldInterval: 200
                    propagateComposedEvents: false

                    onClicked: {
                            busyIndicator7.running = true
                            thread7.sendMessage({run : true});
                    }
                    onReleased: {
                        console.log("openTetris")
                        mouse.accepted = false
                    }

                    BusyIndicator{
                        id:busyIndicator7
                        anchors.centerIn: parent
                        implicitHeight: 50
                        implicitWidth: 50
                        opacity: running? 1.0 : 1.0
                        //contentItem: QmlBusyIndicator{}
                        running:false
                    }
                }
            }
            Image {
                id:img8
                width: 100
                height: 100
                source: "qrc:/icon/16.png"
                scale: m8.containsMouse ? 1.2:1

                WorkerScript{
                    id:thread8
                    source: "handler.js"
                    onMessage: {
                        openOtherApp.openWuziqi()
                        busyIndicator8.running = messageObject.run;

                    }
                }

                MouseArea{
                    id:m8
                    anchors.fill: parent
                    anchors.margins: 20
                    hoverEnabled: true
                    pressAndHoldInterval: 200
                    propagateComposedEvents: false

                    onClicked: {
                            busyIndicator8.running = true
                            thread8.sendMessage({run : true});
                    }
                    onReleased: {
                        console.log("openWuziqi")
                        mouse.accepted = false
                    }

                    BusyIndicator{
                        id:busyIndicator8
                        anchors.centerIn: parent
                        implicitHeight: 50
                        implicitWidth: 50
                        opacity: running? 1.0 : 1.0
                        //contentItem: QmlBusyIndicator{}
                        running:false
                    }
                }
            }

        }
    }

}

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

    PathView{
        id:view
        anchors.fill:parent
        snapMode: PathView.SnapOneItem
        model:["Page2Form.qml","Page1Form.qml","Page3Form.qml"]
        delegate: Loader{
            width:parent.width
            height:parent.height
            source:modelData


        }
//        highlightRangeMode: PathView.StrictlyEnforceRange
//        currentIndex: -1
//        pathItemCount: height/itemHeight
//        preferredHighlightBegin: 0.5
//        preferredHighlightEnd: view.width/5
        path:Path{
            startX:view.width/2;startY: view.height/2
//            PathQuad { x: view.width/2; y: -view.height*view.model.length; controlX: -view.width; controlY: view.height/2 }
//            PathQuad { x: view.width/2; y: view.height/2; controlX: view.width * view.model.length; controlY: view.height/2 }

            PathLine { x: view.width*view.model.length; y: view.height/2 }
            PathLine { x: view.width/2; y: view.height/2 }
        }
    }
}

import QtQuick 2.0
import QtQuick.Controls 2.0

Button{
    property string textButton
    property real widthButton
    property real heigthButton
    property string idMouseArea

        id:idMouseArea
        width: widthButton
        height: heigthButton
        spacing: 10
        background: Rectangle{
        color:  mouseAreaBtnDeBusca.containsMouse ? "#11cdef" /*ou #0fdbff*/ : "#dfe0e1"
        radius: 10

        Label {
            text: textButton
            font.family: "Helvetica"
            font.pointSize: 15
            color: mouseAreaBtnDeBusca.containsMouse ? "#fff" :  "black"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            opacity: mouseAreaBtnDeBusca.containsMouse ? 1 : 0.6
          }
       }
   }

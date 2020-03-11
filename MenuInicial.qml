import QtQuick 2.6
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.12

Rectangle{

    id:ratangulo
    width: parent.width / 2
    height: cadastro.height / 2
    anchors.centerIn: parent
    color: "#fff"
    anchors.leftMargin: 30
    border.color: "#d3d3d3";
    radius: 10
    border.width: 0.3
    visible: false

    signal emitSignalFundo();
    signal buscarPorNome();

Column{
    width: parent.width
    height: parent.height / 1.6
    anchors.bottom: parent.bottom

Button{
    id:btnNovoBilhete
    width:  mouseAreaNovoBilhete.pressed ? parent.width / 1.5 : parent.width / 2
    height: mouseAreaNovoBilhete.pressed ? parent.height / 4.5 : parent.height / 5
    anchors.horizontalCenter: parent.horizontalCenter
    Label {
        text: "Novo Bilhete"
        font.family: "Helvetica"
        font.pointSize: mouseAreaNovoBilhete.pressed ? 20 :15
        color: mouseAreaNovoBilhete.containsMouse ? "#fff" :  "black"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        opacity: mouseAreaNovoBilhete.containsMouse ? 1 : 0.6
      }
    background: Rectangle{
    radius: 10
    visible: true
    color: mouseAreaNovoBilhete.containsMouse ? "#11cdef" /*ou #0fdbff*/ : "#dfe0e1"    }
MouseArea{
    id:mouseAreaNovoBilhete
    anchors.fill: parent
    hoverEnabled: true
        onClicked: {
           ratangulo.emitSignalFundo()
       }
    }
}

Button{
    id:btnBuscas
    anchors.horizontalCenter: parent.horizontalCenter
    width:  mouseAreaBuscarBilhete.pressed ? parent.width / 1.5 : parent.width / 2
    height: mouseAreaBuscarBilhete.pressed ? parent.height / 4.5 : parent.height / 5
    Label {
        text: "Buscas"
        font.family: "Helvetica"
        font.pointSize: mouseAreaBuscarBilhete.pressed ? 20 :15
        color: mouseAreaBuscarBilhete.containsMouse ? "#fff" :  "black"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        opacity: mouseAreaBuscarBilhete.containsMouse ? 1 : 0.6
      }
    spacing: 10
    anchors.top: btnNovoBilhete.bottom
    anchors.topMargin: 2
    background: Rectangle{
    radius: 10
    color: mouseAreaBuscarBilhete.containsMouse ? "#11cdef" /*ou #0fdbff*/ : "#dfe0e1"}
MouseArea{
    id:mouseAreaBuscarBilhete
    anchors.fill: parent
    hoverEnabled: true
        onClicked: {
            ratangulo.buscarPorNome();
        }
      }
    }
  }
}



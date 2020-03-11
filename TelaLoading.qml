import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.12
import br.com.bilheteentradaousaida 1.0

Rectangle{
id:root
width: parent.width
height: parent.height
color: "transparent"

   signal iconSucessoVisible( var bool , var bool);
   property bool imgSelect: bilheteEntradaOuSaida.selectAnimationFailOrSucess
   property bool animationRunnigFalseOrTrue:bilheteEntradaOuSaida.animationRunnig
    function iconVisibleCheck(){
    if( img.visible ){
     return root.iconSucessoVisible( true , root.imgSelect )
    }
   }

    function iconeSucess(){
        root.iconVisibleCheck()
        img.playing = true
    return "img/loading.gif";
    }

Rectangle{
    id:retanguloOpacidade
    width: parent.width
    height: parent.height
    color: "#000"
    opacity: 0.5
}

Rectangle{
    id:retanguloLoading
    width: parent.width / 3.5
    height: parent.height / 1.8
    radius: 15
    color: "#fff"
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter

Column{
    width: parent.width
    height: parent.height / 2

Label{
    id:msmSucesso
    anchors.topMargin: 40
    text: root.imgSelect ? "Sucesso!" : "Erro!"
    font.pointSize: 36
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    color: root.imgSelect ? "#47ad49" : "red"
    visible: img.visible ? true : false
  }
}

Rectangle{
    id:teste
    width: 125
    height: 125
    radius: 360
    border.color: "#fff"
    color: "#47ad49"
    opacity: 0.3
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    visible: animationRunnigFalseOrTrue ? true : false

    NumberAnimation on height {
    loops: Animation.Infinite
    from: teste.height
    to: 150
    duration:2000
}

NumberAnimation on width {
    loops: Animation.Infinite
    from: teste.width
    to: 150
    duration:2000
 }
}

Rectangle{
    id:teste2
    width: 60
    height: 60
    border.color: "#fff"
    color: "#fff"
    radius: 360
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    visible: animationRunnigFalseOrTrue ? true : false

NumberAnimation on height {
    id:animation
    loops: Animation.Infinite
    from: teste2.height
    to: 150
    duration:2000
}

NumberAnimation on width {
    loops: Animation.Infinite
    from: teste2.width
    to: 150
    duration:2000
    }
  }
    AnimatedImage {
        id:img
        anchors.centerIn: parent
        width: 80
        height: 80
        source: root.imgSelect ? root.iconeSucess() : "img/fail.png"
        visible: !animationRunnigFalseOrTrue ? true : false
        opacity: 0.9
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter        
        onVisibleChanged: root.iconVisibleCheck()
        playing: img.visible ? true : false
    }
  }
}

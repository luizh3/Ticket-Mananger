import QtQuick 2.12
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.12
import br.com.telaconfiggeral 1.0
import br.com.bilheteentradaousaida 1.0

Rectangle{
    id:mainRetangulo
    anchors.fill: parent
    width: parent.width
    color: "white"
    anchors.margins: 30

    property var retornoTextComboBox
    property var turmas: configGeral.comboBox

    BilheteEntradaOuSaida{
    id:bilheteEntradaOuSaida
    }

    onBuscarPorNomeDto:function( nome , turma){
     bilheteEntradaOuSaida.buscarPorNomeDto( nome , turma);
    }

    ConfigGeral{
    id:configGeral
    }

    function retanguloLadoDireito(){
    retanguloDireita.visible = bilheteEntradaOuSaida.hasDtos()
    }

    signal buscarPorNomeDto( var nome , var turma );
    signal voltarPagina();

    function clear(){
    textNome.text = ""
    turmaAluno.text = ""
    textNome.focus = true
    }

    function dtoLimpar(){
    repeater.model = 0   
    }
    function dtoSetar(){
        repeater.model = bilheteEntradaOuSaida.dtos
    }

    Column{
    width: parent.width
    height: parent.height - ( 2.8 * btnVoltar.height )
    spacing: 15

    Row{
    id:row
    spacing: 15
    width: parent.width

    TextField{
    id:textNome
    width: parent.width / 1.56
    height: 50
    placeholderText: "Buscar Por Nome"
    background: Rectangle{
    radius: 10
    border.color: textNome.focus ? "#11cdef" : "#d3d3d3"
    }
  }
    RowLayout{
    id:rouList
    Layout.fillWidth: true
    width: 200
    height: 50
    NotoComboBox{
    modelTxt: turmas
    textEditComboBox:"Turma:"
    widthComBox: 200
    heigthComBox: 50
    onEmitirText: function( texto ){
       mainRetangulo.retornoTextComboBox = texto
     }
   }
 }

    Button{
        id:btnDeBusca
        width: parent.width / 6
        height: 50
        spacing: 10
        background: Rectangle{
        color: mouseAreaBtnDeBusca.containsMouse ? "#11cdef" /*ou #0fdbff*/ : "#dfe0e1"
        radius: 10
        visible: true
        anchors.left: textNome.right

        Label {
               text: "Buscar"
               font.family: "Helvetica"
               font.pointSize: 15
               color: mouseAreaBtnDeBusca.containsMouse ? "#fff" :  "black"
               anchors.horizontalCenter: parent.horizontalCenter
               anchors.verticalCenter: parent.verticalCenter
               opacity: mouseAreaBtnDeBusca.containsMouse ? 1 : 0.6
       }
    }

    MouseArea{
        id:mouseAreaBtnDeBusca
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
//      turmadoaluno.currentIndex == 1 ? turmadoaluno.currentText = "" : turmadoaluno.currentText
        mainRetangulo.buscarPorNomeDto( textNome.text , mainRetangulo.retornoTextComboBox );
        mainRetangulo.dtoSetar()
        mainRetangulo.retanguloLadoDireito()
        mainRetangulo.clear()
        }
     }
   }
}

    Rectangle{
    width: parent.width / 1.04
    height: 1
    color: "#dfe0e1"
    }

    Row{

        id:rowId
        spacing: 40
        width: parent.width
        height: parent.height

    Flickable{
    id:flickable
    width:parent.width / 2 - 30
    height: parent.height - row.height - parent.spacing
    contentHeight: todoList.height
    clip: true

             Column{
                    id:todoList
                    width: parent.width
                    spacing: 10

                     Repeater{
                         model:bilheteEntradaOuSaida.dtos
                         id:repeater

                    Todo{

                    id:todo
                    nome:modelData.nome
                    turma:modelData.turma
                    assinaturaPedagogo: modelData.assinatura
                    tipoBilhete:modelData.tipoBilhete
                    turno:modelData.turno
                    motivoEmissao:modelData.motivo
                    descricaoBilhete:modelData.description
                    horaEmissao:modelData.hora
                    dataEmissao:modelData.data
                    border.color: mouseArea.containsMouse ? "#87cefa" : "#d3d3d3"
                    width: todoList.width / 1.2  + 30

                    RotationAnimation on width {
                        running: mouseArea.containsMouse
                        from: todo.width
                        to: todoList.width / 1.1 + 30
                        duration: 200
                    }

                    RotationAnimation on height {
                        running: mouseArea.containsMouse
                        from: todo.height
                        to: 275
                        duration: 200
                    }

                    SequentialAnimation {
                        running: !mouseArea.containsMouse
                        NumberAnimation { target: todo; property: "width"; to: todoList.width / 1.2  + 30; duration: 200 }
                    }

                    SequentialAnimation {
                        running: !mouseArea.containsMouse
                        NumberAnimation { target: todo; property: "height"; to: 250; duration: 200}
                    }

                    MouseArea{
                    id:mouseArea
                    anchors.fill: todo
                    hoverEnabled: true
                 }
               }
            }
        }

   ScrollBar.vertical: ScrollBar {
   active: flickable.interactive
  }
}

    Rectangle{
    id:retanguloDireita
    width: parent.width / 2.2
    height:  parent.height - 50
    color: "#fff"
    visible: bilheteEntradaOuSaida.hasDtos()
    radius: 10
    border.color: "#d3d3d3"

    Rectangle{
    id:textRetangulo
    width: parent.width  / 1.1
    height:  parent.height / 1.1
    color: "#fff"
    anchors.centerIn: parent

    Column{
    width: parent.width
    height: parent.height
    spacing: 30

        Repeater{
        id:repeaterDireita
        model:bilheteEntradaOuSaida.dtosTelaBusca
        TelaListarInformacoesAluno{
        }
        }
     }
    }
  }
}

    Button{
        id:btnVoltar
        width: parent.width / 6
        height: 50
        background: Rectangle{
        color:  btnVoltarMouseArea.containsMouse ? "#11cdef" /*ou #0fdbff*/ : "#dfe0e1"
        radius: 10
        visible: true
        Label {
              text: "Voltar"
              font.family: "Helvetica"
              font.pointSize: 15
              color: btnVoltarMouseArea.containsMouse ? "#fff" :  "black"
              anchors.horizontalCenter: parent.horizontalCenter
              anchors.verticalCenter: parent.verticalCenter
              opacity: btnVoltarMouseArea.containsMouse ? 1 : 0.6
            }
    }
    MouseArea{
        id:btnVoltarMouseArea
        anchors.fill: parent
        hoverEnabled: true
        onClicked:function() {
            mainRetangulo.voltarPagina()
            mainRetangulo.dtoLimpar()
            retanguloDireita.visible = false
        }
      }
    }
  }
}

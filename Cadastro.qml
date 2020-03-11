import QtQuick 2.0
import QtQuick.Controls 2.0
import br.com.bilhete 1.0
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.12
import br.com.telaconfiggeral 1.0
import br.com.bilheteentradaousaida 1.0

Rectangle{

    id:root
    color: "#fff"

    signal centroBilhete( var description , var nome , var assinatura , var dateString , var turma , var turno);
    signal cabecalho ( var tipoBilhete, var motivo );
    signal retornarPrint( var retorno );
    signal opcaoGerarPdf( var opcaoGerarPdf )
    signal salvarArquivo();
    signal voltarTela();

    property var locale: Qt.locale()
    property date currentDate: new Date()
    property string dateString
    property string retornoPrintar :'Precione Salvar Para Saida Do bilhete'
    property var retornoTurmas : configGeral.comboBox
    property var retornoTextComboBoxTipo
    property var retornoTextComboBoxTurno
    property var retornoTextComboBoxTurmaAluno

    onCentroBilhete: function( description , nome , assinatura , dataString , turma , turno){
        bilheteEntradaOuSaida.centroBilhete( description , nome , assinatura , dataString , turma , turno )
    }
    onCabecalho: function( tipoBilhete, motivo ){
        bilheteEntradaOuSaida.cabesalhoBilhete( tipoBilhete , motivo)
    }

    onOpcaoGerarPdf:function( opcaoGerarPdf ){
        bilheteEntradaOuSaida.setOpcaoGerarPdf( opcaoGerarPdf )
    }

    onSalvarArquivo: function(){
        bilheteEntradaOuSaida.salvarArquivoFormatado()
    }

    BilheteEntradaOuSaida{
    id:bilheteEntradaOuSaida
    }

    ConfigGeral{
    id:configGeral
    }

    function validarEnable(){
      if( nome.text == '' || motivo.text == '' || assinatura.text == ''  || retornoTextComboBoxTurmaAluno == '' || retornoTextComboBoxTurno == '' ){
            return false
      }
      return true
    }

    function textFieldDisable(){
        btn.enabled = false
        mycomboTurno1.enabled = false
        mycomboTurno.enabled = false
        myswitch.enabled = false
        description.enabled = false
        nome.enabled = false
        motivo.enabled = false
        assinatura.enabled = false
        btn2.enabled = false
        bilheteTipoBilhete.enabled = false
    }

    function textFieldEnable(){
        btn.enabled = true
        mycomboTurno1.enabled = true
        mycomboTurno.enabled = true
        myswitch.enabled = true
        description.enabled = true
        nome.enabled = true
        motivo.enabled = true
        assinatura.enabled = true
        btn2.enabled = true
        bilheteTipoBilhete.enabled = true

    }

    onRetornarPrint : {
        retornoPrintar = bilheteEntradaOuSaida.arquivoPrintar()
    }

    QtObject {
    Component.onCompleted: {
            dateString = currentDate.toLocaleDateString();
            print( dateString );
        }
    }

    function reset(){
        description.text = ''
        nome.text = ''
        motivo.text = ''
        assinatura.text = ''
        textFieldTurma.focus = true
    }

    Rectangle{
    anchors.fill: parent
    width: parent.width
    height: parent.height
    anchors.margins: parent.width / 30
    anchors.topMargin: parent.height / 8
    color: "#fff"


    RowLayout{
        Layout.fillWidth: true
        Layout.fillHeight: true
        anchors.bottom: container.top
    Label{
        text: "GERAR-PDF" /*+ " = " + myswitch.position*/
        font.pointSize: 13
        horizontalAlignment: Label.AlignHCenter
        verticalAlignment: Label.AlignVCenter
    }
    Switch{
        id:myswitch
        text: myswitch.position == 1 ? "SIM" :"NAO"
        font.pointSize: 13
    }
    }

    RectangularGlow {
        id: effect1
        anchors.fill: ratangulo
        glowRadius: 10
        cornerRadius: 10
        spread: 0.1
        color: "#d3d3d3"
    }

    Rectangle{
    id:ratangulo
    width: parent.width / 2
    height:parent.height / 1.1
    anchors.left:container.right
    color: "#fff"
    radius: 10
    anchors.margins: 10

    TextArea {
        id:textArea
        anchors.centerIn: parent
        font.pointSize: 12
        text: retornoPrintar
        color:"black"
        enabled: false
        background: Rectangle{
            border.color: "#9da7b1"
            radius: 3
        }
      }
    }

    RectangularGlow {
        id: effect2
        anchors.fill: container
        glowRadius: 10
        cornerRadius: 10
        spread: 0.1
        color: "#d3d3d3"
    }

    Rectangle{
        id:container
        width: parent.width / 2
        height: parent.height / 1.1
        radius: 10

    Rectangle{
        anchors.fill: parent
        color: "white"
        width: parent.width
        anchors.margins: 15
        anchors.topMargin: 30

        Column{
            id:column
            width: parent.width
            spacing: 7

            RowLayout{
            Layout.fillWidth: true
            spacing: 20

            NotoComboBox{
            id:bilheteTipoBilhete
            widthComBox: 330
            heigthComBox: 50
            modelTxt: ["","ENTRADA","SAIDA"]
            textEditComboBox: "BILHETE DE:"
            onEmitirText: function( texto ){
               root.retornoTextComboBoxTipo = texto
             }
           }
            NotoComboBox{
            id:mycomboTurno
            widthComBox: 330
            heigthComBox: 50
            modelTxt: ["","MANHA","TARDE","NOITE"]
            textEditComboBox: "TURNO ALUNO:"
            onEmitirText: function( texto ){
               root.retornoTextComboBoxTurno = texto
             }
           }
         }

            RowLayout{
            Layout.fillWidth: true

            NotoComboBox{
            id:mycomboTurno1
            widthComBox: 680
            heigthComBox: 50
            modelTxt: retornoTurmas
            textEditComboBox: "TURMA ALUNO:"
            onEmitirText: function( texto ){
               root.retornoTextComboBoxTurmaAluno = texto
             }
           }

           }

            TextField{
               id:nome
               placeholderText: "Nome Aluno"
               width: parent.width / 2
               anchors.left: parent.left
               height: 45
               background: Rectangle{
               radius: 5
               border.color: nome.focus ? /*"#87cefa"*/ "#11cdef" : "#d3d3d3"
               }
            }

            TextField{
               id:motivo
               placeholderText: "Motivo"
               width: parent.width
               height: 45
               background: Rectangle{
               radius: 5
               border.color: motivo.focus ? /*"#87cefa"*/ "#11cdef" : "#d3d3d3"
               }

            }
            TextField{
               id:assinatura
               placeholderText: "Assinatura Pedagogo"
               width: parent.width / 2
               height: 45
               background: Rectangle{
               radius: 5
               border.color: assinatura.focus ? /*"#87cefa"*/ "#11cdef" : "#d3d3d3"
               }
            }

            TextArea{
                id:description
                placeholderText: "Complemento"
                width: parent.width
                height: parent.height / 2.5
                wrapMode: "WordWrap"
                background: Rectangle{
                    border.color: description.focus ? /*"#87cefa"*/ "#11cdef" : "#d3d3d3"
                    radius: 5
                }
            }


         Row {
             spacing: 20

             Button{
                 id:btn
                 width: ratangulo.width / 3
                 height: ratangulo.height / 11
                 spacing: 10
                 background: Rectangle{
                 color: colorButtonSalvar()
                 anchors.left: btn2.right
                 radius: 10

                 function colorButtonSalvar(){
                     if( !mouseAreaBtnSalvar.enabled ){
                        return "#a9a9a9"
                     }else if( mouseAreaBtnSalvar.enabled && mouseAreaBtnSalvar.containsMouse ){
                            labelTxtSalvar.color = "#fff"
                            labelTxtSalvar.opacity = 1.0
                            return "#11cdef"
                     }
                       labelTxtSalvar.opacity = 0.6
                    labelTxtSalvar.color = "black"
                   return "#dfe0e1"
                 }

                 Label {
                     id:labelTxtSalvar
                     text: "Salvar"
                     font.family: "Helvetica"
                     font.pointSize: 15
                     color: !mouseAreaBtnSalvar.enabled ? "#fff" : "black"
                     anchors.horizontalCenter: parent.horizontalCenter
                     anchors.verticalCenter: parent.verticalCenter
                     opacity: !mouseAreaBtnSalvar.enabled ? 0.8 : 0.6
                   }

             }
             MouseArea{
                 id:mouseAreaBtnSalvar
                 anchors.fill: parent
                 hoverEnabled: true
                 enabled: root.validarEnable()

                 onClicked: {
                     root.centroBilhete( description.text , nome.text ,  assinatura.text , dateString , retornoTextComboBoxTurmaAluno , retornoTextComboBoxTurno );
                     root.cabecalho( retornoTextComboBoxTipo , /*emitidopor.text ,*/ motivo.text )
                     root.textFieldDisable()
                     telaLoading.visible = true
                     root.opcaoGerarPdf( myswitch.position )
                     root.salvarArquivo();
                     root.retornarPrint( retornoPrintar );
                     root.reset()
                 }
               }
            }

            Button{
                id:btn2
                width: ratangulo.width / 3
                height: ratangulo.height / 11
                spacing: 10
                background: Rectangle{
                color:  mouseAreaBtnDeBusca.containsMouse ? "#11cdef" /*ou #0fdbff*/ : "#dfe0e1"
                radius: 10

                Label {
                    text: "Voltar"
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
                onClicked:{
                root.voltarTela()
              }
             }
           }
         }
       }
    }
  }

//    DropShadow {
//        anchors.fill: container
//        horizontalOffset: -1 && 1
//        verticalOffset: -1 && 1
//        baselineOffset:  1 && 1
//        radius: 4.0
//        samples: 10
//        spread: 0.5
//        color: "#d3d3d3"
//        source: container
//    }
 }

    TelaLoading{
    id:telaLoading
    visible: false
    width: parent.width
    height: parent.height

    property bool buttonColorCheck : false
    property bool buttonCheckFailOuSucess : false

    onIconSucessoVisible:function( boolParam1 , boolParam2 ){
        buttonColorCheck = boolParam1
        buttonCheckFailOuSucess = boolParam2
    }

    function validarCorButton(){
        if( buttonColorCheck && buttonCheckFailOuSucess ){
            return "#74d175"
        }else if( buttonColorCheck && !buttonCheckFailOuSucess ){
            return "red"
        }
       return "#dfe0e1"
    }

    function validarCorTextoButton(){
        if( buttonColorCheck ){
            return "#fff"
        }
       return "#000"
    }

    Column{
        width: parent.width / 3.5
        height: parent.height / 1.8
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

    Column{
        width: parent.width
        height:parent.height / 1.1

    Button{
        id:buttonVoltar
        width: mouseAreaSalvar.pressed ? parent.width / 1.6  : parent.width / 2.1
        height:mouseAreaSalvar.pressed ? parent.height / 5.5 : parent.height / 6.5

    TextEdit {
        id:textFielText
        text: "Voltar"
        font.family: "Helvetica"
        font.pointSize: 15
        color: telaLoading.validarCorTextoButton()
        focus: true
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
      }
        anchors.bottom:parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        background: Rectangle{
        color: telaLoading.validarCorButton()
        radius: 5
    }
    MouseArea{
        id:mouseAreaSalvar
        hoverEnabled: true
        anchors.fill: parent
        onClicked: {
        root.textFieldEnable()
        telaLoading.visible = false
           }
          }
         }
       }
     }
   }
 }

//    states: State {
//        name: "pressed"
//        when: mouseArea.pressed
//        PropertyChanges {
//            target: root
//            scale: root.enabled ? 1.2 : 1.0
//        }
//    }

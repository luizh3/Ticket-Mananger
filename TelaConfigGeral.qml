import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.1
import br.com.telaconfiggeral 1.0;

Rectangle {
    id:retangulo
    anchors.fill: parent
    color: "#fff"

    ConfigGeral{
    id:configGeral
    }

//    onVisibleChanged: timmer2.running = true
    property string retornoNomeEscola: configGeral.retornoNomeEscola()
    property string retornoNumMaximoCarcter: configGeral.retornoMaximoCaracterLinha()
    property bool validAnimationFailOrSucess: configGeral.selectAnimationFailOrSucess
    property var retornoTextComboBox
    property var turmas: configGeral.comboBox

    signal voltarPagina();
    signal salvarNomeEscola( var nomeEscola , var maximoCaraLinha );
    signal adicionarNomeTurma (var nomeTurma );
    signal mudarResulucaoTela ( var index );
    signal excluirTurma( var turma );

    onAdicionarNomeTurma:function( nomeTurma){
        configGeral.insertNomeTurma( nomeTurma )
    }

    onExcluirTurma:function( turma ){
        configGeral.deletarTurma( turma );
    }

    onSalvarNomeEscola:function( nomeEscola , maximoCaraLinha ){
        configGeral.salvarNomeEscola( nomeEscola  , maximoCaraLinha)
    }

    function validarSalvarTurmaOuNao(){
        if( !criarNovaTurmaCheckBox.checked ){
      retangulo.adicionarNomeTurma( adicionarNovaTurma.text )
    }
  }

    function validarExcluirTurmaOuNao(){
        if( !excluirTurmaCheckBox.checked ){
            retangulo.excluirTurma( retornoTextComboBox );
        }
    }

//    function validarOpacity(){
//    if( imgSucess.visible ){
//    for( var i = 0; i < 50; i++){
//        imgSucess.opacity -= 0.01
//      }
//    }
//  }


    function ativarCheck(){
      checkBoxNomeEscola.checked = true
      checkBoxCaracteLinha.checked = true
      criarNovaTurmaCheckBox.checked = true
      adicionarNovaTurma.text = ""
    }

    Label{
    text: "CONFIGURACOES"
    font.pointSize: 30
    anchors.horizontalCenter: parent.horizontalCenter
    }

    RectangularGlow {
        id: effect
        anchors.fill: segundoRetangulo
        glowRadius: 10
        cornerRadius: 10
        spread: 0.1
        color: "#d3d3d3"
    }

    Rectangle{
    width: parent.width
    height: parent.height
    color: "black"
    opacity: 0.3
    }

    Rectangle{
    id:imgSucess
    width: 330
    height: 150
    color: "transparent"
    anchors.right: parent.right
    visible: false

//    Timer{ id:timmer2; interval: 1000; onTriggered: timmer2.running ? imgSucess.visible = true : false }

    Timer {
        id:timmer; interval: 500; repeat: true
        onTriggered: retangulo.validarOpacity()
    }

    SequentialAnimation on y {
        id:animation
        running: imgSucess.visible ? true : false
        PropertyAnimation { from:45; to: 25 ; duration: 150;}
        PropertyAnimation { from:25; to: 25 ; duration: 1250;}
        PropertyAnimation { to: -120; duration: 400; }
    }

    Rectangle{
    width: 280
    height: 75
    anchors.centerIn: parent
    color: retangulo.validAnimationFailOrSucess ? "#b7d8b7" : "#f8b7bd"
    radius: 5

    Image {
        id:imgV
        anchors.right: textId.left
        anchors.verticalCenter: parent.verticalCenter
        width:  retangulo.validAnimationFailOrSucess ? 30 : 40
        height:  retangulo.validAnimationFailOrSucess ? 30 : 40
        source: retangulo.validAnimationFailOrSucess ? "img/v.png" : "img/img8.png"
    }

    Label{
      id:textId
     anchors.fill: parent
     anchors.topMargin:  parent.height / 3
     anchors.leftMargin:  retangulo.validAnimationFailOrSucess ? parent.width / 5 : parent.width / 4
//     anchors.horizontalCenter: parent.horizontalCenter
//     anchors.verticalCenter: parent.verticalCenter
     text: retangulo.validAnimationFailOrSucess ?  " Arquivo Salvo com Sucesso!" : "Erro Tente novamente!"
     font.pointSize: 11
     opacity: 0.8
     }

    }

    }

    Rectangle{
    id:segundoRetangulo
    width: parent.width / 2.5
    height: parent.height / 1.2
    anchors.centerIn: parent
    color: "white"
    radius: 10

    Button{
    id:buttonVoltar
    width: 50
    height: 50
    anchors.right: parent.right
    background: Rectangle{
    border.color: mouseAreaVoltar.containsMouse ? "#87cefa" : "#d3d3d3"
    radius: 5
    opacity: 0
    }

    Image {
        id:img
        anchors.centerIn: parent
        width: 35
        height: 35
        source: "img/img8.png"

        SequentialAnimation {
            running: mouseAreaVoltar.containsMouse
            NumberAnimation { target: img; property: "width"; to: 40; duration: 50 }
        }

        SequentialAnimation {
            running: mouseAreaVoltar.containsMouse
            NumberAnimation { target: img; property: "height"; to: 40; duration: 50}
        }

        SequentialAnimation {
            running: !mouseAreaVoltar.containsMouse
            NumberAnimation { target: img; property: "width"; to: 35; duration: 50 }
        }

        SequentialAnimation {
            running: !mouseAreaVoltar.containsMouse
            NumberAnimation { target: img; property: "height"; to: 35; duration: 50}
        }

        MouseArea{
        id:mouseAreaImage
        hoverEnabled: true
        anchors.fill: img
        }
     }

    MouseArea{
    id:mouseAreaVoltar
    hoverEnabled: true
    anchors.fill: parent
    onClicked: {
        retangulo.voltarPagina()
        retangulo.ativarCheck()
    }
   }
  }

Column{
    width: parent.width
    height: parent.height / 4
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.bottom: parent.bottom

    Button{
    width:mouseAreaSalvar.pressed ? parent.width / 2.5: parent.width / 3
    height:mouseAreaSalvar.pressed ? parent.height / 2.5 : parent.height / 3
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    background: Rectangle{
    color: mouseAreaSalvar.containsMouse ? "#11cdef" /*ou #0fdbff*/ : "#dfe0e1"
    radius: 5
    Label {
        text: "Salvar"
        font.family: "Helvetica"
        font.pointSize: mouseAreaSalvar.pressed ? 20 :15
        color: mouseAreaSalvar.containsMouse ? "#fff" :  "black"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        opacity: mouseAreaSalvar.containsMouse ? 1 : 0.6
      }
    }
    MouseArea{
    id:mouseAreaSalvar
    hoverEnabled: true
    anchors.fill: parent
    onClicked: {
     retangulo.salvarNomeEscola( nomeEscola.text , maximoCaracterLinha.text )
     retangulo.validarSalvarTurmaOuNao();
     retangulo.validarExcluirTurmaOuNao();
     retangulo.ativarCheck()
     imgSucess.visible = true
     animation.running = true
//     retangulo.validarOpacity();
//     timmer.running = true;
    }
   }
  }
}

    Column{
    anchors.centerIn: parent
    width: parent.width - 100
    height: parent.height - 100
    spacing: 10

    CheckBox {
        id:checkBoxNomeEscola
        checked: true
        text: checkBoxNomeEscola.checked ? "Editar Nome Colegio": "Edicao Abilitada"

    }

    TextField{
       id:nomeEscola
       text: retornoNomeEscola
       width: parent.width / 2
       anchors.left: parent.left
       height: 40
       enabled: checkBoxNomeEscola.checked ? false : true
       background: Rectangle{
       radius: 5
       enabled: false
       color: checkBoxNomeEscola.checked ? "#d3d3d3" : "white"
       border.color: nomeEscola.focus && !checkBoxNomeEscola.checked ? "#87cefa" : "#d3d3d3"

       }
    }

    CheckBox{
        id:checkBoxCaracteLinha
        checked: true
        text: checkBoxCaracteLinha.checked ? "Editar Maximo Caracter Uma Linha" : "Edicao Abilitada"
    }

    TextField{
       id:maximoCaracterLinha
       placeholderText: retornoNumMaximoCarcter
       width: parent.width / 2
       anchors.left: parent.left
       height: 40
       enabled: checkBoxCaracteLinha.checked ? false : true
       background: Rectangle{
       radius: 5
       enabled: false
       color: checkBoxCaracteLinha.checked ? "#d3d3d3" : "white"
       border.color: maximoCaracterLinha.focus && !checkBoxCaracteLinha.checked ? "#87cefa" : "#d3d3d3"
       }
    }

    RowLayout{
    Layout.fillWidth: true
    Layout.fillHeight:true

    Label{
    text: "GERAR-PDF"
    font.pixelSize: 16
    horizontalAlignment:Label.AlignHCenter
    verticalAlignment: Label.AlignVCenter
    }

    Switch{
    id:mySwitch
    text: mySwitch.position == 1 ? "SIM" : "NAO"
    font.pointSize: 13
      }
     }

    CheckBox{
        id:criarNovaTurmaCheckBox
        checked: true
        text: criarNovaTurmaCheckBox.checked ? "Adicionar turma" : "Edicao Abilitada"
    }

    TextField{
       id:adicionarNovaTurma
       placeholderText: "Adicionar turma"
       width: parent.width / 2
       anchors.left: parent.left
       height: 40
       enabled: criarNovaTurmaCheckBox.checked ? false : true
       background: Rectangle{
       radius: 5
       enabled: false
       color: criarNovaTurmaCheckBox.checked ? "#d3d3d3" : "white"
       border.color: adicionarNovaTurma.focus && !criarNovaTurmaCheckBox.checked ? "#87cefa" : "#d3d3d3"
      }
    }


    CheckBox{
        id:excluirTurmaCheckBox
        checked: true
        text: excluirTurmaCheckBox.checked ? "Excluir turma" : "Edicao Abilitada"
    }
    NotoComboBox{
    modelTxt: turmas
    textEditComboBox:"Turma:"
    widthComBox: parent.width / 2
    heigthComBox: 40
    tamanhoQuadradoDropBox:45
    enabled: !excluirTurmaCheckBox.checked
    onEmitirText: function( texto ){
       retangulo.retornoTextComboBox = texto
     }
   }

    ColumnLayout {
        Column{
//        Label{
//        text:"Ajustar Resolucao da Tela"
//        }
        Row{
         spacing: 10
        RadioButton {
            text: qsTr("FullScreen")
            onCheckedChanged: retangulo.mudarResulucaoTela( true  );

        }
        RadioButton {
            checked: true
            text: qsTr("Modo Janela")
            onCheckedChanged: retangulo.mudarResulucaoTela(  false );
        }
       }
      }
    }
   }
 }
}


